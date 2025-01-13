#include <string.h>
#include <stdint.h>

#include "sdk_project_config.h"

#include "defineble.h"
#include "definecanoe.h"

#include "defines.h"

#include "commble.h"
#include "commcanoe.h"
#include "commuwb.h"
#include "commpc.h"

#ifdef HEADER_BLE_FLASH_WRITE
#include "code_ble.h"
#endif


//----------------------------------------------
//	Definitions
//----------------------------------------------
#define READ_SPI_READY			(PINS_DRV_ReadPins(PTA) & (1 << 3))
#define READ_SPI_INT			(PINS_DRV_ReadPins(PTA) & (1 << 2))

#define ACK_RETRY_MAX           200
#define DATA_RETRY_MAX          3

#define SPI_ACK                 0xCC
#define SPI_NAK                 0x33
//  IC SIZE
#define FLASH_SIZE              0x58000

#define INFO_ADDR               0x54000
#define INFO_SIZE               0x02000

#define BIM_ADDR                0x56000
#define BIM_SIZE                0x02000

#define SECTOR_SIZE             0x02000
#define DOWNLOAD_SIZE           0x00080

#define SECTOR_SIZE				0x02000			//	(1 << 13)

#define SPI_BUFFER_SIZE			0x90
#define UART_BUFFER_SIZE		0x100

enum
{
	eBLE_STATUS_APP = 0,
	eBLE_STATUS_BOOT,
};

enum
{
	eSTEP_SPI_IDLE = 0,
	eSTEP_SPI_CHECKREADY,
	eSTEP_SPI_SENDSTART,
	eSTEP_SPI_SENDING,
	eSTEP_SPI_SENDDONE,
	eSTEP_SPI_RECVSTART,
	eSTEP_SPI_RECEIVING,
	eSTEP_SPI_RECVDONE,
};

enum
{
	eSTEP_UART_IDLE = 0,
	eSTEP_UART_DELAY,
	eSTEP_UART_SEND,
	eSTEP_UART_WAITACK,
	eSTEP_UART_RECV,
};

enum
{
	eSTEP_FLOW_IDLE = 0,
	eSTEP_FLOW_COMMAND_BUILD,
	eSTEP_FLOW_COMMAND_WAIT,
	eSTEP_FLOW_AUTOBAUDRATE,
	eSTEP_FLOW_REPROG_BUILD,
	eSTEP_FLOW_REPROG_WAIT,
};

enum
{
	eTYPE_TRANSMIT_NONE = 0,
	eTYPE_TRANSMIT_REQUEST,
	eTYPE_TRANSMIT_RESPONSE_1,
	eTYPE_TRANSMIT_RESPONSE_2,
};

enum
{
	eSTEP_REPROGRAM_INIT = 0,
	eSTEP_REPROGRAM_STATUS,
	eSTEP_REPROGRAM_ERASE,
	eSTEP_REPROGRAM_HEADER,
	eSTEP_REPROGRAM_WRITE,
	eSTEP_REPROGRAM_DATA,
	eSTEP_REPROGRAM_CRC32,
	eSTEP_REPROGRAM_EXIT,
};


//	REPROGRAMMING
#define REPROGRAM_COUNTER_MAX	7
#define REPROGRAM_FRAME_SIZE	(128 + 16)




//----------------------------------------------
//	Variables
//----------------------------------------------
static int m_nBleStatus = eBLE_STATUS_APP;
static int m_nSpiStep = eSTEP_SPI_IDLE;
static int m_nFlowStep = eSTEP_FLOW_IDLE;
static int m_nTransmitType = eTYPE_TRANSMIT_NONE;
static int m_nNumberReadsize = 0;
//static int m_nNumberRemaining = 0;

static bool m_bReady = false;
static bool m_bIntOccured = false;
static bool m_bTransmitted = false;
static bool m_bReceived = false;
static bool m_bResponseDone = false;

static volatile unsigned int m_nGpioValue;

static unsigned int m_nRecvComplete;


typedef struct
{
	unsigned char tx[SPI_BUFFER_SIZE];
	unsigned char rx[SPI_BUFFER_SIZE];
} spi_buffer_t;

