#include <string.h>

#include "sdk_project_config.h"
#include "interrupt_manager.h"

#include "defines.h"
#include "util.h"

#include "commpc.h"


//----------------------------------------------
//	Definitions
//----------------------------------------------
#define UART_BUFFER_SIZE		0x100
#define UART_PACKET_MAX			0x40


enum
{
	eSTEP_DOWN_IDLE = 0,
};

enum
{
	eSTEP_FLASH_IDLE = 0,
};

typedef struct {
	unsigned int nHeaderAddr;
	unsigned int nProgramAddr;
	unsigned int nFilesize;
	unsigned int nVersion;
	unsigned int nCrc32;
} flash_header_t;

//----------------------------------------------
//	Variables
//----------------------------------------------
static int m_nBlockHandle = -1;

static flash_ssd_config_t flashSSDConfig;

static flash_header_t m_info[eSPI_LINK_MAX] = {
	{ FLASH_ADDR_BLE_HEADER, FLASH_ADDR_BLE_PROGRAM, 0, 0, 0 },
	{ FLASH_ADDR_UWB_HEADER, FLASH_ADDR_UWB_PROGRAM, 0, 0, 0 },
};

static bool m_bReceived = false;
static bool m_bTransmitted = true;


static int m_nRecvLen;
static int m_nRecvSize;

static unsigned char m_RecvBuffer[UART_BUFFER_SIZE];
static unsigned char m_ProcBuffer[UART_BUFFER_SIZE];
static unsigned char m_SendBuffer[UART_BUFFER_SIZE];

static unsigned char m_BleHdr[FLASH_SIZE_BLE_HEADER];
static unsigned char m_UwbHdr[FLASH_SIZE_UWB_HEADER];


//----------------------------------------------
//	Predefined Functions
//----------------------------------------------
static void callbackTFTC(void);
static void callbackReceive(void *driverState, uart_event_t event, void *userData);
static void callbackTransmit(void *driverState, uart_event_t event, void *userData);

static void procUart(void);

static void procFlash_write(volatile unsigned char *pBuffer, int cbData);
static void procFlash_erase(volatile unsigned char *pBuffer, int cbData);

static void onRecvData(volatile unsigned char *pBuffer, int cbData);
static int onStripPacket(unsigned char *pDes, unsigned char *pSrc, int cbData);

static void onSetHdr(unsigned char nID, volatile unsigned char *pBuffer, int cbData);
static void onSetFile(unsigned char nID, volatile unsigned char *pBuffer, int cbData);
static void onReqCrc32(unsigned char nID, unsigned char *pBuffer, int cbData);

static void doSendData(unsigned char nID, unsigned char *pBuffer, int cbData);
static int doBuildPacket(unsigned char *pDest, unsigned char *pSrc, int cbData);
static int doSerialPush(unsigned char *pBuffer, int cbData);
static int doSerialSend(void);

static void my_flash_Erase(volatile uint32_t paddr,int psize);
static void my_flash_write(volatile uint32_t paddr, volatile unsigned char *pBuffer, int cbData);

static void my_crc32_check(void);


//----------------------------------------------
//	Functions
//----------------------------------------------
void initPC(void)
{
	status_t ret;

	m_nBlockHandle = blockOpen();

	//	initialize FLASH
	MSCM->OCMDR[0] |= MSCM_OCMDR_OCM1(0x03);
	MSCM->OCMDR[1] |= MSCM_OCMDR_OCM1(0x03);

	INT_SYS_InstallHandler(FTFC_IRQn, callbackTFTC, (isr_t *)0);
	INT_SYS_EnableIRQ(FTFC_IRQn);

	ret = FLASH_DRV_Init(&Flash_InitConfig0, &flashSSDConfig);
	DEV_ASSERT(STATUS_SUCCESS == ret);

    //	initialize UART
    LPUART_DRV_Init(INST_LPUART_LPUART_1, &lpUartState1, &lpUartInitConfig1);
    LPUART_DRV_InstallRxCallback(INST_LPUART_LPUART_1, callbackReceive, NULL);
    LPUART_DRV_InstallTxCallback(INST_LPUART_LPUART_1, callbackTransmit, NULL);

    doSendData(COMMAND_DEBUG, (unsigned char *)"Hello UWB_BLE_S32K144", strlen("Hello UWB_BLE_S32K144"));

    //	UART Start
	LPUART_DRV_ReceiveData(INST_LPUART_LPUART_1, m_RecvBuffer, 1U);
}

