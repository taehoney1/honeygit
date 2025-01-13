#include <stdint.h>

#include "sdk_project_config.h"

#include "defineble.h"
#include "definecanoe.h"

#include "defines.h"

#include "commuwb.h"
#include "commcanoe.h"
#include "commble.h"
#include "commpc.h"

#ifdef HEADER_UWB_FLASH_WRITE
#include "code_uwb.h"
#endif


//----------------------------------------------
//	Definitions
//----------------------------------------------
#define CS_HIGH					(PINS_DRV_WritePin(PTB, 5, 1))
#define CS_LOW					(PINS_DRV_WritePin(PTB, 5, 0))

#define RESET_ACTIVE			(PINS_DRV_WritePin(PTC, 5, 0))
#define RESET_RELEASE			(PINS_DRV_WritePin(PTC, 5, 1))

#define P10_HIGH				(PINS_DRV_WritePin(PTB, 0, 1))
#define P10_LOW					(PINS_DRV_WritePin(PTB, 0, 0))

#define P13_HIGH				(PINS_DRV_WritePin(PTB, 1, 1))
#define P13_LOW					(PINS_DRV_WritePin(PTB, 1, 0))

#define READ_UCI_READY			(PINS_DRV_ReadPins(PTE) & (1 << 0))
#define READ_UCI_INT			(PINS_DRV_ReadPins(PTE) & (1 << 9))

#define RESPONSE_OFFSET			4

#define CONV_1ST_PATH_POWER(x)	(unsigned char)((x * 3) >> 9)	//	x * log(2) * 10 / 0x200

enum
{
    eINFO_DEVICE = 0x00u,            			//	UWB IC Information version

    ePRE_RESP0 = 0x11U,              			//	ranging get sequence
    ePRE_RESP1 = 0x12U,							//	ranging get sequence
    ePRE_RESP2 = 0x13U,							//	ranging get sequence
    eRESP_DELTA_TIME = 0x14U,					//	Responder delta time-stamps
    eINIT_DELTA_TIME = 0x15U,					//	Initiator delta time-stamps

    eONE_TIME_RANGING1 = 0x21U,
    eONE_TIME_RANGING2 = 0x22U,
    eONE_TIME_RANGING3 = 0x23U,
    eONE_TIME_RANGING4 = 0x24U,
    eONE_TIME_RANGING5 = 0x25U,
    eONE_TIME_RANGING6 = 0x26U,
    eONE_TIME_RANGING7 = 0x27U,

    eRX_MODE_CFG = 0x31u,
    eRX_MODE_CMD = 0x32u,

    eSET_CONFIG_CMD = 0x41u,

	eRESET_CMD = 0x51u,

	eACTIVATE_SWUP = 0x61u,
    eSWUP_SEND_MANIFEST = 0x62u,
    eSWUP_START_UPDATE = 0x63u,
    eSWUP_FLASH = 0x64u,
    eSWUP_VERIFY = 0x65u,
    eSWUP_FINISH = 0x66u,
    eSWUP_SEND_MESSAGE = 0x6Au,

    eSWUP_RCI_GET_DEVICE_INFO = 0x67u,
    eSWUP_RCI_TRANSFER_MANIFEST = 0x68u,
    eSWUP_RCI_START_UPDATE = 0x69u,
    eSWUP_RCI_TRANSFER_COMPONENT = 0x6Au,
    eSWUP_RCI_VERIFY_ALL = 0x6Bu,
    eSWUP_RCI_VERIFY_FINISH_UPDATE = 0x69u,

    eNO_CMD = 0xFF
};

//	UCI
#define UCI_BUFFER_SIZE			0x90

enum
{
	eSTEP_UCI_IDLE = 0,
	eSTEP_UCI_CHECKREADY,
	eSTEP_UCI_SENDSTART,
	eSTEP_UCI_SENDING,
	eSTEP_UCI_SENDDONE,
	eSTEP_UCI_RECVSTART,
	eSTEP_UCI_RECEIVING,
	eSTEP_UCI_RECVDONE,
};