static status_t m_transStatus;
static unsigned char m_SpiSend[SPI_BUFFER_SIZE];
static unsigned char m_SpiRecv[SPI_BUFFER_SIZE];
static unsigned char m_SpiZero[SPI_BUFFER_SIZE];

static int m_nRecvLen;
static int m_nRecvSize;

static unsigned char m_RecvBuffer[UART_BUFFER_SIZE];
static unsigned char m_ProcBuffer[UART_BUFFER_SIZE];
static unsigned char m_SendBuffer[UART_BUFFER_SIZE];

static int m_nReprogramCounter = 0;
static int m_nEraseCounter = 0;
static int m_nEraseMaxCounter;
static int m_nFlashCounter = 0;
static int m_nFlashMaxCounter;

static int m_nFileSize, m_nVersion, m_nCrc32;

static unsigned int m_nSpiReadyTimer;
static unsigned int m_nSpiReplyTimer;
static unsigned int m_nRebootTimer;
static unsigned int m_nAutoGenerionTimer;




//----------------------------------------------
//  Prototype Functions
//----------------------------------------------
static void callbackSpiIo(void);
static void callbackReceive(void *driverState, uart_event_t event, void *userData);

static void procSpi(void);
static void procReprogram(void);
static void procFlow(void);

static void onRecvSpiMessage(unsigned char *pBuffer, int cbData);

static void doSendSpiAck();
static void doSendSpiNak();

static void doMakeSpiSend(unsigned int nID, unsigned char *pBuffer, int cbData);

static void doAutoBaudrate(void);
static void doSendPing(void);
static void doSendGetChipid(void);
static void doSendGetStatus(void);
static void doSendSectorErase(unsigned int nAddr);
static void doSendDownStart(unsigned int nAddr, int cbData);
static void doSendDownCrc32Start(unsigned int nAddr, int cbData);
static void doSendData(unsigned int nAddr);
static void doSendCrc32(unsigned int nAddr, int cbData, unsigned int nRepeat);
static void doSendReset(void);


//----------------------------------------------
//	Functions
//----------------------------------------------
void initBLE(void)
{
	(void)m_nSpiReplyTimer;
	(void)m_SendBuffer;
	(void)m_ProcBuffer;
	(void)doSendReset;
	(void)doSendDownStart;
	(void)doSendGetStatus;
	(void)doSendGetChipid;

	simpleZero(m_SpiZero, SPI_BUFFER_SIZE);

    //	SPI master configuration: clock speed: 500 kHz, 8 bits/frame, LSB first
    LPSPI_DRV_MasterInit(INST_LPSPI_2, &lpspi_2State, &lpspi_1_MasterConfig0);
    //	Configure delay between transfer, delay between SCK and PCS and delay between PCS and SCK
//    LPSPI_DRV_MasterSetDelay(INST_LPSPI_2, 100, 1, 1);
    LPSPI_DRV_MasterSetDelay(INST_LPSPI_2, 200, 2, 2);

    PINS_DRV_SetPinDirection(PTA, 9U, GPIO_OUTPUT_DIRECTION);
    PINS_DRV_WritePin(PTA, 9U, 1);

    PINS_DRV_SetPinDirection(PTA, 2U, GPIO_INPUT_DIRECTION);
    PINS_DRV_SetPinDirection(PTA, 3U, GPIO_INPUT_DIRECTION);
    m_nGpioValue = PINS_DRV_ReadPins(PTA);

//    PINS_DRV_SetPinIntSel(PORTA, 2U, PORT_INT_EITHER_EDGE);
    PINS_DRV_SetPinIntSel(PORTA, 2U, PORT_INT_FALLING_EDGE);
//    PINS_DRV_SetPinIntSel(PORTA, 3U, PORT_INT_EITHER_EDGE);
    INT_SYS_InstallHandler(PORTA_IRQn, &callbackSpiIo, NULL);
    INT_SYS_EnableIRQ(PORTA_IRQn);

    //	initialize UART
    LPUART_DRV_Init(INST_LPUART_LPUART_2, &lpUartState2, &lpUartInitConfig2);
    LPUART_DRV_InstallRxCallback(INST_LPUART_LPUART_2, callbackReceive, NULL);

    m_nRecvLen = 0;
    m_nRecvSize = 2;
	LPUART_DRV_ReceiveData(INST_LPUART_LPUART_2, m_RecvBuffer, 1U);
}