void commPC(unsigned int nEvent)
{
	if(nEvent & EVENT_RXUART1)
	{
		m_bReceived = true;
	}
	if(nEvent & EVENT_TXUART1)
	{
		m_bTransmitted = true;
	}

	procUart();
	//procFlash();
}


//----------------------------------------------
//	Callback
//----------------------------------------------
START_FUNCTION_DEFINITION_RAMSECTION
void callbackCCIF(void)
{
	if ((FTFx_FCNFG & FTFx_FCNFG_CCIE_MASK) == 0u)
    {
        FTFx_FCNFG |= FTFx_FCNFG_CCIE_MASK;
    }
}
END_FUNCTION_DEFINITION_RAMSECTION

static void callbackTFTC(void)
{
	FTFx_FCNFG &= (~FTFx_FCNFG_CCIE_MASK);
}

static void callbackReceive(void *driverState, uart_event_t event, void *userData)
{
	//	unused parameters
	(void)driverState;
	(void)userData;

	switch(event)
	{
	case UART_EVENT_RX_FULL:
		if(m_nRecvLen != (UART_BUFFER_SIZE - 2))
		{
			if(m_RecvBuffer[m_nRecvLen] == COMM_EOF && m_nRecvLen > 5)
			{
				m_nRecvLen++;
			}
			else
			{
				LPUART_DRV_SetRxBuffer(INST_LPUART_LPUART_1, &m_RecvBuffer[++m_nRecvLen], 1U);
			}
		}
		break;
	case UART_EVENT_END_TRANSFER:
		setEvent(EVENT_RXUART1);
		break;
	case UART_EVENT_TX_EMPTY:
	case UART_EVENT_ERROR:
		break;
	}
}

static void callbackTransmit(void *driverState, uart_event_t event, void *userData)
{
	//	unused parameters
	(void)driverState;
	(void)userData;

	switch(event)
	{
	case UART_EVENT_END_TRANSFER:
		setEvent(EVENT_TXUART1);
		break;
	default:
		break;
	}
}


//----------------------------------------------
//	from
//----------------------------------------------



//----------------------------------------------
//	to
//----------------------------------------------


//----------------------------------------------
//	Process
//----------------------------------------------
void procUart(void)
{
    if(m_bReceived == true)
    {

    	int i;
    	int nSize;
    	unsigned char Buffer[0x90];

    	for(i = 0; i < m_nRecvLen; i++)
    	{
    		if(m_RecvBuffer[i] == COMM_EOF)
    		{
    			if(m_nRecvSize >= 5)
    			{
    				nSize = onStripPacket(Buffer, m_ProcBuffer, m_nRecvSize);
    				if(nSize >= 5)
    				{
    					onRecvData(Buffer, nSize - 1);
    				}
    				else // check sum err
    				{
    					doSendData(COMM_NAK, NULL, 0);
    				}
    			}
    			m_nRecvSize = 0;
    			continue;
    		}

    		m_ProcBuffer[m_nRecvSize++] = m_RecvBuffer[i];
    	}

    	m_nRecvLen = 0;
    	m_nRecvSize = 0;

    	m_bReceived = false;
    	LPUART_DRV_ReceiveData(INST_LPUART_LPUART_1, m_RecvBuffer, 1U);
    }

	if(m_bTransmitted == true)
	{
		if(blockGetCount(m_nBlockHandle))
		{
			doSerialSend();
		}
	}
}


//----------------------------------------------
//	Receive
//----------------------------------------------
static int onStripPacket(unsigned char *pDest, unsigned char *pSrc, int cbData)
{
    int i;
    int nSize;
    unsigned char nSum = 0;

    for (i = 0, nSize = 0; i < cbData; i++, nSize++)
    {
        if (pSrc[i] == COMM_IDF)
        {
            i++;
            pDest[nSize] = pSrc[i] | 0x20;
        }
        else
        {
            pDest[nSize] = pSrc[i];
        }

        nSum += pDest[nSize];
    }

    // Parity Error
    if (nSum != 0)
    {
        return 0;
    }

    return nSize;
}