enum
{
	eSTEP_FLOW_IDLE = 0,
	eSTEP_FLOW_RESET_RELEASE,

	eSTEP_FLOW_INIT_BUILD,
	eSTEP_FLOW_INIT_WAIT,

	eSTEP_FLOW_START_BUILD,
	eSTEP_FLOW_START_WAIT,
	eSTEP_FLOW_STOP_BUILD,
	eSTEP_FLOW_STOP_WAIT,

	eSTEP_FLOW_REPROGRAM_BUILD,
	eSTEP_FLOW_REPROGRAM_WAIT,
};

enum
{
	eTYPE_TRANSMIT_NONE = 0,
	eTYPE_TRANSMIT_REQUEST,
	eTYPE_TRANSMIT_RESPONSE_1,
	eTYPE_TRANSMIT_RESPONSE_2,
};

typedef struct
{
	unsigned int nSendname;
	unsigned int nSendlength;
} structUciTable;


#define INIT_COUNTER_MAX		6

const uint8_t CIR_LOG[] = {0x20,0x04,0x00,0x0A,0x02,0xF4,0x01,0x01,0xF6,0x04,0xFF,0xFF,0x07,0x00};
const uint8_t SESSION_INIT_CMD[] = {0x21,0x00,0x00,0x05,0xCA,0xFE,0xFA,0xCE,0xA0};

const uint8_t SESSION_SET_APP_CONFIG_CMD1[] = {0x21,0x03,0x00,0x25,
	0xCA,0xFE,0xFA,0xCE,
	0x09, 										//	number of parameters
	0x04,0x01,0x09, 							//	channel number korea = 9
	0x05,0x01,0x04, 							//	number of controller 1??
	0x06,0x02,0x00,0x00,						//	device type
	0x08,0x02,0x60,0x09,						//	slot duration 2400rtsu = 2000us)
	0x09,0x04,0xE0,0x01,0x00,0x00,				//	ranging interval D8:216ms 60:96ms 01E0:480ms
	0x11,0x01,0x00,								//	role 00:responder 01:initial
	0xF2,0x01,0x3C,								//	transmit power
	0x1B,0x01,0x0C,								//	slot per round
	0x2C,0x01,0x03								//	hopping mode 00?
};
const uint8_t SESSION_SET_APP_CONFIG_CMD2[] = {0x21,0x03,0x00,0x08,0xCA,0xFE,0xFA,0xCE,0x01,0x1E,0x01,0x00};
const uint8_t SESSION_SET_APP_CONFIG_CMD_CIR[] = {0x21,0x03,0x00,0x0D,0xCA,0xFE,0xFA,0xCE,0x02,0xF7,0x02,0x00,0x00,0xF8,0x02,0x00,0x04};

const uint8_t RANGE_START_CMD[] = {0x22, 0x00, 0x00, 0x04, 0xCA, 0xFE, 0xFA, 0xCE};
const uint8_t RANGE_STOP_CMD[]  = {0x22, 0x01, 0x00, 0x04, 0xCA, 0xFE, 0xFA, 0xCE};

static structUciTable m_InitTable[INIT_COUNTER_MAX] = {
	{(unsigned int)CIR_LOG, 						sizeof(CIR_LOG)},
	{(unsigned int)SESSION_INIT_CMD, 				sizeof(SESSION_INIT_CMD)},
	{(unsigned int)SESSION_SET_APP_CONFIG_CMD1,  	sizeof(SESSION_SET_APP_CONFIG_CMD1)},
	{(unsigned int)SESSION_SET_APP_CONFIG_CMD2,		sizeof(SESSION_SET_APP_CONFIG_CMD2)},
	{(unsigned int)SESSION_SET_APP_CONFIG_CMD_CIR,	sizeof(SESSION_SET_APP_CONFIG_CMD_CIR)},
	{(unsigned int)RANGE_START_CMD,					sizeof(RANGE_START_CMD)}
};

