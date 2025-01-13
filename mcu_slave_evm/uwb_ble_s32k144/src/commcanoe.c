#include <string.h>
#include <stdbool.h>

#include "sdk_project_config.h"

#include "defineble.h"
#include "definecanoe.h"

#include "defines.h"

#include "commcanoe.h"
#include "commble.h"
#include "commuwb.h"


//----------------------------------------------
//	Definitions
//----------------------------------------------
#define TX_MAILBOX				(0x06UL)

#define CANID_RECV_KIND			0x10

#define CANID_BUFFER_SIZE		32

//	Define receive buffer
#define IAU_FD_04_200ms				0x00000351
#define IAU_FD_05_200ms        		0x00000352
#define CCU_01_00ms					0x0000043F
#define L_BDC_FD_IAU_02_00ms    	0x04000051	//	for UWB Ranging
#define L_UWB_BLE_SLV_FD_01_00ms 	0x040000B0
#define L_BDC_FD_IAU_10_200ms   	0x08000050
#define L_UWB_BLE_MST_FD_14_00ms	0x040000AD	//	for OTA

static unsigned char m_IAU_FD_04_200ms[CANID_BUFFER_SIZE];
static unsigned char m_IAU_FD_05_200ms[CANID_BUFFER_SIZE];
static unsigned char m_CCU_01_00ms[CANID_BUFFER_SIZE];
static unsigned char m_L_BDC_FD_IAU_02_00ms[CANID_BUFFER_SIZE];
static unsigned char m_L_UWB_BLE_SLV_FD_01_00ms[CANID_BUFFER_SIZE];
static unsigned char m_L_BDC_FD_IAU_10_200ms[CANID_BUFFER_SIZE];
static unsigned char m_L_UWB_BLE_MST_FD_14_00ms[CANID_BUFFER_SIZE];

static unsigned char* m_addrCanBuffer[CANID_RECV_KIND] = {
	m_IAU_FD_04_200ms,
	m_IAU_FD_05_200ms,
	m_CCU_01_00ms,
	m_L_BDC_FD_IAU_02_00ms,
	m_L_UWB_BLE_SLV_FD_01_00ms,
	m_L_BDC_FD_IAU_10_200ms,
	m_L_UWB_BLE_MST_FD_14_00ms,
};

static can_message_t m_messageTx_03_00 = {
	.cs = 0U,
	.id = 0x040000B2,							//	L_UWB_BLE_SLV_FD_03_00ms
	.length = 32U
};

static can_message_t m_messageTx_01_00 = {
	.cs = 0U,
	.id = 0x040000BF,
	.length = 32U
};

static can_message_t m_messageTx_20_200 = {
	.cs = 0U,
	.id = 0x080000B0,							//	L_UWB_BLE_SLV_FD_20_200ms
	.length = 16U
};

static can_message_t m_messageTx_21_200 = {
	.cs = 0U,
	.id = 0x080000B1,							//	L_UWB_BLE_SLV_FD_21_200ms
	.length = 16U
};

typedef enum
{
    LED0_CHANGE_REQUESTED = 0x00U,
    LED1_CHANGE_REQUESTED = 0x01U
} can_commands_list;


//----------------------------------------------
//	Variables
//----------------------------------------------
const can_buff_config_t buffCfgTxExt =
{
    .enableFD = true,
    .enableBRS = true,
    .fdPadding = 0U,
    .idType = CAN_MSG_ID_EXT,
    .isRemote = false
};
const can_buff_config_t buffCfgRxExt =
{
    .enableFD = true,
    .enableBRS = true,
    .fdPadding = 0U,
    .idType = CAN_MSG_ID_EXT,
    .isRemote = false
};
#if 0
const can_buff_config_t buffCfgRxStd =
{
	.enableFD = true,
	.enableBRS = true,
	.fdPadding = 0U,
	.idType = CAN_MSG_ID_STD,
	.isRemote = false
};
#endif

static can_buff_config_t m_BufferConfig[7];