void commBLE(unsigned int nEvent)
{
	if(nEvent & EVENT_SPIREADY)
	{
		m_bReady = true;
	}
	if(nEvent & EVENT_SPIINT)
	{
		m_bIntOccured = true;
	}
	if(nEvent & EVENT_SPITO)
	{
		m_bTransmitted = true;
	}
	if(nEvent & EVENT_RXUART2)
	{
		m_bReceived = true;
	}
#if BUTTON_TEST == 2
	if(nEvent & EVENT_BTN1)
	{
		unsigned char buffer[4] = { 0x07, };
		doCan2Ble(COMMAND_BLE_REPROGRAM, buffer, 1);
	}
	if(nEvent & EVENT_BTN2)
	{
		doCan2Ble(COMMAND_BLE_TEST, NULL, 0);
	}
#endif

	switch(m_nBleStatus)
	{
	case eBLE_STATUS_BOOT:
		procReprogram();
		break;
	case eBLE_STATUS_APP:
	default:
		procSpi();
		break;
	}

	procFlow();
}


//----------------------------------------------
//	Callback
//----------------------------------------------
static void callbackSpiIo(void)
{
	unsigned int nEvent = 0;
    uint32_t nOccured = PINS_DRV_GetPortIntFlag(PORTA) & ((1 << 2) | (1 << 3));

    if(nOccured != 0)
    {
        if(nOccured & (1 << 2))
        {
        	PINS_DRV_ClearPinIntFlagCmd(PORTA, 2U);
        	nEvent = nEvent | EVENT_SPIINT;
        }

        m_nGpioValue = PINS_DRV_ReadPins(PTA);

    	setEvent(nEvent);
    }
}

static void callbackReceive(void *driverState, uart_event_t event, void *userData)
{
	//	unused parameters
	(void)driverState;
	(void)userData;

	switch(event)
	{
	case UART_EVENT_RX_FULL:
		if(m_nRecvLen >= (m_nRecvSize - 1))
		{
			m_nRecvLen++;
		}
		else
		{
			LPUART_DRV_SetRxBuffer(INST_LPUART_LPUART_2, &m_RecvBuffer[++m_nRecvLen], 1U);
		}
		break;
	case UART_EVENT_END_TRANSFER:
		m_nRecvComplete++;
		setEvent(EVENT_RXUART2);
		break;
	case UART_EVENT_TX_EMPTY:
	case UART_EVENT_ERROR:
		LPUART_DRV_ReceiveData(INST_LPUART_LPUART_2, m_RecvBuffer, 1U);
		break;
	}
}


//----------------------------------------------
//	from CAN
//----------------------------------------------
void doCan2Ble(unsigned char nID, unsigned char *pBuffer, int cbData)
{
	unsigned int *pCodeBle;

    switch(nID)
	{
	case COMMAND_BLE:
	    doMakeSpiSend(nID, pBuffer, cbData);
		break;

	case COMMAND_BLE_REPROGRAM:
//		PINS_DRV_WritePin(PTA, 9U, 0);	//	for EXIT BOOT

#ifdef HEADER_BLE_FLASH_WRITE
		pCodeBle = (unsigned int *)m_codeBle;
#else

#endif
		m_nFileSize = pCodeBle[0];
		m_nVersion = pCodeBle[1];
		m_nCrc32 = pCodeBle[2];

		m_nReprogramCounter = 0;
		m_nEraseCounter = 0;
		m_nEraseMaxCounter = (m_nFileSize & 0x1FFF) ? ((m_nFileSize >> 13) + 1) : (m_nFileSize >> 13);
		m_nFlashCounter = 0;
		m_nFlashMaxCounter = (m_nFileSize & 0x7F) ? ((m_nFileSize >> 7) + 1) : (m_nFileSize >> 7);

		m_nReprogramCounter = eSTEP_REPROGRAM_STATUS;
		m_nFlowStep = eSTEP_FLOW_AUTOBAUDRATE;
		break;

#if BUTTON_TEST == 2
	case COMMAND_BLE_TEST:
		doAutoBaudrate();
		doSendCrc32(0, m_nFileSize, 0);
		break;
#endif
	}
}