//	SWUP
#define REPROGRAM_COUNTER_MAX	8
#define SWUP_FRAME_SIZE			(7 + 128 + 9)

const unsigned char m_SwupUciReset[] = {0x20, 0x00, 0x00, 0x01, 0x00};				//	STEP 1 : RESET CMD
const unsigned char m_SwupUciActivate[] = {0x2E, 0x3F, 0x00, 0x01, 0x01};				//	STEP 2 : ACTIVATE SWUP
const unsigned char m_SwupUciMessage[] = {0x2F, 0x20, 0x00, 0x00};						//		 ? : send message
const unsigned char m_SwupManifestFrames[] = {0x2F, 0x07, 0x00, 0x81, 0x00};			//		 2 : SWUP_SEND_MANIFEST
const unsigned char m_SwupStartUpdate[] = {0x2F, 0x0A, 0x00, 0x00};						//	     3 : SWUP_START_UPDATE
const unsigned char m_SwupFlashFramse[] = {0x2F, 0x10, 0x00, 0x83, 0x00, 0x00, 0x00};	//	     4 : SWUP_FLASH
const unsigned char m_SwupVerify[] = {0x2F, 0x12, 0x00, 0x00};							//	     5 : SWUP_VERIFY
const unsigned char m_SwupFinish[] = {0x2F, 0x1A, 0x00, 0x00};							//		 6 : SWUP_FINSH

static structUciTable m_ReprogramTable[REPROGRAM_COUNTER_MAX] = {
	{(unsigned int)m_SwupUciReset,			sizeof(m_SwupUciReset)},				//2024-05-16 jeontaeheon
	{(unsigned int)m_SwupUciActivate,		sizeof(m_SwupUciActivate)},
	{(unsigned int)m_SwupUciMessage,		sizeof(m_SwupUciMessage)},
	{(unsigned int)m_SwupManifestFrames,	sizeof(m_SwupManifestFrames)},
	{(unsigned int)m_SwupStartUpdate,		sizeof(m_SwupStartUpdate)},
	{(unsigned int)m_SwupFlashFramse,		sizeof(m_SwupFlashFramse)},
	{(unsigned int)m_SwupVerify,			sizeof(m_SwupVerify)},
	{(unsigned int)m_SwupFinish,			sizeof(m_SwupFinish)}
};


//----------------------------------------------
//	Variables
//----------------------------------------------
static int m_nUciStep = eSTEP_UCI_IDLE;
static int m_nFlowStep = eSTEP_FLOW_IDLE;
static int m_nFlowNext = eSTEP_FLOW_IDLE;
static int m_nTransmitType = eTYPE_TRANSMIT_NONE;
static int m_nNumberReadsize = 0;
static int m_nNumberSendsize = 0;

static bool m_bReady = false;
static bool m_bIntOccured = false;
static bool m_bTransmitted = false;
static bool m_bInitDone = false;
static bool m_bResponseDone = false;

typedef struct
{
	unsigned char tx[UCI_BUFFER_SIZE];
	unsigned char rx[UCI_BUFFER_SIZE];
} spi_buffer_t;

//static spi_buffer_t m_masterBuffer;
static volatile status_t m_transStatus;
static volatile unsigned char m_UciSend[UCI_BUFFER_SIZE];
static volatile unsigned char m_UciRecv[UCI_BUFFER_SIZE];
static volatile unsigned char m_UciZero[UCI_BUFFER_SIZE];
static volatile unsigned char m_UciTemp[4];

static int m_nInitCounter;
static int m_nGID;
static int m_nOPID;

static int m_nSessionState = -1;
static unsigned char m_RangingResult[24];
static unsigned int m_nRangingCount;
static unsigned int m_nRangingCmdVal;
static unsigned int m_nRangingStatus;
static unsigned int m_nRangingDistance;

static int m_nReprogramCounter = 0;
static int m_nManifestCounter = 0;
static int m_nFlashCounter = 0;
static int m_nFlashMaxCounter;

static int m_nFileSize, m_nVersion, m_nCrc32;