can_message_t m_recvMsg[CANID_RECV_KIND];
#if 0
static unsigned int m_recvId[CANID_RECV_KIND] = {
	IAU_FD_04_200ms,
	IAU_FD_05_200ms,
	CCU_01_00ms,
	L_BDC_FD_IAU_02_00ms,
	L_UWB_BLE_SLV_FD_01_00ms,
	L_BDC_FD_IAU_10_200ms,
	0, 0,
	0, 0,	0, 0,	0, 0,	0, 0
};
#endif

static tIAU_FD_04_200ms *m_pIAU_FD_04_200ms;
static tIAU_FD_05_200ms *m_pIAU_FD_05_200ms;
static tCCU_01_00ms *m_pCCU_01_00ms;
static tL_BDC_FD_IAU_02_00ms *m_pL_BDC_FD_IAU_02_00ms;
static tL_UWB_BLE_SLV_FD_01_00ms *m_pL_UWB_BLE_SLV_FD_01_00ms;
static tL_BDC_FD_IAU_10_200ms *m_pL_BDC_FD_IAU_10_200ms;
static tL_UWB_BLE_MST_FD_14_00ms *m_pL_UWB_BLE_MST_FD_14_00ms;

uint8_t ledRequested = (uint8_t)LED0_CHANGE_REQUESTED;


//----------------------------------------------
//	Prototype Functions
//----------------------------------------------
static bool checkDataDifferent(unsigned char *pCurr, unsigned char *pPrev, int cbData);
static void makeDevData(can_message_t *pMessage);


//----------------------------------------------
//	Functions
//----------------------------------------------
void initCANOE(void)
{
	//	initVariables
	m_pIAU_FD_04_200ms = (tIAU_FD_04_200ms *)m_IAU_FD_04_200ms;
	m_pIAU_FD_05_200ms = (tIAU_FD_05_200ms *)m_IAU_FD_05_200ms;
	m_pCCU_01_00ms = (tCCU_01_00ms *)m_CCU_01_00ms;
	m_pL_BDC_FD_IAU_02_00ms = (tL_BDC_FD_IAU_02_00ms *)m_L_BDC_FD_IAU_02_00ms;
	m_pL_UWB_BLE_SLV_FD_01_00ms = (tL_UWB_BLE_SLV_FD_01_00ms *)m_L_UWB_BLE_SLV_FD_01_00ms;
	m_pL_BDC_FD_IAU_10_200ms = (tL_BDC_FD_IAU_10_200ms *)m_L_BDC_FD_IAU_10_200ms;
	m_pL_UWB_BLE_MST_FD_14_00ms = (tL_UWB_BLE_MST_FD_14_00ms *)m_L_UWB_BLE_MST_FD_14_00ms;

	//	initialize CAN
    CAN_Init(&can_pal1_instance, &can_pal1_Config0);


    //	Configure TX buffer with index TX_MAILBOX
    simpleCopy((unsigned char *)(m_BufferConfig + 6), (unsigned char *)&buffCfgTxExt, sizeof(can_buff_config_t));
    CAN_ConfigTxBuff(&can_pal1_instance, TX_MAILBOX, m_BufferConfig + 6);

    //	Configure RX buffer with index RX_MAILBOX
    simpleCopy((unsigned char *)(m_BufferConfig + 0), (unsigned char *)&buffCfgRxExt, sizeof(can_buff_config_t));
    CAN_ConfigRxBuff(&can_pal1_instance, 0, m_BufferConfig + 0, L_BDC_FD_IAU_10_200ms);

    simpleCopy((unsigned char *)(m_BufferConfig + 1), (unsigned char *)&buffCfgRxExt, sizeof(can_buff_config_t));
    CAN_ConfigRxBuff(&can_pal1_instance, 1, m_BufferConfig + 1, L_UWB_BLE_MST_FD_14_00ms);

    simpleCopy((unsigned char *)(m_BufferConfig + 2), (unsigned char *)&buffCfgRxExt, sizeof(can_buff_config_t));
    CAN_ConfigRxBuff(&can_pal1_instance, 2, m_BufferConfig + 2, L_BDC_FD_IAU_02_00ms);

//    CAN_SetRxFilter(&can_pal1_instance, CAN_MSG_ID_EXT, 0, 0);
    CAN_Receive(&can_pal1_instance, 0, &m_recvMsg[0]);
    CAN_Receive(&can_pal1_instance, 1, &m_recvMsg[1]);
}