static void onRecvData(volatile unsigned char *pBuffer, int cbData)
{
    switch (pBuffer[0])
    {
    case COMM_NAK:
    	break;

    case COMMAND_BLE_SET_HDR:
    case COMMAND_UWB_SET_HDR:
    	onSetHdr(pBuffer[0], pBuffer + 2, pBuffer[1]);
    	break;

    case COMMAND_BLE_SET_FILE:
    case COMMAND_UWB_SET_FILE:
    	onSetFile(pBuffer[0], pBuffer + 2, pBuffer[1]);
    	break;

    case COMMAND_BLE_REQ_CRC32:
    case COMMAND_UWB_REQ_CRC32:
    	onReqCrc32(pBuffer[0], NULL, 0);
    	break;

    case COMMAND_MCU_FLASH_ERASE:				//2024.05.09 Taeheon
    	procFlash_erase(pBuffer, cbData);
    	break;
    case COMMAND_MCU_FLASH_WRITE:				//2024.05.09 Taeheon
    	procFlash_write(pBuffer, cbData);
    	break;
    case COMMAND_CRC_CHECK:						//2024.05.09 Taeheon
    	my_crc32_check();
		break;
    default:
    	break;
    }
}

static void onSetHdr(unsigned char nID, volatile unsigned char *pBuffer, int cbData)
{
	unsigned int nSpiLink;
	unsigned int nErasesize;
	unsigned int *pUint = (unsigned int *)pBuffer;
	unsigned char UartBuffer[0x04];

	switch(nID)
	{
	case COMMAND_BLE_SET_HDR:
		nSpiLink = eSPI_LINK_BLE;
		simpleCopy(m_BleHdr, (unsigned char *)pBuffer, FLASH_SIZE_BLE_HEADER);
		break;
	case COMMAND_UWB_SET_HDR:
		nSpiLink = eSPI_LINK_UWB;
		simpleCopy(m_UwbHdr, (unsigned char *)pBuffer, FLASH_SIZE_UWB_HEADER);
		break;
	default:
		return;
	}

	m_info[nSpiLink].nFilesize = pUint[0];
	m_info[nSpiLink].nVersion = pUint[1];
	m_info[nSpiLink].nCrc32 = pUint[2];
	nErasesize = (((m_info[nSpiLink].nFilesize + FLASH_SIZE_BLE_HEADER) / FEATURE_FLS_PF_BLOCK_SECTOR_SIZE) + 1) * FEATURE_FLS_PF_BLOCK_SECTOR_SIZE;

	//	Erase coding
	flashSSDConfig.CallBack = (flash_callback_t)callbackCCIF;
	if(FLASH_DRV_EraseSector(&flashSSDConfig, m_info[nSpiLink].nHeaderAddr, nErasesize) != STATUS_SUCCESS)
	{
		UartBuffer[0] = RESPONSE_ERROR_ERASE;
	}
	else
	{
		flashSSDConfig.CallBack = NULL_CALLBACK;

		//	Blank check
		if(FLASH_DRV_VerifySection(&flashSSDConfig, m_info[nSpiLink].nHeaderAddr, nErasesize / FTFx_DPHRASE_SIZE, 1) != STATUS_SUCCESS)
		{
			UartBuffer[0] = RESPONSE_ERROR_BLANK;
		}
		else
		{
			//	Write coding
			if(FLASH_DRV_Program(&flashSSDConfig, m_info[nSpiLink].nHeaderAddr, cbData, (unsigned char *)pBuffer) != STATUS_SUCCESS)
			{
				UartBuffer[0] = RESPONSE_ERROR_PROGRAM;
			}
			else
			{
				UartBuffer[0] = RESPONSE_SUCCESS;
			}
		}
	}

	doSendData(nID + 1, UartBuffer, 1);
}

static void onSetFile(unsigned char nID, volatile unsigned char *pBuffer, int cbData)
{
	unsigned int nSpiLink;
	unsigned int nAddress;
	unsigned int nProgramsize;
	unsigned int *pUint = (unsigned int *)pBuffer;
	unsigned char UartBuffer[0x08];

	switch(nID)
	{
	case COMMAND_BLE_SET_FILE:
		nSpiLink = eSPI_LINK_BLE;
		break;
	case COMMAND_UWB_SET_FILE:
		nSpiLink = eSPI_LINK_UWB;
		break;
	default:
		return;
	}

	nAddress = m_info[nSpiLink].nProgramAddr + pUint[0];
	nProgramsize = ((pUint[1] / FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE) + 1) * FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE;
	//	Write coding
	if(FLASH_DRV_Program(&flashSSDConfig, nAddress, nProgramsize, (unsigned char *)(pBuffer + 8)) != STATUS_SUCCESS)
	{
		UartBuffer[0] = RESPONSE_ERROR_PROGRAM;
		doSendData(nID + 1, UartBuffer, 1);
	}
	else
	{
		UartBuffer[0] = RESPONSE_SUCCESS;
		simpleCopy(UartBuffer + 1, (unsigned char *)pBuffer, 4);
		doSendData(nID + 1, UartBuffer, 1);
	}
}