//----------------------------------------------
//	Process
//----------------------------------------------
void procSpi(void)
{
	switch(m_nSpiStep)
	{
	case eSTEP_SPI_IDLE:
		if(m_bIntOccured == true)
		{
			m_bIntOccured = false;
	    	m_nSpiStep = eSTEP_SPI_RECVSTART;
		}
		else if(m_nTransmitType == eTYPE_TRANSMIT_REQUEST)
		{
			m_nSpiReadyTimer = OSIF_GetMilliseconds() + 2;
			m_nSpiStep = eSTEP_SPI_CHECKREADY;
		}
		break;
	case eSTEP_SPI_CHECKREADY:
		if(READ_SPI_READY == 0)
//		if(((m_nGpioValue = PINS_DRV_ReadPins(PTA)) & (1 << 3)) == 0)
		{
			m_nSpiStep = eSTEP_SPI_SENDSTART;
		}
		else
		{
			if(OSIF_GetMilliseconds() > m_nSpiReadyTimer)
			{
				m_nSpiStep = eSTEP_SPI_IDLE;
			}
		}
		break;
	case eSTEP_SPI_SENDSTART:
		m_transStatus = LPSPI_DRV_MasterTransferBlocking(INST_LPSPI_2, m_SpiSend, m_SpiRecv, m_nNumberReadsize, m_nNumberReadsize);
		if(m_transStatus == STATUS_SUCCESS)
		{
			m_bTransmitted = true;
			m_nSpiStep = eSTEP_SPI_SENDING;
		}
		else
		{
			m_nSpiStep = eSTEP_SPI_IDLE;
		}
		break;
	case eSTEP_SPI_SENDING:
		if(m_bTransmitted == true)
		{
			m_bTransmitted = false;
			m_nSpiStep = eSTEP_SPI_SENDDONE;
		}
		break;
	case eSTEP_SPI_SENDDONE:
		m_nTransmitType = eTYPE_TRANSMIT_NONE;
		m_nSpiStep = eSTEP_SPI_IDLE;
		break;

	case eSTEP_SPI_RECVSTART:
		m_transStatus = LPSPI_DRV_MasterTransferBlocking(INST_LPSPI_2, (unsigned char *)m_SpiZero, (unsigned char *)m_SpiRecv, 2, 1);
		if(m_transStatus == STATUS_SUCCESS)
		{
			if(m_SpiRecv[0] == 0)
			{
				switch(m_SpiRecv[1])
				{
				case SPI_ACK:
				case SPI_NAK:
					m_nSpiStep = eSTEP_SPI_IDLE;
					break;
				case 0:
				default:
					break;
				}
			}
			else
			{
		    	m_nNumberReadsize = m_SpiRecv[0];
//		    	m_transStatus = LPSPI_DRV_MasterTransfer(INST_LPSPI_2, (unsigned char *)m_SpiZero, (unsigned char *)(m_SpiRecv + 0), m_nNumberReadsize);
		    	for(volatile int i = 0; i < 200; i++);
		    	for(volatile int i = 0; i < 1000; i++)
		    	{
		    		if(READ_SPI_READY == 0)
		    			break;
		    	}
		    	m_transStatus = LPSPI_DRV_MasterTransferBlocking(INST_LPSPI_2, (unsigned char *)m_SpiZero, (unsigned char *)m_SpiRecv, m_nNumberReadsize, m_nNumberReadsize);
		    	m_bTransmitted = true;
				m_nSpiStep = eSTEP_SPI_RECEIVING;
			}
		}
		else
		{
			m_nSpiStep = eSTEP_SPI_IDLE;
		}
		break;
	case eSTEP_SPI_RECEIVING:
		if(m_bTransmitted == true)
		{
			m_bTransmitted = false;
			m_nSpiStep = eSTEP_SPI_RECVDONE;
		}
		break;

	case eSTEP_SPI_RECVDONE:
		m_nSpiStep = eSTEP_SPI_IDLE;
		onRecvSpiMessage(m_SpiRecv, m_nNumberReadsize);
		break;
	}
}