void commCANOE(unsigned int nEvent)
{
    //	Wait until the previous FlexCAN receive is completed
	if(CAN_GetTransferStatus(&can_pal1_instance, 0) == STATUS_SUCCESS)
	{
		if(checkDataDifferent(m_addrCanBuffer[5], m_recvMsg[0].data, m_recvMsg[0].length) == true)
		{
			makeDevData(&m_recvMsg[0]);
		}
		CAN_Receive(&can_pal1_instance, 0, &m_recvMsg[0]);

		toggleLed();
	}
	if(CAN_GetTransferStatus(&can_pal1_instance, 1) == STATUS_SUCCESS)
	{
		if(checkDataDifferent(m_addrCanBuffer[6], m_recvMsg[1].data, m_recvMsg[1].length) == true)
		{
			makeDevData(&m_recvMsg[1]);
		}
		CAN_Receive(&can_pal1_instance, 1, &m_recvMsg[1]);
	}
	if(CAN_GetTransferStatus(&can_pal1_instance, 2) == STATUS_SUCCESS)
	{
		if(checkDataDifferent(m_addrCanBuffer[3], m_recvMsg[2].data, m_recvMsg[2].length) == true)
		{
			makeDevData(&m_recvMsg[2]);
		}
		CAN_Receive(&can_pal1_instance, 2, &m_recvMsg[2]);
	}


#if (BUTTON_TEST == 1)
	if(nEvent & EVENT_BTN1)
	{
		m_messageTx_03_00.data[0] = 0;
		CAN_Send(&can_pal1_instance, TX_MAILBOX, &m_messageTx_03_00);
	}
	if(nEvent & EVENT_BTN2)
	{
		m_messageTx_20_200.data[0] = 1;
		CAN_Send(&can_pal1_instance, TX_MAILBOX, &m_messageTx_20_200);
	}
#endif
}


//----------------------------------------------
//	CAN
//----------------------------------------------
void doBle2Can(unsigned char *pBuffer, int cbData)
{
	if((pBuffer[5] == bMsg_L_UWB_BLE_MST_FD_20_200ms) || (pBuffer[5] == bMsg_L_UWB_BLE_SLV_FD_20_200ms))
	{
		bst_L_UWB_BLE_SLV_FD_20_200ms* pMsgStruct = (bst_L_UWB_BLE_SLV_FD_20_200ms*)(pBuffer + 7);
		tL_UWB_BLE_SLV_FD_20_200ms* pBufStruct = (tL_UWB_BLE_SLV_FD_20_200ms *)&m_messageTx_20_200.data;

		pBufStruct->SLV_BLE_DK_ID1 = pMsgStruct->SLV_BLE_DK_ID1;
		pBufStruct->SLV_BLE_RSSI1 = pMsgStruct->SLV_BLE_RSSI1;
		pBufStruct->SLV_BLE_ConnectedDeviceInfo = pMsgStruct->SLV_BLE_ConnectedDeviceInfo[0] | (pMsgStruct->SLV_BLE_ConnectedDeviceInfo[1] << 8);
//		pBufStruct->SLV_BLE_OP_ADV_State = pMsgStruct->SLV_BLE_OP_ADV_State;
		pBufStruct->SLV_BLE_Passive_ADV_State = pMsgStruct->SLV_BLE_Passive_ADV_State;
		pBufStruct->SLV_BLE_NewDeviceConnetStatus = pMsgStruct->SLV_BLE_NewDeviceConnetStatus;

//			simpleCopy
		simpleCopy(m_messageTx_20_200.data, pBuffer, cbData);
        CAN_Send(&can_pal1_instance, TX_MAILBOX, &m_messageTx_20_200);
	}
}