static unsigned int m_nUciReadyTimer;
static unsigned int m_nRebootTimer;


//----------------------------------------------
//	Prototype Functions
//----------------------------------------------
static void callbackSpiMaster(void *driverState, spi_event_t event, void *userData);

static void procUci(void);
static void procFlow(void);

static void onRecvUciMessage(unsigned char *pBuffer, int cbData);


//----------------------------------------------
//	Definitions
//----------------------------------------------
void initUWB(void)
{
	//	IO
	RESET_ACTIVE;
	P10_HIGH;
	P13_HIGH;
//	CS_HIGH;

    PINS_DRV_SetPinDirection(PTE, 0U, GPIO_INPUT_DIRECTION);
    PINS_DRV_SetPinDirection(PTE, 9U, GPIO_INPUT_DIRECTION);

    simpleZero((unsigned char *)m_UciZero, UCI_BUFFER_SIZE);

    //	SPI master configuration: clock speed: 500 kHz, 8 bits/frame, LSB first
    LPSPI_DRV_MasterInit(INST_LPSPI_1, &lpspi_1State, &lpspi_0_MasterConfig0);
    lpspi_1State.callback = (spi_callback_t)callbackSpiMaster;
    //	Configure delay between transfer, delay between SCK and PCS and delay between PCS and SCK
///    LPSPI_DRV_MasterSetDelay(INST_LPSPI_1, 100, 1, 1);

    m_nFlowNext = eSTEP_FLOW_RESET_RELEASE;
    m_nRebootTimer = OSIF_GetMilliseconds() + 2;
}

void commUWB(unsigned int nEvent)
{
	if(nEvent & EVENT_UCIREADY)
	{
		m_bReady = true;
	}
	if(nEvent & EVENT_UCIINT)
	{
		m_bIntOccured = true;
	}
	if(nEvent & EVENT_UCITO)
	{
		m_bTransmitted = true;
	}
#if (BUTTON_TEST == 3)
	if(nEvent & EVENT_BTN1)
	{
		unsigned char buffer[4] = { 0x00, };
		doCan2Uwb(COMMAND_UWB_COMM, buffer, 1);
	}
	if(nEvent & EVENT_BTN2)
	{
#	if 0
		unsigned char buffer[4] = { 0x02, };
		doCan2Uwb(COMMAND_UWB_COMM, buffer, 1);
#	endif
		unsigned char buffer[4] = { 0x04, };
		doCan2Uwb(COMMAND_UWB_REPROGRAM, buffer, 1);
	}
#endif

	procUci();
	procFlow();
}


//----------------------------------------------
//	Callback
//----------------------------------------------
void callbackSpiMaster(void *driverState, spi_event_t event, void *userData)
{
	(void)driverState;
	(void)userData;

	switch(event)
	{
	case SPI_EVENT_END_TRANSFER:
		break;

	}
	setEvent(EVENT_UCITO);
}


//----------------------------------------------
//	from CAN
//----------------------------------------------
void doCan2Uwb(unsigned char nID, unsigned char *pBuffer, int cbData)
{
	unsigned int *pCodeUwb;

    switch(nID)
	{
	case COMMAND_UWB_COMM:
//	    doMakeSpiSend(nID, pBuffer, cbData);
		switch(pBuffer[0])
		{
		case 0:
//			m_nFlowNext = eSTEP_FLOW_START_BUILD;
			m_nFlowNext = eSTEP_FLOW_INIT_BUILD;
			break;
		case 1:
			break;
		case 2:
			m_nFlowNext = eSTEP_FLOW_STOP_BUILD;
			break;
		}
		break;

	case COMMAND_UWB_REPROGRAM:
#ifdef	HEADER_FLASH_WRITE
		pCodeUwb = (unsigned int *)m_codeUwb;
#else
		pCodeUwb = (unsigned int *)FLASH_ADDR_UWB_HEADER;
#endif

		m_nFileSize = pCodeUwb[0];
		m_nVersion = pCodeUwb[1];
		m_nCrc32 = pCodeUwb[2];

		m_nReprogramCounter = 0;
		m_nManifestCounter = 0;
		m_nFlashCounter = 0;
		m_nFlashMaxCounter = (m_nFileSize & 0x7F) ? ((m_nFileSize >> 7) + 1) : (m_nFileSize >> 7);
		m_nFlowNext = eSTEP_FLOW_REPROGRAM_BUILD;
		break;
	}
}