void procReprogram()
{
	switch(m_nSpiStep)
	{
	case eSTEP_UART_IDLE:
		if(m_nTransmitType == eTYPE_TRANSMIT_REQUEST)
		{
			m_nSpiStep = eSTEP_UART_DELAY;
			m_nRebootTimer = OSIF_GetMilliseconds() + 10;
		}
		break;
	case eSTEP_UART_DELAY:
		if(OSIF_GetMilliseconds() > m_nRebootTimer)
		{
			m_nSpiStep = eSTEP_UART_SEND;
		}
		break;
	case eSTEP_UART_SEND:
	    //	UART Start
		m_nRecvLen = 0;
		switch(m_SpiSend[2])
		{
		case COMMAND_CRC32:
		    m_nRecvSize = 8;
		    break;
		default:
		    m_nRecvSize = 2;
			break;
		}
		LPUART_DRV_ReceiveData(INST_LPUART_LPUART_2, m_RecvBuffer, 1U);

		m_transStatus = LPUART_DRV_SendDataBlocking(INST_LPUART_LPUART_2, m_SpiSend, m_nNumberReadsize, (m_nNumberReadsize >> 1));
		if(m_transStatus == STATUS_SUCCESS)
		{
			m_nSpiStep = eSTEP_UART_WAITACK;
		}
		else
		{
			m_nSpiStep = eSTEP_UART_IDLE;
		}
		break;
	case eSTEP_UART_WAITACK:
		if(m_bReceived == true)
		{
			m_bReceived = false;

			for(int i = 0; i < m_nRecvLen; i++)
			{
				if(m_RecvBuffer[i] == SPI_ACK)
				{
					switch(m_SpiSend[2])
					{
					case COMMAND_GET_STATUS:
//						m_nRecvSize = 3;
//						LPUART_DRV_ReceiveData(INST_LPUART_LPUART_2, m_RecvBuffer, 1U);
						m_nSpiStep = eSTEP_UART_RECV;
						break;
					case COMMAND_GET_CHIP_ID:
//						m_nRecvSize = 6;
//						LPUART_DRV_ReceiveData(INST_LPUART_LPUART_2, m_RecvBuffer, 1U);
						m_nSpiStep = eSTEP_UART_RECV;
						break;
					case COMMAND_CRC32:
//						m_nRecvSize = 6;
//						LPUART_DRV_ReceiveData(INST_LPUART_LPUART_2, m_RecvBuffer, 1U);
						m_nSpiStep = eSTEP_UART_RECV;
						break;
					default:
						m_nSpiStep = eSTEP_UART_IDLE;
						m_bResponseDone = true;
						break;
					}
					break;
				}
				else if(m_RecvBuffer[i] == SPI_NAK)
				{
					m_nSpiStep = eSTEP_UART_IDLE;
					break;
				}
			}

			m_nRecvLen = 0;
		}
		break;
	case eSTEP_UART_RECV:
//		if(m_bReceived == true)
		{
//			m_bReceived = false;

			m_nSpiStep = eSTEP_SPI_IDLE;
	//		onRecvSpiMessage(m_SpiRecv, m_nNumberReadsize);
			m_bResponseDone = true;
		}
		break;
	}
}