void doUwb2Can(int nType, unsigned char *pBuffer, int cbData)
{
	if(nType == 0)
	{
		tL_UWB_BLE_SLV_FD_21_200ms* pBufStruct = (tL_UWB_BLE_SLV_FD_21_200ms *)&m_messageTx_21_200.data;
		pBufStruct->SLV_UWB_Status1 = pBuffer[0];
	}
	else if(nType == 1)
	{
//		tL_UWB_BLE_SLV_FD_03_00ms* pBufStruct = (tL_UWB_BLE_SLV_FD_03_00ms *)&m_messageTx_03_00.data;
		simpleCopy(m_messageTx_03_00.data, pBuffer, cbData);
		CAN_Send(&can_pal1_instance, TX_MAILBOX, &m_messageTx_03_00);
	}
	else if(nType == 2)
	{
		tL_UWB_BLE_SLV_FD_Dvp_01_00ms* pBufStruct = (tL_UWB_BLE_SLV_FD_Dvp_01_00ms *)&m_messageTx_01_00.data;
		pBufStruct->SLV_Dvp_Data_00 = pBuffer[0];
		pBufStruct->SLV_Dvp_Data_01 = pBuffer[1];
		CAN_Send(&can_pal1_instance, TX_MAILBOX, &m_messageTx_01_00);
	}
}

static int OnbMsgData(unsigned char *pDest, unsigned char *pSrc, int nId, int bMessage, int cbData);

static bool checkDataDifferent(unsigned char *pCurr, unsigned char *pPrev, int cbData)
{
	for(int i = 0; i < cbData; i++)
	{
		if(pCurr[i] != pPrev[i])
			return true;
	}

	return false;
}