static void onReqCrc32(unsigned char nID, unsigned char *pBuffer, int cbData)
{
	unsigned int nSpiLink;
	unsigned char UartBuffer[0x04];

	switch(nID)
	{
	case COMMAND_BLE_SET_FILE:
		nSpiLink = eSPI_LINK_BLE;
		break;
	case COMMAND_UWB_SET_FILE:
		nSpiLink = eSPI_LINK_UWB;
		break;
	default:
		return;
	}

	//	CRC Calculation
	if(crc32((char const *)&m_info[nSpiLink].nProgramAddr, m_info[nSpiLink].nFilesize) != m_info[nSpiLink].nCrc32)
	{
		UartBuffer[0] = RESPONSE_ERROR_CRC32;
		doSendData(nID + 1, UartBuffer, 1);
	}
	else
	{
		UartBuffer[0] = RESPONSE_SUCCESS;
		doSendData(nID + 1, UartBuffer, 1);
	}
}

//----------------------------------------------
//	Send
//----------------------------------------------
void doSendCommand(unsigned char *pBuffer, int cbData)
{
	doSendData(COMMAND_COMMAND, pBuffer, cbData);
}

void doSendDebug(unsigned char *pBuffer, int cbData)
{
	doSendData(COMMAND_DEBUG, pBuffer, cbData);
}

static void doSendData(unsigned char nId, unsigned char *pBuffer, int cbData)
{
    int i, nSize;
    unsigned char Buffer[0x90];
    unsigned char nBcc;

    nSize = 0;
    Buffer[nSize++] = nId;
    Buffer[nSize++] = (unsigned char)cbData;

    nBcc = Buffer[0] + Buffer[1];

    for (i = 0; i < cbData; i++, nSize++)
    {
        Buffer[nSize] = pBuffer[i];
        nBcc += pBuffer[i];
    }
    Buffer[nSize++] = (~nBcc) + 1;

    nSize = doBuildPacket(m_SendBuffer, Buffer, nSize);

    doSerialPush(m_SendBuffer, nSize);
}

static int doBuildPacket(unsigned char *pDest, unsigned char *pSrc, int cbData)
{
    int i;
    int nSize;
    unsigned char nSum = 0;

    nSize = 0;
    pDest[nSize++] = COMM_EOF;

    for (i = 0; i < cbData; i++)
    {
        if (pSrc[i] == COMM_EOF || pSrc[i] == COMM_IDF)
        {
            pDest[nSize++] = COMM_IDF;
            pDest[nSize++] = pSrc[i] & (~0x20);
        }
        else
        {
            pDest[nSize++] = pSrc[i];
        }

        nSum += pSrc[i];
    }

    nSum = ((~(nSum & 0xFF)) + 1) & 0xFF;
    if (nSum == COMM_EOF || nSum == COMM_IDF)
    {
        pDest[nSize++] = COMM_IDF;
        pDest[nSize++] = nSum & (~0x20);
    }
    else
    {
        pDest[nSize++] = nSum;
    }

    pDest[nSize++] = COMM_EOF;

    return nSize;
}

static int doSerialPush(unsigned char *pBuffer, int cbData)
{
	return blockPutMessage(m_nBlockHandle, 0, pBuffer, cbData);
}

static int doSerialSend()
{
	int nCommand;
	int cbData;

	unsigned char Buffer[UART_PACKET_MAX];

	cbData = blockGetMessage(m_nBlockHandle, &nCommand, Buffer, UART_PACKET_MAX);
    if(INST_LPUART_LPUART_1 == 0)
        return 0;

    m_bTransmitted = false;

     LPUART_DRV_SendDataBlocking(INST_LPUART_LPUART_1, Buffer, cbData, (cbData >> 1));
//    LPUART_DRV_SendData(INST_LPUART_LPUART_1, Buffer, cbData);
    return cbData;
}


//----------------------------------------------
//	procFlash
//----------------------------------------------