void procFlow(void)
{
	switch(m_nFlowStep)
	{
	case eSTEP_FLOW_IDLE:
		break;
	case eSTEP_FLOW_COMMAND_BUILD:
		break;

	case eSTEP_FLOW_COMMAND_WAIT:
		break;

	case eSTEP_FLOW_AUTOBAUDRATE:
		doAutoBaudrate();
		m_nFlowStep = eSTEP_FLOW_REPROG_BUILD;
		m_nReprogramCounter = eSTEP_REPROGRAM_INIT;
		m_nAutoGenerionTimer = OSIF_GetMilliseconds() + 10;
		break;

	case eSTEP_FLOW_REPROG_BUILD:
		switch(m_nReprogramCounter)
		{
		case eSTEP_REPROGRAM_INIT:
			if(OSIF_GetMilliseconds() > m_nAutoGenerionTimer)
			{
				m_nFlowStep = eSTEP_FLOW_REPROG_WAIT;
			}
			break;

		case eSTEP_REPROGRAM_STATUS:
			m_nBleStatus = eBLE_STATUS_BOOT;
			m_nFlowStep = eSTEP_FLOW_REPROG_WAIT;
//			doSendGetStatus();
			doSendPing();
			m_bResponseDone = false;
			break;
		case eSTEP_REPROGRAM_ERASE:
			m_nFlowStep = eSTEP_FLOW_REPROG_WAIT;
			doSendSectorErase(m_nEraseCounter * SECTOR_SIZE);
			m_bResponseDone = false;
			break;
		case eSTEP_REPROGRAM_HEADER:
			m_nFlowStep = eSTEP_FLOW_REPROG_WAIT;
			m_bResponseDone = false;
			break;
		case eSTEP_REPROGRAM_WRITE:
			m_nFlowStep = eSTEP_FLOW_REPROG_WAIT;
			doSendDownCrc32Start(0, m_nFileSize);
			m_bResponseDone = false;
			break;
		case eSTEP_REPROGRAM_DATA:
			m_nFlowStep = eSTEP_FLOW_REPROG_WAIT;
			doSendData(m_nFlashCounter * DOWNLOAD_SIZE);
			m_bResponseDone = false;
			break;
		case eSTEP_REPROGRAM_CRC32:
			m_nFlowStep = eSTEP_FLOW_REPROG_WAIT;
			doSendCrc32(0, m_nFileSize, 0);
			m_bResponseDone = false;
			break;
		case eSTEP_REPROGRAM_EXIT:
			m_nBleStatus = eBLE_STATUS_APP;
			m_nFlowStep = eSTEP_FLOW_IDLE;
			break;
		}
		break;
	case eSTEP_FLOW_REPROG_WAIT:
		switch(m_nReprogramCounter)
		{
		case eSTEP_REPROGRAM_INIT:
//			if(m_bResponseDone == true)
			{
				m_nReprogramCounter = eSTEP_REPROGRAM_STATUS;
				m_nFlowStep = eSTEP_FLOW_REPROG_BUILD;
			}
			break;
		case eSTEP_REPROGRAM_STATUS:
			if(m_bResponseDone == true)
			{
				m_nBleStatus = eBLE_STATUS_BOOT;
				m_nReprogramCounter = eSTEP_REPROGRAM_ERASE;

				m_nEraseCounter = 0;
				m_nFlowStep = eSTEP_FLOW_REPROG_BUILD;
			}
			break;
		case eSTEP_REPROGRAM_ERASE:
			if(m_bResponseDone == true)
			{
				if(m_nEraseCounter >= m_nEraseMaxCounter)
				{
//					m_nReprogramCounter = eSTEP_REPROGRAM_HEADER;
					m_nReprogramCounter = eSTEP_REPROGRAM_WRITE;

					m_nFlowStep = eSTEP_FLOW_REPROG_BUILD;
				}
				else
				{
					m_nEraseCounter++;
					m_nFlowStep = eSTEP_FLOW_REPROG_BUILD;
				}
			}
			break;
		case eSTEP_REPROGRAM_HEADER:
			if(m_bResponseDone == true)
			{
				m_nFlashCounter = 0;
				m_nReprogramCounter = eSTEP_REPROGRAM_WRITE;
				m_nFlowStep = eSTEP_FLOW_REPROG_BUILD;
			}
			break;
		case eSTEP_REPROGRAM_WRITE:
			if(m_bResponseDone == true)
			{
				m_nFlashCounter = 0;
				m_nReprogramCounter = eSTEP_REPROGRAM_DATA;
				m_nFlowStep = eSTEP_FLOW_REPROG_BUILD;
			}
			break;
		case eSTEP_REPROGRAM_DATA:
			if(m_bResponseDone == true)
			{
				if(m_nFlashCounter >= m_nFlashMaxCounter)
				{
					m_nReprogramCounter = eSTEP_REPROGRAM_CRC32;
					m_nFlowStep = eSTEP_FLOW_REPROG_BUILD;
				}
				else
				{
					m_nFlashCounter++;
					m_nFlowStep = eSTEP_FLOW_REPROG_BUILD;
#ifdef BLE_DEBUG_SEND
#endif
				}
			}
			break;
		case eSTEP_REPROGRAM_CRC32:
			if(m_bResponseDone == true)
			{
				m_nReprogramCounter = eSTEP_REPROGRAM_EXIT;
				m_nFlowStep = eSTEP_FLOW_REPROG_BUILD;

#ifdef BLE_DEBUG_SEND
				if(((m_nCrc32 >> 24) & 0xFF) == m_RecvBuffer[4]
				&& ((m_nCrc32 >> 16) & 0xFF) == m_RecvBuffer[5]
				&& ((m_nCrc32 >>  8) & 0xFF) == m_RecvBuffer[6]
				&& ((m_nCrc32 >>  0) & 0xFF) == m_RecvBuffer[7])
					doSendDebug((unsigned char *)"BLE Reprogram Success", strlen("BLE Reprogram Success"));
				else
					doSendDebug((unsigned char *)"BLE Reprogram fail !!", strlen("BLE Reprogram fail !!"));
#endif
			}
			break;
		}
		break;
	}
}