void makeDevData(can_message_t *pMessage)
{
	if(pMessage != NULL)
	{
		switch(pMessage->id)
		{
		case IAU_FD_04_200ms:
			strncpy((char *)m_IAU_FD_04_200ms, (char *)pMessage->data, pMessage->length);
			{
				int nDestSize;
				bool bDifferent = false;
				unsigned char SrcBuffer[32] = { 0, }, DestBuffer[32];
				bst_IAU_FD_04_200ms* pStruct = (bst_IAU_FD_04_200ms*)SrcBuffer;
				if(pStruct->IAU_OwnerPhnRegRVal != m_pIAU_FD_04_200ms->IAU_OwnerPhnRegRVal)
				{
					bDifferent = true;
					pStruct->IAU_OwnerPhnRegRVal = m_pIAU_FD_04_200ms->IAU_OwnerPhnRegRVal;
				}
				if(bDifferent == true)
				{
					nDestSize = OnbMsgData(DestBuffer, SrcBuffer, bMsg_IAU_FD_04_200ms, eMSG_TYPE_REQ, sizeof(bst_IAU_FD_04_200ms));
					doCan2Ble(COMMAND_BLE_COMM, DestBuffer, nDestSize);
				}
			}
			break;
		case IAU_FD_05_200ms:
			strncpy((char *)m_IAU_FD_05_200ms, (char *)pMessage->data, pMessage->length);
			{
				int nDestSize;
				bool bDifferent = false;
				unsigned char SrcBuffer[32] = { 0, }, DestBuffer[32];
				bst_IAU_FD_05_200ms* pStruct = (bst_IAU_FD_05_200ms*)SrcBuffer;
				if(pStruct->IAU_SharedPhnRegStat != m_pIAU_FD_05_200ms->IAU_SharedPhnRegStat)
				{
					bDifferent = true;
					pStruct->IAU_SharedPhnRegStat = m_pIAU_FD_05_200ms->IAU_SharedPhnRegStat;
				}
				if(bDifferent == true)
				{
					nDestSize = OnbMsgData(DestBuffer, SrcBuffer, bMsg_IAU_FD_05_200ms, eMSG_TYPE_REQ, sizeof(bst_IAU_FD_05_200ms));
					doCan2Ble(COMMAND_BLE_COMM, DestBuffer, nDestSize);
				}
			}
			break;
		case CCU_01_00ms:
			strncpy((char *)m_CCU_01_00ms, (char *)pMessage->data, pMessage->length);
			{
				int nDestSize;
				bool bDifferent = false;
				unsigned char SrcBuffer[32] = { 0, }, DestBuffer[32];
				bst_CCU_01_00ms* pStruct = (bst_CCU_01_00ms*)SrcBuffer;
				if(pStruct->CCU_ForcedPowerOffReq != m_pCCU_01_00ms->CCU_ForcedPowerOffReq)
				{
					bDifferent = true;
					pStruct->CCU_ForcedPowerOffReq = m_pCCU_01_00ms->CCU_ForcedPowerOffReq;
				}
				if(bDifferent == true)
				{
					nDestSize = OnbMsgData(DestBuffer, SrcBuffer, bMsg_CCU_01_00ms, eMSG_TYPE_REQ, sizeof(bst_CCU_01_00ms));
					doCan2Ble(COMMAND_BLE_COMM, DestBuffer, nDestSize);
				}
			}
			break;
		case L_BDC_FD_IAU_02_00ms:
			{
				int nDestSize;
				bool bDifferent = false;
				unsigned char SrcBuffer[32] = { 0, }, DestBuffer[32];
				bst_L_BDC_FD_IAU_02_00ms* pMsgStruct = (bst_L_BDC_FD_IAU_02_00ms*)SrcBuffer;
				tL_BDC_FD_IAU_02_00ms* pBufStruct = (tL_BDC_FD_IAU_02_00ms *)pMessage->data;
				if((pBufStruct->BDC_RndNum_Trgt != m_pL_BDC_FD_IAU_02_00ms->BDC_RndNum_Trgt)
				|| (pBufStruct->BDC_RndNum_TRCod != m_pL_BDC_FD_IAU_02_00ms->BDC_RndNum_TRCod)
				|| (pBufStruct->BDC_RndNum_Cmd != m_pL_BDC_FD_IAU_02_00ms->BDC_RndNum_Cmd)
				|| (pBufStruct->DKID_Set != m_pL_BDC_FD_IAU_02_00ms->DKID_Set)
				|| (pBufStruct->DKID_Del != m_pL_BDC_FD_IAU_02_00ms->DKID_Del))
				{
					bDifferent = true;
				}

				if(bDifferent == true)
				{
					pMsgStruct->BDC_RndNum_Trgt = pBufStruct->BDC_RndNum_Trgt;
					pMsgStruct->BDC_RndNum_TRCod = pBufStruct->BDC_RndNum_TRCod;
					pMsgStruct->BDC_RndNum_Cmd = pBufStruct->BDC_RndNum_Cmd;
					pMsgStruct->DKID_Set = pBufStruct->DKID_Set;
					pMsgStruct->DKID_Del = pBufStruct->DKID_Del;

					nDestSize = OnbMsgData(DestBuffer, SrcBuffer, bMsg_L_BDC_FD_IAU_02_00ms, eMSG_TYPE_REQ, sizeof(bst_L_BDC_FD_IAU_02_00ms));
					doCan2Ble(COMMAND_BLE_COMM, DestBuffer, nDestSize);
				}

				if(pBufStruct->UWB_Ranging_Cmd_Val != m_pL_BDC_FD_IAU_02_00ms->UWB_Ranging_Cmd_Val)
				{
					pMsgStruct->UWB_Ranging_Cmd_Val = pBufStruct->UWB_Ranging_Cmd_Val;
					doCan2Uwb(COMMAND_UWB_COMM, (unsigned char *)&pMsgStruct->UWB_Ranging_Cmd_Val, 1);
				}
			}
			simpleCopy(m_L_BDC_FD_IAU_02_00ms, pMessage->data, pMessage->length);
			break;
		case L_UWB_BLE_SLV_FD_01_00ms:
			strncpy((char *)m_L_UWB_BLE_SLV_FD_01_00ms, (char *)pMessage->data, pMessage->length);
			{
				int nDestSize;
				bool bDifferent = false;
				unsigned char SrcBuffer[32] = { 0, }, DestBuffer[32];
				bst_L_UWB_BLE_SLV_FD_01_00ms* pStruct = (bst_L_UWB_BLE_SLV_FD_01_00ms*)SrcBuffer;
				if(pStruct->SLV_BLE_Decrypt_FB != m_pL_UWB_BLE_SLV_FD_01_00ms->SLV_BLE_Decrypt_FB)
				{
					bDifferent = true;
					pStruct->SLV_BLE_Decrypt_FB = m_pL_UWB_BLE_SLV_FD_01_00ms->SLV_BLE_Decrypt_FB;
				}
				if(bDifferent == true)
				{
					nDestSize = OnbMsgData(DestBuffer, SrcBuffer, bMsg_L_UWB_BLE_SLV_FD_01_00ms, eMSG_TYPE_REQ, sizeof(bst_L_UWB_BLE_SLV_FD_01_00ms));
					doCan2Ble(COMMAND_BLE_COMM, DestBuffer, nDestSize);
				}
			}
			break;
		case L_BDC_FD_IAU_10_200ms:
			{
				int nDestSize;
				bool bDifferent = false;
				unsigned char SrcBuffer[32] = { 0, }, DestBuffer[32];
				bst_L_BDC_FD_IAU_10_200ms* pMsgStruct = (bst_L_BDC_FD_IAU_10_200ms*)SrcBuffer;
				tL_BDC_FD_IAU_10_200ms* pBufStruct = (tL_BDC_FD_IAU_10_200ms *)pMessage->data;
				if((m_pL_BDC_FD_IAU_10_200ms->OPAdv_On_Cmd != pBufStruct->OPAdv_On_Cmd))
				{
					bDifferent = true;
				}
				if(bDifferent == true)
				{
					pMsgStruct->OPAdv_On_Cmd = pBufStruct->OPAdv_On_Cmd;

					nDestSize = OnbMsgData(DestBuffer, SrcBuffer, bMsg_L_BDC_FD_IAU_10_200ms, eMSG_TYPE_REQ, sizeof(bst_L_BDC_FD_IAU_10_200ms));
					doCan2Ble(COMMAND_BLE, DestBuffer, nDestSize);
				}
			}
			simpleCopy(m_L_BDC_FD_IAU_10_200ms, pMessage->data, pMessage->length);
			break;
		case L_UWB_BLE_MST_FD_14_00ms:
			{
				int nDestSize;
				bool bDifferent = false;
				unsigned char SrcBuffer[32] = { 0, }, DestBuffer[32];
				bst_L_UWB_BLE_MST_FD_14_00ms* pMsgStruct = (bst_L_UWB_BLE_MST_FD_14_00ms *)SrcBuffer;
				tL_UWB_BLE_MST_FD_14_00ms* pBufStruct = (tL_UWB_BLE_MST_FD_14_00ms *)pMessage->data;
				if((m_pL_UWB_BLE_MST_FD_14_00ms->MST_OTA_Cmd != pBufStruct->MST_OTA_Cmd))
				{
					bDifferent = true;
				}
				if(bDifferent == true)
				{
					pMsgStruct->MST_OTA_CMD = pBufStruct->MST_OTA_Cmd;

					switch(pMsgStruct->MST_OTA_CMD)
					{
					case 4:
						doCan2Uwb(COMMAND_UWB_REPROGRAM, (unsigned char *)&pMsgStruct->MST_OTA_CMD, 1);
						break;
					case 7:
						nDestSize = OnbMsgData(DestBuffer, SrcBuffer, bMsg_L_UWB_BLE_MST_FD_14_00ms, eMSG_TYPE_REQ, sizeof(bst_L_UWB_BLE_MST_FD_14_00ms));
						doCan2Ble(COMMAND_BLE_REPROGRAM, DestBuffer, nDestSize);
						break;
					}
				}
			}
			break;
		}
	}
	else
	{

	}
}

int OnbMsgData(unsigned char *pDest, unsigned char *pSrc, int nId, int bMessage, int cbData)
{
	int nSrc, nDest;

	nDest = 0;

	pDest[nDest++] = COMMAND_SOF;
	pDest[nDest++] = bMessage;
	pDest[nDest++] = nId;
	pDest[nDest++] = cbData;
	for (nSrc = 0; nSrc < cbData; nSrc++, nDest++)
	{
		pDest[nDest] = pSrc[nSrc];
	}
	pDest[nDest++] = COMMAND_FCS;
	pDest[nDest++] = COMMAND_EOF;

	return nDest;
}