static void procFlash_erase(volatile unsigned char *pBuffer, int cbData)
{
	//comm form  Recvcomm(1), address(4)     ~ data
    //           0x85,  0x00,0x06,0x80,0x00, ~ data
	uint32_t address, size = 0;
	//address = (pBuffer[1] << 24) | (pBuffer[2] << 16) | (pBuffer[3] << 8) | pBuffer[4]; // big endian
	//size = (pBuffer[5] << 24) | (pBuffer[6] << 16) | (pBuffer[7] << 8) | pBuffer[8]; 
	address = (pBuffer[4] << 24) | (pBuffer[3] << 16) | (pBuffer[2] << 8) | pBuffer[1];  // little endian
	size = (pBuffer[8] << 24) | (pBuffer[7] << 16) | (pBuffer[6] << 8) | pBuffer[5]; // file size
	my_flash_Erase(address, size);
}
static void procFlash_write(volatile unsigned char *pBuffer, int cbData)
{
	uint32_t address;
	//address = (pBuffer[1] << 24) | (pBuffer[2] << 16) | (pBuffer[3] << 8) | pBuffer[4]; // big endian
	address = (pBuffer[4] << 24) | (pBuffer[3] << 16) | (pBuffer[2] << 8) | pBuffer[1];

	my_flash_write(address, pBuffer, cbData - 5);
}

static void my_flash_Erase(volatile uint32_t paddr,int psize)
{
	status_t ret;
	if(psize > 4096) // 4096의 배수 만들기
	{
		psize = psize + (4096 - (psize % 4096));
	}
	else
	{
		psize = 4096;
	}

	ret = FLASH_DRV_Init(&Flash_InitConfig0, &flashSSDConfig);
	DEV_ASSERT(STATUS_SUCCESS == ret);

	INT_SYS_DisableIRQGlobal();

	ret = FLASH_DRV_EraseSector(&flashSSDConfig, paddr, psize);
	DEV_ASSERT(STATUS_SUCCESS == ret);
	flashSSDConfig.CallBack = NULL_CALLBACK;
	/* Verify the erase operation at margin level value of 1, user read */
	ret = FLASH_DRV_VerifySection(&flashSSDConfig, paddr, psize / FTFx_DPHRASE_SIZE, 1u);
	DEV_ASSERT(STATUS_SUCCESS == ret);

	INT_SYS_EnableIRQGlobal();

//	doSendData(COMMAND_DEBUG, (unsigned char *)"r \r\n", strlen("r \r\n"));
//	print((const char*)"r0\r\n");
}

static void my_flash_write(volatile uint32_t paddr, volatile unsigned char *pBuffer, int cbData)
{
	uint8_t temp_buf[256];
	status_t ret;
	uint32_t failAddr;

	for(int i=0; i< cbData; i++)
	{
		temp_buf[i] = pBuffer[i+5];
	}


	INT_SYS_DisableIRQGlobal();
	/* Write some data to the erased PFlash sector */
	ret = FLASH_DRV_Program(&flashSSDConfig, paddr, cbData, temp_buf);
	DEV_ASSERT(STATUS_SUCCESS == ret);

	/* Verify the program operation at margin level value of 1, user margin */
	ret = FLASH_DRV_ProgramCheck(&flashSSDConfig, paddr, cbData, temp_buf, &failAddr, 1u);
	DEV_ASSERT(STATUS_SUCCESS == ret);

	INT_SYS_EnableIRQGlobal();

	//doSendData(COMMAND_DEBUG, (unsigned char *)"r \r\n", strlen("r \r\n"));
//	print((const char*)"r0\r\n");
}

#if 0
void print(const char *sourceStr)
{
    uint32_t bytesRemaining;
    /* Send data via LPUART */
    LPUART_DRV_SendData(INST_LPUART_LPUART_1, (uint8_t *) sourceStr, strlen(sourceStr));
    while (LPUART_DRV_GetReceiveStatus(INST_LPUART_LPUART_1, &bytesRemaining) != STATUS_SUCCESS){};
}
#endif

static void my_crc32_check(void)
{
	volatile unsigned int *pAddress = (volatile unsigned int *)FLASH_ADDR_UWB_HEADER;
	//volatile unsigned char p_buffer[100000];
	uint32_t  crc_value, p_crc_value;
	uint32_t file_size=0;

	//file_size = (pAddress[0]<<24) | (pAddress[1]<<16) | (pAddress[2]<<8) | pAddress[3];
	//p_crc_value = (pAddress[8]<<24) | (pAddress[9]<<16) | (pAddress[10]<<8) | pAddress[11];
	file_size = pAddress[0];
	p_crc_value = pAddress[2];

//	for(int i = 0; i < file_size; i++)
	{
//		p_buffer[i] = pAddress[i+16];
	}
	pAddress = (volatile unsigned int *)(FLASH_ADDR_UWB_PROGRAM);
	crc_value = crc32((const char *)pAddress , file_size);
#if 0
	if(crc_value == p_crc_value)
	{
		print((const char*)"crc32 check success!!\r\n");
	}
	else
	{
		print((const char*)"crc32 check error!!\r\n");
	}
#else
	(void)crc_value;
	(void)p_crc_value;
#endif
}