//----------------------------------------------
static void onRecvSpiMessage(unsigned char *pBuffer, int cbData)
{
	int i;
	unsigned char nBcc = 0;

	for (i = 2; i < cbData; i++)
	{
		nBcc += pBuffer[i];
	}

	if(nBcc == pBuffer[1])
	{
		doSendSpiAck();

///		OnSendUartData(eSLV, pBuffer[2], pBuffer + 3, cbData - 3);

		doBle2Can(pBuffer, cbData);
	}
	else
	{
		doSendSpiNak();
	}
}

static void doSendSpiAck()
{
	m_nNumberReadsize = 0;
	m_SpiSend[m_nNumberReadsize++] = 0x00;
	m_SpiSend[m_nNumberReadsize++] = SPI_ACK;

    m_nTransmitType = eTYPE_TRANSMIT_REQUEST;
}

static void doSendSpiNak()
{
	m_nNumberReadsize = 0;
	m_SpiSend[m_nNumberReadsize++] = 0x00;
	m_SpiSend[m_nNumberReadsize++] = SPI_NAK;

    m_nTransmitType = eTYPE_TRANSMIT_REQUEST;
}

//----------------------------------------------
static void doMakeSpiSend(unsigned int nID, unsigned char *pBuffer, int cbData)
{
    int i;
    unsigned char nBcc;

	nBcc = nID;
    for (i = 0, m_nNumberReadsize = 3; i < cbData; i++, m_nNumberReadsize++)
    {
        m_SpiSend[m_nNumberReadsize] = pBuffer[i];
        nBcc += pBuffer[i];
    }

    m_SpiSend[0] = m_nNumberReadsize;
    m_SpiSend[1] = nBcc;
    m_SpiSend[2] = nID;

    m_nTransmitType = eTYPE_TRANSMIT_REQUEST;
}

static void doAutoBaudrate(void)
{
	unsigned char Buffer[4] = { 0x55, 0x55 };

	LPUART_DRV_SendDataBlocking(INST_LPUART_LPUART_2, Buffer, 2, 1);
}

static void doSendPing(void)
{
    doMakeSpiSend(COMMAND_PING, NULL, 0);
}

static void doSendGetChipid(void)
{
	doMakeSpiSend(COMMAND_GET_CHIP_ID, NULL, 0);
}

static void doSendGetStatus(void)
{
	doMakeSpiSend(COMMAND_GET_STATUS, NULL, 0);
}

static void doSendSectorErase(unsigned int nAddr)
{
	//	Big-endian
	int cbSize = 0;
	unsigned char Buffer[4];

	Buffer[cbSize++] = (nAddr >> 24) & 0xFF;
	Buffer[cbSize++] = (nAddr >> 16) & 0xFF;
	Buffer[cbSize++] = (nAddr >>  8) & 0xFF;
	Buffer[cbSize++] = (nAddr      ) & 0xFF;

	doMakeSpiSend(COMMAND_SECTOR_ERASE, Buffer, cbSize);
}