//----------------------------------------------
//	Process
//----------------------------------------------
void procUci(void)
{
	switch(m_nUciStep)
	{
	case eSTEP_UCI_IDLE:
		if(READ_UCI_INT == 0)
		{
			CS_LOW;
	    	m_nUciStep = eSTEP_UCI_RECVSTART;
		}
		else if(m_nTransmitType == eTYPE_TRANSMIT_REQUEST)
		{
			CS_LOW;
			m_nUciReadyTimer = OSIF_GetMilliseconds() + 2;
			m_nUciStep = eSTEP_UCI_CHECKREADY;
		}
		break;
	case eSTEP_UCI_CHECKREADY:
		if(READ_UCI_READY == 0)
		{
			m_nUciStep = eSTEP_UCI_SENDSTART;
		}
		else
		{
			if(OSIF_GetMilliseconds() > m_nUciReadyTimer)
			{
				m_nUciStep = eSTEP_UCI_IDLE;
//				m_nFlowStep = eSTEP_FLOW_IDLE;
			}
		}
		break;
	case eSTEP_UCI_SENDSTART:
//		m_UciSend[0] = m_UciTemp[0];	// ????

		m_nGID = m_UciSend[0] & 0x0F;
		m_nOPID = m_UciSend[1] & 0xFF;

//		m_transStatus = LPSPI_DRV_MasterTransfer(INST_LPSPI_1, (unsigned char *)m_UciSend, (unsigned char *)m_UciRecv, m_nNumberSendsize);
		m_transStatus = LPSPI_DRV_MasterTransferBlocking(INST_LPSPI_1, (unsigned char *)m_UciSend, NULL, m_nNumberSendsize, m_nNumberSendsize);
		if(m_transStatus == STATUS_SUCCESS)
		{
//			m_nUciStep = eSTEP_UCI_SENDING;
			m_nUciStep = eSTEP_UCI_SENDDONE;
		}
		else
		{
			m_nUciStep = eSTEP_UCI_IDLE;
		}
		break;
	case eSTEP_UCI_SENDING:
		if(m_bTransmitted == true)
		{
			m_bTransmitted = false;
			m_nUciStep = eSTEP_UCI_SENDDONE;
		}
		break;
	case eSTEP_UCI_SENDDONE:
		m_nTransmitType = eTYPE_TRANSMIT_NONE;
		CS_HIGH;
		m_nUciStep = eSTEP_UCI_IDLE;
		break;

	case eSTEP_UCI_RECVSTART:
		m_transStatus = LPSPI_DRV_MasterTransferBlocking(INST_LPSPI_1, (unsigned char *)m_UciZero, (unsigned char *)m_UciRecv, 1, 1);
		m_transStatus = LPSPI_DRV_MasterTransferBlocking(INST_LPSPI_1, (unsigned char *)m_UciZero, (unsigned char *)m_UciRecv, RESPONSE_OFFSET, 1);
		if(m_transStatus == STATUS_SUCCESS)
		{
			m_nNumberReadsize = m_UciRecv[3];
//	    	m_transStatus = LPSPI_DRV_MasterTransfer(INST_LPSPI_1, (unsigned char *)m_UciZero, (unsigned char *)(m_UciRecv + RESPONSE_OFFSET), m_nNumberReadsize);
	    	m_transStatus = LPSPI_DRV_MasterTransferBlocking(INST_LPSPI_1, (unsigned char *)m_UciZero, (unsigned char *)(m_UciRecv + RESPONSE_OFFSET), m_nNumberReadsize, m_nNumberReadsize);
	    	m_bTransmitted = true;
	    	if(m_transStatus == STATUS_SUCCESS)
	    	{
	    		m_nUciStep = eSTEP_UCI_RECVDONE;
	    	}
	    	else
	    	{
	    		m_nUciStep = eSTEP_UCI_IDLE;
//	    		print((const char *)"SPI ERROR \r\n");
	    	}
		}
		else
		{
			m_nUciStep = eSTEP_UCI_IDLE;
//			print((const char *)"SPI ERROR \r\n");
		}
		break;
	case eSTEP_UCI_RECEIVING:
		if(m_bTransmitted == true)
		{
			m_bTransmitted = false;
			m_nUciStep = eSTEP_UCI_RECVDONE;
		}
		break;
	case eSTEP_UCI_RECVDONE:
		CS_HIGH;
		m_nUciStep = eSTEP_UCI_IDLE;
		onRecvUciMessage((unsigned char *)m_UciRecv, m_nNumberReadsize + RESPONSE_OFFSET);
#ifdef UWB_DEBUG_SEND
		doSendCommand((unsigned char *)m_UciRecv, m_nNumberReadsize + RESPONSE_OFFSET);
#endif
		if(((m_UciRecv[0] & 0x0F) == m_nGID) && (m_UciRecv[1] == m_nOPID) && (m_bResponseDone == false))
		{
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
		if(m_nFlowNext != eSTEP_FLOW_IDLE)
		{
			m_nFlowStep = m_nFlowNext;
			m_nFlowNext = eSTEP_FLOW_IDLE;
		}
		break;

	case eSTEP_FLOW_RESET_RELEASE:
		if(OSIF_GetMilliseconds() > m_nRebootTimer)
		{
			RESET_RELEASE;

			m_nFlowStep = eSTEP_FLOW_INIT_BUILD;
			m_nInitCounter = 0;
		}
		break;

	//	INITIAL
	case eSTEP_FLOW_INIT_BUILD:
		m_nNumberSendsize = m_InitTable[m_nInitCounter].nSendlength;
		simpleCopy((unsigned char *)m_UciSend, (unsigned char *)m_InitTable[m_nInitCounter].nSendname, m_nNumberSendsize);
//		m_UciTemp[0] = m_UciSend[0];			// ???
		m_bResponseDone = false;
		m_nFlowStep = eSTEP_FLOW_INIT_WAIT;
		m_nTransmitType = eTYPE_TRANSMIT_REQUEST;
		break;
	case eSTEP_FLOW_INIT_WAIT:
		if(m_bResponseDone == true)
		{
			if(++m_nInitCounter < INIT_COUNTER_MAX)
			{
				m_nFlowStep = eSTEP_FLOW_INIT_BUILD;
			}
			else
			{
				m_bInitDone = true;
				m_nInitCounter = 0;
				m_nFlowStep = eSTEP_FLOW_IDLE;
			}
		}
		break;

	//	START / STOP
	case eSTEP_FLOW_START_BUILD:
		m_nNumberSendsize = sizeof(RANGE_START_CMD);
		simpleCopy((unsigned char *)m_UciSend, (unsigned char *)RANGE_START_CMD, m_nNumberSendsize);
		m_UciTemp[0] = m_UciSend[0];			// ???
		m_bResponseDone = false;
		m_nFlowStep = eSTEP_FLOW_START_WAIT;
		m_nTransmitType = eTYPE_TRANSMIT_REQUEST;
		break;
	case eSTEP_FLOW_START_WAIT:
		if(m_bResponseDone == true)
		{
			m_nFlowStep = eSTEP_FLOW_IDLE;
		}
		break;

	case eSTEP_FLOW_STOP_BUILD:
		m_nNumberSendsize = sizeof(RANGE_STOP_CMD);
		simpleCopy((unsigned char *)m_UciSend, (unsigned char *)RANGE_STOP_CMD, m_nNumberSendsize);
		m_UciTemp[0] = m_UciSend[0];			// ???
		m_bResponseDone = false;
		m_nFlowStep = eSTEP_FLOW_STOP_WAIT;
		m_nTransmitType = eTYPE_TRANSMIT_REQUEST;
		break;
	case eSTEP_FLOW_STOP_WAIT:
		if(m_bResponseDone == true)
		{
			m_nFlowStep = eSTEP_FLOW_IDLE;
		}
		break;

	//	REPROGRAM
	case eSTEP_FLOW_REPROGRAM_BUILD:
		m_nNumberSendsize = m_ReprogramTable[m_nReprogramCounter].nSendlength;
		simpleCopy((unsigned char *)m_UciSend, (unsigned char *)m_ReprogramTable[m_nReprogramCounter].nSendname, m_nNumberSendsize);
		m_UciTemp[0] = m_UciSend[0];			//	???
#ifdef HEADER_UWB_FLASH_WRITE
#else
		volatile unsigned char *pAddress = (volatile unsigned char *)(FLASH_ADDR_UWB_PROGRAM);
#endif

		switch(m_nReprogramCounter)
		{
		case 0:	// step 1 reset
			P10_LOW;
			P13_LOW;
			m_nRebootTimer = OSIF_GetMilliseconds() + 1000;		//	1 second delay
			break;
		case 1: // step 2 Activate
			P10_HIGH;
			P13_HIGH;
			break;
		case 3:	// step 3 manifest
			m_UciSend[4] = (unsigned char)m_nManifestCounter;
#ifdef HEADER_UWB_FLASH_WRITE
			simpleCopy((unsigned char *)m_UciSend + 5, (unsigned char *)m_codeUwb + (m_nManifestCounter * 0x80 + 0x10), 0x80);
#else
		    simpleCopy((unsigned char *)m_UciSend + 5, (unsigned char *)pAddress + (m_nManifestCounter * 0x80), 0x80);
#endif
			m_nNumberSendsize += 0x80;
			break;

		case 5: //step 5 SWUP_FLASH
			m_UciSend[4] = 0;
			m_UciSend[5] = (unsigned char)(m_nFlashCounter     ) & 0xFF;
			m_UciSend[6] = (unsigned char)(m_nFlashCounter >> 8) & 0xFF;
#ifdef HEADER_UWB_FLASH_WRITE
			simpleCopy((unsigned char *)m_UciSend + 7, (unsigned char *)m_codeUwb + (m_nFlashCounter * 0x80 + 0x210), 0x80);
#else
			simpleCopy((unsigned char *)m_UciSend + 7, (unsigned char *)pAddress + (m_nFlashCounter * 0x80 + 0x200), 0x80);
#endif
			m_nNumberSendsize += 0x80;

			m_nRebootTimer = OSIF_GetMilliseconds() + 50;
			break;

		}
		m_bResponseDone = false;
		m_nFlowStep = eSTEP_FLOW_REPROGRAM_WAIT;
		m_nTransmitType = eTYPE_TRANSMIT_REQUEST;
		break;

	case eSTEP_FLOW_REPROGRAM_WAIT:
		if(m_bResponseDone == true)
		{
			switch(m_nReprogramCounter)
			{
			case 0:
				if(m_nRebootTimer < OSIF_GetMilliseconds())
				{
					m_nReprogramCounter++;
					m_nFlowStep = eSTEP_FLOW_REPROGRAM_BUILD;
				}
				break;
			case 3:
				if(++m_nManifestCounter >= 4)
				{
					m_nReprogramCounter++;
				}
				m_nFlowStep = eSTEP_FLOW_REPROGRAM_BUILD;
				break;
			case 5:
				if(m_nRebootTimer < OSIF_GetMilliseconds())
				{
					if(++m_nFlashCounter >= m_nFlashMaxCounter)
					{
						m_nReprogramCounter++;
					}
					m_nFlowStep = eSTEP_FLOW_REPROGRAM_BUILD;
				}
				break;
			default:
				if(++m_nReprogramCounter < REPROGRAM_COUNTER_MAX)
				{
					m_nFlowStep = eSTEP_FLOW_REPROGRAM_BUILD;
				}
				else
				{
					m_bInitDone = true;
					m_nInitCounter = 0;
					m_nFlowStep = eSTEP_FLOW_IDLE;
				}
				break;
			}
		}
		break;
	}
}


//----------------------------------------------
static void onRecvUciMessage(unsigned char *pBuffer, int cbData)
{
	switch(pBuffer[0])
	{
	case 0x61:
		if(pBuffer[1] == 0x02 && pBuffer[3] == 0x06)
		{
			switch(pBuffer[RESPONSE_OFFSET + 4])
			{
			case 0x01:							//	de-initial
			case 0x00:							//	initial
			case 0x03:							//	idle
				m_nSessionState = pBuffer[RESPONSE_OFFSET + 4];
			default:
				m_nSessionState = -1;
				break;
			}
		}
		break;
	case 0x6E:
		if(pBuffer[RESPONSE_OFFSET + 0] == 0x08)
		{
			//	block index
			if(pBuffer[RESPONSE_OFFSET + 11] == 0x04 && pBuffer[RESPONSE_OFFSET + 12] == 0x02)
			{
				m_RangingResult[1] = pBuffer[RESPONSE_OFFSET + 14];
				m_RangingResult[2] = pBuffer[RESPONSE_OFFSET + 13];
			}
			//	receive 1st path info
			if(pBuffer[RESPONSE_OFFSET + 35] == 0x08 && pBuffer[RESPONSE_OFFSET + 36] == 0x28)
			{
				m_RangingResult[7] = CONV_1ST_PATH_POWER((pBuffer[RESPONSE_OFFSET + 56] << 8) | (pBuffer[RESPONSE_OFFSET + 55]));
				m_RangingResult[6] = CONV_1ST_PATH_POWER((pBuffer[RESPONSE_OFFSET + 60] << 8) | (pBuffer[RESPONSE_OFFSET + 59]));
			}
		}
		break;
	case 0x62:
		m_nRangingDistance = (unsigned int)(unsigned short *)(pBuffer + RESPONSE_OFFSET + 11);
		if(pBuffer[RESPONSE_OFFSET + 0] == 0x01)
		{
			if(pBuffer[RESPONSE_OFFSET + 4] != 0)
			{
				//	fail increment
			}
			else
			{
				//	fail clear
			}

			//	fail counter is 1040

			//	if no error
			m_RangingResult[0] = 0x01;			//	DK_ID
			m_RangingResult[3] = (unsigned char)(++m_nRangingCount);
			m_RangingResult[4] = m_nRangingDistance / 100;		//	meter
			m_RangingResult[5] = m_nRangingDistance % 100;		//	centi-meter

			m_RangingResult[8] = 0x01;			//	DK_ID
			m_RangingResult[9] = 0x00;			//	Session ID mismatched - 0:No mismatched, 1:Mismatched
			m_RangingResult[10]= 0x00;			//	MAX RR Count Expiration - 0:No Expire, 1:MAX RR Count Expired
			m_RangingResult[11]= 0x00;			//	CIR Data

			simpleZero(m_RangingResult + 12, 12);

			//	to CAN 24 BYTE
			doUwb2Can(1, m_RangingResult, sizeof(m_RangingResult));
		}
		break;
	case 0x60:
		//	ready
		if(pBuffer[1] == 0x01)
		{
			switch(pBuffer[RESPONSE_OFFSET + 0])
			{
			case 0x01:
				//	ranging stop
				if(m_nRangingCmdVal == 0x02 || m_nRangingCmdVal == 0x01)
				{
					m_nRangingStatus = 0x01;
					//	setRangingStatus
				}
				else if(m_nRangingCmdVal == 0x00)
				{
					//	fail
				}
			}
			case 0x00:
				break;
			case 0x02:
				m_nRangingStatus = 0x04;
				//	setRangingStatus
				break;
		}
		break;
	}
}