static void doSendDownStart(unsigned int nAddr, int cbData)
{
	int cbSize = 0;
	unsigned char Buffer[8];

	Buffer[cbSize++] = (nAddr >> 24) & 0xFF;
	Buffer[cbSize++] = (nAddr >> 16) & 0xFF;
	Buffer[cbSize++] = (nAddr >>  8) & 0xFF;
	Buffer[cbSize++] = (nAddr      ) & 0xFF;
	Buffer[cbSize++] = (cbData >> 24) & 0xFF;
	Buffer[cbSize++] = (cbData >> 16) & 0xFF;
	Buffer[cbSize++] = (cbData >>  8) & 0xFF;
	Buffer[cbSize++] = (cbData      ) & 0xFF;

	doMakeSpiSend(COMMAND_DOWNLOAD, Buffer, cbSize);
}

static void doSendDownCrc32Start(unsigned int nAddr, int cbData)
{
	int cbSize = 0;
	unsigned char Buffer[12];

	Buffer[cbSize++] = (nAddr >> 24) & 0xFF;
	Buffer[cbSize++] = (nAddr >> 16) & 0xFF;
	Buffer[cbSize++] = (nAddr >>  8) & 0xFF;
	Buffer[cbSize++] = (nAddr      ) & 0xFF;
	Buffer[cbSize++] = (cbData >> 24) & 0xFF;
	Buffer[cbSize++] = (cbData >> 16) & 0xFF;
	Buffer[cbSize++] = (cbData >>  8) & 0xFF;
	Buffer[cbSize++] = (cbData      ) & 0xFF;
	Buffer[cbSize++] = (m_nCrc32 >> 24) & 0xFF;
	Buffer[cbSize++] = (m_nCrc32 >> 16) & 0xFF;
	Buffer[cbSize++] = (m_nCrc32 >>  8) & 0xFF;
	Buffer[cbSize++] = (m_nCrc32      ) & 0xFF;

	doMakeSpiSend(COMMAND_DOWNLOAD_CRC, Buffer, cbSize);
}

static void doSendData(unsigned int nAddr)
{
	int cbSize;
	unsigned char Buffer[SPI_BUFFER_SIZE];

	cbSize = ((m_nFileSize - nAddr) > DOWNLOAD_SIZE) ? DOWNLOAD_SIZE : (m_nFileSize - nAddr);

#ifdef HEADER_BLE_FLASH_WRITE
	simpleCopy(Buffer, (unsigned char *)(m_codeBle + nAddr + 0x10), cbSize);
#else

#endif
	doMakeSpiSend(COMMAND_SEND_DATA, Buffer, cbSize);
}

static void doSendCrc32(unsigned int nAddr, int cbData, unsigned int nRepeat)
{
	int cbSize = 0;
	unsigned char Buffer[12];

	Buffer[cbSize++] = (nAddr >> 24) & 0xFF;
	Buffer[cbSize++] = (nAddr >> 16) & 0xFF;
	Buffer[cbSize++] = (nAddr >>  8) & 0xFF;
	Buffer[cbSize++] = (nAddr      ) & 0xFF;
	Buffer[cbSize++] = (cbData >> 24) & 0xFF;
	Buffer[cbSize++] = (cbData >> 16) & 0xFF;
	Buffer[cbSize++] = (cbData >>  8) & 0xFF;
	Buffer[cbSize++] = (cbData      ) & 0xFF;
	Buffer[cbSize++] = (nRepeat >> 24) & 0xFF;
	Buffer[cbSize++] = (nRepeat >> 16) & 0xFF;
	Buffer[cbSize++] = (nRepeat >>  8) & 0xFF;
	Buffer[cbSize++] = (nRepeat      ) & 0xFF;

	doMakeSpiSend(COMMAND_CRC32, Buffer, cbSize);
}

static void doSendReset(void)
{
	doMakeSpiSend(COMMAND_RESET, NULL, 0);
}
