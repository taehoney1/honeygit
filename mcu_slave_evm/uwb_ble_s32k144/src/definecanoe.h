/*****************************************************************************
* Copyright (C) 2023 by SDC Micro
* Module name   : CAN
* File name     : CanMsg.h
* Author        : Gilbert Ahn
* Date          : 2023-09-12
* Version       : 1.0
* Comment       : CAN communication
*
* - Revision History -
* Version   Author          Date            Comment
* 1.0       Gilbert Ahn     2023-09-12      Initial Release.
*****************************************************************************/

#ifndef __DEFINE_CANOE_H__
#define __DEFINE_CANOE_H__

#ifdef __cplusplus
{
#endif

/*****************************************************************************
* INCLUDE FILES
*****************************************************************************/
//  *** PE ***
//  =>

//  IAU_FD_04_200ms / IAU_FD_05_200ms
//  IAU_OwnerPhnRegRVal / IAU_SharedPhnRegStat : 
enum
{
    ePhnRegRVal_UNREGISTERD = 0,
    ePhnRegRVal_REGISTERD,
    ePhnRegRVal_RESERVED,
    ePhnRegRVal_INVALID,
};
//  IAU_FD_05_200ms

//  L_BDC_FD_IAU_10_200ms                       // 1st
//  BDC_TP_CAN_Sta
enum
{
    eBDC_TP_CAN_Sta_IDLE = 0,
    eBDC_TP_CAN_Sta_WPC,
    eBDC_TP_CAN_Sta_DHL,
    eBDC_TP_CAN_Sta_DHR,
    eBDC_TP_CAN_Sta_BLE_TRX,
    eBDC_TP_CAN_Sta_DHRL,
    eBDC_TP_CAN_Sta_DHRR,
    eBDC_TP_CAN_Sta_BLE2_TRX,
};
//  OPAdv_On_Cmd
enum
{
    eOPAdv_On_Cmd_STOP = 0,
    eOPAdv_On_Cmd_STARTENABLE,
    eOPAdv_On_Cmd_RESERVED,
    eOPAdv_On_Cmd_INVALID,
};

//  <=

//  L_UWB_BLE_MST_FD_20_200ms
// 
// 
enum
{
    eBLE_OP_ADV_State_OFF = 0,
    eBLE_OP_ADV_State_ON,
};

enum
{
    eBLE_Passive_ADV_State_OFF = 0,
    eBLE_Passive_ADV_State_ON,
};

enum
{
    eBLE_NewDeviceConnetStatus_DEFAULT = 0,
    eBLE_NewDeviceConnetStatus_CONNECTED,
    eBLE_NewDeviceConnetStatus_DISCONNECTED,
    eBLE_NewDeviceConnetStatus_INVALID,
};

enum
{
    eBLE_PairingResult_DEFAULT = 0,
    eBLE_PairingResult_START,
    eBLE_PairingResult_COMPLETE,
    eBLE_PairingResult_FAIL,
};

//  L_TP_BDC_FD_L_UWB_BLE_MST_FD
#define DK_ID_NEW               0x11

//  Message Type Value
enum
{
    eMESSAGE_TYPE_FRAMEWORK = 0,
    eMESSAGE_TYPE_SE,
    eMESSAGE_TYPE_UWB_RANGING_SERVICE,
    eMESSAGE_TYPE_DCK_EVENT_NOTIFICATION,
    eMESSAGE_TYPE_VEHICLE_OEM_APP,
    eMESSAGE_TYPE_SUPPLEMENTARY_SERVICE,
    eMESSAGE_TYPE_HEAD_UNIT_PAIRING,
};



//  *** DOWNLOAD ***
//  L_UWB_BLE_MST_FD_14_00ms
//  MST_OTA_Cmd : 24, 8
enum
{
    eOTACmd_Default = 0,
    eOTACmd_SLAVE_DownLoad_Request,
    eOTACmd_SLAVE_Erase_Memory,
    eOTACmd_SLAVE_Signature_Verify,
    eOTACmd_UWB_MCU_DownLoad_Request,
    eOTACmd_UWB_MCU_Erase_Memory,
    eOTACmd_UWB_MCU_Signature_Verify,
    eOTACmd_BLE_IC_DownLoad_Request,                   //  0x07
    eOTACmd_BLE_IC_Erase_Memory,                       //  0x08
    eOTACmd_BLE_IC_Signature_Verify,
};

//
//  SLV_OTA_Rsp : 36, 4
enum
{
    eOTARsp_Default = 0,
    eOTARsp_Request_Success,
    eOTARsp_Request_Fail,
    eOTARsp_Erase_Success,
    eOTARsp_Erase_Fail,
    eOTARsp_RESERVED,
    eOTARsp_Verify_Success,                             //  0x07
    eOTARsp_Verify_Fail,
};

//  L_UWB_BLE_MST_FD_15_00ms
//  MST_Download_Data : 24, 232(29 Bytes)


//  L_UWB_BLE_SLV_FD_21_200ms
//  SLV_SW_UWB_Ver_Major : 136. 8
//  SLV_SW_UWB_Ver_Minor : 144. 8


//  Payload Header : CCC-TS-101-Digital-Key-R3_V1.1.0.pdf : 19.3 DK Message Format


// 
//	0x0000043F	CCU_01_00ms
//	0x00000351	IAU_FD_04_200ms					//	IAU_OwnerPhnRegRVal
//	0x00000351	IAU_FD_05_200ms					//	IAU_SharedPhnRegStat

//	0x04000051	L_BDC_FD_IAU_02_00ms			//	DKID_Set, DKID_Del
//	0x04000052	L_BDC_FD_IAU_03_00ms			//	not used
//	0x04000053	L_BDC_FD_IAU_04_00ms			//	not used

//	0x040000A0	L_UWB_BLE_MST_FD_01_00ms
//	0x040000A3	L_UWB_BLE_MST_FD_04_00ms
//	0x040000A4	L_UWB_BLE_MST_FD_05_00ms
//	0x040000A5	L_UWB_BLE_MST_FD_06_00ms
//	0x040000A6	L_UWB_BLE_MST_FD_07_00ms
//	0x040000A7	L_UWB_BLE_MST_FD_08_00ms
//	0x040000A8	L_UWB_BLE_MST_FD_09_00ms
//	0x040000A9	L_UWB_BLE_MST_FD_10_00ms
//	0x040000AA	L_UWB_BLE_MST_FD_11_00ms

//	0x040000B0	L_UWB_BLE_MST_FD_01_00ms
//	0x040000B3	L_UWB_BLE_MST_FD_04_00ms
//	0x040000B4	L_UWB_BLE_MST_FD_05_00ms
//	0x040000B5	L_UWB_BLE_MST_FD_06_00ms
//	0x040000B6	L_UWB_BLE_MST_FD_07_00ms
//	0x040000B7	L_UWB_BLE_MST_FD_08_00ms

//	0x08000050	L_BDC_FD_IAU_10_200ms			//	OPAdv_On_Cmd
//	0x080000A0	L_UWB_BLE_MST_FD_20_200ms		//	MST_BLE_PairingResult, MST_BLE_NewDeviceConnectStatus, MST_BLE_ConnectedDeviceInfo
//	0x080000A1	L_UWB_BLE_MST_FD_21_200ms
//	0x080000B0	L_UWB_BLE_SLV_FD_20_200ms		//	SLV_BLE_PairingResult, SLV_BLE_NewDeviceConnectStatus, SLV_BLE_ConnectedDeviceInfo
//	0x080000B1	L_UWB_BLE_SLV_FD_21_200ms

//	0x0C000050	L_TP_BDC_FD_L_UWB_BLE_MST_FD	//	32 bytes
//	0xC0000052	L_TP_BDC_FD_L_UWB_BLE_SLV_FD	//	32 bytes
//	0xC0000101	L_TP_L_UWB_BLE_MST_FD_BDC_FD	//	32 bytes
//	0xC0000103	L_TP_L_UWB_BLE_SLV_FD_BDC_FD	//	32 bytes

//  0x040000AD  L_UWB_BLE_MST_FD_14_00ms        //  8 bytes
//  0x040000AE  L_UWB_BLE_MST_FD_15_00ms        //  32 bytes
//  0x040000B0  L_UWB_BLE_SLV_FD_01_00ms        //  8 bytes

typedef unsigned char   u08;
typedef unsigned short  u16;
typedef unsigned int    u32;

/*****************************************************************************
* MACRO DEFINITIONS
*****************************************************************************/
/*! /brief Definition of message size */
#define SLAVE_CANMSG_RX_NUM       41u
#define SLAVE_CANMSG_TX_NUM       13u
#define SLAVE_CANMSG_MAX          (SLAVE_CANMSG_RX_NUM+SLAVE_CANMSG_TX_NUM)

#define ANCHOR_CANMSG_RX_NUM       36u
#define ANCHOR_CANMSG_TX_NUM       6u
#define ANCHOR_CANMSG_MAX          (ANCHOR_CANMSG_RX_NUM+ANCHOR_CANMSG_TX_NUM)


/*! /brief Definition of index numner for message. */
#define SLAVE_IAU_FD_04_200ms                ( 0) /* ID: 0x351      */
#define SLAVE_IAU_FD_05_200ms                ( 1) /* ID: 0x352      */
#define SLAVE_BDC_FD_02_200ms                ( 2) /* ID: 0x3D1      */
#define SLAVE_CCU_01_00ms                    ( 3) /* ID: 0x43F      */
#define SLAVE_L_BDC_FD_IAU_02_00ms           ( 4) /* ID: 0x4000051  */
#define SLAVE_L_BDC_FD_IAU_03_00ms           ( 5) /* ID: 0x4000052  */
#define SLAVE_L_BDC_FD_IAU_04_00ms           ( 6) /* ID: 0x4000053  */
#define SLAVE_L_BDC_FD_IAU_05_00ms           ( 7) /* ID: 0x4000054  */
#define SLAVE_L_BDC_FD_IAU_06_00ms           ( 8) /* ID: 0x4000055  */
#define SLAVE_L_BDC_FD_IAU_07_00ms           ( 9) /* ID: 0x4000056  */
#define SLAVE_L_UWB_BLE_MST_FD_01_00ms       (10) /* ID: 0x40000A0  */
#define SLAVE_L_UWB_BLE_MST_FD_04_00ms       (11) /* ID: 0x40000A3  */
#define SLAVE_L_UWB_BLE_MST_FD_05_00ms       (12) /* ID: 0x40000A4  */
#define SLAVE_L_UWB_BLE_MST_FD_06_00ms       (13) /* ID: 0x40000A5  */
#define SLAVE_L_UWB_BLE_MST_FD_07_00ms       (14) /* ID: 0x40000A6  */
#define SLAVE_L_UWB_BLE_MST_FD_08_00ms       (15) /* ID: 0x40000A7  */
#define SLAVE_L_UWB_BLE_MST_FD_09_00ms       (16) /* ID: 0x40000A8  */
#define SLAVE_L_UWB_BLE_MST_FD_14_00ms       (17) /* ID: 0x40000AD  */
#define SLAVE_L_UWB_BLE_MST_FD_15_00ms       (18) /* ID: 0x40000AE  */
#define SLAVE_L_EDT_FD_BLE_Dvp_01_00ms       (19) /* ID: 0x4000200  */
#define SLAVE_L_EDT_FD_DH_Dvp_02_00ms        (20) /* ID: 0x4000201  */
#define SLAVE_L_EDT_FD_UWB_Dvp_03_00ms       (21) /* ID: 0x4000202  */
#define SLAVE_L_BDC_FD_IAU_10_200ms          (22) /* ID: 0x8000050  */
#define SLAVE_L_BDC_FD_ROA_01_200ms          (23) /* ID: 0x8000060  */
#define SLAVE_L_UWB_BLE_MST_FD_20_200ms      (24) /* ID: 0x80000A0  */
#define SLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD   (25) /* ID: 0xC000102  */
#define SLAVE_NM_L_WPC_FD                    (26) /* ID: 0x17FC001E */
#define SLAVE_NM_L_UWB_BLE_MST_FD            (27) /* ID: 0x17FC0020 */
#define SLAVE_NM_L_UWB_FL_FD                 (28) /* ID: 0x17FC0022 */
#define SLAVE_NM_L_UWB_FR_FD                 (29) /* ID: 0x17FC0023 */
#define SLAVE_NM_L_UWB_FRNK_FD               (30) /* ID: 0x17FC0024 */
#define SLAVE_NM_L_UWB_RL_FD                 (31) /* ID: 0x17FC0025 */
#define SLAVE_NM_L_UWB_RR_FD                 (32) /* ID: 0x17FC0026 */
#define SLAVE_NM_L_UWB_TRNK_FD               (33) /* ID: 0x17FC0027 */
#define SLAVE_NM_L_DHL_FD                    (34) /* ID: 0x17FC002A */
#define SLAVE_NM_L_DHR_FD                    (35) /* ID: 0x17FC002B */
#define SLAVE_NM_L_DHRL_FD                   (36) /* ID: 0x17FC002C */
#define SLAVE_NM_L_DHRR_FD                   (37) /* ID: 0x17FC002D */
#define SLAVE_NM_CGW_CCU                     (38) /* ID: 0x17FC0070 */
#define SLAVE_NM_GW_BDC_FD                   (39) /* ID: 0x17FC0080 */
#define SLAVE_NM_L_SAL_FD                    (40) /* ID: 0x17FC00A9 */
#define SLAVE_L_UWB_BLE_SLV_FD_01_00ms       (41) /* ID: 0x40000B0  */
#define SLAVE_L_UWB_BLE_SLV_FD_02_00ms       (42) /* ID: 0x40000B1  */
#define SLAVE_L_UWB_BLE_SLV_FD_03_00ms       (43) /* ID: 0x40000B2  */
#define SLAVE_L_UWB_BLE_SLV_FD_04_00ms       (44) /* ID: 0x40000B3  */
#define SLAVE_L_UWB_BLE_SLV_FD_05_00ms       (45) /* ID: 0x40000B4  */
#define SLAVE_L_UWB_BLE_SLV_FD_06_00ms       (46) /* ID: 0x40000B5  */
#define SLAVE_L_UWB_BLE_SLV_FD_07_00ms       (47) /* ID: 0x40000B6  */
#define SLAVE_L_UWB_BLE_SLV_FD_08_00ms       (48) /* ID: 0x40000B7  */
#define SLAVE_L_UWB_BLE_SLV_FD_Dvp_01_00ms   (49) /* ID: 0x40000BF  */
#define SLAVE_L_UWB_BLE_SLV_FD_20_200ms      (50) /* ID: 0x80000B0  */
#define SLAVE_L_UWB_BLE_SLV_FD_21_200ms      (51) /* ID: 0x80000B1  */
#define SLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD   (52) /* ID: 0xC000103  */
#define SLAVE_NM_L_UWB_BLE_SLV_FD            (53) /* ID: 0x17FC0021 */

///
#if 0
unsigned int CanMsgTable[] = {
0x00000351, // #define SLAVE_IAU_FD_04_200ms                ( 0) /* ID: 0x351      */
0x00000352, // #define SLAVE_IAU_FD_05_200ms                ( 1) /* ID: 0x352      */
0x000003D1, // #define SLAVE_BDC_FD_02_200ms                ( 2) /* ID: 0x3D1      */
0x0000043F, // #define SLAVE_CCU_01_00ms                    ( 3) /* ID: 0x43F      */
0x04000051, // #define SLAVE_L_BDC_FD_IAU_02_00ms           ( 4) /* ID: 0x4000051  */
0x04000052, // #define SLAVE_L_BDC_FD_IAU_03_00ms           ( 5) /* ID: 0x4000052  */
0x04000053, // #define SLAVE_L_BDC_FD_IAU_04_00ms           ( 6) /* ID: 0x4000053  */
0x04000054, // #define SLAVE_L_BDC_FD_IAU_05_00ms           ( 7) /* ID: 0x4000054  */
0x04000055, // #define SLAVE_L_BDC_FD_IAU_06_00ms           ( 8) /* ID: 0x4000055  */
0x04000056, // #define SLAVE_L_BDC_FD_IAU_07_00ms           ( 9) /* ID: 0x4000056  */
0x040000A0, // #define SLAVE_L_UWB_BLE_MST_FD_01_00ms       (10) /* ID: 0x40000A0  */
0x040000A3, // #define SLAVE_L_UWB_BLE_MST_FD_04_00ms       (11) /* ID: 0x40000A3  */
0x040000A4, // #define SLAVE_L_UWB_BLE_MST_FD_05_00ms       (12) /* ID: 0x40000A4  */
0x040000A5, // #define SLAVE_L_UWB_BLE_MST_FD_06_00ms       (13) /* ID: 0x40000A5  */
0x040000A6, // #define SLAVE_L_UWB_BLE_MST_FD_07_00ms       (14) /* ID: 0x40000A6  */
0x040000A7, // #define SLAVE_L_UWB_BLE_MST_FD_08_00ms       (15) /* ID: 0x40000A7  */
0x040000A8, // #define SLAVE_L_UWB_BLE_MST_FD_09_00ms       (16) /* ID: 0x40000A8  */
0x040000AD, // #define SLAVE_L_UWB_BLE_MST_FD_14_00ms       (17) /* ID: 0x40000AD  */
0x040000AE, // #define SLAVE_L_UWB_BLE_MST_FD_15_00ms       (18) /* ID: 0x40000AE  */
0x04000200, // #define SLAVE_L_EDT_FD_BLE_Dvp_01_00ms       (19) /* ID: 0x4000200  */
0x04000201, // #define SLAVE_L_EDT_FD_DH_Dvp_02_00ms        (20) /* ID: 0x4000201  */
0x04000202, // #define SLAVE_L_EDT_FD_UWB_Dvp_03_00ms       (21) /* ID: 0x4000202  */
0x08000050, // #define SLAVE_L_BDC_FD_IAU_10_200ms          (22) /* ID: 0x8000050  */
0x08000060, // #define SLAVE_L_BDC_FD_ROA_01_200ms          (23) /* ID: 0x8000060  */
0x080000A0, // #define SLAVE_L_UWB_BLE_MST_FD_20_200ms      (24) /* ID: 0x80000A0  */
0x0C000102, // #define SLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD   (25) /* ID: 0xC000102  */
0x17FC001E, // #define SLAVE_NM_L_WPC_FD                    (26) /* ID: 0x17FC001E */
0x17FC0020, // #define SLAVE_NM_L_UWB_BLE_MST_FD            (27) /* ID: 0x17FC0020 */
0x17FC0022, // #define SLAVE_NM_L_UWB_FL_FD                 (28) /* ID: 0x17FC0022 */
0x17FC0023, // #define SLAVE_NM_L_UWB_FR_FD                 (29) /* ID: 0x17FC0023 */
0x17FC0024, // #define SLAVE_NM_L_UWB_FRNK_FD               (30) /* ID: 0x17FC0024 */
0x17FC0025, // #define SLAVE_NM_L_UWB_RL_FD                 (31) /* ID: 0x17FC0025 */
0x17FC0026, // #define SLAVE_NM_L_UWB_RR_FD                 (32) /* ID: 0x17FC0026 */
0x17FC0027, // #define SLAVE_NM_L_UWB_TRNK_FD               (33) /* ID: 0x17FC0027 */
0x17FC002A, // #define SLAVE_NM_L_DHL_FD                    (34) /* ID: 0x17FC002A */
0x17FC002B, // #define SLAVE_NM_L_DHR_FD                    (35) /* ID: 0x17FC002B */
0x17FC002C, // #define SLAVE_NM_L_DHRL_FD                   (36) /* ID: 0x17FC002C */
0x17FC002D, // #define SLAVE_NM_L_DHRR_FD                   (37) /* ID: 0x17FC002D */
0x17FC0070, // #define SLAVE_NM_CGW_CCU                     (38) /* ID: 0x17FC0070 */
0x17FC0080, // #define SLAVE_NM_GW_BDC_FD                   (39) /* ID: 0x17FC0080 */
0x17FC00A9, // #define SLAVE_NM_L_SAL_FD                    (40) /* ID: 0x17FC00A9 */
0x040000B0, // #define SLAVE_L_UWB_BLE_SLV_FD_01_00ms       (41) /* ID: 0x40000B0  */
0x040000B1, // #define SLAVE_L_UWB_BLE_SLV_FD_02_00ms       (42) /* ID: 0x40000B1  */
0x040000B2, // #define SLAVE_L_UWB_BLE_SLV_FD_03_00ms       (43) /* ID: 0x40000B2  */
0x040000B3, // #define SLAVE_L_UWB_BLE_SLV_FD_04_00ms       (44) /* ID: 0x40000B3  */
0x040000B4, // #define SLAVE_L_UWB_BLE_SLV_FD_05_00ms       (45) /* ID: 0x40000B4  */
0x040000B5, // #define SLAVE_L_UWB_BLE_SLV_FD_06_00ms       (46) /* ID: 0x40000B5  */
0x040000B6, // #define SLAVE_L_UWB_BLE_SLV_FD_07_00ms       (47) /* ID: 0x40000B6  */
0x040000B7, // #define SLAVE_L_UWB_BLE_SLV_FD_08_00ms       (48) /* ID: 0x40000B7  */
0x040000BF, // #define SLAVE_L_UWB_BLE_SLV_FD_Dvp_01_00ms   (49) /* ID: 0x40000BF  */
0x080000B0, // #define SLAVE_L_UWB_BLE_SLV_FD_20_200ms      (50) /* ID: 0x80000B0  */
0x080000B1, // #define SLAVE_L_UWB_BLE_SLV_FD_21_200ms      (51) /* ID: 0x80000B1  */
0x0C000103, // #define SLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD   (52) /* ID: 0xC000103  */
0x17FC0021, // #define SLAVE_NM_L_UWB_BLE_SLV_FD            (53) /* ID: 0x17FC0021 */
};
#endif

/*! /brief Definition of NM Address. */
#define SLAVE_NM_CURRENT_ADDRESS             0x21u
#define SLAVE_NM_CURRENT_INDEX               SLAVE_NM_L_UWB_BLE_SLV_FD

#define ANCHOR_IAU_FD_04_200ms                ( 0) /* ID: 0x351      */
#define ANCHOR_IAU_FD_05_200ms                ( 1) /* ID: 0x352      */
#define ANCHOR_CCU_01_00ms                    ( 2) /* ID: 0x43F      */
#define ANCHOR_L_BDC_FD_IAU_02_00ms           ( 3) /* ID: 0x4000051  */
#define ANCHOR_L_BDC_FD_IAU_05_00ms           ( 4) /* ID: 0x4000054  */
#define ANCHOR_L_BDC_FD_IAU_06_00ms           ( 5) /* ID: 0x4000055  */
#define ANCHOR_L_BDC_FD_IAU_07_00ms           ( 6) /* ID: 0x4000056  */
#define ANCHOR_L_UWB_BLE_MST_FD_04_00ms       ( 7) /* ID: 0x40000A3  */
#define ANCHOR_L_UWB_BLE_MST_FD_05_00ms       ( 8) /* ID: 0x40000A4  */
#define ANCHOR_L_UWB_BLE_MST_FD_06_00ms       ( 9) /* ID: 0x40000A5  */
#define ANCHOR_L_UWB_BLE_MST_FD_07_00ms       (10) /* ID: 0x40000A6  */
#define ANCHOR_L_UWB_BLE_MST_FD_08_00ms       (11) /* ID: 0x40000A7  */
#define ANCHOR_L_UWB_BLE_MST_FD_09_00ms       (12) /* ID: 0x40000A8  */
#define ANCHOR_L_UWB_BLE_MST_FD_14_00ms       (13) /* ID: 0x40000AD  */
#define ANCHOR_L_UWB_BLE_MST_FD_15_00ms       (14) /* ID: 0x40000AE  */
#define ANCHOR_L_UWB_BLE_SLV_FD_04_00ms       (15) /* ID: 0x40000B3  */
#define ANCHOR_L_UWB_BLE_SLV_FD_05_00ms       (16) /* ID: 0x40000B4  */
#define ANCHOR_L_UWB_BLE_SLV_FD_06_00ms       (17) /* ID: 0x40000B5  */
#define ANCHOR_L_UWB_BLE_SLV_FD_07_00ms       (18) /* ID: 0x40000B6  */
#define ANCHOR_L_UWB_BLE_SLV_FD_08_00ms       (19) /* ID: 0x40000B7  */
#define ANCHOR_L_BDC_FD_IAU_10_200ms          (20) /* ID: 0x8000050  */
#define ANCHOR_NM_L_WPC_FD                    (21) /* ID: 0x17FC001E */
#define ANCHOR_NM_L_UWB_BLE_MST_FD            (22) /* ID: 0x17FC0020 */
#define ANCHOR_NM_L_UWB_BLE_SLV_FD            (23) /* ID: 0x17FC0021 */
#define ANCHOR_NM_L_UWB_FR_FD                 (24) /* ID: 0x17FC0023 */
#define ANCHOR_NM_L_UWB_FRNK_FD               (25) /* ID: 0x17FC0024 */
#define ANCHOR_NM_L_UWB_RL_FD                 (26) /* ID: 0x17FC0025 */
#define ANCHOR_NM_L_UWB_RR_FD                 (27) /* ID: 0x17FC0026 */
#define ANCHOR_NM_L_UWB_TRNK_FD               (28) /* ID: 0x17FC0027 */
#define ANCHOR_NM_L_DHL_FD                    (29) /* ID: 0x17FC002A */
#define ANCHOR_NM_L_DHR_FD                    (30) /* ID: 0x17FC002B */
#define ANCHOR_NM_L_DHRL_FD                   (31) /* ID: 0x17FC002C */
#define ANCHOR_NM_L_DHRR_FD                   (32) /* ID: 0x17FC002D */
#define ANCHOR_NM_CGW_CCU                     (33) /* ID: 0x17FC0070 */
#define ANCHOR_NM_GW_BDC_FD                   (34) /* ID: 0x17FC0080 */
#define ANCHOR_NM_L_SAL_FD                    (35) /* ID: 0x17FC00A9 */
#define ANCHOR_L_UWB_FD_01_00ms               (36) /* ID: 0x40000C0  */
#define ANCHOR_L_UWB_FD_02_00ms               (37) /* ID: 0x40000C1  */
#define ANCHOR_L_UWB_FD_03_00ms               (38) /* ID: 0x40000C2  */
#define ANCHOR_L_UWB_FD_Dvp_01_00ms           (39) /* ID: 0x40000CF  */
#define ANCHOR_L_UWB_FD_10_200ms              (40) /* ID: 0x80000C0  */
#define ANCHOR_NM_L_UWB_FD                    (41) /* ID: 0x17FC0022, 0x17FC0023, 0x17FC0025, 0x17FC0026 */


/*! /brief Definition of NM Address. */
#define ANCHOR_NM_CURRENT_ADDRESS             0x22u
#define ANCHOR_NM_CURRENT_INDEX               ANCHOR_NM_L_UWB_FD

/*****************************************************************************
* TYPE DEFINITIONS
*****************************************************************************/
/*! /brief Definition of frame structure */
#pragma pack(push, 1)
typedef struct
{
    u16 IAU_FD_Crc4Val;
    u08 IAU_FD_AlvCnt4Val;
    u08 IAU_StartIdentifiedProfile_Ext   :  4;
    u08 reserved_00                      :  4;
    u08 reserved_01;
    u08 reserved_02;
    u08 reserved_03;
    u08 reserved_04;
    u08 reserved_05;
    u08 reserved_06                      :  2;
    u08 IAU_ProfileIDRVal                :  4;
    u08 reserved_07                      :  2;
    u08 IAU_DigitalKeyProcessingSta      :  4;
    u08 IAU_DigitalKeyExit               :  4;
    u08 IAU_DigitalKeyEnblRVal           :  2;
    u08 IAU_OwnerPhnRegRVal              :  2;
    u08 IAU_NFCCard1RegRVal              :  2;
    u08 IAU_NFCCard2RegRVal              :  2;
    u08 reserved_08;
    u08 IAU_DISPWrng                     :  4;
    u08 reserved_09                      :  4;
    u08 reserved_10;
    u08 IAU_DigitalKey2Opt               :  3;
    u08 reserved_11                      :  1;
    u08 IAUwFRULearnState                :  2;
    u08 IAUwFPMLearnState                :  2;
    u08 IAU_ValetDigitalkey              :  2;
    u08 IAU_DigitalKeyNumberOpt          :  3;
    u08 IAU_eSEReprogramSta              :  2;
    u08 reserved_12                      :  1;
    u08 reserved_13                      :  3;
    u08 IAU_DgtKeyGrpPrflRval2           :  5;
    u08 IAU_StartIdentifiedProfile       :  3;
    u08 IAU_DigitalKeyProfileRval2       :  5;
    u32 IAU_NFCCard1SN;
    u08 reserved_14;
    u08 reserved_15;
    u08 reserved_16;
    u08 reserved_17;
    u08 reserved_18;
    u08 reserved_19;
    u08 reserved_20;
    u08 reserved_21                      :  6;
    u08 RSPA_UWBRspaExtRngSta            :  2;
    u08 reserved_22                      :  2;
    u08 RSPA_CanFltSta                   :  2;
    u08 RSPA_BLESigErrSta                :  2;
    u08 RSPA_ConStat                     :  2;
} tIAU_FD_04_200ms;

typedef struct
{
    u16 IAU_FD_Crc5Val;
    u08 IAU_FD_AlvCnt5Val;
    u08 reserved_23;
    u08 reserved_24;
    u08 reserved_25;
    u08 reserved_26;
    u08 reserved_27;
    u08 reserved_28;
    u08 reserved_29;
    u08 reserved_30;
    u08 reserved_31;
    u08 reserved_32;
    u08 reserved_33;
    u08 IAU_DigitalKeyProfileRval        :  4;
    u08 IAU_SharedPhnRegStat             :  2;
    u08 IAU_CardKeyEnblRVal              :  2;
    u08 IAU_DrvDHLPhnDetect              :  2;
    u08 IAU_AstDHLPhnDetect              :  2;
    u08 IAU_RLDHLPhnDetect               :  2;
    u08 IAU_RRDHLPhnDetect               :  2;
    u08 IAU_Manufacturer;
    u08 IAU_VendorCode_00;
    u08 IAU_VendorCode_01;
    u08 IAU_VendorCode_02;
    u32 IAU_Serial;
    u16 IAU_Year;
    u08 IAU_Month;
    u16 IAU_Date;
    u08 IAU_SWVerMajor1                  :  7;
    u08 reserved_34                      :  1;
    u08 IAU_SWVerMinor1                  :  7;
    u08 reserved_35                      :  1;
    u08 IAU_SWVerMinor2                  :  7;
    u08 reserved_36                      :  1;
} tIAU_FD_05_200ms;

typedef struct
{
    u16 BDC_FD_Crc2Val;
    u08 BDC_FD_AlvCnt2Val;
    u08 BCM_KeyInSta                     :  2;
    u08 BCM_AccInSta                     :  2;
    u08 BCM_Ign1InSta                    :  2;
    u08 BCM_Ign2InSta                    :  2;
    u08 IBU_HDPSpprtSWVer                :  6;
    u08 IBU_HDPSpprtRdy                  :  2;
    u08 BCM_GearPosPSta                  :  2;
    u08 BCM_SmkOptTyp                    :  2;
    u08 reserved_37                      :  4;
    u08 IBU_SWVerMajor1                  :  7;
    u08 reserved_38                      :  1;
    u08 IBU_SWVerMinor1                  :  7;
    u08 reserved_39                      :  1;
    u08 IBU_SWVerMinor2                  :  7;
    u08 reserved_40                      :  1;
    u08 BDC_PlatformVerType              :  4;
    u08 reserved_41                      :  4;
    u08 BDC_PlatformVerDate;
    u08 reserved_42;
    u08 reserved_43;
    u08 reserved_44;
    u08 reserved_45;
    u08 reserved_46;
    u08 reserved_47;
    u08 reserved_48;
    u08 reserved_49;
    u08 reserved_50;
    u08 reserved_51;
    u08 reserved_52;
    u08 reserved_53;
    u08 reserved_54;
    u08 reserved_55;
    u08 reserved_56;
    u08 reserved_57;
    u08 reserved_58;
    u08 reserved_59;
    u08 reserved_60;
    u08 reserved_61;
    u08 reserved_62;
} tBDC_FD_02_200ms;

typedef struct
{
    u08 CCU_01_Crc1Val;
    u08 CCU_ForcedPowerOffReq            :  2;
    u08 reserved_63                      :  2;
    u08 CCU_01_AlvCnt1Val                :  4;
    u08 reserved_64;
    u08 reserved_65;
    u08 reserved_66;
    u08 reserved_67;
    u08 reserved_68;
    u08 reserved_69;
} tCCU_01_00ms;

typedef struct
{
    u08 reserved_70;
    u08 reserved_71;
    u08 reserved_72;
    u08 BDC_RndNum_Trgt                  :  4;
    u08 BDC_RndNum_TRCod                 :  4;
    u08 BDC_RndNum_Cmd                   :  4;
    u08 reserved_73                      :  4;
    u08 BDC_RndNum_00;
    u08 BDC_RndNum_01;
    u08 BDC_RndNum_02;
    u08 BDC_RndNum_03;
    u08 BDC_RndNum_04;
    u08 BDC_RndNum_05;
    u08 BDC_Decrypt_FB                   :  2;
    u08 reserved_74                      :  6;
    u08 DKID_Set;
    u08 DKID_Del;
    u08 UWB_Ranging_Cmd_DKID;
    u08 UWB_Ranging_Cmd_Val;
} tL_BDC_FD_IAU_02_00ms;

typedef struct
{
    u08 reserved_75;
    u08 reserved_76;
    u08 reserved_77;
    u08 BDC_To_BLE_Enc_Data1_00;
    u08 BDC_To_BLE_Enc_Data1_01;
    u08 BDC_To_BLE_Enc_Data1_02;
    u08 BDC_To_BLE_Enc_Data1_03;
    u08 BDC_To_BLE_Enc_Data1_04;
    u08 BDC_To_BLE_Enc_Data1_05;
    u08 BDC_To_BLE_Enc_Data1_06;
    u08 BDC_To_BLE_Enc_Data1_07;
    u08 BDC_To_BLE_Enc_Data1_08;
    u08 BDC_To_BLE_Enc_Data1_09;
    u08 BDC_To_BLE_Enc_Data1_10;
    u08 BDC_To_BLE_Enc_Data1_11;
    u08 BDC_To_BLE_Enc_Data1_12;
    u08 BDC_To_BLE_Enc_Data1_13;
    u08 BDC_To_BLE_Enc_Data1_14;
    u08 BDC_To_BLE_Enc_Data1_15;
    u08 BDC_To_BLE_Enc_Data1_16;
    u08 BDC_To_BLE_Enc_Data1_17;
    u08 BDC_To_BLE_Enc_Data1_18;
    u08 BDC_To_BLE_Enc_Data1_19;
    u08 BDC_To_BLE_Enc_Data1_20;
    u08 BDC_To_BLE_Enc_Data1_21;
    u08 BDC_To_BLE_Enc_Data1_22;
    u08 BDC_To_BLE_Enc_Data1_23;
    u08 BDC_To_BLE_Enc_Data1_24;
    u08 BDC_To_BLE_Enc_Data1_25;
    u08 BDC_To_BLE_Enc_Data1_26;
    u08 BDC_To_BLE_Enc_Data1_27;
    u08 BDC_To_BLE_Enc_Data1_28;
} tL_BDC_FD_IAU_03_00ms;

typedef struct
{
    u08 reserved_78;
    u08 reserved_79;
    u08 reserved_80;
    u08 BDC_To_BLE_Enc_Data2_00;
    u08 BDC_To_BLE_Enc_Data2_01;
    u08 BDC_To_BLE_Enc_Data2_02;
    u08 BDC_To_BLE_Enc_Data2_03;
    u08 BDC_To_BLE_Enc_Data2_04;
    u08 BDC_To_BLE_Enc_Data2_05;
    u08 BDC_To_BLE_Enc_Data2_06;
    u08 BDC_To_BLE_Enc_Data2_07;
    u08 BDC_To_BLE_Enc_Data2_08;
    u08 BDC_To_BLE_Enc_Data2_09;
    u08 BDC_To_BLE_Enc_Data2_10;
    u08 BDC_To_BLE_Enc_Data2_11;
    u08 BDC_To_BLE_Enc_Data2_12;
    u08 BDC_To_BLE_Enc_Data2_13;
    u08 BDC_To_BLE_Enc_Data2_14;
    u08 BDC_To_BLE_Enc_Data2_15;
    u08 BDC_To_BLE_Enc_Data2_16;
    u08 BDC_To_BLE_Enc_Data2_17;
    u08 BDC_To_BLE_Enc_Data2_18;
    u08 BDC_To_BLE_Enc_Data2_19;
    u08 BDC_To_BLE_Enc_Data2_20;
    u08 BDC_To_BLE_Enc_Data2_21;
    u08 BDC_To_BLE_Enc_Data2_22;
    u08 BDC_To_BLE_Enc_Data2_23;
    u08 BDC_To_BLE_Enc_Data2_24;
    u08 BDC_To_BLE_Enc_Data2_25;
    u08 BDC_To_BLE_Enc_Data2_26;
    u08 BDC_To_BLE_Enc_Data2_27;
    u08 BDC_To_BLE_Enc_Data2_28;
} tL_BDC_FD_IAU_04_00ms;

typedef struct
{
    u08 reserved_81;
    u08 reserved_82;
    u08 reserved_83;
    u08 BDC_To_UWB_Enc_Data1_00;
    u08 BDC_To_UWB_Enc_Data1_01;
    u08 BDC_To_UWB_Enc_Data1_02;
    u08 BDC_To_UWB_Enc_Data1_03;
    u08 BDC_To_UWB_Enc_Data1_04;
    u08 BDC_To_UWB_Enc_Data1_05;
    u08 BDC_To_UWB_Enc_Data1_06;
    u08 BDC_To_UWB_Enc_Data1_07;
    u08 BDC_To_UWB_Enc_Data1_08;
    u08 BDC_To_UWB_Enc_Data1_09;
    u08 BDC_To_UWB_Enc_Data1_10;
    u08 BDC_To_UWB_Enc_Data1_11;
    u08 BDC_To_UWB_Enc_Data1_12;
    u08 BDC_To_UWB_Enc_Data1_13;
    u08 BDC_To_UWB_Enc_Data1_14;
    u08 BDC_To_UWB_Enc_Data1_15;
    u08 BDC_To_UWB_Enc_Data1_16;
    u08 BDC_To_UWB_Enc_Data1_17;
    u08 BDC_To_UWB_Enc_Data1_18;
    u08 BDC_To_UWB_Enc_Data1_19;
    u08 BDC_To_UWB_Enc_Data1_20;
    u08 BDC_To_UWB_Enc_Data1_21;
    u08 BDC_To_UWB_Enc_Data1_22;
    u08 BDC_To_UWB_Enc_Data1_23;
    u08 BDC_To_UWB_Enc_Data1_24;
    u08 BDC_To_UWB_Enc_Data1_25;
    u08 BDC_To_UWB_Enc_Data1_26;
    u08 BDC_To_UWB_Enc_Data1_27;
    u08 BDC_To_UWB_Enc_Data1_28;
} tL_BDC_FD_IAU_05_00ms;

typedef struct
{
    u08 reserved_84;
    u08 reserved_85;
    u08 reserved_86;
    u08 BDC_To_UWB_Enc_Data2_00;
    u08 BDC_To_UWB_Enc_Data2_01;
    u08 BDC_To_UWB_Enc_Data2_02;
    u08 BDC_To_UWB_Enc_Data2_03;
    u08 BDC_To_UWB_Enc_Data2_04;
    u08 BDC_To_UWB_Enc_Data2_05;
    u08 BDC_To_UWB_Enc_Data2_06;
    u08 BDC_To_UWB_Enc_Data2_07;
    u08 BDC_To_UWB_Enc_Data2_08;
    u08 BDC_To_UWB_Enc_Data2_09;
    u08 BDC_To_UWB_Enc_Data2_10;
    u08 BDC_To_UWB_Enc_Data2_11;
    u08 BDC_To_UWB_Enc_Data2_12;
    u08 BDC_To_UWB_Enc_Data2_13;
    u08 BDC_To_UWB_Enc_Data2_14;
    u08 BDC_To_UWB_Enc_Data2_15;
    u08 BDC_To_UWB_Enc_Data2_16;
    u08 BDC_To_UWB_Enc_Data2_17;
    u08 BDC_To_UWB_Enc_Data2_18;
    u08 BDC_To_UWB_Enc_Data2_19;
    u08 BDC_To_UWB_Enc_Data2_20;
    u08 BDC_To_UWB_Enc_Data2_21;
    u08 BDC_To_UWB_Enc_Data2_22;
    u08 BDC_To_UWB_Enc_Data2_23;
    u08 BDC_To_UWB_Enc_Data2_24;
    u08 BDC_To_UWB_Enc_Data2_25;
    u08 BDC_To_UWB_Enc_Data2_26;
    u08 BDC_To_UWB_Enc_Data2_27;
    u08 BDC_To_UWB_Enc_Data2_28;
} tL_BDC_FD_IAU_06_00ms;

typedef struct
{
    u08 reserved_87;
    u08 reserved_88;
    u08 reserved_89;
    u08 BDC_To_UWB_Enc_Data3_00;
    u08 BDC_To_UWB_Enc_Data3_01;
    u08 BDC_To_UWB_Enc_Data3_02;
    u08 BDC_To_UWB_Enc_Data3_03;
    u08 BDC_To_UWB_Enc_Data3_04;
    u08 BDC_To_UWB_Enc_Data3_05;
    u08 BDC_To_UWB_Enc_Data3_06;
    u08 BDC_To_UWB_Enc_Data3_07;
    u08 BDC_To_UWB_Enc_Data3_08;
    u08 BDC_To_UWB_Enc_Data3_09;
    u08 BDC_To_UWB_Enc_Data3_10;
    u08 BDC_To_UWB_Enc_Data3_11;
    u08 BDC_To_UWB_Enc_Data3_12;
    u08 BDC_To_UWB_Enc_Data3_13;
    u08 BDC_To_UWB_Enc_Data3_14;
    u08 BDC_To_UWB_Enc_Data3_15;
    u08 BDC_To_UWB_Enc_Data3_16;
    u08 BDC_To_UWB_Enc_Data3_17;
    u08 BDC_To_UWB_Enc_Data3_18;
    u08 BDC_To_UWB_Enc_Data3_19;
    u08 BDC_To_UWB_Enc_Data3_20;
    u08 BDC_To_UWB_Enc_Data3_21;
    u08 BDC_To_UWB_Enc_Data3_22;
    u08 BDC_To_UWB_Enc_Data3_23;
    u08 BDC_To_UWB_Enc_Data3_24;
    u08 BDC_To_UWB_Enc_Data3_25;
    u08 BDC_To_UWB_Enc_Data3_26;
    u08 BDC_To_UWB_Enc_Data3_27;
    u08 BDC_To_UWB_Enc_Data3_28;
} tL_BDC_FD_IAU_07_00ms;

typedef struct
{
    u16 L_UWB_BLE_MST_FD_Crc1Val;
    u08 L_UWB_BLE_MST_FD_AlvCnt1Val;
    u08 MST_BLE_Decrypt_FB               :  4;
    u08 MST_UWB_Decrypt_FB               :  4;
    u08 MST_SLV_Decrypt_FB               :  4;
    u08 MST_OTA_Status                   :  2;
    u08 reserved_90                      :  2;
    u08 reserved_91;
    u08 reserved_92;
    u08 reserved_93;
} tL_UWB_BLE_MST_FD_01_00ms;

typedef struct
{
    u16 L_UWB_BLE_MST_FD_Crc4Val;
    u08 L_UWB_BLE_MST_FD_AlvCnt4Val;
    u08 MST_RndNum_Trgt                  :  4;
    u08 MST_RndNum_TRCode                :  4;
    u08 MST_RndNum_Cmd                   :  4;
    u08 reserved_94                      :  4;
    u08 MST_RndNum_00;
    u08 MST_RndNum_01;
    u08 MST_RndNum_02;
    u08 MST_RndNum_03;
    u08 MST_RndNum_04;
    u08 MST_RndNum_05;
    u08 reserved_95;
    u08 reserved_96;
    u08 reserved_97;
    u08 reserved_98;
    u08 reserved_99;
} tL_UWB_BLE_MST_FD_04_00ms;

typedef struct
{
    u16 L_UWB_BLE_MST_FD_Crc5Val;
    u08 L_UWB_BLE_MST_FD_AlvCnt5Val;
    u08 MST_To_UWB_Enc_Data1_00;
    u08 MST_To_UWB_Enc_Data1_01;
    u08 MST_To_UWB_Enc_Data1_02;
    u08 MST_To_UWB_Enc_Data1_03;
    u08 MST_To_UWB_Enc_Data1_04;
    u08 MST_To_UWB_Enc_Data1_05;
    u08 MST_To_UWB_Enc_Data1_06;
    u08 MST_To_UWB_Enc_Data1_07;
    u08 MST_To_UWB_Enc_Data1_08;
    u08 MST_To_UWB_Enc_Data1_09;
    u08 MST_To_UWB_Enc_Data1_10;
    u08 MST_To_UWB_Enc_Data1_11;
    u08 MST_To_UWB_Enc_Data1_12;
    u08 MST_To_UWB_Enc_Data1_13;
    u08 MST_To_UWB_Enc_Data1_14;
    u08 MST_To_UWB_Enc_Data1_15;
    u08 MST_To_UWB_Enc_Data1_16;
    u08 MST_To_UWB_Enc_Data1_17;
    u08 MST_To_UWB_Enc_Data1_18;
    u08 MST_To_UWB_Enc_Data1_19;
    u08 MST_To_UWB_Enc_Data1_20;
    u08 MST_To_UWB_Enc_Data1_21;
    u08 MST_To_UWB_Enc_Data1_22;
    u08 MST_To_UWB_Enc_Data1_23;
    u08 MST_To_UWB_Enc_Data1_24;
    u08 MST_To_UWB_Enc_Data1_25;
    u08 MST_To_UWB_Enc_Data1_26;
    u08 MST_To_UWB_Enc_Data1_27;
    u08 MST_To_UWB_Enc_Data1_28;
} tL_UWB_BLE_MST_FD_05_00ms;

typedef struct
{
    u16 L_UWB_BLE_MST_FD_Crc6Val;
    u08 L_UWB_BLE_MST_FD_AlvCnt6Val;
    u08 MST_To_UWB_Enc_Data2_00;
    u08 MST_To_UWB_Enc_Data2_01;
    u08 MST_To_UWB_Enc_Data2_02;
    u08 MST_To_UWB_Enc_Data2_03;
    u08 MST_To_UWB_Enc_Data2_04;
    u08 MST_To_UWB_Enc_Data2_05;
    u08 MST_To_UWB_Enc_Data2_06;
    u08 MST_To_UWB_Enc_Data2_07;
    u08 MST_To_UWB_Enc_Data2_08;
    u08 MST_To_UWB_Enc_Data2_09;
    u08 MST_To_UWB_Enc_Data2_10;
    u08 MST_To_UWB_Enc_Data2_11;
    u08 MST_To_UWB_Enc_Data2_12;
    u08 MST_To_UWB_Enc_Data2_13;
    u08 MST_To_UWB_Enc_Data2_14;
    u08 MST_To_UWB_Enc_Data2_15;
    u08 MST_To_UWB_Enc_Data2_16;
    u08 MST_To_UWB_Enc_Data2_17;
    u08 MST_To_UWB_Enc_Data2_18;
    u08 MST_To_UWB_Enc_Data2_19;
    u08 MST_To_UWB_Enc_Data2_20;
    u08 MST_To_UWB_Enc_Data2_21;
    u08 MST_To_UWB_Enc_Data2_22;
    u08 MST_To_UWB_Enc_Data2_23;
    u08 MST_To_UWB_Enc_Data2_24;
    u08 MST_To_UWB_Enc_Data2_25;
    u08 MST_To_UWB_Enc_Data2_26;
    u08 MST_To_UWB_Enc_Data2_27;
    u08 MST_To_UWB_Enc_Data2_28;
} tL_UWB_BLE_MST_FD_06_00ms;

typedef struct
{
    u16 L_UWB_BLE_MST_FD_Crc7Val;
    u08 L_UWB_BLE_MST_FD_AlvCnt7Val;
    u08 MST_To_UWB_Enc_Data3_00;
    u08 MST_To_UWB_Enc_Data3_01;
    u08 MST_To_UWB_Enc_Data3_02;
    u08 MST_To_UWB_Enc_Data3_03;
    u08 MST_To_UWB_Enc_Data3_04;
    u08 MST_To_UWB_Enc_Data3_05;
    u08 MST_To_UWB_Enc_Data3_06;
    u08 MST_To_UWB_Enc_Data3_07;
    u08 MST_To_UWB_Enc_Data3_08;
    u08 MST_To_UWB_Enc_Data3_09;
    u08 MST_To_UWB_Enc_Data3_10;
    u08 MST_To_UWB_Enc_Data3_11;
    u08 MST_To_UWB_Enc_Data3_12;
    u08 MST_To_UWB_Enc_Data3_13;
    u08 MST_To_UWB_Enc_Data3_14;
    u08 MST_To_UWB_Enc_Data3_15;
    u08 MST_To_UWB_Enc_Data3_16;
    u08 MST_To_UWB_Enc_Data3_17;
    u08 MST_To_UWB_Enc_Data3_18;
    u08 MST_To_UWB_Enc_Data3_19;
    u08 MST_To_UWB_Enc_Data3_20;
    u08 MST_To_UWB_Enc_Data3_21;
    u08 MST_To_UWB_Enc_Data3_22;
    u08 MST_To_UWB_Enc_Data3_23;
    u08 MST_To_UWB_Enc_Data3_24;
    u08 MST_To_UWB_Enc_Data3_25;
    u08 MST_To_UWB_Enc_Data3_26;
    u08 MST_To_UWB_Enc_Data3_27;
    u08 MST_To_UWB_Enc_Data3_28;
} tL_UWB_BLE_MST_FD_07_00ms;

typedef struct
{
    u16 L_UWB_BLE_MST_FD_Crc8Val;
    u08 L_UWB_BLE_MST_FD_AlvCnt8Val;
    u08 MST_To_UWB_Enc_Data4_00;
    u08 MST_To_UWB_Enc_Data4_01;
    u08 MST_To_UWB_Enc_Data4_02;
    u08 MST_To_UWB_Enc_Data4_03;
    u08 MST_To_UWB_Enc_Data4_04;
    u08 MST_To_UWB_Enc_Data4_05;
    u08 MST_To_UWB_Enc_Data4_06;
    u08 MST_To_UWB_Enc_Data4_07;
    u08 MST_To_UWB_Enc_Data4_08;
    u08 MST_To_UWB_Enc_Data4_09;
    u08 MST_To_UWB_Enc_Data4_10;
    u08 MST_To_UWB_Enc_Data4_11;
    u08 MST_To_UWB_Enc_Data4_12;
    u08 MST_To_UWB_Enc_Data4_13;
    u08 MST_To_UWB_Enc_Data4_14;
    u08 MST_To_UWB_Enc_Data4_15;
    u08 MST_To_UWB_Enc_Data4_16;
    u08 MST_To_UWB_Enc_Data4_17;
    u08 MST_To_UWB_Enc_Data4_18;
    u08 MST_To_UWB_Enc_Data4_19;
    u08 MST_To_UWB_Enc_Data4_20;
    u08 MST_To_UWB_Enc_Data4_21;
    u08 MST_To_UWB_Enc_Data4_22;
    u08 MST_To_UWB_Enc_Data4_23;
    u08 MST_To_UWB_Enc_Data4_24;
    u08 MST_To_UWB_Enc_Data4_25;
    u08 MST_To_UWB_Enc_Data4_26;
    u08 MST_To_UWB_Enc_Data4_27;
    u08 MST_To_UWB_Enc_Data4_28;
} tL_UWB_BLE_MST_FD_08_00ms;

typedef struct
{
    u16 L_UWB_BLE_MST_FD_Crc9Val;
    u08 L_UWB_BLE_MST_FD_AlvCnt9Val;
    u08 MST_To_UWB_Enc_Data5_00;
    u08 MST_To_UWB_Enc_Data5_01;
    u08 MST_To_UWB_Enc_Data5_02;
    u08 MST_To_UWB_Enc_Data5_03;
    u08 MST_To_UWB_Enc_Data5_04;
    u08 MST_To_UWB_Enc_Data5_05;
    u08 MST_To_UWB_Enc_Data5_06;
    u08 MST_To_UWB_Enc_Data5_07;
    u08 MST_To_UWB_Enc_Data5_08;
    u08 MST_To_UWB_Enc_Data5_09;
    u08 MST_To_UWB_Enc_Data5_10;
    u08 MST_To_UWB_Enc_Data5_11;
    u08 MST_To_UWB_Enc_Data5_12;
    u08 MST_To_UWB_Enc_Data5_13;
    u08 MST_To_UWB_Enc_Data5_14;
    u08 MST_To_UWB_Enc_Data5_15;
    u08 MST_To_UWB_Enc_Data5_16;
    u08 MST_To_UWB_Enc_Data5_17;
    u08 MST_To_UWB_Enc_Data5_18;
    u08 MST_To_UWB_Enc_Data5_19;
    u08 MST_To_UWB_Enc_Data5_20;
    u08 MST_To_UWB_Enc_Data5_21;
    u08 MST_To_UWB_Enc_Data5_22;
    u08 MST_To_UWB_Enc_Data5_23;
    u08 MST_To_UWB_Enc_Data5_24;
    u08 MST_To_UWB_Enc_Data5_25;
    u08 MST_To_UWB_Enc_Data5_26;
    u08 MST_To_UWB_Enc_Data5_27;
    u08 MST_To_UWB_Enc_Data5_28;
} tL_UWB_BLE_MST_FD_09_00ms;

typedef struct
{
    u16 L_UWB_BLE_MST_FD_Crc14Val;
    u08 L_UWB_BLE_MST_FD_AlvCnt14Val;
    u08 MST_OTA_Cmd;
    u08 reserved_100;
    u08 reserved_101;
    u08 reserved_102;
    u08 reserved_103;
} tL_UWB_BLE_MST_FD_14_00ms;

typedef struct
{
    u16 L_UWB_BLE_MST_FD_Crc15Val;
    u08 L_UWB_BLE_MST_FD_AlvCnt15Val;
    u08 MST_Download_Data_00;
    u08 MST_Download_Data_01;
    u08 MST_Download_Data_02;
    u08 MST_Download_Data_03;
    u08 MST_Download_Data_04;
    u08 MST_Download_Data_05;
    u08 MST_Download_Data_06;
    u08 MST_Download_Data_07;
    u08 MST_Download_Data_08;
    u08 MST_Download_Data_09;
    u08 MST_Download_Data_10;
    u08 MST_Download_Data_11;
    u08 MST_Download_Data_12;
    u08 MST_Download_Data_13;
    u08 MST_Download_Data_14;
    u08 MST_Download_Data_15;
    u08 MST_Download_Data_16;
    u08 MST_Download_Data_17;
    u08 MST_Download_Data_18;
    u08 MST_Download_Data_19;
    u08 MST_Download_Data_20;
    u08 MST_Download_Data_21;
    u08 MST_Download_Data_22;
    u08 MST_Download_Data_23;
    u08 MST_Download_Data_24;
    u08 MST_Download_Data_25;
    u08 MST_Download_Data_26;
    u08 MST_Download_Data_27;
    u08 MST_Download_Data_28;
} tL_UWB_BLE_MST_FD_15_00ms;

typedef struct
{
    u08 EDT_BLE_Dvp_Data_00;
    u08 EDT_BLE_Dvp_Data_01;
    u08 EDT_BLE_Dvp_Data_02;
    u08 EDT_BLE_Dvp_Data_03;
    u08 EDT_BLE_Dvp_Data_04;
    u08 EDT_BLE_Dvp_Data_05;
    u08 EDT_BLE_Dvp_Data_06;
    u08 EDT_BLE_Dvp_Data_07;
    u08 EDT_BLE_Dvp_Data_08;
    u08 EDT_BLE_Dvp_Data_09;
    u08 EDT_BLE_Dvp_Data_10;
    u08 EDT_BLE_Dvp_Data_11;
    u08 EDT_BLE_Dvp_Data_12;
    u08 EDT_BLE_Dvp_Data_13;
    u08 EDT_BLE_Dvp_Data_14;
    u08 EDT_BLE_Dvp_Data_15;
    u08 EDT_BLE_Dvp_Data_16;
    u08 EDT_BLE_Dvp_Data_17;
    u08 EDT_BLE_Dvp_Data_18;
    u08 EDT_BLE_Dvp_Data_19;
    u08 EDT_BLE_Dvp_Data_20;
    u08 EDT_BLE_Dvp_Data_21;
    u08 EDT_BLE_Dvp_Data_22;
    u08 EDT_BLE_Dvp_Data_23;
    u08 EDT_BLE_Dvp_Data_24;
    u08 EDT_BLE_Dvp_Data_25;
    u08 EDT_BLE_Dvp_Data_26;
    u08 EDT_BLE_Dvp_Data_27;
    u08 EDT_BLE_Dvp_Data_28;
    u08 EDT_BLE_Dvp_Data_29;
    u08 EDT_BLE_Dvp_Data_30;
    u08 EDT_BLE_Dvp_Data_31              :  7;
    u08 reserved_104                     :  1;
} tL_EDT_FD_BLE_Dvp_01_00ms;

typedef struct
{
    u08 EDT_DH_Dvp_Data_00;
    u08 EDT_DH_Dvp_Data_01;
    u08 EDT_DH_Dvp_Data_02;
    u08 EDT_DH_Dvp_Data_03;
    u08 EDT_DH_Dvp_Data_04;
    u08 EDT_DH_Dvp_Data_05;
    u08 EDT_DH_Dvp_Data_06;
    u08 EDT_DH_Dvp_Data_07;
    u08 EDT_DH_Dvp_Data_08;
    u08 EDT_DH_Dvp_Data_09;
    u08 EDT_DH_Dvp_Data_10;
    u08 EDT_DH_Dvp_Data_11;
    u08 EDT_DH_Dvp_Data_12;
    u08 EDT_DH_Dvp_Data_13;
    u08 EDT_DH_Dvp_Data_14;
    u08 EDT_DH_Dvp_Data_15;
    u08 EDT_DH_Dvp_Data_16;
    u08 EDT_DH_Dvp_Data_17;
    u08 EDT_DH_Dvp_Data_18;
    u08 EDT_DH_Dvp_Data_19;
    u08 EDT_DH_Dvp_Data_20;
    u08 EDT_DH_Dvp_Data_21;
    u08 EDT_DH_Dvp_Data_22;
    u08 EDT_DH_Dvp_Data_23;
    u08 EDT_DH_Dvp_Data_24;
    u08 EDT_DH_Dvp_Data_25;
    u08 EDT_DH_Dvp_Data_26;
    u08 EDT_DH_Dvp_Data_27;
    u08 EDT_DH_Dvp_Data_28;
    u08 EDT_DH_Dvp_Data_29;
    u08 EDT_DH_Dvp_Data_30;
    u08 EDT_DH_Dvp_Data_31               :  7;
    u08 reserved_105                     :  1;
} tL_EDT_FD_DH_Dvp_02_00ms;

typedef struct
{
    u08 EDT_UWB_Dvp_Data_00;
    u08 EDT_UWB_Dvp_Data_01;
    u08 EDT_UWB_Dvp_Data_02;
    u08 EDT_UWB_Dvp_Data_03;
    u08 EDT_UWB_Dvp_Data_04;
    u08 EDT_UWB_Dvp_Data_05;
    u08 EDT_UWB_Dvp_Data_06;
    u08 EDT_UWB_Dvp_Data_07;
    u08 EDT_UWB_Dvp_Data_08;
    u08 EDT_UWB_Dvp_Data_09;
    u08 EDT_UWB_Dvp_Data_10;
    u08 EDT_UWB_Dvp_Data_11;
    u08 EDT_UWB_Dvp_Data_12;
    u08 EDT_UWB_Dvp_Data_13;
    u08 EDT_UWB_Dvp_Data_14;
    u08 EDT_UWB_Dvp_Data_15;
    u08 EDT_UWB_Dvp_Data_16;
    u08 EDT_UWB_Dvp_Data_17;
    u08 EDT_UWB_Dvp_Data_18;
    u08 EDT_UWB_Dvp_Data_19;
    u08 EDT_UWB_Dvp_Data_20;
    u08 EDT_UWB_Dvp_Data_21;
    u08 EDT_UWB_Dvp_Data_22;
    u08 EDT_UWB_Dvp_Data_23;
    u08 EDT_UWB_Dvp_Data_24;
    u08 EDT_UWB_Dvp_Data_25;
    u08 EDT_UWB_Dvp_Data_26;
    u08 EDT_UWB_Dvp_Data_27;
    u08 EDT_UWB_Dvp_Data_28;
    u08 EDT_UWB_Dvp_Data_29;
    u08 EDT_UWB_Dvp_Data_30;
    u08 EDT_UWB_Dvp_Data_31              :  7;
    u08 reserved_106                     :  1;
} tL_EDT_FD_UWB_Dvp_03_00ms;

typedef struct
{
    u08 reserved_114;
    u08 reserved_115;
    u08 reserved_116;
    u08 ROA_SnsrRunReq                   :  3;
    u08 ROA_DiaReq                       :  3;
    u08 ROA_Region_Opt                   :  2;
    u08 ROA_EngSta                       :  2;
    u08 reserved_117                     :  6;
    u08 reserved_118;
    u08 reserved_119;
    u08 reserved_120;
} tL_BDC_FD_ROA_01_200ms;

typedef struct
{
    u16 L_UWB_BLE_MST_FD_Crc20Val;
    u08 L_UWB_BLE_MST_FD_AlvCnt20Val;
    u08 MST_BLE_DK_ID1;
    u08 MST_BLE_RSSI1;
    u08 MST_BLE_DK_ID2;
    u08 MST_BLE_RSSI2;
    u08 MST_BLE_DK_ID3;
    u08 MST_BLE_RSSI3;
    u08 MST_BLE_DK_ID4;
    u08 MST_BLE_RSSI4;
    u16 MST_BLE_BTAddIRK_Update;
    u16 MST_BLE_ConnectedDeviceInfo;
    u08 MST_BLE_OP_ADV_State             :  1;
    u08 MST_BLE_Passive_ADV_State        :  1;
    u08 MST_BLE_NewDeviceConnetStatus    :  2;
    u08 MST_BLE_PairingResult            :  2;
    u08 reserved_121                     :  2;
} tL_UWB_BLE_MST_FD_20_200ms;

typedef struct
{
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte0;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte1;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte2;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte3;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte4;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte5;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte6;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte7;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte8;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte9;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte10;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte11;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte12;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte13;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte14;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte15;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte16;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte17;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte18;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte19;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte20;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte21;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte22;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte23;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte24;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte25;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte26;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte27;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte28;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte29;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte30;
    u08 L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte31;
} tL_TP_BDC_FD_L_UWB_BLE_SLV_FD;

typedef struct
{
    u16 L_UWB_BLE_SLV_FD_Crc1Val;
    u08 L_UWB_BLE_SLV_FD_AlvCnt1Val;
    u08 SLV_BLE_Decrypt_FB               :  4;
    u08 SLV_UWB_Decrypt_FB               :  4;
    u08 SLV_MST_Decrypt_FB               :  4;
    u08 SLV_OTA_Rsp                      :  4;
    u08 reserved_152;
    u08 reserved_153;
    u08 reserved_154;
} tL_UWB_BLE_SLV_FD_01_00ms;

typedef struct
{
    u16 L_UWB_BLE_SLV_FD_Crc2Val;
    u08 L_UWB_BLE_SLV_FD_AlvCnt2Val;
    u08 SLV_UWB_FOB_RSD_Enc_Result_00;
    u08 SLV_UWB_FOB_RSD_Enc_Result_01;
    u08 SLV_UWB_FOB_RSD_Enc_Result_02;
    u08 SLV_UWB_FOB_RSD_Enc_Result_03;
    u08 SLV_UWB_FOB_RSD_Enc_Result_04;
    u08 SLV_UWB_FOB_RSD_Enc_Result_05;
    u08 SLV_UWB_FOB_RSD_Enc_Result_06;
    u08 SLV_UWB_FOB_RSD_Enc_Result_07;
    u08 reserved_155;
    u08 reserved_156;
    u08 reserved_157;
    u08 reserved_158;
    u08 reserved_159;
} tL_UWB_BLE_SLV_FD_02_00ms;

typedef struct
{
    u16 L_UWB_BLE_SLV_FD_Crc3Val;
    u08 L_UWB_BLE_SLV_FD_AlvCnt3Val;
    u08 SLV_UWB_Ranging_Enc_Result_00;
    u08 SLV_UWB_Ranging_Enc_Result_01;
    u08 SLV_UWB_Ranging_Enc_Result_02;
    u08 SLV_UWB_Ranging_Enc_Result_03;
    u08 SLV_UWB_Ranging_Enc_Result_04;
    u08 SLV_UWB_Ranging_Enc_Result_05;
    u08 SLV_UWB_Ranging_Enc_Result_06;
    u08 SLV_UWB_Ranging_Enc_Result_07;
    u08 SLV_UWB_Ranging_Enc_Result_08;
    u08 SLV_UWB_Ranging_Enc_Result_09;
    u08 SLV_UWB_Ranging_Enc_Result_10;
    u08 SLV_UWB_Ranging_Enc_Result_11;
    u08 SLV_UWB_Ranging_Enc_Result_12;
    u08 SLV_UWB_Ranging_Enc_Result_13;
    u08 SLV_UWB_Ranging_Enc_Result_14;
    u08 SLV_UWB_Ranging_Enc_Result_15;
    u08 SLV_UWB_Ranging_Enc_Result_16;
    u08 SLV_UWB_Ranging_Enc_Result_17;
    u08 SLV_UWB_Ranging_Enc_Result_18;
    u08 SLV_UWB_Ranging_Enc_Result_19;
    u08 SLV_UWB_Ranging_Enc_Result_20;
    u08 SLV_UWB_Ranging_Enc_Result_21;
    u08 SLV_UWB_Ranging_Enc_Result_22;
    u08 SLV_UWB_Ranging_Enc_Result_23;
    u08 reserved_160;
    u08 reserved_161;
    u08 reserved_162;
    u08 reserved_163;
    u08 reserved_164;
} tL_UWB_BLE_SLV_FD_03_00ms;

typedef struct
{
    u16 L_UWB_BLE_SLV_FD_Crc4Val;
    u08 L_UWB_BLE_SLV_FD_AlvCnt4Val;
    u08 SLV_To_MST_Enc_Data1_00;
    u08 SLV_To_MST_Enc_Data1_01;
    u08 SLV_To_MST_Enc_Data1_02;
    u08 SLV_To_MST_Enc_Data1_03;
    u08 SLV_To_MST_Enc_Data1_04;
    u08 SLV_To_MST_Enc_Data1_05;
    u08 SLV_To_MST_Enc_Data1_06;
    u08 SLV_To_MST_Enc_Data1_07;
    u08 SLV_To_MST_Enc_Data1_08;
    u08 SLV_To_MST_Enc_Data1_09;
    u08 SLV_To_MST_Enc_Data1_10;
    u08 SLV_To_MST_Enc_Data1_11;
    u08 SLV_To_MST_Enc_Data1_12;
    u08 SLV_To_MST_Enc_Data1_13;
    u08 SLV_To_MST_Enc_Data1_14;
    u08 SLV_To_MST_Enc_Data1_15;
    u08 SLV_To_MST_Enc_Data1_16;
    u08 SLV_To_MST_Enc_Data1_17;
    u08 SLV_To_MST_Enc_Data1_18;
    u08 SLV_To_MST_Enc_Data1_19;
    u08 SLV_To_MST_Enc_Data1_20;
    u08 SLV_To_MST_Enc_Data1_21;
    u08 SLV_To_MST_Enc_Data1_22;
    u08 SLV_To_MST_Enc_Data1_23;
    u08 SLV_To_MST_Enc_Data1_24;
    u08 SLV_To_MST_Enc_Data1_25;
    u08 SLV_To_MST_Enc_Data1_26;
    u08 SLV_To_MST_Enc_Data1_27;
    u08 SLV_To_MST_Enc_Data1_28;
} tL_UWB_BLE_SLV_FD_04_00ms;

typedef struct
{
    u16 L_UWB_BLE_SLV_FD_Crc5Val;
    u08 L_UWB_BLE_SLV_FD_AlvCnt5Val;
    u08 SLV_To_MST_Enc_Data2_00;
    u08 SLV_To_MST_Enc_Data2_01;
    u08 SLV_To_MST_Enc_Data2_02;
    u08 SLV_To_MST_Enc_Data2_03;
    u08 SLV_To_MST_Enc_Data2_04;
    u08 SLV_To_MST_Enc_Data2_05;
    u08 SLV_To_MST_Enc_Data2_06;
    u08 SLV_To_MST_Enc_Data2_07;
    u08 SLV_To_MST_Enc_Data2_08;
    u08 SLV_To_MST_Enc_Data2_09;
    u08 SLV_To_MST_Enc_Data2_10;
    u08 SLV_To_MST_Enc_Data2_11;
    u08 SLV_To_MST_Enc_Data2_12;
    u08 SLV_To_MST_Enc_Data2_13;
    u08 SLV_To_MST_Enc_Data2_14;
    u08 SLV_To_MST_Enc_Data2_15;
    u08 SLV_To_MST_Enc_Data2_16;
    u08 SLV_To_MST_Enc_Data2_17;
    u08 SLV_To_MST_Enc_Data2_18;
    u08 SLV_To_MST_Enc_Data2_19;
    u08 SLV_To_MST_Enc_Data2_20;
    u08 SLV_To_MST_Enc_Data2_21;
    u08 SLV_To_MST_Enc_Data2_22;
    u08 SLV_To_MST_Enc_Data2_23;
    u08 SLV_To_MST_Enc_Data2_24;
    u08 SLV_To_MST_Enc_Data2_25;
    u08 SLV_To_MST_Enc_Data2_26;
    u08 SLV_To_MST_Enc_Data2_27;
    u08 SLV_To_MST_Enc_Data2_28;
} tL_UWB_BLE_SLV_FD_05_00ms;

typedef struct
{
    u16 L_UWB_BLE_SLV_FD_Crc6Val;
    u08 L_UWB_BLE_SLV_FD_AlvCnt6Val;
    u08 SLV_To_MST_Enc_Data3_00;
    u08 SLV_To_MST_Enc_Data3_01;
    u08 SLV_To_MST_Enc_Data3_02;
    u08 SLV_To_MST_Enc_Data3_03;
    u08 SLV_To_MST_Enc_Data3_04;
    u08 SLV_To_MST_Enc_Data3_05;
    u08 SLV_To_MST_Enc_Data3_06;
    u08 SLV_To_MST_Enc_Data3_07;
    u08 SLV_To_MST_Enc_Data3_08;
    u08 SLV_To_MST_Enc_Data3_09;
    u08 SLV_To_MST_Enc_Data3_10;
    u08 SLV_To_MST_Enc_Data3_11;
    u08 SLV_To_MST_Enc_Data3_12;
    u08 SLV_To_MST_Enc_Data3_13;
    u08 SLV_To_MST_Enc_Data3_14;
    u08 SLV_To_MST_Enc_Data3_15;
    u08 SLV_To_MST_Enc_Data3_16;
    u08 SLV_To_MST_Enc_Data3_17;
    u08 SLV_To_MST_Enc_Data3_18;
    u08 SLV_To_MST_Enc_Data3_19;
    u08 SLV_To_MST_Enc_Data3_20;
    u08 SLV_To_MST_Enc_Data3_21;
    u08 SLV_To_MST_Enc_Data3_22;
    u08 SLV_To_MST_Enc_Data3_23;
    u08 SLV_To_MST_Enc_Data3_24;
    u08 SLV_To_MST_Enc_Data3_25;
    u08 SLV_To_MST_Enc_Data3_26;
    u08 SLV_To_MST_Enc_Data3_27;
    u08 SLV_To_MST_Enc_Data3_28;
} tL_UWB_BLE_SLV_FD_06_00ms;

typedef struct
{
    u16 L_UWB_BLE_SLV_FD_Crc7Val;
    u08 L_UWB_BLE_SLV_FD_AlvCnt7Val;
    u08 SLV_To_MST_Enc_Data4_00;
    u08 SLV_To_MST_Enc_Data4_01;
    u08 SLV_To_MST_Enc_Data4_02;
    u08 SLV_To_MST_Enc_Data4_03;
    u08 SLV_To_MST_Enc_Data4_04;
    u08 SLV_To_MST_Enc_Data4_05;
    u08 SLV_To_MST_Enc_Data4_06;
    u08 SLV_To_MST_Enc_Data4_07;
    u08 SLV_To_MST_Enc_Data4_08;
    u08 SLV_To_MST_Enc_Data4_09;
    u08 SLV_To_MST_Enc_Data4_10;
    u08 SLV_To_MST_Enc_Data4_11;
    u08 SLV_To_MST_Enc_Data4_12;
    u08 SLV_To_MST_Enc_Data4_13;
    u08 SLV_To_MST_Enc_Data4_14;
    u08 SLV_To_MST_Enc_Data4_15;
    u08 SLV_To_MST_Enc_Data4_16;
    u08 SLV_To_MST_Enc_Data4_17;
    u08 SLV_To_MST_Enc_Data4_18;
    u08 SLV_To_MST_Enc_Data4_19;
    u08 SLV_To_MST_Enc_Data4_20;
    u08 SLV_To_MST_Enc_Data4_21;
    u08 SLV_To_MST_Enc_Data4_22;
    u08 SLV_To_MST_Enc_Data4_23;
    u08 SLV_To_MST_Enc_Data4_24;
    u08 SLV_To_MST_Enc_Data4_25;
    u08 SLV_To_MST_Enc_Data4_26;
    u08 SLV_To_MST_Enc_Data4_27;
    u08 SLV_To_MST_Enc_Data4_28;
} tL_UWB_BLE_SLV_FD_07_00ms;

typedef struct
{
    u16 L_UWB_BLE_SLV_FD_Crc8Val;
    u08 L_UWB_BLE_SLV_FD_AlvCnt8Val;
    u08 SLV_To_MST_Enc_Data5_00;
    u08 SLV_To_MST_Enc_Data5_01;
    u08 SLV_To_MST_Enc_Data5_02;
    u08 SLV_To_MST_Enc_Data5_03;
    u08 SLV_To_MST_Enc_Data5_04;
    u08 SLV_To_MST_Enc_Data5_05;
    u08 SLV_To_MST_Enc_Data5_06;
    u08 SLV_To_MST_Enc_Data5_07;
    u08 SLV_To_MST_Enc_Data5_08;
    u08 SLV_To_MST_Enc_Data5_09;
    u08 SLV_To_MST_Enc_Data5_10;
    u08 SLV_To_MST_Enc_Data5_11;
    u08 SLV_To_MST_Enc_Data5_12;
    u08 SLV_To_MST_Enc_Data5_13;
    u08 SLV_To_MST_Enc_Data5_14;
    u08 SLV_To_MST_Enc_Data5_15;
    u08 SLV_To_MST_Enc_Data5_16;
    u08 SLV_To_MST_Enc_Data5_17;
    u08 SLV_To_MST_Enc_Data5_18;
    u08 SLV_To_MST_Enc_Data5_19;
    u08 SLV_To_MST_Enc_Data5_20;
    u08 SLV_To_MST_Enc_Data5_21;
    u08 SLV_To_MST_Enc_Data5_22;
    u08 SLV_To_MST_Enc_Data5_23;
    u08 SLV_To_MST_Enc_Data5_24;
    u08 SLV_To_MST_Enc_Data5_25;
    u08 SLV_To_MST_Enc_Data5_26;
    u08 SLV_To_MST_Enc_Data5_27;
    u08 SLV_To_MST_Enc_Data5_28;
} tL_UWB_BLE_SLV_FD_08_00ms;

typedef struct
{
    u08 reserved_68;
    u08 reserved_69;
    u08 reserved_70;
    u08 BodyType_Sta                     :  3;
    u08 reserved_71                      :  2;
    u08 BDC_TP_CAN_Sta                   :  3;
    u08 OPAdv_On_Cmd                     :  2;
    u08 WPC_Device_On_Cmd                :  2;
    u08 RgnTyp_Opt                       :  4;
    u08 SunRoofTyp_Opt                   :  3;
    u08 reserved_72                      :  5;
    u08 reserved_73;
    u08 reserved_74;
} tL_BDC_FD_IAU_10_200ms;

typedef struct
{
    u08 SNI_L_WPC_FD;
    u08 CBV_RMR_L_WPC_FD                 :  1;
    u08 CBV_NMCoID_L_WPC_FD              :  2;
    u08 CBV_NMCoSRB_L_WPC_FD             :  1;
    u08 CBV_AWB_L_WPC_FD                 :  1;
    u08 reserved_75                      :  1;
    u08 CBV_PNIB_L_WPC_FD                :  1;
    u08 reserved_76                      :  1;
    u08 NRR_L_WPC_FD;
    u08 NM_State_L_WPC_FD;
    u32 PNI_L_WPC_FD;
    u08 PNI_L_WPC_FD_1_00;
    u08 PNI_L_WPC_FD_1_01;
    u08 PNI_L_WPC_FD_1_02;
    u08 PNI_L_WPC_FD_1_03;
    u08 PNI_L_WPC_FD_1_04;
    u08 PNI_L_WPC_FD_1_05;
    u08 PNI_L_WPC_FD_1_06;
    u08 PNI_L_WPC_FD_1_07;
    u08 PNI_L_WPC_FD_2_00;
    u08 PNI_L_WPC_FD_2_01;
    u08 PNI_L_WPC_FD_2_02;
    u08 PNI_L_WPC_FD_2_03;
    u08 PNI_L_WPC_FD_2_04;
    u08 PNI_L_WPC_FD_2_05;
    u08 PNI_L_WPC_FD_2_06;
    u08 PNI_L_WPC_FD_2_07;
    u08 PNI_L_WPC_FD_3_00;
    u08 PNI_L_WPC_FD_3_01;
    u08 PNI_L_WPC_FD_3_02;
    u08 PNI_L_WPC_FD_3_03;
    u08 PNI_L_WPC_FD_3_04;
    u08 PNI_L_WPC_FD_3_05;
    u08 PNI_L_WPC_FD_3_06;
    u08 PNI_L_WPC_FD_3_07;
} tNM_L_WPC_FD;

typedef struct
{
    u08 SNI_L_UWB_BLE_MST_FD;
    u08 CBV_RMR_L_UWB_BLE_MST_FD         :  1;
    u08 CBV_NMCoID_L_UWB_BLE_MST_FD      :  2;
    u08 CBV_NMCoSRB_L_UWB_BLE_MST_FD     :  1;
    u08 CBV_AWB_L_UWB_BLE_MST_FD         :  1;
    u08 reserved_77                      :  1;
    u08 CBV_PNIB_L_UWB_BLE_MST_FD        :  1;
    u08 reserved_78                      :  1;
    u08 NRR_L_UWB_BLE_MST_FD;
    u08 NM_State_L_UWB_BLE_MST_FD;
    u32 PNI_L_UWB_BLE_MST_FD;
    u08 PNI_L_UWB_BLE_MST_FD_1_00;
    u08 PNI_L_UWB_BLE_MST_FD_1_01;
    u08 PNI_L_UWB_BLE_MST_FD_1_02;
    u08 PNI_L_UWB_BLE_MST_FD_1_03;
    u08 PNI_L_UWB_BLE_MST_FD_1_04;
    u08 PNI_L_UWB_BLE_MST_FD_1_05;
    u08 PNI_L_UWB_BLE_MST_FD_1_06;
    u08 PNI_L_UWB_BLE_MST_FD_1_07;
    u08 PNI_L_UWB_BLE_MST_FD_2_00;
    u08 PNI_L_UWB_BLE_MST_FD_2_01;
    u08 PNI_L_UWB_BLE_MST_FD_2_02;
    u08 PNI_L_UWB_BLE_MST_FD_2_03;
    u08 PNI_L_UWB_BLE_MST_FD_2_04;
    u08 PNI_L_UWB_BLE_MST_FD_2_05;
    u08 PNI_L_UWB_BLE_MST_FD_2_06;
    u08 PNI_L_UWB_BLE_MST_FD_2_07;
    u08 PNI_L_UWB_BLE_MST_FD_3_00;
    u08 PNI_L_UWB_BLE_MST_FD_3_01;
    u08 PNI_L_UWB_BLE_MST_FD_3_02;
    u08 PNI_L_UWB_BLE_MST_FD_3_03;
    u08 PNI_L_UWB_BLE_MST_FD_3_04;
    u08 PNI_L_UWB_BLE_MST_FD_3_05;
    u08 PNI_L_UWB_BLE_MST_FD_3_06;
    u08 PNI_L_UWB_BLE_MST_FD_3_07;
} tNM_L_UWB_BLE_MST_FD;

typedef struct
{
    u08 SLV_Dvp_Data_00;
    u08 SLV_Dvp_Data_01;
    u08 SLV_Dvp_Data_02;
    u08 SLV_Dvp_Data_03;
    u08 SLV_Dvp_Data_04;
    u08 SLV_Dvp_Data_05;
    u08 SLV_Dvp_Data_06;
    u08 SLV_Dvp_Data_07;
    u08 SLV_Dvp_Data_08;
    u08 SLV_Dvp_Data_09;
    u08 SLV_Dvp_Data_10;
    u08 SLV_Dvp_Data_11;
    u08 SLV_Dvp_Data_12;
    u08 SLV_Dvp_Data_13;
    u08 SLV_Dvp_Data_14;
    u08 SLV_Dvp_Data_15;
    u08 SLV_Dvp_Data_16;
    u08 SLV_Dvp_Data_17;
    u08 SLV_Dvp_Data_18;
    u08 SLV_Dvp_Data_19;
    u08 SLV_Dvp_Data_20;
    u08 SLV_Dvp_Data_21;
    u08 SLV_Dvp_Data_22;
    u08 SLV_Dvp_Data_23;
    u08 SLV_Dvp_Data_24;
    u08 SLV_Dvp_Data_25;
    u08 SLV_Dvp_Data_26;
    u08 SLV_Dvp_Data_27;
    u08 SLV_Dvp_Data_28;
    u08 SLV_Dvp_Data_29;
    u08 SLV_Dvp_Data_30;
    u08 SLV_Dvp_Data_31                  :  7;
    u08 reserved_165                     :  1;
} tL_UWB_BLE_SLV_FD_Dvp_01_00ms;

typedef struct
{
    u16 L_UWB_BLE_SLV_FD_Crc20Val;
    u08 L_UWB_BLE_SLV_FD_AlvCnt20Val;
    u08 SLV_BLE_DK_ID1;
    u08 SLV_BLE_RSSI1;
    u08 SLV_BLE_DK_ID2;
    u08 SLV_BLE_RSSI2;
    u08 SLV_BLE_DK_ID3;
    u08 SLV_BLE_RSSI3;
    u08 SLV_BLE_DK_ID4;
    u08 SLV_BLE_RSSI4;
    u16 SLV_BLE_BTAddIRK_Update;
    u16 SLV_BLE_ConnectedDeviceInfo;
    u32 reserved_166                     :  1;
    u32 SLV_BLE_Passive_ADV_State        :  1;
    u32 SLV_BLE_NewDeviceConnetStatus    :  2;
    u32 SLV_BLE_PairingResult            :  2;
    u32 SLV_BLE_BondingDataStatus_00     :  8;
    u32 SLV_BLE_BondingDataStatus_01     :  8;
    u32 reserved_167                     : 10;
    u08 reserved_168;
    u08 reserved_169;
    u08 reserved_170;
    u08 reserved_171;
    u08 reserved_172;
} tL_UWB_BLE_SLV_FD_20_200ms;

typedef struct
{
    u16 L_UWB_BLE_SLV_FD_Crc21Val;
    u08 L_UWB_BLE_SLV_FD_AlvCnt21Val;
    u08 SLV_UWB_Status1                  :  4;
    u08 SLV_UWB_Status2                  :  4;
    u08 SLV_UWB_Status3                  :  4;
    u08 SLV_UWB_Status4                  :  4;
    u08 SLV_UWB_Status5                  :  4;
    u08 SLV_UWB_Status6                  :  4;
    u08 SLV_UWB_Status7                  :  4;
    u08 SLV_UWB_Status8                  :  4;
    u08 SLV_UWB_Status9                  :  4;
    u08 SLV_UWB_Status10                 :  4;
    u08 SLV_UWB_Status11                 :  4;
    u08 SLV_UWB_Status12                 :  4;
    u08 SLV_UWB_Status13                 :  4;
    u08 SLV_UWB_Status14                 :  4;
    u08 SLV_UWB_Status15                 :  4;
    u08 SLV_UWB_Status16                 :  4;
    u08 SLV_HW_Ver_Major;
    u08 SLV_HW_Ver_Minor;
    u08 SLV_SW_MCU_Ver_Major;
    u08 SLV_SW_MCU_Ver_Minor;
    u08 SLV_SW_UWB_Ver_Major;
    u08 SLV_SW_UWB_Ver_Minor;
    u08 SLV_SW_BLE_Ver_Major;
    u08 SLV_SW_BLE_Ver_Minor;
    u08 SLV_DTC;
    u08 reserved_173;
    u08 reserved_174;
    u08 reserved_175;
    u08 reserved_176;
} tL_UWB_BLE_SLV_FD_21_200ms;

typedef struct
{
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte0;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte1;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte2;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte3;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte4;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte5;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte6;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte7;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte8;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte9;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte10;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte11;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte12;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte13;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte14;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte15;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte16;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte17;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte18;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte19;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte20;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte21;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte22;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte23;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte24;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte25;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte26;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte27;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte28;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte29;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte30;
    u08 L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte31;
} tL_TP_L_UWB_BLE_SLV_FD_BDC_FD;

typedef struct
{
    u08 SNI_L_UWB_BLE_SLV_FD;
    u08 CBV_RMR_L_UWB_BLE_SLV_FD         :  1;
    u08 CBV_NMCoID_L_UWB_BLE_SLV_FD      :  2;
    u08 CBV_NMCoSRB_L_UWB_BLE_SLV_FD     :  1;
    u08 CBV_AWB_L_UWB_BLE_SLV_FD         :  1;
    u08 reserved_177                     :  1;
    u08 CBV_PNIB_L_UWB_BLE_SLV_FD        :  1;
    u08 reserved_178                     :  1;
    u08 NRR_L_UWB_BLE_SLV_FD;
    u08 NM_State_L_UWB_BLE_SLV_FD;
    u32 PNI_L_UWB_BLE_SLV_FD;
    u08 PNI_L_UWB_BLE_SLV_FD_1_00;
    u08 PNI_L_UWB_BLE_SLV_FD_1_01;
    u08 PNI_L_UWB_BLE_SLV_FD_1_02;
    u08 PNI_L_UWB_BLE_SLV_FD_1_03;
    u08 PNI_L_UWB_BLE_SLV_FD_1_04;
    u08 PNI_L_UWB_BLE_SLV_FD_1_05;
    u08 PNI_L_UWB_BLE_SLV_FD_1_06;
    u08 PNI_L_UWB_BLE_SLV_FD_1_07;
    u08 PNI_L_UWB_BLE_SLV_FD_2_00;
    u08 PNI_L_UWB_BLE_SLV_FD_2_01;
    u08 PNI_L_UWB_BLE_SLV_FD_2_02;
    u08 PNI_L_UWB_BLE_SLV_FD_2_03;
    u08 PNI_L_UWB_BLE_SLV_FD_2_04;
    u08 PNI_L_UWB_BLE_SLV_FD_2_05;
    u08 PNI_L_UWB_BLE_SLV_FD_2_06;
    u08 PNI_L_UWB_BLE_SLV_FD_2_07;
    u08 PNI_L_UWB_BLE_SLV_FD_3_00;
    u08 PNI_L_UWB_BLE_SLV_FD_3_01;
    u08 PNI_L_UWB_BLE_SLV_FD_3_02;
    u08 PNI_L_UWB_BLE_SLV_FD_3_03;
    u08 PNI_L_UWB_BLE_SLV_FD_3_04;
    u08 PNI_L_UWB_BLE_SLV_FD_3_05;
    u08 PNI_L_UWB_BLE_SLV_FD_3_06;
    u08 PNI_L_UWB_BLE_SLV_FD_3_07;
} tNM_L_UWB_BLE_SLV_FD;

typedef struct
{
    u08 SNI_L_UWB_FR_FD;
    u08 CBV_RMR_L_UWB_FR_FD              :  1;
    u08 CBV_NMCoID_L_UWB_FR_FD           :  2;
    u08 CBV_NMCoSRB_L_UWB_FR_FD          :  1;
    u08 CBV_AWB_L_UWB_FR_FD              :  1;
    u08 reserved_81                      :  1;
    u08 CBV_PNIB_L_UWB_FR_FD             :  1;
    u08 reserved_82                      :  1;
    u08 NRR_L_UWB_FR_FD;
    u08 NM_State_L_UWB_FR_FD;
    u32 PNI_L_UWB_FR_FD;
    u08 PNI_L_UWB_FR_FD_1_00;
    u08 PNI_L_UWB_FR_FD_1_01;
    u08 PNI_L_UWB_FR_FD_1_02;
    u08 PNI_L_UWB_FR_FD_1_03;
    u08 PNI_L_UWB_FR_FD_1_04;
    u08 PNI_L_UWB_FR_FD_1_05;
    u08 PNI_L_UWB_FR_FD_1_06;
    u08 PNI_L_UWB_FR_FD_1_07;
    u08 PNI_L_UWB_FR_FD_2_00;
    u08 PNI_L_UWB_FR_FD_2_01;
    u08 PNI_L_UWB_FR_FD_2_02;
    u08 PNI_L_UWB_FR_FD_2_03;
    u08 PNI_L_UWB_FR_FD_2_04;
    u08 PNI_L_UWB_FR_FD_2_05;
    u08 PNI_L_UWB_FR_FD_2_06;
    u08 PNI_L_UWB_FR_FD_2_07;
    u08 PNI_L_UWB_FR_FD_3_00;
    u08 PNI_L_UWB_FR_FD_3_01;
    u08 PNI_L_UWB_FR_FD_3_02;
    u08 PNI_L_UWB_FR_FD_3_03;
    u08 PNI_L_UWB_FR_FD_3_04;
    u08 PNI_L_UWB_FR_FD_3_05;
    u08 PNI_L_UWB_FR_FD_3_06;
    u08 PNI_L_UWB_FR_FD_3_07;
} tNM_L_UWB_FR_FD;

typedef struct
{
    u08 SNI_L_UWB_FRNK_FD;
    u08 CBV_RMR_L_UWB_FRNK_FD            :  1;
    u08 CBV_NMCoID_L_UWB_FRNK_FD         :  2;
    u08 CBV_NMCoSRB_L_UWB_FRNK_FD        :  1;
    u08 CBV_AWB_L_UWB_FRNK_FD            :  1;
    u08 reserved_83                      :  1;
    u08 CBV_PNIB_L_UWB_FRNK_FD           :  1;
    u08 reserved_84                      :  1;
    u08 NRR_L_UWB_FRNK_FD;
    u08 NM_State_L_UWB_FRNK_FD;
    u32 PNI_L_UWB_FRNK_FD;
    u08 PNI_L_UWB_FRNK_FD_1_00;
    u08 PNI_L_UWB_FRNK_FD_1_01;
    u08 PNI_L_UWB_FRNK_FD_1_02;
    u08 PNI_L_UWB_FRNK_FD_1_03;
    u08 PNI_L_UWB_FRNK_FD_1_04;
    u08 PNI_L_UWB_FRNK_FD_1_05;
    u08 PNI_L_UWB_FRNK_FD_1_06;
    u08 PNI_L_UWB_FRNK_FD_1_07;
    u08 PNI_L_UWB_FRNK_FD_2_00;
    u08 PNI_L_UWB_FRNK_FD_2_01;
    u08 PNI_L_UWB_FRNK_FD_2_02;
    u08 PNI_L_UWB_FRNK_FD_2_03;
    u08 PNI_L_UWB_FRNK_FD_2_04;
    u08 PNI_L_UWB_FRNK_FD_2_05;
    u08 PNI_L_UWB_FRNK_FD_2_06;
    u08 PNI_L_UWB_FRNK_FD_2_07;
    u08 PNI_L_UWB_FRNK_FD_3_00;
    u08 PNI_L_UWB_FRNK_FD_3_01;
    u08 PNI_L_UWB_FRNK_FD_3_02;
    u08 PNI_L_UWB_FRNK_FD_3_03;
    u08 PNI_L_UWB_FRNK_FD_3_04;
    u08 PNI_L_UWB_FRNK_FD_3_05;
    u08 PNI_L_UWB_FRNK_FD_3_06;
    u08 PNI_L_UWB_FRNK_FD_3_07;
} tNM_L_UWB_FRNK_FD;

typedef struct
{
    u08 SNI_L_UWB_RL_FD;
    u08 CBV_RMR_L_UWB_RL_FD              :  1;
    u08 CBV_NMCoID_L_UWB_RL_FD           :  2;
    u08 CBV_NMCoSRB_L_UWB_RL_FD          :  1;
    u08 CBV_AWB_L_UWB_RL_FD              :  1;
    u08 reserved_85                      :  1;
    u08 CBV_PNIB_L_UWB_RL_FD             :  1;
    u08 reserved_86                      :  1;
    u08 NRR_L_UWB_RL_FD;
    u08 NM_State_L_UWB_RL_FD;
    u32 PNI_L_UWB_RL_FD;
    u08 PNI_L_UWB_RL_FD_1_00;
    u08 PNI_L_UWB_RL_FD_1_01;
    u08 PNI_L_UWB_RL_FD_1_02;
    u08 PNI_L_UWB_RL_FD_1_03;
    u08 PNI_L_UWB_RL_FD_1_04;
    u08 PNI_L_UWB_RL_FD_1_05;
    u08 PNI_L_UWB_RL_FD_1_06;
    u08 PNI_L_UWB_RL_FD_1_07;
    u08 PNI_L_UWB_RL_FD_2_00;
    u08 PNI_L_UWB_RL_FD_2_01;
    u08 PNI_L_UWB_RL_FD_2_02;
    u08 PNI_L_UWB_RL_FD_2_03;
    u08 PNI_L_UWB_RL_FD_2_04;
    u08 PNI_L_UWB_RL_FD_2_05;
    u08 PNI_L_UWB_RL_FD_2_06;
    u08 PNI_L_UWB_RL_FD_2_07;
    u08 PNI_L_UWB_RL_FD_3_00;
    u08 PNI_L_UWB_RL_FD_3_01;
    u08 PNI_L_UWB_RL_FD_3_02;
    u08 PNI_L_UWB_RL_FD_3_03;
    u08 PNI_L_UWB_RL_FD_3_04;
    u08 PNI_L_UWB_RL_FD_3_05;
    u08 PNI_L_UWB_RL_FD_3_06;
    u08 PNI_L_UWB_RL_FD_3_07;
} tNM_L_UWB_RL_FD;

typedef struct
{
    u08 SNI_L_UWB_RR_FD;
    u08 CBV_RMR_L_UWB_RR_FD              :  1;
    u08 CBV_NMCoID_L_UWB_RR_FD           :  2;
    u08 CBV_NMCoSRB_L_UWB_RR_FD          :  1;
    u08 CBV_AWB_L_UWB_RR_FD              :  1;
    u08 reserved_87                      :  1;
    u08 CBV_PNIB_L_UWB_RR_FD             :  1;
    u08 reserved_88                      :  1;
    u08 NRR_L_UWB_RR_FD;
    u08 NM_State_L_UWB_RR_FD;
    u32 PNI_L_UWB_RR_FD;
    u08 PNI_L_UWB_RR_FD_1_00;
    u08 PNI_L_UWB_RR_FD_1_01;
    u08 PNI_L_UWB_RR_FD_1_02;
    u08 PNI_L_UWB_RR_FD_1_03;
    u08 PNI_L_UWB_RR_FD_1_04;
    u08 PNI_L_UWB_RR_FD_1_05;
    u08 PNI_L_UWB_RR_FD_1_06;
    u08 PNI_L_UWB_RR_FD_1_07;
    u08 PNI_L_UWB_RR_FD_2_00;
    u08 PNI_L_UWB_RR_FD_2_01;
    u08 PNI_L_UWB_RR_FD_2_02;
    u08 PNI_L_UWB_RR_FD_2_03;
    u08 PNI_L_UWB_RR_FD_2_04;
    u08 PNI_L_UWB_RR_FD_2_05;
    u08 PNI_L_UWB_RR_FD_2_06;
    u08 PNI_L_UWB_RR_FD_2_07;
    u08 PNI_L_UWB_RR_FD_3_00;
    u08 PNI_L_UWB_RR_FD_3_01;
    u08 PNI_L_UWB_RR_FD_3_02;
    u08 PNI_L_UWB_RR_FD_3_03;
    u08 PNI_L_UWB_RR_FD_3_04;
    u08 PNI_L_UWB_RR_FD_3_05;
    u08 PNI_L_UWB_RR_FD_3_06;
    u08 PNI_L_UWB_RR_FD_3_07;
} tNM_L_UWB_RR_FD;

typedef struct
{
    u08 SNI_L_UWB_TRNK_FD;
    u08 CBV_RMR_L_UWB_TRNK_FD            :  1;
    u08 CBV_NMCoID_L_UWB_TRNK_FD         :  2;
    u08 CBV_NMCoSRB_L_UWB_TRNK_FD        :  1;
    u08 CBV_AWB_L_UWB_TRNK_FD            :  1;
    u08 reserved_89                      :  1;
    u08 CBV_PNIB_L_UWB_TRNK_FD           :  1;
    u08 reserved_90                      :  1;
    u08 NRR_L_UWB_TRNK_FD;
    u08 NM_State_L_UWB_TRNK_FD;
    u32 PNI_L_UWB_TRNK_FD;
    u08 PNI_L_UWB_TRNK_FD_1_00;
    u08 PNI_L_UWB_TRNK_FD_1_01;
    u08 PNI_L_UWB_TRNK_FD_1_02;
    u08 PNI_L_UWB_TRNK_FD_1_03;
    u08 PNI_L_UWB_TRNK_FD_1_04;
    u08 PNI_L_UWB_TRNK_FD_1_05;
    u08 PNI_L_UWB_TRNK_FD_1_06;
    u08 PNI_L_UWB_TRNK_FD_1_07;
    u08 PNI_L_UWB_TRNK_FD_2_00;
    u08 PNI_L_UWB_TRNK_FD_2_01;
    u08 PNI_L_UWB_TRNK_FD_2_02;
    u08 PNI_L_UWB_TRNK_FD_2_03;
    u08 PNI_L_UWB_TRNK_FD_2_04;
    u08 PNI_L_UWB_TRNK_FD_2_05;
    u08 PNI_L_UWB_TRNK_FD_2_06;
    u08 PNI_L_UWB_TRNK_FD_2_07;
    u08 PNI_L_UWB_TRNK_FD_3_00;
    u08 PNI_L_UWB_TRNK_FD_3_01;
    u08 PNI_L_UWB_TRNK_FD_3_02;
    u08 PNI_L_UWB_TRNK_FD_3_03;
    u08 PNI_L_UWB_TRNK_FD_3_04;
    u08 PNI_L_UWB_TRNK_FD_3_05;
    u08 PNI_L_UWB_TRNK_FD_3_06;
    u08 PNI_L_UWB_TRNK_FD_3_07;
} tNM_L_UWB_TRNK_FD;

typedef struct
{
    u08 SNI_L_DHL_FD;
    u08 CBV_RMR_L_DHL_FD                 :  1;
    u08 CBV_NMCoID_L_DHL_FD              :  2;
    u08 CBV_NMCoSRB_L_DHL_FD             :  1;
    u08 CBV_AWB_L_DHL_FD                 :  1;
    u08 reserved_91                      :  1;
    u08 CBV_PNIB_L_DHL_FD                :  1;
    u08 reserved_92                      :  1;
    u08 NRR_L_DHL_FD;
    u08 NM_State_L_DHL_FD;
    u32 PNI_L_DHL_FD;
    u08 PNI_L_DHL_FD_1_00;
    u08 PNI_L_DHL_FD_1_01;
    u08 PNI_L_DHL_FD_1_02;
    u08 PNI_L_DHL_FD_1_03;
    u08 PNI_L_DHL_FD_1_04;
    u08 PNI_L_DHL_FD_1_05;
    u08 PNI_L_DHL_FD_1_06;
    u08 PNI_L_DHL_FD_1_07;
    u08 PNI_L_DHL_FD_2_00;
    u08 PNI_L_DHL_FD_2_01;
    u08 PNI_L_DHL_FD_2_02;
    u08 PNI_L_DHL_FD_2_03;
    u08 PNI_L_DHL_FD_2_04;
    u08 PNI_L_DHL_FD_2_05;
    u08 PNI_L_DHL_FD_2_06;
    u08 PNI_L_DHL_FD_2_07;
    u08 PNI_L_DHL_FD_3_00;
    u08 PNI_L_DHL_FD_3_01;
    u08 PNI_L_DHL_FD_3_02;
    u08 PNI_L_DHL_FD_3_03;
    u08 PNI_L_DHL_FD_3_04;
    u08 PNI_L_DHL_FD_3_05;
    u08 PNI_L_DHL_FD_3_06;
    u08 PNI_L_DHL_FD_3_07;
} tNM_L_DHL_FD;

typedef struct
{
    u08 SNI_L_DHR_FD;
    u08 CBV_RMR_L_DHR_FD                 :  1;
    u08 CBV_NMCoID_L_DHR_FD              :  2;
    u08 CBV_NMCoSRB_L_DHR_FD             :  1;
    u08 CBV_AWB_L_DHR_FD                 :  1;
    u08 reserved_93                      :  1;
    u08 CBV_PNIB_L_DHR_FD                :  1;
    u08 reserved_94                      :  1;
    u08 NRR_L_DHR_FD;
    u08 NM_State_L_DHR_FD;
    u32 PNI_L_DHR_FD;
    u08 PNI_L_DHR_FD_1_00;
    u08 PNI_L_DHR_FD_1_01;
    u08 PNI_L_DHR_FD_1_02;
    u08 PNI_L_DHR_FD_1_03;
    u08 PNI_L_DHR_FD_1_04;
    u08 PNI_L_DHR_FD_1_05;
    u08 PNI_L_DHR_FD_1_06;
    u08 PNI_L_DHR_FD_1_07;
    u08 PNI_L_DHR_FD_2_00;
    u08 PNI_L_DHR_FD_2_01;
    u08 PNI_L_DHR_FD_2_02;
    u08 PNI_L_DHR_FD_2_03;
    u08 PNI_L_DHR_FD_2_04;
    u08 PNI_L_DHR_FD_2_05;
    u08 PNI_L_DHR_FD_2_06;
    u08 PNI_L_DHR_FD_2_07;
    u08 PNI_L_DHR_FD_3_00;
    u08 PNI_L_DHR_FD_3_01;
    u08 PNI_L_DHR_FD_3_02;
    u08 PNI_L_DHR_FD_3_03;
    u08 PNI_L_DHR_FD_3_04;
    u08 PNI_L_DHR_FD_3_05;
    u08 PNI_L_DHR_FD_3_06;
    u08 PNI_L_DHR_FD_3_07;
} tNM_L_DHR_FD;

typedef struct
{
    u08 SNI_L_DHRL_FD;
    u08 CBV_RMR_L_DHRL_FD                :  1;
    u08 CBV_NMCoID_L_DHRL_FD             :  2;
    u08 CBV_NMCoSRB_L_DHRL_FD            :  1;
    u08 CBV_AWB_L_DHRL_FD                :  1;
    u08 reserved_95                      :  1;
    u08 CBV_PNIB_L_DHRL_FD               :  1;
    u08 reserved_96                      :  1;
    u08 NRR_L_DHRL_FD;
    u08 NM_State_L_DHRL_FD;
    u32 PNI_L_DHRL_FD;
    u08 PNI_L_DHRL_FD_1_00;
    u08 PNI_L_DHRL_FD_1_01;
    u08 PNI_L_DHRL_FD_1_02;
    u08 PNI_L_DHRL_FD_1_03;
    u08 PNI_L_DHRL_FD_1_04;
    u08 PNI_L_DHRL_FD_1_05;
    u08 PNI_L_DHRL_FD_1_06;
    u08 PNI_L_DHRL_FD_1_07;
    u08 PNI_L_DHRL_FD_2_00;
    u08 PNI_L_DHRL_FD_2_01;
    u08 PNI_L_DHRL_FD_2_02;
    u08 PNI_L_DHRL_FD_2_03;
    u08 PNI_L_DHRL_FD_2_04;
    u08 PNI_L_DHRL_FD_2_05;
    u08 PNI_L_DHRL_FD_2_06;
    u08 PNI_L_DHRL_FD_2_07;
    u08 PNI_L_DHRL_FD_3_00;
    u08 PNI_L_DHRL_FD_3_01;
    u08 PNI_L_DHRL_FD_3_02;
    u08 PNI_L_DHRL_FD_3_03;
    u08 PNI_L_DHRL_FD_3_04;
    u08 PNI_L_DHRL_FD_3_05;
    u08 PNI_L_DHRL_FD_3_06;
    u08 PNI_L_DHRL_FD_3_07;
} tNM_L_DHRL_FD;

typedef struct
{
    u08 SNI_L_DHRR_FD;
    u08 CBV_RMR_L_DHRR_FD                :  1;
    u08 CBV_NMCoID_L_DHRR_FD             :  2;
    u08 CBV_NMCoSRB_L_DHRR_FD            :  1;
    u08 CBV_AWB_L_DHRR_FD                :  1;
    u08 reserved_97                      :  1;
    u08 CBV_PNIB_L_DHRR_FD               :  1;
    u08 reserved_98                      :  1;
    u08 NRR_L_DHRR_FD;
    u08 NM_State_L_DHRR_FD;
    u32 PNI_L_DHRR_FD;
    u08 PNI_L_DHRR_FD_1_00;
    u08 PNI_L_DHRR_FD_1_01;
    u08 PNI_L_DHRR_FD_1_02;
    u08 PNI_L_DHRR_FD_1_03;
    u08 PNI_L_DHRR_FD_1_04;
    u08 PNI_L_DHRR_FD_1_05;
    u08 PNI_L_DHRR_FD_1_06;
    u08 PNI_L_DHRR_FD_1_07;
    u08 PNI_L_DHRR_FD_2_00;
    u08 PNI_L_DHRR_FD_2_01;
    u08 PNI_L_DHRR_FD_2_02;
    u08 PNI_L_DHRR_FD_2_03;
    u08 PNI_L_DHRR_FD_2_04;
    u08 PNI_L_DHRR_FD_2_05;
    u08 PNI_L_DHRR_FD_2_06;
    u08 PNI_L_DHRR_FD_2_07;
    u08 PNI_L_DHRR_FD_3_00;
    u08 PNI_L_DHRR_FD_3_01;
    u08 PNI_L_DHRR_FD_3_02;
    u08 PNI_L_DHRR_FD_3_03;
    u08 PNI_L_DHRR_FD_3_04;
    u08 PNI_L_DHRR_FD_3_05;
    u08 PNI_L_DHRR_FD_3_06;
    u08 PNI_L_DHRR_FD_3_07;
} tNM_L_DHRR_FD;

typedef struct
{
    u08 SNI_CGW_CCU;
    u08 CBV_RMR_CGW_CCU                  :  1;
    u08 CBV_NMCoID_CGW_CCU               :  2;
    u08 CBV_NMCoSRB_CGW_CCU              :  1;
    u08 CBV_AWB_CGW_CCU                  :  1;
    u08 reserved_99                      :  1;
    u08 CBV_PNIB_CGW_CCU                 :  1;
    u08 reserved_100                     :  1;
    u08 NRR_CGW_CCU;
    u08 NM_State_CGW_CCU;
    u32 PNI_CGW_CCU;
    u08 PNI_CGW_CCU_1_00;
    u08 PNI_CGW_CCU_1_01;
    u08 PNI_CGW_CCU_1_02;
    u08 PNI_CGW_CCU_1_03;
    u08 PNI_CGW_CCU_1_04;
    u08 PNI_CGW_CCU_1_05;
    u08 PNI_CGW_CCU_1_06;
    u08 PNI_CGW_CCU_1_07;
    u08 PNI_CGW_CCU_2_00;
    u08 PNI_CGW_CCU_2_01;
    u08 PNI_CGW_CCU_2_02;
    u08 PNI_CGW_CCU_2_03;
    u08 PNI_CGW_CCU_2_04;
    u08 PNI_CGW_CCU_2_05;
    u08 PNI_CGW_CCU_2_06;
    u08 PNI_CGW_CCU_2_07;
    u08 PNI_CGW_CCU_3_00;
    u08 PNI_CGW_CCU_3_01;
    u08 PNI_CGW_CCU_3_02;
    u08 PNI_CGW_CCU_3_03;
    u08 PNI_CGW_CCU_3_04;
    u08 PNI_CGW_CCU_3_05;
    u08 PNI_CGW_CCU_3_06;
    u08 PNI_CGW_CCU_3_07;
} tNM_CGW_CCU;

typedef struct
{
    u08 SNI_GW_BDC_FD;
    u08 CBV_RMR_GW_BDC_FD                :  1;
    u08 CBV_NMCoID_GW_BDC_FD             :  2;
    u08 CBV_NMCoSRB_GW_BDC_FD            :  1;
    u08 CBV_AWB_GW_BDC_FD                :  1;
    u08 reserved_101                     :  1;
    u08 CBV_PNIB_GW_BDC_FD               :  1;
    u08 reserved_102                     :  1;
    u08 NRR_GW_BDC_FD;
    u08 NM_State_GW_BDC_FD;
    u32 PNI_GW_BDC_FD;
    u08 PNI_GW_BDC_FD_1_00;
    u08 PNI_GW_BDC_FD_1_01;
    u08 PNI_GW_BDC_FD_1_02;
    u08 PNI_GW_BDC_FD_1_03;
    u08 PNI_GW_BDC_FD_1_04;
    u08 PNI_GW_BDC_FD_1_05;
    u08 PNI_GW_BDC_FD_1_06;
    u08 PNI_GW_BDC_FD_1_07;
    u08 PNI_GW_BDC_FD_2_00;
    u08 PNI_GW_BDC_FD_2_01;
    u08 PNI_GW_BDC_FD_2_02;
    u08 PNI_GW_BDC_FD_2_03;
    u08 PNI_GW_BDC_FD_2_04;
    u08 PNI_GW_BDC_FD_2_05;
    u08 PNI_GW_BDC_FD_2_06;
    u08 PNI_GW_BDC_FD_2_07;
    u08 PNI_GW_BDC_FD_3_00;
    u08 PNI_GW_BDC_FD_3_01;
    u08 PNI_GW_BDC_FD_3_02;
    u08 PNI_GW_BDC_FD_3_03;
    u08 PNI_GW_BDC_FD_3_04;
    u08 PNI_GW_BDC_FD_3_05;
    u08 PNI_GW_BDC_FD_3_06;
    u08 PNI_GW_BDC_FD_3_07;
} tNM_GW_BDC_FD;

typedef struct
{
    u08 SNI_L_SAL_FD;
    u08 CBV_RMR_L_SAL_FD                 :  1;
    u08 CBV_NMCoID_L_SAL_FD              :  2;
    u08 CBV_NMCoSRB_L_SAL_FD             :  1;
    u08 CBV_AWB_L_SAL_FD                 :  1;
    u08 reserved_103                     :  1;
    u08 CBV_PNIB_L_SAL_FD                :  1;
    u08 reserved_104                     :  1;
    u08 NRR_L_SAL_FD;
    u08 NM_State_L_SAL_FD;
    u32 PNI_L_SAL_FD;
    u08 PNI_L_SAL_FD_1_00;
    u08 PNI_L_SAL_FD_1_01;
    u08 PNI_L_SAL_FD_1_02;
    u08 PNI_L_SAL_FD_1_03;
    u08 PNI_L_SAL_FD_1_04;
    u08 PNI_L_SAL_FD_1_05;
    u08 PNI_L_SAL_FD_1_06;
    u08 PNI_L_SAL_FD_1_07;
    u08 PNI_L_SAL_FD_2_00;
    u08 PNI_L_SAL_FD_2_01;
    u08 PNI_L_SAL_FD_2_02;
    u08 PNI_L_SAL_FD_2_03;
    u08 PNI_L_SAL_FD_2_04;
    u08 PNI_L_SAL_FD_2_05;
    u08 PNI_L_SAL_FD_2_06;
    u08 PNI_L_SAL_FD_2_07;
    u08 PNI_L_SAL_FD_3_00;
    u08 PNI_L_SAL_FD_3_01;
    u08 PNI_L_SAL_FD_3_02;
    u08 PNI_L_SAL_FD_3_03;
    u08 PNI_L_SAL_FD_3_04;
    u08 PNI_L_SAL_FD_3_05;
    u08 PNI_L_SAL_FD_3_06;
    u08 PNI_L_SAL_FD_3_07;
} tNM_L_SAL_FD;

typedef struct
{
    u16 L_UWB_FD_Crc1Val;
    u08 L_UWB_FD_AlvCnt1Val;
    u08 reserved_105                     :  4;
    u08 UWB_FL_UWB_Decrypt_FB            :  4;
    u08 UWB_FL_MST_Decrypt_FB            :  4;
    u08 UWB_FL_OTA_Rsp                   :  4;
    u08 reserved_106;
    u08 reserved_107;
    u08 reserved_108;
} tL_UWB_FD_01_00ms;

typedef struct
{
    u16 L_UWB_FD_Crc2Val;
    u08 L_UWB_FD_AlvCnt2Val;
    u08 UWB_FL_FOB_RSD_Enc_Result_00;
    u08 UWB_FL_FOB_RSD_Enc_Result_01;
    u08 UWB_FL_FOB_RSD_Enc_Result_02;
    u08 UWB_FL_FOB_RSD_Enc_Result_03;
    u08 UWB_FL_FOB_RSD_Enc_Result_04;
    u08 UWB_FL_FOB_RSD_Enc_Result_05;
    u08 UWB_FL_FOB_RSD_Enc_Result_06;
    u08 UWB_FL_FOB_RSD_Enc_Result_07;
    u08 reserved_109;
    u08 reserved_110;
    u08 reserved_111;
    u08 reserved_112;
    u08 reserved_113;
} tL_UWB_FD_02_00ms;

typedef struct
{
    u16 L_UWB_FD_Crc3Val;
    u08 L_UWB_FD_AlvCnt3Val;
    u08 UWB_FL_Ranging_Enc_Result_00;
    u08 UWB_FL_Ranging_Enc_Result_01;
    u08 UWB_FL_Ranging_Enc_Result_02;
    u08 UWB_FL_Ranging_Enc_Result_03;
    u08 UWB_FL_Ranging_Enc_Result_04;
    u08 UWB_FL_Ranging_Enc_Result_05;
    u08 UWB_FL_Ranging_Enc_Result_06;
    u08 UWB_FL_Ranging_Enc_Result_07;
    u08 UWB_FL_Ranging_Enc_Result_08;
    u08 UWB_FL_Ranging_Enc_Result_09;
    u08 UWB_FL_Ranging_Enc_Result_10;
    u08 UWB_FL_Ranging_Enc_Result_11;
    u08 UWB_FL_Ranging_Enc_Result_12;
    u08 UWB_FL_Ranging_Enc_Result_13;
    u08 UWB_FL_Ranging_Enc_Result_14;
    u08 UWB_FL_Ranging_Enc_Result_15;
    u08 UWB_FL_Ranging_Enc_Result_16;
    u08 UWB_FL_Ranging_Enc_Result_17;
    u08 UWB_FL_Ranging_Enc_Result_18;
    u08 UWB_FL_Ranging_Enc_Result_19;
    u08 UWB_FL_Ranging_Enc_Result_20;
    u08 UWB_FL_Ranging_Enc_Result_21;
    u08 UWB_FL_Ranging_Enc_Result_22;
    u08 UWB_FL_Ranging_Enc_Result_23;
    u08 reserved_114;
    u08 reserved_115;
    u08 reserved_116;
    u08 reserved_117;
    u08 reserved_118;
} tL_UWB_FD_03_00ms;

typedef struct
{
    u08 UWB_FL_Dvp_Data_00;
    u08 UWB_FL_Dvp_Data_01;
    u08 UWB_FL_Dvp_Data_02;
    u08 UWB_FL_Dvp_Data_03;
    u08 UWB_FL_Dvp_Data_04;
    u08 UWB_FL_Dvp_Data_05;
    u08 UWB_FL_Dvp_Data_06;
    u08 UWB_FL_Dvp_Data_07;
    u08 UWB_FL_Dvp_Data_08;
    u08 UWB_FL_Dvp_Data_09;
    u08 UWB_FL_Dvp_Data_10;
    u08 UWB_FL_Dvp_Data_11;
    u08 UWB_FL_Dvp_Data_12;
    u08 UWB_FL_Dvp_Data_13;
    u08 UWB_FL_Dvp_Data_14;
    u08 UWB_FL_Dvp_Data_15;
    u08 UWB_FL_Dvp_Data_16;
    u08 UWB_FL_Dvp_Data_17;
    u08 UWB_FL_Dvp_Data_18;
    u08 UWB_FL_Dvp_Data_19;
    u08 UWB_FL_Dvp_Data_20;
    u08 UWB_FL_Dvp_Data_21;
    u08 UWB_FL_Dvp_Data_22;
    u08 UWB_FL_Dvp_Data_23;
    u08 UWB_FL_Dvp_Data_24;
    u08 UWB_FL_Dvp_Data_25;
    u08 UWB_FL_Dvp_Data_26;
    u08 UWB_FL_Dvp_Data_27;
    u08 UWB_FL_Dvp_Data_28;
    u08 UWB_FL_Dvp_Data_29;
    u08 UWB_FL_Dvp_Data_30;
    u08 UWB_FL_Dvp_Data_31               :  7;
    u08 reserved_119                     :  1;
} tL_UWB_FD_Dvp_01_00ms;

typedef struct
{
    u16 L_UWB_FD_Crc10Val;
    u08 L_UWB_FD_AlvCnt10Val;
    u08 UWB_FL_Status1                   :  4;
    u08 UWB_FL_Status2                   :  4;
    u08 UWB_FL_Status3                   :  4;
    u08 UWB_FL_Status4                   :  4;
    u08 UWB_FL_Status5                   :  4;
    u08 UWB_FL_Status6                   :  4;
    u08 UWB_FL_Status7                   :  4;
    u08 UWB_FL_Status8                   :  4;
    u08 UWB_FL_Status9                   :  4;
    u08 UWB_FL_Status10                  :  4;
    u08 UWB_FL_Status11                  :  4;
    u08 UWB_FL_Status12                  :  4;
    u08 UWB_FL_Status13                  :  4;
    u08 UWB_FL_Status14                  :  4;
    u08 UWB_FL_Status15                  :  4;
    u08 UWB_FL_Status16                  :  4;
    u08 UWB_FL_HW_Ver_Major;
    u08 UWB_FL_HW_Ver_Minor;
    u08 UWB_FL_SW_MCU_Ver_Major;
    u08 UWB_FL_SW_MCU_Ver_Minor;
    u08 UWB_FL_SW_IC_Ver_Major;
    u08 UWB_FL_SW_IC_Ver_Minor;
    u08 UWB_FL_DTC;
    u08 reserved_120;
    u08 reserved_121;
    u08 reserved_122;
    u08 reserved_123;
    u08 reserved_124;
    u08 reserved_125;
} tL_UWB_FD_10_200ms;

typedef struct
{
    u08 SNI_L_UWB_FD;
    u08 CBV_RMR_L_UWB_FD              :  1;
    u08 CBV_NMCoID_L_UWB_FD           :  2;
    u08 CBV_NMCoSRB_L_UWB_FD          :  1;
    u08 CBV_AWB_L_UWB_FD              :  1;
    u08 reserved_126                     :  1;
    u08 CBV_PNIB_L_UWB_FD             :  1;
    u08 reserved_127                     :  1;
    u08 NRR_L_UWB_FD;
    u08 NM_State_L_UWB_FD;
    u32 PNI_L_UWB_FD;
    u08 PNI_L_UWB_FD_1_00;
    u08 PNI_L_UWB_FD_1_01;
    u08 PNI_L_UWB_FD_1_02;
    u08 PNI_L_UWB_FD_1_03;
    u08 PNI_L_UWB_FD_1_04;
    u08 PNI_L_UWB_FD_1_05;
    u08 PNI_L_UWB_FD_1_06;
    u08 PNI_L_UWB_FD_1_07;
    u08 PNI_L_UWB_FD_2_00;
    u08 PNI_L_UWB_FD_2_01;
    u08 PNI_L_UWB_FD_2_02;
    u08 PNI_L_UWB_FD_2_03;
    u08 PNI_L_UWB_FD_2_04;
    u08 PNI_L_UWB_FD_2_05;
    u08 PNI_L_UWB_FD_2_06;
    u08 PNI_L_UWB_FD_2_07;
    u08 PNI_L_UWB_FD_3_00;
    u08 PNI_L_UWB_FD_3_01;
    u08 PNI_L_UWB_FD_3_02;
    u08 PNI_L_UWB_FD_3_03;
    u08 PNI_L_UWB_FD_3_04;
    u08 PNI_L_UWB_FD_3_05;
    u08 PNI_L_UWB_FD_3_06;
    u08 PNI_L_UWB_FD_3_07;
} tNM_L_UWB_FD;

typedef struct
{
    u16 L_UWB_FL_FD_Crc1Val;
    u08 L_UWB_FL_FD_AlvCnt1Val;
    u08 reserved_105                     :  4;
    u08 UWB_FL_UWB_Decrypt_FB            :  4;
    u08 UWB_FL_MST_Decrypt_FB            :  4;
    u08 UWB_FL_OTA_Rsp                   :  4;
    u08 reserved_106;
    u08 reserved_107;
    u08 reserved_108;
} tL_UWB_FL_FD_01_00ms;

typedef struct
{
    u16 L_UWB_FL_FD_Crc2Val;
    u08 L_UWB_FL_FD_AlvCnt2Val;
    u08 UWB_FL_FOB_RSD_Enc_Result_00;
    u08 UWB_FL_FOB_RSD_Enc_Result_01;
    u08 UWB_FL_FOB_RSD_Enc_Result_02;
    u08 UWB_FL_FOB_RSD_Enc_Result_03;
    u08 UWB_FL_FOB_RSD_Enc_Result_04;
    u08 UWB_FL_FOB_RSD_Enc_Result_05;
    u08 UWB_FL_FOB_RSD_Enc_Result_06;
    u08 UWB_FL_FOB_RSD_Enc_Result_07;
    u08 reserved_109;
    u08 reserved_110;
    u08 reserved_111;
    u08 reserved_112;
    u08 reserved_113;
} tL_UWB_FL_FD_02_00ms;

typedef struct
{
    u16 L_UWB_FL_FD_Crc3Val;
    u08 L_UWB_FL_FD_AlvCnt3Val;
    u08 UWB_FL_Ranging_Enc_Result_00;
    u08 UWB_FL_Ranging_Enc_Result_01;
    u08 UWB_FL_Ranging_Enc_Result_02;
    u08 UWB_FL_Ranging_Enc_Result_03;
    u08 UWB_FL_Ranging_Enc_Result_04;
    u08 UWB_FL_Ranging_Enc_Result_05;
    u08 UWB_FL_Ranging_Enc_Result_06;
    u08 UWB_FL_Ranging_Enc_Result_07;
    u08 UWB_FL_Ranging_Enc_Result_08;
    u08 UWB_FL_Ranging_Enc_Result_09;
    u08 UWB_FL_Ranging_Enc_Result_10;
    u08 UWB_FL_Ranging_Enc_Result_11;
    u08 UWB_FL_Ranging_Enc_Result_12;
    u08 UWB_FL_Ranging_Enc_Result_13;
    u08 UWB_FL_Ranging_Enc_Result_14;
    u08 UWB_FL_Ranging_Enc_Result_15;
    u08 UWB_FL_Ranging_Enc_Result_16;
    u08 UWB_FL_Ranging_Enc_Result_17;
    u08 UWB_FL_Ranging_Enc_Result_18;
    u08 UWB_FL_Ranging_Enc_Result_19;
    u08 UWB_FL_Ranging_Enc_Result_20;
    u08 UWB_FL_Ranging_Enc_Result_21;
    u08 UWB_FL_Ranging_Enc_Result_22;
    u08 UWB_FL_Ranging_Enc_Result_23;
    u08 reserved_114;
    u08 reserved_115;
    u08 reserved_116;
    u08 reserved_117;
    u08 reserved_118;
} tL_UWB_FL_FD_03_00ms;

typedef struct
{
    u08 UWB_FL_Dvp_Data_00;
    u08 UWB_FL_Dvp_Data_01;
    u08 UWB_FL_Dvp_Data_02;
    u08 UWB_FL_Dvp_Data_03;
    u08 UWB_FL_Dvp_Data_04;
    u08 UWB_FL_Dvp_Data_05;
    u08 UWB_FL_Dvp_Data_06;
    u08 UWB_FL_Dvp_Data_07;
    u08 UWB_FL_Dvp_Data_08;
    u08 UWB_FL_Dvp_Data_09;
    u08 UWB_FL_Dvp_Data_10;
    u08 UWB_FL_Dvp_Data_11;
    u08 UWB_FL_Dvp_Data_12;
    u08 UWB_FL_Dvp_Data_13;
    u08 UWB_FL_Dvp_Data_14;
    u08 UWB_FL_Dvp_Data_15;
    u08 UWB_FL_Dvp_Data_16;
    u08 UWB_FL_Dvp_Data_17;
    u08 UWB_FL_Dvp_Data_18;
    u08 UWB_FL_Dvp_Data_19;
    u08 UWB_FL_Dvp_Data_20;
    u08 UWB_FL_Dvp_Data_21;
    u08 UWB_FL_Dvp_Data_22;
    u08 UWB_FL_Dvp_Data_23;
    u08 UWB_FL_Dvp_Data_24;
    u08 UWB_FL_Dvp_Data_25;
    u08 UWB_FL_Dvp_Data_26;
    u08 UWB_FL_Dvp_Data_27;
    u08 UWB_FL_Dvp_Data_28;
    u08 UWB_FL_Dvp_Data_29;
    u08 UWB_FL_Dvp_Data_30;
    u08 UWB_FL_Dvp_Data_31               :  7;
    u08 reserved_119                     :  1;
} tL_UWB_FL_FD_Dvp_01_00ms;

typedef struct
{
    u16 L_UWB_FL_FD_Crc10Val;
    u08 L_UWB_FL_FD_AlvCnt10Val;
    u08 UWB_FL_Status1                   :  4;
    u08 UWB_FL_Status2                   :  4;
    u08 UWB_FL_Status3                   :  4;
    u08 UWB_FL_Status4                   :  4;
    u08 UWB_FL_Status5                   :  4;
    u08 UWB_FL_Status6                   :  4;
    u08 UWB_FL_Status7                   :  4;
    u08 UWB_FL_Status8                   :  4;
    u08 UWB_FL_Status9                   :  4;
    u08 UWB_FL_Status10                  :  4;
    u08 UWB_FL_Status11                  :  4;
    u08 UWB_FL_Status12                  :  4;
    u08 UWB_FL_Status13                  :  4;
    u08 UWB_FL_Status14                  :  4;
    u08 UWB_FL_Status15                  :  4;
    u08 UWB_FL_Status16                  :  4;
    u08 UWB_FL_HW_Ver_Major;
    u08 UWB_FL_HW_Ver_Minor;
    u08 UWB_FL_SW_MCU_Ver_Major;
    u08 UWB_FL_SW_MCU_Ver_Minor;
    u08 UWB_FL_SW_IC_Ver_Major;
    u08 UWB_FL_SW_IC_Ver_Minor;
    u08 UWB_FL_DTC;
    u08 reserved_120;
    u08 reserved_121;
    u08 reserved_122;
    u08 reserved_123;
    u08 reserved_124;
    u08 reserved_125;
} tL_UWB_FL_FD_10_200ms;

typedef struct
{
    u08 SNI_L_UWB_FL_FD;
    u08 CBV_RMR_L_UWB_FL_FD              :  1;
    u08 CBV_NMCoID_L_UWB_FL_FD           :  2;
    u08 CBV_NMCoSRB_L_UWB_FL_FD          :  1;
    u08 CBV_AWB_L_UWB_FL_FD              :  1;
    u08 reserved_126                     :  1;
    u08 CBV_PNIB_L_UWB_FL_FD             :  1;
    u08 reserved_127                     :  1;
    u08 NRR_L_UWB_FL_FD;
    u08 NM_State_L_UWB_FL_FD;
    u32 PNI_L_UWB_FL_FD;
    u08 PNI_L_UWB_FL_FD_1_00;
    u08 PNI_L_UWB_FL_FD_1_01;
    u08 PNI_L_UWB_FL_FD_1_02;
    u08 PNI_L_UWB_FL_FD_1_03;
    u08 PNI_L_UWB_FL_FD_1_04;
    u08 PNI_L_UWB_FL_FD_1_05;
    u08 PNI_L_UWB_FL_FD_1_06;
    u08 PNI_L_UWB_FL_FD_1_07;
    u08 PNI_L_UWB_FL_FD_2_00;
    u08 PNI_L_UWB_FL_FD_2_01;
    u08 PNI_L_UWB_FL_FD_2_02;
    u08 PNI_L_UWB_FL_FD_2_03;
    u08 PNI_L_UWB_FL_FD_2_04;
    u08 PNI_L_UWB_FL_FD_2_05;
    u08 PNI_L_UWB_FL_FD_2_06;
    u08 PNI_L_UWB_FL_FD_2_07;
    u08 PNI_L_UWB_FL_FD_3_00;
    u08 PNI_L_UWB_FL_FD_3_01;
    u08 PNI_L_UWB_FL_FD_3_02;
    u08 PNI_L_UWB_FL_FD_3_03;
    u08 PNI_L_UWB_FL_FD_3_04;
    u08 PNI_L_UWB_FL_FD_3_05;
    u08 PNI_L_UWB_FL_FD_3_06;
    u08 PNI_L_UWB_FL_FD_3_07;
} tNM_L_UWB_FL_FD;
#pragma pack(pop)


/*****************************************************************************
* CONSTANT DEFINITIONS
*****************************************************************************/
/* N/A */

/*****************************************************************************
* GLOBAL VARIABLE DEFINITIONS AND PROTOTYPES
*****************************************************************************/
/*! /brief Export variables */
extern const u32 cgCanMsgIds_SLAVE[SLAVE_CANMSG_MAX];
extern const u16 cgCanMsgFlags1_SLAVE[SLAVE_CANMSG_MAX];
extern const u08 cgCanMsgRepeat_SLAVE[SLAVE_CANMSG_MAX];
extern const u32 cgCanMsgCycle_SLAVE[SLAVE_CANMSG_MAX];
extern const u32 cgCanMsgCycleFast_SLAVE[SLAVE_CANMSG_MAX];
extern const u32 cgCanMsgDelay_SLAVE[SLAVE_CANMSG_MAX];
///extern tCanFrameBuffer gCanMsg_SLAVE[SLAVE_CANMSG_MAX];
extern u08 * const cgCanMsg_SLAVE[SLAVE_CANMSG_MAX];
extern const u08 * const cgCanMsgInitValue_SLAVE[SLAVE_CANMSG_MAX];
extern const u08 * const cgCanMsgInvalidValue_SLAVE[SLAVE_CANMSG_MAX];

extern const u32 cgCanMsgIds_FL[ANCHOR_CANMSG_MAX];
extern const u32 cgCanMsgIds_FR[ANCHOR_CANMSG_MAX];
extern const u32 cgCanMsgIds_RL[ANCHOR_CANMSG_MAX];
extern const u32 cgCanMsgIds_RR[ANCHOR_CANMSG_MAX];
extern const u16 cgCanMsgFlags1_ANCHOR[ANCHOR_CANMSG_MAX];
extern const u08 cgCanMsgRepeat_ANCHOR[ANCHOR_CANMSG_MAX];
extern const u32 cgCanMsgCycle_ANCHOR[ANCHOR_CANMSG_MAX];
extern const u32 cgCanMsgCycleFast_ANCHOR[ANCHOR_CANMSG_MAX];
extern const u32 cgCanMsgDelay_ANCHOR[ANCHOR_CANMSG_MAX];
///extern tCanFrameBuffer gCanMsg_ANCHOR[ANCHOR_CANMSG_MAX];
extern u08 * const cgCanMsg_ANCHOR[ANCHOR_CANMSG_MAX];
extern const u08 * const cgCanMsgInitValue_ANCHOR[ANCHOR_CANMSG_MAX];
extern const u08 * const cgCanMsgInvalidValue_ANCHOR[ANCHOR_CANMSG_MAX];

extern tIAU_FD_04_200ms                gIAU_FD_04_200ms;
extern tIAU_FD_05_200ms                gIAU_FD_05_200ms;
extern tBDC_FD_02_200ms                gBDC_FD_02_200ms;
extern tCCU_01_00ms                    gCCU_01_00ms;
extern tL_BDC_FD_IAU_02_00ms           gL_BDC_FD_IAU_02_00ms;
extern tL_BDC_FD_IAU_03_00ms           gL_BDC_FD_IAU_03_00ms;
extern tL_BDC_FD_IAU_04_00ms           gL_BDC_FD_IAU_04_00ms;
extern tL_BDC_FD_IAU_05_00ms           gL_BDC_FD_IAU_05_00ms;
extern tL_BDC_FD_IAU_06_00ms           gL_BDC_FD_IAU_06_00ms;
extern tL_BDC_FD_IAU_07_00ms           gL_BDC_FD_IAU_07_00ms;
extern tL_UWB_BLE_MST_FD_01_00ms       gL_UWB_BLE_MST_FD_01_00ms;
extern tL_UWB_BLE_MST_FD_04_00ms       gL_UWB_BLE_MST_FD_04_00ms;
extern tL_UWB_BLE_MST_FD_05_00ms       gL_UWB_BLE_MST_FD_05_00ms;
extern tL_UWB_BLE_MST_FD_06_00ms       gL_UWB_BLE_MST_FD_06_00ms;
extern tL_UWB_BLE_MST_FD_07_00ms       gL_UWB_BLE_MST_FD_07_00ms;
extern tL_UWB_BLE_MST_FD_08_00ms       gL_UWB_BLE_MST_FD_08_00ms;
extern tL_UWB_BLE_MST_FD_09_00ms       gL_UWB_BLE_MST_FD_09_00ms;
extern tL_UWB_BLE_MST_FD_14_00ms       gL_UWB_BLE_MST_FD_14_00ms;
extern tL_UWB_BLE_MST_FD_15_00ms       gL_UWB_BLE_MST_FD_15_00ms;
extern tL_UWB_BLE_SLV_FD_04_00ms       gL_UWB_BLE_SLV_FD_04_00ms;
extern tL_UWB_BLE_SLV_FD_05_00ms       gL_UWB_BLE_SLV_FD_05_00ms;
extern tL_UWB_BLE_SLV_FD_06_00ms       gL_UWB_BLE_SLV_FD_06_00ms;
extern tL_UWB_BLE_SLV_FD_07_00ms       gL_UWB_BLE_SLV_FD_07_00ms;
extern tL_UWB_BLE_SLV_FD_08_00ms       gL_UWB_BLE_SLV_FD_08_00ms;
extern tL_EDT_FD_BLE_Dvp_01_00ms       gL_EDT_FD_BLE_Dvp_01_00ms;
extern tL_EDT_FD_DH_Dvp_02_00ms        gL_EDT_FD_DH_Dvp_02_00ms;
extern tL_EDT_FD_UWB_Dvp_03_00ms       gL_EDT_FD_UWB_Dvp_03_00ms;
extern tL_BDC_FD_IAU_10_200ms          gL_BDC_FD_IAU_10_200ms;
extern tL_BDC_FD_ROA_01_200ms          gL_BDC_FD_ROA_01_200ms;
extern tL_UWB_BLE_MST_FD_20_200ms      gL_UWB_BLE_MST_FD_20_200ms;
extern tL_TP_BDC_FD_L_UWB_BLE_SLV_FD   gL_TP_BDC_FD_L_UWB_BLE_SLV_FD;
extern tNM_L_WPC_FD                    gNM_L_WPC_FD;
extern tNM_L_UWB_BLE_MST_FD            gNM_L_UWB_BLE_MST_FD;
extern tNM_L_UWB_BLE_SLV_FD            gNM_L_UWB_BLE_SLV_FD;
extern tNM_L_UWB_FD                    gNM_L_UWB_FD;
extern tNM_L_UWB_FL_FD                 gNM_L_UWB_FL_FD;
extern tNM_L_UWB_FR_FD                 gNM_L_UWB_FR_FD;
extern tNM_L_UWB_FRNK_FD               gNM_L_UWB_FRNK_FD;
extern tNM_L_UWB_RL_FD                 gNM_L_UWB_RL_FD;
extern tNM_L_UWB_RR_FD                 gNM_L_UWB_RR_FD;
extern tNM_L_UWB_TRNK_FD               gNM_L_UWB_TRNK_FD;
extern tNM_L_DHL_FD                    gNM_L_DHL_FD;
extern tNM_L_DHR_FD                    gNM_L_DHR_FD;
extern tNM_L_DHRL_FD                   gNM_L_DHRL_FD;
extern tNM_L_DHRR_FD                   gNM_L_DHRR_FD;
extern tNM_CGW_CCU                     gNM_CGW_CCU;
extern tNM_GW_BDC_FD                   gNM_GW_BDC_FD;
extern tNM_L_SAL_FD                    gNM_L_SAL_FD;
extern tL_UWB_FD_01_00ms               gL_UWB_FD_01_00ms;
extern tL_UWB_FD_02_00ms               gL_UWB_FD_02_00ms;
extern tL_UWB_FD_03_00ms               gL_UWB_FD_03_00ms;
extern tL_UWB_BLE_SLV_FD_01_00ms       gL_UWB_BLE_SLV_FD_01_00ms;
extern tL_UWB_BLE_SLV_FD_02_00ms       gL_UWB_BLE_SLV_FD_02_00ms;
extern tL_UWB_BLE_SLV_FD_03_00ms       gL_UWB_BLE_SLV_FD_03_00ms;
extern tL_UWB_BLE_SLV_FD_04_00ms       gL_UWB_BLE_SLV_FD_04_00ms;
extern tL_UWB_BLE_SLV_FD_05_00ms       gL_UWB_BLE_SLV_FD_05_00ms;
extern tL_UWB_BLE_SLV_FD_06_00ms       gL_UWB_BLE_SLV_FD_06_00ms;
extern tL_UWB_BLE_SLV_FD_07_00ms       gL_UWB_BLE_SLV_FD_07_00ms;
extern tL_UWB_BLE_SLV_FD_08_00ms       gL_UWB_BLE_SLV_FD_08_00ms;
extern tL_UWB_FD_Dvp_01_00ms           gL_UWB_FD_Dvp_01_00ms;
extern tL_UWB_FD_10_200ms              gL_UWB_FD_10_200ms;
extern tL_UWB_BLE_SLV_FD_Dvp_01_00ms   gL_UWB_BLE_SLV_FD_Dvp_01_00ms;
extern tL_UWB_BLE_SLV_FD_20_200ms      gL_UWB_BLE_SLV_FD_20_200ms;
extern tL_UWB_BLE_SLV_FD_21_200ms      gL_UWB_BLE_SLV_FD_21_200ms;
extern tL_TP_L_UWB_BLE_SLV_FD_BDC_FD   gL_TP_L_UWB_BLE_SLV_FD_BDC_FD;
extern tNM_L_UWB_FD                    gNM_L_UWB_FD;
extern tNM_L_UWB_BLE_SLV_FD            gNM_L_UWB_BLE_SLV_FD;



/*****************************************************************************
* STATIC VARIABLE DEFINITIONS
*****************************************************************************/
/* N/A */

/*****************************************************************************
* FUNCTION PROTOTYPES
*****************************************************************************/
void CanMsg_Init(void);
void CanMsg_DeInit(void);

/*! /brief Prototype of Signal Access Function */
u16 IlGetRxSLAVE_IAU_FD_Crc4Val(void);
void IlPutRxSLAVE_IAU_FD_Crc4Val(u16 sigData);

u08 IlGetRxSLAVE_IAU_FD_AlvCnt4Val(void);
void IlPutRxSLAVE_IAU_FD_AlvCnt4Val(u08 sigData);

u08 IlGetRxSLAVE_IAU_StartIdentifiedProfile_Ext(void);
void IlPutRxSLAVE_IAU_StartIdentifiedProfile_Ext(u08 sigData);

u08 IlGetRxSLAVE_IAU_ProfileIDRVal(void);
void IlPutRxSLAVE_IAU_ProfileIDRVal(u08 sigData);

u08 IlGetRxSLAVE_IAU_DigitalKeyProcessingSta(void);
void IlPutRxSLAVE_IAU_DigitalKeyProcessingSta(u08 sigData);

u08 IlGetRxSLAVE_IAU_DigitalKeyExit(void);
void IlPutRxSLAVE_IAU_DigitalKeyExit(u08 sigData);

u08 IlGetRxSLAVE_IAU_DigitalKeyEnblRVal(void);
void IlPutRxSLAVE_IAU_DigitalKeyEnblRVal(u08 sigData);

u08 IlGetRxSLAVE_IAU_OwnerPhnRegRVal(void);
void IlPutRxSLAVE_IAU_OwnerPhnRegRVal(u08 sigData);

u08 IlGetRxSLAVE_IAU_NFCCard1RegRVal(void);
void IlPutRxSLAVE_IAU_NFCCard1RegRVal(u08 sigData);

u08 IlGetRxSLAVE_IAU_NFCCard2RegRVal(void);
void IlPutRxSLAVE_IAU_NFCCard2RegRVal(u08 sigData);

u08 IlGetRxSLAVE_IAU_DISPWrng(void);
void IlPutRxSLAVE_IAU_DISPWrng(u08 sigData);

u08 IlGetRxSLAVE_IAU_DigitalKey2Opt(void);
void IlPutRxSLAVE_IAU_DigitalKey2Opt(u08 sigData);

u08 IlGetRxSLAVE_IAUwFRULearnState(void);
void IlPutRxSLAVE_IAUwFRULearnState(u08 sigData);

u08 IlGetRxSLAVE_IAUwFPMLearnState(void);
void IlPutRxSLAVE_IAUwFPMLearnState(u08 sigData);

u08 IlGetRxSLAVE_IAU_ValetDigitalkey(void);
void IlPutRxSLAVE_IAU_ValetDigitalkey(u08 sigData);

u08 IlGetRxSLAVE_IAU_DigitalKeyNumberOpt(void);
void IlPutRxSLAVE_IAU_DigitalKeyNumberOpt(u08 sigData);

u08 IlGetRxSLAVE_IAU_eSEReprogramSta(void);
void IlPutRxSLAVE_IAU_eSEReprogramSta(u08 sigData);

u08 IlGetRxSLAVE_IAU_DgtKeyGrpPrflRval2(void);
void IlPutRxSLAVE_IAU_DgtKeyGrpPrflRval2(u08 sigData);

u08 IlGetRxSLAVE_IAU_StartIdentifiedProfile(void);
void IlPutRxSLAVE_IAU_StartIdentifiedProfile(u08 sigData);

u08 IlGetRxSLAVE_IAU_DigitalKeyProfileRval2(void);
void IlPutRxSLAVE_IAU_DigitalKeyProfileRval2(u08 sigData);

u32 IlGetRxSLAVE_IAU_NFCCard1SN(void);
void IlPutRxSLAVE_IAU_NFCCard1SN(u32 sigData);

u08 IlGetRxSLAVE_RSPA_UWBRspaExtRngSta(void);
void IlPutRxSLAVE_RSPA_UWBRspaExtRngSta(u08 sigData);

u08 IlGetRxSLAVE_RSPA_CanFltSta(void);
void IlPutRxSLAVE_RSPA_CanFltSta(u08 sigData);

u08 IlGetRxSLAVE_RSPA_BLESigErrSta(void);
void IlPutRxSLAVE_RSPA_BLESigErrSta(u08 sigData);

u08 IlGetRxSLAVE_RSPA_ConStat(void);
void IlPutRxSLAVE_RSPA_ConStat(u08 sigData);

u16 IlGetRxSLAVE_IAU_FD_Crc5Val(void);
void IlPutRxSLAVE_IAU_FD_Crc5Val(u16 sigData);

u08 IlGetRxSLAVE_IAU_FD_AlvCnt5Val(void);
void IlPutRxSLAVE_IAU_FD_AlvCnt5Val(u08 sigData);

u08 IlGetRxSLAVE_IAU_DigitalKeyProfileRval(void);
void IlPutRxSLAVE_IAU_DigitalKeyProfileRval(u08 sigData);

u08 IlGetRxSLAVE_IAU_SharedPhnRegStat(void);
void IlPutRxSLAVE_IAU_SharedPhnRegStat(u08 sigData);

u08 IlGetRxSLAVE_IAU_CardKeyEnblRVal(void);
void IlPutRxSLAVE_IAU_CardKeyEnblRVal(u08 sigData);

u08 IlGetRxSLAVE_IAU_DrvDHLPhnDetect(void);
void IlPutRxSLAVE_IAU_DrvDHLPhnDetect(u08 sigData);

u08 IlGetRxSLAVE_IAU_AstDHLPhnDetect(void);
void IlPutRxSLAVE_IAU_AstDHLPhnDetect(u08 sigData);

u08 IlGetRxSLAVE_IAU_RLDHLPhnDetect(void);
void IlPutRxSLAVE_IAU_RLDHLPhnDetect(u08 sigData);

u08 IlGetRxSLAVE_IAU_RRDHLPhnDetect(void);
void IlPutRxSLAVE_IAU_RRDHLPhnDetect(u08 sigData);

u08 IlGetRxSLAVE_IAU_Manufacturer(void);
void IlPutRxSLAVE_IAU_Manufacturer(u08 sigData);

u08 IlGetRxSLAVE_IAU_VendorCode_00(void);
void IlPutRxSLAVE_IAU_VendorCode_00(u08 sigData);

u08 IlGetRxSLAVE_IAU_VendorCode_01(void);
void IlPutRxSLAVE_IAU_VendorCode_01(u08 sigData);

u08 IlGetRxSLAVE_IAU_VendorCode_02(void);
void IlPutRxSLAVE_IAU_VendorCode_02(u08 sigData);

u32 IlGetRxSLAVE_IAU_Serial(void);
void IlPutRxSLAVE_IAU_Serial(u32 sigData);

u16 IlGetRxSLAVE_IAU_Year(void);
void IlPutRxSLAVE_IAU_Year(u16 sigData);

u08 IlGetRxSLAVE_IAU_Month(void);
void IlPutRxSLAVE_IAU_Month(u08 sigData);

u16 IlGetRxSLAVE_IAU_Date(void);
void IlPutRxSLAVE_IAU_Date(u16 sigData);

u08 IlGetRxSLAVE_IAU_SWVerMajor1(void);
void IlPutRxSLAVE_IAU_SWVerMajor1(u08 sigData);

u08 IlGetRxSLAVE_IAU_SWVerMinor1(void);
void IlPutRxSLAVE_IAU_SWVerMinor1(u08 sigData);

u08 IlGetRxSLAVE_IAU_SWVerMinor2(void);
void IlPutRxSLAVE_IAU_SWVerMinor2(u08 sigData);

u16 IlGetRxSLAVE_BDC_FD_Crc2Val(void);
void IlPutRxSLAVE_BDC_FD_Crc2Val(u16 sigData);

u08 IlGetRxSLAVE_BDC_FD_AlvCnt2Val(void);
void IlPutRxSLAVE_BDC_FD_AlvCnt2Val(u08 sigData);

u08 IlGetRxSLAVE_BCM_KeyInSta(void);
void IlPutRxSLAVE_BCM_KeyInSta(u08 sigData);

u08 IlGetRxSLAVE_BCM_AccInSta(void);
void IlPutRxSLAVE_BCM_AccInSta(u08 sigData);

u08 IlGetRxSLAVE_BCM_Ign1InSta(void);
void IlPutRxSLAVE_BCM_Ign1InSta(u08 sigData);

u08 IlGetRxSLAVE_BCM_Ign2InSta(void);
void IlPutRxSLAVE_BCM_Ign2InSta(u08 sigData);

u08 IlGetRxSLAVE_IBU_HDPSpprtSWVer(void);
void IlPutRxSLAVE_IBU_HDPSpprtSWVer(u08 sigData);

u08 IlGetRxSLAVE_IBU_HDPSpprtRdy(void);
void IlPutRxSLAVE_IBU_HDPSpprtRdy(u08 sigData);

u08 IlGetRxSLAVE_BCM_GearPosPSta(void);
void IlPutRxSLAVE_BCM_GearPosPSta(u08 sigData);

u08 IlGetRxSLAVE_BCM_SmkOptTyp(void);
void IlPutRxSLAVE_BCM_SmkOptTyp(u08 sigData);

u08 IlGetRxSLAVE_IBU_SWVerMajor1(void);
void IlPutRxSLAVE_IBU_SWVerMajor1(u08 sigData);

u08 IlGetRxSLAVE_IBU_SWVerMinor1(void);
void IlPutRxSLAVE_IBU_SWVerMinor1(u08 sigData);

u08 IlGetRxSLAVE_IBU_SWVerMinor2(void);
void IlPutRxSLAVE_IBU_SWVerMinor2(u08 sigData);

u08 IlGetRxSLAVE_BDC_PlatformVerType(void);
void IlPutRxSLAVE_BDC_PlatformVerType(u08 sigData);

u08 IlGetRxSLAVE_BDC_PlatformVerDate(void);
void IlPutRxSLAVE_BDC_PlatformVerDate(u08 sigData);

u08 IlGetRxSLAVE_CCU_01_Crc1Val(void);
void IlPutRxSLAVE_CCU_01_Crc1Val(u08 sigData);

u08 IlGetRxSLAVE_CCU_ForcedPowerOffReq(void);
void IlPutRxSLAVE_CCU_ForcedPowerOffReq(u08 sigData);

u08 IlGetRxSLAVE_CCU_01_AlvCnt1Val(void);
void IlPutRxSLAVE_CCU_01_AlvCnt1Val(u08 sigData);

u08 IlGetRxSLAVE_BDC_RndNum_Trgt(void);
void IlPutRxSLAVE_BDC_RndNum_Trgt(u08 sigData);

u08 IlGetRxSLAVE_BDC_RndNum_TRCod(void);
void IlPutRxSLAVE_BDC_RndNum_TRCod(u08 sigData);

u08 IlGetRxSLAVE_BDC_RndNum_Cmd(void);
void IlPutRxSLAVE_BDC_RndNum_Cmd(u08 sigData);

u08 IlGetRxSLAVE_BDC_RndNum_00(void);
void IlPutRxSLAVE_BDC_RndNum_00(u08 sigData);

u08 IlGetRxSLAVE_BDC_RndNum_01(void);
void IlPutRxSLAVE_BDC_RndNum_01(u08 sigData);

u08 IlGetRxSLAVE_BDC_RndNum_02(void);
void IlPutRxSLAVE_BDC_RndNum_02(u08 sigData);

u08 IlGetRxSLAVE_BDC_RndNum_03(void);
void IlPutRxSLAVE_BDC_RndNum_03(u08 sigData);

u08 IlGetRxSLAVE_BDC_RndNum_04(void);
void IlPutRxSLAVE_BDC_RndNum_04(u08 sigData);

u08 IlGetRxSLAVE_BDC_RndNum_05(void);
void IlPutRxSLAVE_BDC_RndNum_05(u08 sigData);

u08 IlGetRxSLAVE_BDC_Decrypt_FB(void);
void IlPutRxSLAVE_BDC_Decrypt_FB(u08 sigData);

u08 IlGetRxSLAVE_DKID_Set(void);
void IlPutRxSLAVE_DKID_Set(u08 sigData);

u08 IlGetRxSLAVE_DKID_Del(void);
void IlPutRxSLAVE_DKID_Del(u08 sigData);

u08 IlGetRxSLAVE_UWB_Ranging_Cmd_DKID(void);
void IlPutRxSLAVE_UWB_Ranging_Cmd_DKID(u08 sigData);

u08 IlGetRxSLAVE_UWB_Ranging_Cmd_Val(void);
void IlPutRxSLAVE_UWB_Ranging_Cmd_Val(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_00(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_00(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_01(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_01(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_02(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_02(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_03(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_03(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_04(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_04(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_05(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_05(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_06(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_06(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_07(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_07(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_08(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_08(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_09(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_09(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_10(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_10(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_11(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_11(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_12(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_12(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_13(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_13(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_14(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_14(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_15(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_15(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_16(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_16(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_17(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_17(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_18(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_18(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_19(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_19(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_20(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_20(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_21(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_21(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_22(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_22(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_23(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_23(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_24(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_24(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_25(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_25(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_26(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_26(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_27(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_27(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data1_28(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data1_28(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_00(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_00(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_01(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_01(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_02(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_02(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_03(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_03(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_04(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_04(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_05(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_05(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_06(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_06(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_07(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_07(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_08(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_08(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_09(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_09(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_10(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_10(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_11(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_11(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_12(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_12(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_13(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_13(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_14(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_14(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_15(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_15(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_16(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_16(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_17(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_17(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_18(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_18(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_19(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_19(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_20(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_20(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_21(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_21(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_22(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_22(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_23(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_23(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_24(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_24(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_25(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_25(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_26(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_26(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_27(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_27(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_BLE_Enc_Data2_28(void);
void IlPutRxSLAVE_BDC_To_BLE_Enc_Data2_28(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_00(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_00(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_01(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_01(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_02(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_02(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_03(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_03(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_04(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_04(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_05(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_05(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_06(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_06(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_07(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_07(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_08(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_08(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_09(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_09(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_10(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_10(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_11(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_11(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_12(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_12(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_13(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_13(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_14(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_14(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_15(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_15(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_16(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_16(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_17(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_17(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_18(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_18(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_19(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_19(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_20(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_20(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_21(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_21(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_22(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_22(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_23(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_23(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_24(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_24(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_25(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_25(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_26(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_26(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_27(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_27(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data1_28(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data1_28(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_00(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_00(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_01(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_01(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_02(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_02(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_03(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_03(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_04(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_04(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_05(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_05(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_06(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_06(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_07(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_07(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_08(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_08(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_09(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_09(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_10(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_10(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_11(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_11(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_12(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_12(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_13(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_13(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_14(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_14(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_15(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_15(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_16(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_16(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_17(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_17(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_18(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_18(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_19(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_19(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_20(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_20(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_21(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_21(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_22(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_22(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_23(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_23(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_24(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_24(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_25(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_25(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_26(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_26(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_27(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_27(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data2_28(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data2_28(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_00(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_00(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_01(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_01(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_02(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_02(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_03(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_03(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_04(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_04(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_05(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_05(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_06(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_06(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_07(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_07(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_08(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_08(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_09(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_09(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_10(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_10(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_11(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_11(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_12(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_12(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_13(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_13(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_14(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_14(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_15(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_15(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_16(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_16(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_17(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_17(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_18(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_18(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_19(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_19(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_20(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_20(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_21(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_21(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_22(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_22(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_23(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_23(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_24(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_24(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_25(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_25(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_26(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_26(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_27(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_27(u08 sigData);

u08 IlGetRxSLAVE_BDC_To_UWB_Enc_Data3_28(void);
void IlPutRxSLAVE_BDC_To_UWB_Enc_Data3_28(u08 sigData);

u16 IlGetRxSLAVE_L_UWB_BLE_MST_FD_Crc1Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_Crc1Val(u16 sigData);

u08 IlGetRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt1Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt1Val(u08 sigData);

u08 IlGetRxSLAVE_MST_BLE_Decrypt_FB(void);
void IlPutRxSLAVE_MST_BLE_Decrypt_FB(u08 sigData);

u08 IlGetRxSLAVE_MST_UWB_Decrypt_FB(void);
void IlPutRxSLAVE_MST_UWB_Decrypt_FB(u08 sigData);

u08 IlGetRxSLAVE_MST_SLV_Decrypt_FB(void);
void IlPutRxSLAVE_MST_SLV_Decrypt_FB(u08 sigData);

u08 IlGetRxSLAVE_MST_OTA_Status(void);
void IlPutRxSLAVE_MST_OTA_Status(u08 sigData);

u16 IlGetRxSLAVE_L_UWB_BLE_MST_FD_Crc4Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_Crc4Val(u16 sigData);

u08 IlGetRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt4Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt4Val(u08 sigData);

u08 IlGetRxSLAVE_MST_RndNum_Trgt(void);
void IlPutRxSLAVE_MST_RndNum_Trgt(u08 sigData);

u08 IlGetRxSLAVE_MST_RndNum_TRCode(void);
void IlPutRxSLAVE_MST_RndNum_TRCode(u08 sigData);

u08 IlGetRxSLAVE_MST_RndNum_Cmd(void);
void IlPutRxSLAVE_MST_RndNum_Cmd(u08 sigData);

u08 IlGetRxSLAVE_MST_RndNum_00(void);
void IlPutRxSLAVE_MST_RndNum_00(u08 sigData);

u08 IlGetRxSLAVE_MST_RndNum_01(void);
void IlPutRxSLAVE_MST_RndNum_01(u08 sigData);

u08 IlGetRxSLAVE_MST_RndNum_02(void);
void IlPutRxSLAVE_MST_RndNum_02(u08 sigData);

u08 IlGetRxSLAVE_MST_RndNum_03(void);
void IlPutRxSLAVE_MST_RndNum_03(u08 sigData);

u08 IlGetRxSLAVE_MST_RndNum_04(void);
void IlPutRxSLAVE_MST_RndNum_04(u08 sigData);

u08 IlGetRxSLAVE_MST_RndNum_05(void);
void IlPutRxSLAVE_MST_RndNum_05(u08 sigData);

u16 IlGetRxSLAVE_L_UWB_BLE_MST_FD_Crc5Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_Crc5Val(u16 sigData);

u08 IlGetRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt5Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt5Val(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_00(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_00(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_01(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_01(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_02(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_02(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_03(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_03(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_04(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_04(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_05(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_05(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_06(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_06(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_07(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_07(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_08(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_08(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_09(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_09(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_10(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_10(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_11(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_11(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_12(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_12(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_13(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_13(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_14(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_14(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_15(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_15(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_16(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_16(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_17(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_17(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_18(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_18(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_19(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_19(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_20(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_20(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_21(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_21(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_22(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_22(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_23(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_23(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_24(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_24(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_25(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_25(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_26(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_26(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_27(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_27(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data1_28(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data1_28(u08 sigData);

u16 IlGetRxSLAVE_L_UWB_BLE_MST_FD_Crc6Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_Crc6Val(u16 sigData);

u08 IlGetRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt6Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt6Val(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_00(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_00(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_01(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_01(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_02(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_02(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_03(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_03(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_04(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_04(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_05(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_05(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_06(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_06(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_07(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_07(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_08(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_08(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_09(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_09(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_10(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_10(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_11(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_11(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_12(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_12(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_13(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_13(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_14(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_14(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_15(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_15(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_16(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_16(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_17(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_17(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_18(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_18(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_19(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_19(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_20(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_20(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_21(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_21(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_22(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_22(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_23(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_23(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_24(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_24(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_25(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_25(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_26(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_26(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_27(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_27(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data2_28(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data2_28(u08 sigData);

u16 IlGetRxSLAVE_L_UWB_BLE_MST_FD_Crc7Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_Crc7Val(u16 sigData);

u08 IlGetRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt7Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt7Val(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_00(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_00(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_01(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_01(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_02(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_02(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_03(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_03(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_04(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_04(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_05(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_05(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_06(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_06(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_07(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_07(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_08(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_08(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_09(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_09(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_10(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_10(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_11(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_11(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_12(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_12(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_13(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_13(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_14(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_14(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_15(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_15(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_16(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_16(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_17(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_17(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_18(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_18(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_19(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_19(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_20(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_20(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_21(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_21(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_22(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_22(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_23(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_23(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_24(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_24(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_25(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_25(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_26(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_26(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_27(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_27(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data3_28(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data3_28(u08 sigData);

u16 IlGetRxSLAVE_L_UWB_BLE_MST_FD_Crc8Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_Crc8Val(u16 sigData);

u08 IlGetRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt8Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt8Val(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_00(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_00(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_01(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_01(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_02(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_02(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_03(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_03(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_04(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_04(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_05(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_05(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_06(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_06(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_07(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_07(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_08(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_08(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_09(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_09(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_10(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_10(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_11(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_11(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_12(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_12(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_13(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_13(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_14(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_14(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_15(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_15(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_16(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_16(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_17(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_17(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_18(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_18(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_19(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_19(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_20(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_20(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_21(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_21(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_22(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_22(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_23(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_23(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_24(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_24(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_25(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_25(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_26(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_26(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_27(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_27(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data4_28(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data4_28(u08 sigData);

u16 IlGetRxSLAVE_L_UWB_BLE_MST_FD_Crc9Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_Crc9Val(u16 sigData);

u08 IlGetRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt9Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt9Val(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_00(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_00(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_01(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_01(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_02(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_02(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_03(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_03(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_04(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_04(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_05(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_05(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_06(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_06(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_07(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_07(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_08(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_08(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_09(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_09(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_10(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_10(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_11(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_11(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_12(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_12(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_13(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_13(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_14(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_14(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_15(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_15(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_16(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_16(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_17(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_17(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_18(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_18(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_19(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_19(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_20(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_20(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_21(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_21(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_22(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_22(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_23(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_23(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_24(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_24(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_25(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_25(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_26(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_26(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_27(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_27(u08 sigData);

u08 IlGetRxSLAVE_MST_To_UWB_Enc_Data5_28(void);
void IlPutRxSLAVE_MST_To_UWB_Enc_Data5_28(u08 sigData);

u16 IlGetRxSLAVE_L_UWB_BLE_MST_FD_Crc14Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_Crc14Val(u16 sigData);

u08 IlGetRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt14Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt14Val(u08 sigData);

u08 IlGetRxSLAVE_MST_OTA_Cmd(void);
void IlPutRxSLAVE_MST_OTA_Cmd(u08 sigData);

u16 IlGetRxSLAVE_L_UWB_BLE_MST_FD_Crc15Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_Crc15Val(u16 sigData);

u08 IlGetRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt15Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt15Val(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_00(void);
void IlPutRxSLAVE_MST_Download_Data_00(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_01(void);
void IlPutRxSLAVE_MST_Download_Data_01(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_02(void);
void IlPutRxSLAVE_MST_Download_Data_02(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_03(void);
void IlPutRxSLAVE_MST_Download_Data_03(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_04(void);
void IlPutRxSLAVE_MST_Download_Data_04(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_05(void);
void IlPutRxSLAVE_MST_Download_Data_05(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_06(void);
void IlPutRxSLAVE_MST_Download_Data_06(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_07(void);
void IlPutRxSLAVE_MST_Download_Data_07(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_08(void);
void IlPutRxSLAVE_MST_Download_Data_08(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_09(void);
void IlPutRxSLAVE_MST_Download_Data_09(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_10(void);
void IlPutRxSLAVE_MST_Download_Data_10(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_11(void);
void IlPutRxSLAVE_MST_Download_Data_11(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_12(void);
void IlPutRxSLAVE_MST_Download_Data_12(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_13(void);
void IlPutRxSLAVE_MST_Download_Data_13(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_14(void);
void IlPutRxSLAVE_MST_Download_Data_14(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_15(void);
void IlPutRxSLAVE_MST_Download_Data_15(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_16(void);
void IlPutRxSLAVE_MST_Download_Data_16(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_17(void);
void IlPutRxSLAVE_MST_Download_Data_17(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_18(void);
void IlPutRxSLAVE_MST_Download_Data_18(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_19(void);
void IlPutRxSLAVE_MST_Download_Data_19(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_20(void);
void IlPutRxSLAVE_MST_Download_Data_20(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_21(void);
void IlPutRxSLAVE_MST_Download_Data_21(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_22(void);
void IlPutRxSLAVE_MST_Download_Data_22(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_23(void);
void IlPutRxSLAVE_MST_Download_Data_23(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_24(void);
void IlPutRxSLAVE_MST_Download_Data_24(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_25(void);
void IlPutRxSLAVE_MST_Download_Data_25(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_26(void);
void IlPutRxSLAVE_MST_Download_Data_26(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_27(void);
void IlPutRxSLAVE_MST_Download_Data_27(u08 sigData);

u08 IlGetRxSLAVE_MST_Download_Data_28(void);
void IlPutRxSLAVE_MST_Download_Data_28(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_00(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_00(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_01(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_01(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_02(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_02(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_03(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_03(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_04(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_04(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_05(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_05(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_06(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_06(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_07(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_07(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_08(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_08(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_09(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_09(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_10(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_10(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_11(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_11(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_12(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_12(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_13(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_13(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_14(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_14(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_15(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_15(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_16(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_16(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_17(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_17(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_18(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_18(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_19(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_19(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_20(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_20(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_21(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_21(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_22(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_22(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_23(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_23(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_24(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_24(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_25(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_25(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_26(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_26(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_27(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_27(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_28(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_28(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_29(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_29(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_30(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_30(u08 sigData);

u08 IlGetRxSLAVE_EDT_BLE_Dvp_Data_31(void);
void IlPutRxSLAVE_EDT_BLE_Dvp_Data_31(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_00(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_00(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_01(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_01(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_02(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_02(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_03(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_03(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_04(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_04(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_05(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_05(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_06(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_06(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_07(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_07(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_08(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_08(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_09(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_09(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_10(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_10(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_11(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_11(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_12(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_12(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_13(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_13(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_14(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_14(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_15(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_15(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_16(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_16(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_17(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_17(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_18(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_18(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_19(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_19(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_20(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_20(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_21(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_21(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_22(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_22(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_23(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_23(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_24(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_24(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_25(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_25(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_26(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_26(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_27(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_27(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_28(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_28(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_29(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_29(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_30(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_30(u08 sigData);

u08 IlGetRxSLAVE_EDT_DH_Dvp_Data_31(void);
void IlPutRxSLAVE_EDT_DH_Dvp_Data_31(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_00(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_00(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_01(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_01(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_02(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_02(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_03(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_03(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_04(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_04(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_05(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_05(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_06(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_06(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_07(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_07(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_08(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_08(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_09(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_09(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_10(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_10(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_11(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_11(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_12(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_12(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_13(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_13(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_14(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_14(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_15(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_15(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_16(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_16(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_17(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_17(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_18(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_18(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_19(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_19(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_20(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_20(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_21(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_21(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_22(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_22(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_23(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_23(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_24(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_24(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_25(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_25(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_26(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_26(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_27(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_27(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_28(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_28(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_29(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_29(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_30(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_30(u08 sigData);

u08 IlGetRxSLAVE_EDT_UWB_Dvp_Data_31(void);
void IlPutRxSLAVE_EDT_UWB_Dvp_Data_31(u08 sigData);

u08 IlGetRxSLAVE_BodyType_Sta(void);
void IlPutRxSLAVE_BodyType_Sta(u08 sigData);

u08 IlGetRxSLAVE_BDC_TP_CAN_Sta(void);
void IlPutRxSLAVE_BDC_TP_CAN_Sta(u08 sigData);

u08 IlGetRxSLAVE_OPAdv_On_Cmd(void);
void IlPutRxSLAVE_OPAdv_On_Cmd(u08 sigData);

u08 IlGetRxSLAVE_WPC_Device_On_Cmd(void);
void IlPutRxSLAVE_WPC_Device_On_Cmd(u08 sigData);

u08 IlGetRxSLAVE_RgnTyp_Opt(void);
void IlPutRxSLAVE_RgnTyp_Opt(u08 sigData);

u08 IlGetRxSLAVE_SunRoofTyp_Opt(void);
void IlPutRxSLAVE_SunRoofTyp_Opt(u08 sigData);

u08 IlGetRxSLAVE_ROA_SnsrRunReq(void);
void IlPutRxSLAVE_ROA_SnsrRunReq(u08 sigData);

u08 IlGetRxSLAVE_ROA_DiaReq(void);
void IlPutRxSLAVE_ROA_DiaReq(u08 sigData);

u08 IlGetRxSLAVE_ROA_Region_Opt(void);
void IlPutRxSLAVE_ROA_Region_Opt(u08 sigData);

u08 IlGetRxSLAVE_ROA_EngSta(void);
void IlPutRxSLAVE_ROA_EngSta(u08 sigData);

u16 IlGetRxSLAVE_L_UWB_BLE_MST_FD_Crc20Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_Crc20Val(u16 sigData);

u08 IlGetRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt20Val(void);
void IlPutRxSLAVE_L_UWB_BLE_MST_FD_AlvCnt20Val(u08 sigData);

u08 IlGetRxSLAVE_MST_BLE_DK_ID1(void);
void IlPutRxSLAVE_MST_BLE_DK_ID1(u08 sigData);

u08 IlGetRxSLAVE_MST_BLE_RSSI1(void);
void IlPutRxSLAVE_MST_BLE_RSSI1(u08 sigData);

u08 IlGetRxSLAVE_MST_BLE_DK_ID2(void);
void IlPutRxSLAVE_MST_BLE_DK_ID2(u08 sigData);

u08 IlGetRxSLAVE_MST_BLE_RSSI2(void);
void IlPutRxSLAVE_MST_BLE_RSSI2(u08 sigData);

u08 IlGetRxSLAVE_MST_BLE_DK_ID3(void);
void IlPutRxSLAVE_MST_BLE_DK_ID3(u08 sigData);

u08 IlGetRxSLAVE_MST_BLE_RSSI3(void);
void IlPutRxSLAVE_MST_BLE_RSSI3(u08 sigData);

u08 IlGetRxSLAVE_MST_BLE_DK_ID4(void);
void IlPutRxSLAVE_MST_BLE_DK_ID4(u08 sigData);

u08 IlGetRxSLAVE_MST_BLE_RSSI4(void);
void IlPutRxSLAVE_MST_BLE_RSSI4(u08 sigData);

u16 IlGetRxSLAVE_MST_BLE_BTAddIRK_Update(void);
void IlPutRxSLAVE_MST_BLE_BTAddIRK_Update(u16 sigData);

u16 IlGetRxSLAVE_MST_BLE_ConnectedDeviceInfo(void);
void IlPutRxSLAVE_MST_BLE_ConnectedDeviceInfo(u16 sigData);

u08 IlGetRxSLAVE_MST_BLE_OP_ADV_State(void);
void IlPutRxSLAVE_MST_BLE_OP_ADV_State(u08 sigData);

u08 IlGetRxSLAVE_MST_BLE_Passive_ADV_State(void);
void IlPutRxSLAVE_MST_BLE_Passive_ADV_State(u08 sigData);

u08 IlGetRxSLAVE_MST_BLE_NewDeviceConnetStatus(void);
void IlPutRxSLAVE_MST_BLE_NewDeviceConnetStatus(u08 sigData);

u08 IlGetRxSLAVE_MST_BLE_PairingResult(void);
void IlPutRxSLAVE_MST_BLE_PairingResult(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte0(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte0(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte1(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte1(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte2(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte2(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte3(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte3(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte4(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte4(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte5(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte5(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte6(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte6(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte7(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte7(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte8(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte8(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte9(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte9(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte10(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte10(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte11(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte11(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte12(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte12(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte13(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte13(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte14(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte14(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte15(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte15(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte16(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte16(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte17(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte17(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte18(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte18(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte19(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte19(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte20(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte20(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte21(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte21(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte22(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte22(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte23(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte23(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte24(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte24(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte25(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte25(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte26(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte26(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte27(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte27(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte28(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte28(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte29(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte29(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte30(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte30(u08 sigData);

u08 IlGetRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte31(void);
void IlPutRxSLAVE_L_TP_BDC_FD_L_UWB_BLE_SLV_FD_Byte31(u08 sigData);

u08 IlGetRxSLAVE_SNI_L_WPC_FD(void);
void IlPutRxSLAVE_SNI_L_WPC_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_L_WPC_FD(void);
void IlPutRxSLAVE_CBV_RMR_L_WPC_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_L_WPC_FD(void);
void IlPutRxSLAVE_CBV_NMCoID_L_WPC_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_L_WPC_FD(void);
void IlPutRxSLAVE_CBV_NMCoSRB_L_WPC_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_L_WPC_FD(void);
void IlPutRxSLAVE_CBV_AWB_L_WPC_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_L_WPC_FD(void);
void IlPutRxSLAVE_CBV_PNIB_L_WPC_FD(u08 sigData);

u08 IlGetRxSLAVE_NRR_L_WPC_FD(void);
void IlPutRxSLAVE_NRR_L_WPC_FD(u08 sigData);

u08 IlGetRxSLAVE_NM_State_L_WPC_FD(void);
void IlPutRxSLAVE_NM_State_L_WPC_FD(u08 sigData);

u32 IlGetRxSLAVE_PNI_L_WPC_FD(void);
void IlPutRxSLAVE_PNI_L_WPC_FD(u32 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_1_00(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_1_01(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_1_02(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_1_03(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_1_04(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_1_05(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_1_06(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_1_07(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_2_00(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_2_01(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_2_02(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_2_03(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_2_04(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_2_05(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_2_06(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_2_07(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_3_00(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_3_01(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_3_02(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_3_03(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_3_04(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_3_05(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_3_06(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_WPC_FD_3_07(void);
void IlPutRxSLAVE_PNI_L_WPC_FD_3_07(u08 sigData);

u08 IlGetRxSLAVE_SNI_L_UWB_BLE_MST_FD(void);
void IlPutRxSLAVE_SNI_L_UWB_BLE_MST_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_L_UWB_BLE_MST_FD(void);
void IlPutRxSLAVE_CBV_RMR_L_UWB_BLE_MST_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_L_UWB_BLE_MST_FD(void);
void IlPutRxSLAVE_CBV_NMCoID_L_UWB_BLE_MST_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_L_UWB_BLE_MST_FD(void);
void IlPutRxSLAVE_CBV_NMCoSRB_L_UWB_BLE_MST_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_L_UWB_BLE_MST_FD(void);
void IlPutRxSLAVE_CBV_AWB_L_UWB_BLE_MST_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_L_UWB_BLE_MST_FD(void);
void IlPutRxSLAVE_CBV_PNIB_L_UWB_BLE_MST_FD(u08 sigData);

u08 IlGetRxSLAVE_NRR_L_UWB_BLE_MST_FD(void);
void IlPutRxSLAVE_NRR_L_UWB_BLE_MST_FD(u08 sigData);

u08 IlGetRxSLAVE_NM_State_L_UWB_BLE_MST_FD(void);
void IlPutRxSLAVE_NM_State_L_UWB_BLE_MST_FD(u08 sigData);

u32 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD(u32 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_00(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_01(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_02(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_03(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_04(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_05(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_06(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_07(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_00(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_01(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_02(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_03(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_04(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_05(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_06(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_07(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_00(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_01(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_02(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_03(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_04(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_05(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_06(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_07(void);
void IlPutRxSLAVE_PNI_L_UWB_BLE_MST_FD_3_07(u08 sigData);

u08 IlGetRxSLAVE_SNI_L_UWB_FL_FD(void);
void IlPutRxSLAVE_SNI_L_UWB_FL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_L_UWB_FL_FD(void);
void IlPutRxSLAVE_CBV_RMR_L_UWB_FL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_L_UWB_FL_FD(void);
void IlPutRxSLAVE_CBV_NMCoID_L_UWB_FL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_L_UWB_FL_FD(void);
void IlPutRxSLAVE_CBV_NMCoSRB_L_UWB_FL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_L_UWB_FL_FD(void);
void IlPutRxSLAVE_CBV_AWB_L_UWB_FL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_L_UWB_FL_FD(void);
void IlPutRxSLAVE_CBV_PNIB_L_UWB_FL_FD(u08 sigData);

u08 IlGetRxSLAVE_NRR_L_UWB_FL_FD(void);
void IlPutRxSLAVE_NRR_L_UWB_FL_FD(u08 sigData);

u08 IlGetRxSLAVE_NM_State_L_UWB_FL_FD(void);
void IlPutRxSLAVE_NM_State_L_UWB_FL_FD(u08 sigData);

u32 IlGetRxSLAVE_PNI_L_UWB_FL_FD(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD(u32 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_1_00(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_1_01(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_1_02(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_1_03(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_1_04(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_1_05(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_1_06(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_1_07(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_2_00(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_2_01(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_2_02(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_2_03(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_2_04(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_2_05(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_2_06(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_2_07(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_3_00(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_3_01(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_3_02(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_3_03(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_3_04(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_3_05(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_3_06(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FL_FD_3_07(void);
void IlPutRxSLAVE_PNI_L_UWB_FL_FD_3_07(u08 sigData);

u08 IlGetRxSLAVE_SNI_L_UWB_FR_FD(void);
void IlPutRxSLAVE_SNI_L_UWB_FR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_L_UWB_FR_FD(void);
void IlPutRxSLAVE_CBV_RMR_L_UWB_FR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_L_UWB_FR_FD(void);
void IlPutRxSLAVE_CBV_NMCoID_L_UWB_FR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_L_UWB_FR_FD(void);
void IlPutRxSLAVE_CBV_NMCoSRB_L_UWB_FR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_L_UWB_FR_FD(void);
void IlPutRxSLAVE_CBV_AWB_L_UWB_FR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_L_UWB_FR_FD(void);
void IlPutRxSLAVE_CBV_PNIB_L_UWB_FR_FD(u08 sigData);

u08 IlGetRxSLAVE_NRR_L_UWB_FR_FD(void);
void IlPutRxSLAVE_NRR_L_UWB_FR_FD(u08 sigData);

u08 IlGetRxSLAVE_NM_State_L_UWB_FR_FD(void);
void IlPutRxSLAVE_NM_State_L_UWB_FR_FD(u08 sigData);

u32 IlGetRxSLAVE_PNI_L_UWB_FR_FD(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD(u32 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_1_00(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_1_01(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_1_02(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_1_03(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_1_04(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_1_05(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_1_06(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_1_07(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_2_00(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_2_01(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_2_02(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_2_03(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_2_04(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_2_05(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_2_06(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_2_07(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_3_00(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_3_01(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_3_02(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_3_03(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_3_04(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_3_05(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_3_06(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FR_FD_3_07(void);
void IlPutRxSLAVE_PNI_L_UWB_FR_FD_3_07(u08 sigData);

u08 IlGetRxSLAVE_SNI_L_UWB_FRNK_FD(void);
void IlPutRxSLAVE_SNI_L_UWB_FRNK_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_L_UWB_FRNK_FD(void);
void IlPutRxSLAVE_CBV_RMR_L_UWB_FRNK_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_L_UWB_FRNK_FD(void);
void IlPutRxSLAVE_CBV_NMCoID_L_UWB_FRNK_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_L_UWB_FRNK_FD(void);
void IlPutRxSLAVE_CBV_NMCoSRB_L_UWB_FRNK_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_L_UWB_FRNK_FD(void);
void IlPutRxSLAVE_CBV_AWB_L_UWB_FRNK_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_L_UWB_FRNK_FD(void);
void IlPutRxSLAVE_CBV_PNIB_L_UWB_FRNK_FD(u08 sigData);

u08 IlGetRxSLAVE_NRR_L_UWB_FRNK_FD(void);
void IlPutRxSLAVE_NRR_L_UWB_FRNK_FD(u08 sigData);

u08 IlGetRxSLAVE_NM_State_L_UWB_FRNK_FD(void);
void IlPutRxSLAVE_NM_State_L_UWB_FRNK_FD(u08 sigData);

u32 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD(u32 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_1_00(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_1_01(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_1_02(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_1_03(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_1_04(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_1_05(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_1_06(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_1_07(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_2_00(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_2_01(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_2_02(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_2_03(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_2_04(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_2_05(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_2_06(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_2_07(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_3_00(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_3_01(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_3_02(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_3_03(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_3_04(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_3_05(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_3_06(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_FRNK_FD_3_07(void);
void IlPutRxSLAVE_PNI_L_UWB_FRNK_FD_3_07(u08 sigData);

u08 IlGetRxSLAVE_SNI_L_UWB_RL_FD(void);
void IlPutRxSLAVE_SNI_L_UWB_RL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_L_UWB_RL_FD(void);
void IlPutRxSLAVE_CBV_RMR_L_UWB_RL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_L_UWB_RL_FD(void);
void IlPutRxSLAVE_CBV_NMCoID_L_UWB_RL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_L_UWB_RL_FD(void);
void IlPutRxSLAVE_CBV_NMCoSRB_L_UWB_RL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_L_UWB_RL_FD(void);
void IlPutRxSLAVE_CBV_AWB_L_UWB_RL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_L_UWB_RL_FD(void);
void IlPutRxSLAVE_CBV_PNIB_L_UWB_RL_FD(u08 sigData);

u08 IlGetRxSLAVE_NRR_L_UWB_RL_FD(void);
void IlPutRxSLAVE_NRR_L_UWB_RL_FD(u08 sigData);

u08 IlGetRxSLAVE_NM_State_L_UWB_RL_FD(void);
void IlPutRxSLAVE_NM_State_L_UWB_RL_FD(u08 sigData);

u32 IlGetRxSLAVE_PNI_L_UWB_RL_FD(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD(u32 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_1_00(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_1_01(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_1_02(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_1_03(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_1_04(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_1_05(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_1_06(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_1_07(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_2_00(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_2_01(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_2_02(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_2_03(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_2_04(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_2_05(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_2_06(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_2_07(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_3_00(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_3_01(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_3_02(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_3_03(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_3_04(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_3_05(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_3_06(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RL_FD_3_07(void);
void IlPutRxSLAVE_PNI_L_UWB_RL_FD_3_07(u08 sigData);

u08 IlGetRxSLAVE_SNI_L_UWB_RR_FD(void);
void IlPutRxSLAVE_SNI_L_UWB_RR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_L_UWB_RR_FD(void);
void IlPutRxSLAVE_CBV_RMR_L_UWB_RR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_L_UWB_RR_FD(void);
void IlPutRxSLAVE_CBV_NMCoID_L_UWB_RR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_L_UWB_RR_FD(void);
void IlPutRxSLAVE_CBV_NMCoSRB_L_UWB_RR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_L_UWB_RR_FD(void);
void IlPutRxSLAVE_CBV_AWB_L_UWB_RR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_L_UWB_RR_FD(void);
void IlPutRxSLAVE_CBV_PNIB_L_UWB_RR_FD(u08 sigData);

u08 IlGetRxSLAVE_NRR_L_UWB_RR_FD(void);
void IlPutRxSLAVE_NRR_L_UWB_RR_FD(u08 sigData);

u08 IlGetRxSLAVE_NM_State_L_UWB_RR_FD(void);
void IlPutRxSLAVE_NM_State_L_UWB_RR_FD(u08 sigData);

u32 IlGetRxSLAVE_PNI_L_UWB_RR_FD(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD(u32 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_1_00(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_1_01(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_1_02(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_1_03(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_1_04(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_1_05(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_1_06(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_1_07(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_2_00(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_2_01(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_2_02(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_2_03(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_2_04(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_2_05(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_2_06(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_2_07(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_3_00(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_3_01(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_3_02(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_3_03(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_3_04(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_3_05(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_3_06(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_RR_FD_3_07(void);
void IlPutRxSLAVE_PNI_L_UWB_RR_FD_3_07(u08 sigData);

u08 IlGetRxSLAVE_SNI_L_UWB_TRNK_FD(void);
void IlPutRxSLAVE_SNI_L_UWB_TRNK_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_L_UWB_TRNK_FD(void);
void IlPutRxSLAVE_CBV_RMR_L_UWB_TRNK_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_L_UWB_TRNK_FD(void);
void IlPutRxSLAVE_CBV_NMCoID_L_UWB_TRNK_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_L_UWB_TRNK_FD(void);
void IlPutRxSLAVE_CBV_NMCoSRB_L_UWB_TRNK_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_L_UWB_TRNK_FD(void);
void IlPutRxSLAVE_CBV_AWB_L_UWB_TRNK_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_L_UWB_TRNK_FD(void);
void IlPutRxSLAVE_CBV_PNIB_L_UWB_TRNK_FD(u08 sigData);

u08 IlGetRxSLAVE_NRR_L_UWB_TRNK_FD(void);
void IlPutRxSLAVE_NRR_L_UWB_TRNK_FD(u08 sigData);

u08 IlGetRxSLAVE_NM_State_L_UWB_TRNK_FD(void);
void IlPutRxSLAVE_NM_State_L_UWB_TRNK_FD(u08 sigData);

u32 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD(u32 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_1_00(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_1_01(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_1_02(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_1_03(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_1_04(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_1_05(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_1_06(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_1_07(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_2_00(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_2_01(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_2_02(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_2_03(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_2_04(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_2_05(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_2_06(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_2_07(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_3_00(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_3_01(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_3_02(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_3_03(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_3_04(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_3_05(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_3_06(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_UWB_TRNK_FD_3_07(void);
void IlPutRxSLAVE_PNI_L_UWB_TRNK_FD_3_07(u08 sigData);

u08 IlGetRxSLAVE_SNI_L_DHL_FD(void);
void IlPutRxSLAVE_SNI_L_DHL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_L_DHL_FD(void);
void IlPutRxSLAVE_CBV_RMR_L_DHL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_L_DHL_FD(void);
void IlPutRxSLAVE_CBV_NMCoID_L_DHL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_L_DHL_FD(void);
void IlPutRxSLAVE_CBV_NMCoSRB_L_DHL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_L_DHL_FD(void);
void IlPutRxSLAVE_CBV_AWB_L_DHL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_L_DHL_FD(void);
void IlPutRxSLAVE_CBV_PNIB_L_DHL_FD(u08 sigData);

u08 IlGetRxSLAVE_NRR_L_DHL_FD(void);
void IlPutRxSLAVE_NRR_L_DHL_FD(u08 sigData);

u08 IlGetRxSLAVE_NM_State_L_DHL_FD(void);
void IlPutRxSLAVE_NM_State_L_DHL_FD(u08 sigData);

u32 IlGetRxSLAVE_PNI_L_DHL_FD(void);
void IlPutRxSLAVE_PNI_L_DHL_FD(u32 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_1_00(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_1_01(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_1_02(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_1_03(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_1_04(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_1_05(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_1_06(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_1_07(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_2_00(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_2_01(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_2_02(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_2_03(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_2_04(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_2_05(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_2_06(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_2_07(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_3_00(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_3_01(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_3_02(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_3_03(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_3_04(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_3_05(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_3_06(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHL_FD_3_07(void);
void IlPutRxSLAVE_PNI_L_DHL_FD_3_07(u08 sigData);

u08 IlGetRxSLAVE_SNI_L_DHR_FD(void);
void IlPutRxSLAVE_SNI_L_DHR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_L_DHR_FD(void);
void IlPutRxSLAVE_CBV_RMR_L_DHR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_L_DHR_FD(void);
void IlPutRxSLAVE_CBV_NMCoID_L_DHR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_L_DHR_FD(void);
void IlPutRxSLAVE_CBV_NMCoSRB_L_DHR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_L_DHR_FD(void);
void IlPutRxSLAVE_CBV_AWB_L_DHR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_L_DHR_FD(void);
void IlPutRxSLAVE_CBV_PNIB_L_DHR_FD(u08 sigData);

u08 IlGetRxSLAVE_NRR_L_DHR_FD(void);
void IlPutRxSLAVE_NRR_L_DHR_FD(u08 sigData);

u08 IlGetRxSLAVE_NM_State_L_DHR_FD(void);
void IlPutRxSLAVE_NM_State_L_DHR_FD(u08 sigData);

u32 IlGetRxSLAVE_PNI_L_DHR_FD(void);
void IlPutRxSLAVE_PNI_L_DHR_FD(u32 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_1_00(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_1_01(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_1_02(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_1_03(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_1_04(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_1_05(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_1_06(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_1_07(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_2_00(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_2_01(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_2_02(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_2_03(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_2_04(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_2_05(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_2_06(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_2_07(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_3_00(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_3_01(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_3_02(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_3_03(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_3_04(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_3_05(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_3_06(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHR_FD_3_07(void);
void IlPutRxSLAVE_PNI_L_DHR_FD_3_07(u08 sigData);

u08 IlGetRxSLAVE_SNI_L_DHRL_FD(void);
void IlPutRxSLAVE_SNI_L_DHRL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_L_DHRL_FD(void);
void IlPutRxSLAVE_CBV_RMR_L_DHRL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_L_DHRL_FD(void);
void IlPutRxSLAVE_CBV_NMCoID_L_DHRL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_L_DHRL_FD(void);
void IlPutRxSLAVE_CBV_NMCoSRB_L_DHRL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_L_DHRL_FD(void);
void IlPutRxSLAVE_CBV_AWB_L_DHRL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_L_DHRL_FD(void);
void IlPutRxSLAVE_CBV_PNIB_L_DHRL_FD(u08 sigData);

u08 IlGetRxSLAVE_NRR_L_DHRL_FD(void);
void IlPutRxSLAVE_NRR_L_DHRL_FD(u08 sigData);

u08 IlGetRxSLAVE_NM_State_L_DHRL_FD(void);
void IlPutRxSLAVE_NM_State_L_DHRL_FD(u08 sigData);

u32 IlGetRxSLAVE_PNI_L_DHRL_FD(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD(u32 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_1_00(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_1_01(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_1_02(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_1_03(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_1_04(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_1_05(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_1_06(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_1_07(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_2_00(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_2_01(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_2_02(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_2_03(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_2_04(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_2_05(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_2_06(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_2_07(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_3_00(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_3_01(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_3_02(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_3_03(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_3_04(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_3_05(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_3_06(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRL_FD_3_07(void);
void IlPutRxSLAVE_PNI_L_DHRL_FD_3_07(u08 sigData);

u08 IlGetRxSLAVE_SNI_L_DHRR_FD(void);
void IlPutRxSLAVE_SNI_L_DHRR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_L_DHRR_FD(void);
void IlPutRxSLAVE_CBV_RMR_L_DHRR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_L_DHRR_FD(void);
void IlPutRxSLAVE_CBV_NMCoID_L_DHRR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_L_DHRR_FD(void);
void IlPutRxSLAVE_CBV_NMCoSRB_L_DHRR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_L_DHRR_FD(void);
void IlPutRxSLAVE_CBV_AWB_L_DHRR_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_L_DHRR_FD(void);
void IlPutRxSLAVE_CBV_PNIB_L_DHRR_FD(u08 sigData);

u08 IlGetRxSLAVE_NRR_L_DHRR_FD(void);
void IlPutRxSLAVE_NRR_L_DHRR_FD(u08 sigData);

u08 IlGetRxSLAVE_NM_State_L_DHRR_FD(void);
void IlPutRxSLAVE_NM_State_L_DHRR_FD(u08 sigData);

u32 IlGetRxSLAVE_PNI_L_DHRR_FD(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD(u32 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_1_00(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_1_01(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_1_02(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_1_03(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_1_04(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_1_05(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_1_06(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_1_07(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_2_00(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_2_01(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_2_02(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_2_03(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_2_04(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_2_05(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_2_06(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_2_07(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_3_00(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_3_01(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_3_02(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_3_03(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_3_04(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_3_05(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_3_06(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_DHRR_FD_3_07(void);
void IlPutRxSLAVE_PNI_L_DHRR_FD_3_07(u08 sigData);

u08 IlGetRxSLAVE_SNI_CGW_CCU(void);
void IlPutRxSLAVE_SNI_CGW_CCU(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_CGW_CCU(void);
void IlPutRxSLAVE_CBV_RMR_CGW_CCU(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_CGW_CCU(void);
void IlPutRxSLAVE_CBV_NMCoID_CGW_CCU(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_CGW_CCU(void);
void IlPutRxSLAVE_CBV_NMCoSRB_CGW_CCU(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_CGW_CCU(void);
void IlPutRxSLAVE_CBV_AWB_CGW_CCU(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_CGW_CCU(void);
void IlPutRxSLAVE_CBV_PNIB_CGW_CCU(u08 sigData);

u08 IlGetRxSLAVE_NRR_CGW_CCU(void);
void IlPutRxSLAVE_NRR_CGW_CCU(u08 sigData);

u08 IlGetRxSLAVE_NM_State_CGW_CCU(void);
void IlPutRxSLAVE_NM_State_CGW_CCU(u08 sigData);

u32 IlGetRxSLAVE_PNI_CGW_CCU(void);
void IlPutRxSLAVE_PNI_CGW_CCU(u32 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_1_00(void);
void IlPutRxSLAVE_PNI_CGW_CCU_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_1_01(void);
void IlPutRxSLAVE_PNI_CGW_CCU_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_1_02(void);
void IlPutRxSLAVE_PNI_CGW_CCU_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_1_03(void);
void IlPutRxSLAVE_PNI_CGW_CCU_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_1_04(void);
void IlPutRxSLAVE_PNI_CGW_CCU_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_1_05(void);
void IlPutRxSLAVE_PNI_CGW_CCU_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_1_06(void);
void IlPutRxSLAVE_PNI_CGW_CCU_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_1_07(void);
void IlPutRxSLAVE_PNI_CGW_CCU_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_2_00(void);
void IlPutRxSLAVE_PNI_CGW_CCU_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_2_01(void);
void IlPutRxSLAVE_PNI_CGW_CCU_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_2_02(void);
void IlPutRxSLAVE_PNI_CGW_CCU_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_2_03(void);
void IlPutRxSLAVE_PNI_CGW_CCU_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_2_04(void);
void IlPutRxSLAVE_PNI_CGW_CCU_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_2_05(void);
void IlPutRxSLAVE_PNI_CGW_CCU_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_2_06(void);
void IlPutRxSLAVE_PNI_CGW_CCU_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_2_07(void);
void IlPutRxSLAVE_PNI_CGW_CCU_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_3_00(void);
void IlPutRxSLAVE_PNI_CGW_CCU_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_3_01(void);
void IlPutRxSLAVE_PNI_CGW_CCU_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_3_02(void);
void IlPutRxSLAVE_PNI_CGW_CCU_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_3_03(void);
void IlPutRxSLAVE_PNI_CGW_CCU_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_3_04(void);
void IlPutRxSLAVE_PNI_CGW_CCU_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_3_05(void);
void IlPutRxSLAVE_PNI_CGW_CCU_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_3_06(void);
void IlPutRxSLAVE_PNI_CGW_CCU_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_CGW_CCU_3_07(void);
void IlPutRxSLAVE_PNI_CGW_CCU_3_07(u08 sigData);

u08 IlGetRxSLAVE_SNI_GW_BDC_FD(void);
void IlPutRxSLAVE_SNI_GW_BDC_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_GW_BDC_FD(void);
void IlPutRxSLAVE_CBV_RMR_GW_BDC_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_GW_BDC_FD(void);
void IlPutRxSLAVE_CBV_NMCoID_GW_BDC_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_GW_BDC_FD(void);
void IlPutRxSLAVE_CBV_NMCoSRB_GW_BDC_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_GW_BDC_FD(void);
void IlPutRxSLAVE_CBV_AWB_GW_BDC_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_GW_BDC_FD(void);
void IlPutRxSLAVE_CBV_PNIB_GW_BDC_FD(u08 sigData);

u08 IlGetRxSLAVE_NRR_GW_BDC_FD(void);
void IlPutRxSLAVE_NRR_GW_BDC_FD(u08 sigData);

u08 IlGetRxSLAVE_NM_State_GW_BDC_FD(void);
void IlPutRxSLAVE_NM_State_GW_BDC_FD(u08 sigData);

u32 IlGetRxSLAVE_PNI_GW_BDC_FD(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD(u32 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_1_00(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_1_01(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_1_02(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_1_03(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_1_04(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_1_05(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_1_06(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_1_07(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_2_00(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_2_01(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_2_02(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_2_03(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_2_04(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_2_05(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_2_06(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_2_07(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_3_00(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_3_01(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_3_02(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_3_03(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_3_04(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_3_05(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_3_06(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_GW_BDC_FD_3_07(void);
void IlPutRxSLAVE_PNI_GW_BDC_FD_3_07(u08 sigData);

u08 IlGetRxSLAVE_SNI_L_SAL_FD(void);
void IlPutRxSLAVE_SNI_L_SAL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_RMR_L_SAL_FD(void);
void IlPutRxSLAVE_CBV_RMR_L_SAL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoID_L_SAL_FD(void);
void IlPutRxSLAVE_CBV_NMCoID_L_SAL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_NMCoSRB_L_SAL_FD(void);
void IlPutRxSLAVE_CBV_NMCoSRB_L_SAL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_AWB_L_SAL_FD(void);
void IlPutRxSLAVE_CBV_AWB_L_SAL_FD(u08 sigData);

u08 IlGetRxSLAVE_CBV_PNIB_L_SAL_FD(void);
void IlPutRxSLAVE_CBV_PNIB_L_SAL_FD(u08 sigData);

u08 IlGetRxSLAVE_NRR_L_SAL_FD(void);
void IlPutRxSLAVE_NRR_L_SAL_FD(u08 sigData);

u08 IlGetRxSLAVE_NM_State_L_SAL_FD(void);
void IlPutRxSLAVE_NM_State_L_SAL_FD(u08 sigData);

u32 IlGetRxSLAVE_PNI_L_SAL_FD(void);
void IlPutRxSLAVE_PNI_L_SAL_FD(u32 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_1_00(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_1_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_1_01(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_1_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_1_02(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_1_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_1_03(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_1_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_1_04(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_1_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_1_05(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_1_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_1_06(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_1_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_1_07(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_1_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_2_00(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_2_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_2_01(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_2_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_2_02(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_2_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_2_03(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_2_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_2_04(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_2_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_2_05(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_2_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_2_06(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_2_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_2_07(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_2_07(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_3_00(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_3_00(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_3_01(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_3_01(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_3_02(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_3_02(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_3_03(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_3_03(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_3_04(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_3_04(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_3_05(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_3_05(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_3_06(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_3_06(u08 sigData);

u08 IlGetRxSLAVE_PNI_L_SAL_FD_3_07(void);
void IlPutRxSLAVE_PNI_L_SAL_FD_3_07(u08 sigData);

u16 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_Crc1Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_Crc1Val(u16 sigData);

u08 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt1Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt1Val(u08 sigData);

u08 IlGetTxSLAVE_SLV_BLE_Decrypt_FB(void);
void IlPutTxSLAVE_SLV_BLE_Decrypt_FB(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Decrypt_FB(void);
void IlPutTxSLAVE_SLV_UWB_Decrypt_FB(u08 sigData);

u08 IlGetTxSLAVE_SLV_MST_Decrypt_FB(void);
void IlPutTxSLAVE_SLV_MST_Decrypt_FB(u08 sigData);

u08 IlGetTxSLAVE_SLV_OTA_Rsp(void);
void IlPutTxSLAVE_SLV_OTA_Rsp(u08 sigData);

u16 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_Crc2Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_Crc2Val(u16 sigData);

u08 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt2Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt2Val(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_00(void);
void IlPutTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_00(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_01(void);
void IlPutTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_01(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_02(void);
void IlPutTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_02(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_03(void);
void IlPutTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_03(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_04(void);
void IlPutTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_04(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_05(void);
void IlPutTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_05(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_06(void);
void IlPutTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_06(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_07(void);
void IlPutTxSLAVE_SLV_UWB_FOB_RSD_Enc_Result_07(u08 sigData);

u16 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_Crc3Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_Crc3Val(u16 sigData);

u08 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt3Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt3Val(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_00(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_00(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_01(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_01(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_02(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_02(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_03(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_03(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_04(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_04(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_05(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_05(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_06(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_06(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_07(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_07(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_08(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_08(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_09(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_09(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_10(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_10(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_11(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_11(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_12(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_12(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_13(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_13(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_14(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_14(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_15(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_15(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_16(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_16(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_17(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_17(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_18(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_18(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_19(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_19(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_20(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_20(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_21(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_21(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_22(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_22(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Ranging_Enc_Result_23(void);
void IlPutTxSLAVE_SLV_UWB_Ranging_Enc_Result_23(u08 sigData);

u16 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_Crc4Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_Crc4Val(u16 sigData);

u08 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt4Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt4Val(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_00(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_00(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_01(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_01(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_02(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_02(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_03(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_03(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_04(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_04(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_05(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_05(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_06(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_06(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_07(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_07(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_08(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_08(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_09(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_09(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_10(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_10(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_11(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_11(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_12(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_12(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_13(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_13(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_14(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_14(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_15(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_15(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_16(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_16(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_17(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_17(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_18(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_18(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_19(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_19(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_20(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_20(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_21(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_21(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_22(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_22(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_23(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_23(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_24(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_24(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_25(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_25(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_26(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_26(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_27(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_27(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data1_28(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data1_28(u08 sigData);

u16 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_Crc5Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_Crc5Val(u16 sigData);

u08 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt5Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt5Val(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_00(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_00(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_01(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_01(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_02(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_02(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_03(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_03(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_04(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_04(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_05(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_05(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_06(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_06(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_07(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_07(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_08(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_08(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_09(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_09(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_10(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_10(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_11(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_11(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_12(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_12(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_13(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_13(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_14(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_14(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_15(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_15(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_16(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_16(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_17(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_17(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_18(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_18(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_19(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_19(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_20(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_20(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_21(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_21(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_22(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_22(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_23(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_23(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_24(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_24(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_25(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_25(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_26(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_26(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_27(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_27(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data2_28(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data2_28(u08 sigData);

u16 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_Crc6Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_Crc6Val(u16 sigData);

u08 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt6Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt6Val(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_00(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_00(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_01(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_01(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_02(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_02(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_03(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_03(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_04(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_04(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_05(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_05(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_06(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_06(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_07(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_07(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_08(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_08(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_09(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_09(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_10(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_10(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_11(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_11(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_12(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_12(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_13(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_13(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_14(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_14(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_15(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_15(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_16(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_16(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_17(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_17(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_18(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_18(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_19(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_19(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_20(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_20(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_21(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_21(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_22(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_22(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_23(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_23(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_24(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_24(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_25(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_25(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_26(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_26(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_27(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_27(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data3_28(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data3_28(u08 sigData);

u16 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_Crc7Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_Crc7Val(u16 sigData);

u08 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt7Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt7Val(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_00(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_00(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_01(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_01(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_02(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_02(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_03(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_03(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_04(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_04(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_05(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_05(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_06(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_06(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_07(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_07(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_08(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_08(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_09(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_09(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_10(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_10(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_11(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_11(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_12(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_12(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_13(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_13(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_14(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_14(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_15(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_15(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_16(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_16(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_17(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_17(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_18(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_18(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_19(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_19(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_20(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_20(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_21(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_21(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_22(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_22(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_23(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_23(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_24(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_24(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_25(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_25(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_26(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_26(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_27(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_27(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data4_28(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data4_28(u08 sigData);

u16 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_Crc8Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_Crc8Val(u16 sigData);

u08 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt8Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt8Val(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_00(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_00(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_01(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_01(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_02(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_02(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_03(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_03(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_04(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_04(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_05(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_05(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_06(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_06(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_07(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_07(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_08(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_08(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_09(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_09(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_10(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_10(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_11(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_11(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_12(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_12(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_13(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_13(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_14(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_14(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_15(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_15(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_16(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_16(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_17(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_17(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_18(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_18(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_19(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_19(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_20(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_20(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_21(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_21(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_22(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_22(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_23(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_23(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_24(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_24(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_25(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_25(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_26(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_26(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_27(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_27(u08 sigData);

u08 IlGetTxSLAVE_SLV_To_MST_Enc_Data5_28(void);
void IlPutTxSLAVE_SLV_To_MST_Enc_Data5_28(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_00(void);
void IlPutTxSLAVE_SLV_Dvp_Data_00(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_01(void);
void IlPutTxSLAVE_SLV_Dvp_Data_01(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_02(void);
void IlPutTxSLAVE_SLV_Dvp_Data_02(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_03(void);
void IlPutTxSLAVE_SLV_Dvp_Data_03(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_04(void);
void IlPutTxSLAVE_SLV_Dvp_Data_04(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_05(void);
void IlPutTxSLAVE_SLV_Dvp_Data_05(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_06(void);
void IlPutTxSLAVE_SLV_Dvp_Data_06(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_07(void);
void IlPutTxSLAVE_SLV_Dvp_Data_07(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_08(void);
void IlPutTxSLAVE_SLV_Dvp_Data_08(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_09(void);
void IlPutTxSLAVE_SLV_Dvp_Data_09(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_10(void);
void IlPutTxSLAVE_SLV_Dvp_Data_10(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_11(void);
void IlPutTxSLAVE_SLV_Dvp_Data_11(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_12(void);
void IlPutTxSLAVE_SLV_Dvp_Data_12(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_13(void);
void IlPutTxSLAVE_SLV_Dvp_Data_13(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_14(void);
void IlPutTxSLAVE_SLV_Dvp_Data_14(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_15(void);
void IlPutTxSLAVE_SLV_Dvp_Data_15(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_16(void);
void IlPutTxSLAVE_SLV_Dvp_Data_16(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_17(void);
void IlPutTxSLAVE_SLV_Dvp_Data_17(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_18(void);
void IlPutTxSLAVE_SLV_Dvp_Data_18(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_19(void);
void IlPutTxSLAVE_SLV_Dvp_Data_19(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_20(void);
void IlPutTxSLAVE_SLV_Dvp_Data_20(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_21(void);
void IlPutTxSLAVE_SLV_Dvp_Data_21(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_22(void);
void IlPutTxSLAVE_SLV_Dvp_Data_22(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_23(void);
void IlPutTxSLAVE_SLV_Dvp_Data_23(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_24(void);
void IlPutTxSLAVE_SLV_Dvp_Data_24(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_25(void);
void IlPutTxSLAVE_SLV_Dvp_Data_25(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_26(void);
void IlPutTxSLAVE_SLV_Dvp_Data_26(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_27(void);
void IlPutTxSLAVE_SLV_Dvp_Data_27(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_28(void);
void IlPutTxSLAVE_SLV_Dvp_Data_28(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_29(void);
void IlPutTxSLAVE_SLV_Dvp_Data_29(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_30(void);
void IlPutTxSLAVE_SLV_Dvp_Data_30(u08 sigData);

u08 IlGetTxSLAVE_SLV_Dvp_Data_31(void);
void IlPutTxSLAVE_SLV_Dvp_Data_31(u08 sigData);

u16 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_Crc20Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_Crc20Val(u16 sigData);

u08 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt20Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt20Val(u08 sigData);

u08 IlGetTxSLAVE_SLV_BLE_DK_ID1(void);
void IlPutTxSLAVE_SLV_BLE_DK_ID1(u08 sigData);

u08 IlGetTxSLAVE_SLV_BLE_RSSI1(void);
void IlPutTxSLAVE_SLV_BLE_RSSI1(u08 sigData);

u08 IlGetTxSLAVE_SLV_BLE_DK_ID2(void);
void IlPutTxSLAVE_SLV_BLE_DK_ID2(u08 sigData);

u08 IlGetTxSLAVE_SLV_BLE_RSSI2(void);
void IlPutTxSLAVE_SLV_BLE_RSSI2(u08 sigData);

u08 IlGetTxSLAVE_SLV_BLE_DK_ID3(void);
void IlPutTxSLAVE_SLV_BLE_DK_ID3(u08 sigData);

u08 IlGetTxSLAVE_SLV_BLE_RSSI3(void);
void IlPutTxSLAVE_SLV_BLE_RSSI3(u08 sigData);

u08 IlGetTxSLAVE_SLV_BLE_DK_ID4(void);
void IlPutTxSLAVE_SLV_BLE_DK_ID4(u08 sigData);

u08 IlGetTxSLAVE_SLV_BLE_RSSI4(void);
void IlPutTxSLAVE_SLV_BLE_RSSI4(u08 sigData);

u16 IlGetTxSLAVE_SLV_BLE_BTAddIRK_Update(void);
void IlPutTxSLAVE_SLV_BLE_BTAddIRK_Update(u16 sigData);

u16 IlGetTxSLAVE_SLV_BLE_ConnectedDeviceInfo(void);
void IlPutTxSLAVE_SLV_BLE_ConnectedDeviceInfo(u16 sigData);

u32 IlGetTxSLAVE_SLV_BLE_Passive_ADV_State(void);
void IlPutTxSLAVE_SLV_BLE_Passive_ADV_State(u32 sigData);

u32 IlGetTxSLAVE_SLV_BLE_NewDeviceConnetStatus(void);
void IlPutTxSLAVE_SLV_BLE_NewDeviceConnetStatus(u32 sigData);

u32 IlGetTxSLAVE_SLV_BLE_PairingResult(void);
void IlPutTxSLAVE_SLV_BLE_PairingResult(u32 sigData);

u32 IlGetTxSLAVE_SLV_BLE_BondingDataStatus_00(void);
void IlPutTxSLAVE_SLV_BLE_BondingDataStatus_00(u32 sigData);

u32 IlGetTxSLAVE_SLV_BLE_BondingDataStatus_01(void);
void IlPutTxSLAVE_SLV_BLE_BondingDataStatus_01(u32 sigData);

u16 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_Crc21Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_Crc21Val(u16 sigData);

u08 IlGetTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt21Val(void);
void IlPutTxSLAVE_L_UWB_BLE_SLV_FD_AlvCnt21Val(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status1(void);
void IlPutTxSLAVE_SLV_UWB_Status1(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status2(void);
void IlPutTxSLAVE_SLV_UWB_Status2(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status3(void);
void IlPutTxSLAVE_SLV_UWB_Status3(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status4(void);
void IlPutTxSLAVE_SLV_UWB_Status4(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status5(void);
void IlPutTxSLAVE_SLV_UWB_Status5(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status6(void);
void IlPutTxSLAVE_SLV_UWB_Status6(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status7(void);
void IlPutTxSLAVE_SLV_UWB_Status7(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status8(void);
void IlPutTxSLAVE_SLV_UWB_Status8(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status9(void);
void IlPutTxSLAVE_SLV_UWB_Status9(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status10(void);
void IlPutTxSLAVE_SLV_UWB_Status10(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status11(void);
void IlPutTxSLAVE_SLV_UWB_Status11(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status12(void);
void IlPutTxSLAVE_SLV_UWB_Status12(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status13(void);
void IlPutTxSLAVE_SLV_UWB_Status13(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status14(void);
void IlPutTxSLAVE_SLV_UWB_Status14(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status15(void);
void IlPutTxSLAVE_SLV_UWB_Status15(u08 sigData);

u08 IlGetTxSLAVE_SLV_UWB_Status16(void);
void IlPutTxSLAVE_SLV_UWB_Status16(u08 sigData);

u08 IlGetTxSLAVE_SLV_HW_Ver_Major(void);
void IlPutTxSLAVE_SLV_HW_Ver_Major(u08 sigData);

u08 IlGetTxSLAVE_SLV_HW_Ver_Minor(void);
void IlPutTxSLAVE_SLV_HW_Ver_Minor(u08 sigData);

u08 IlGetTxSLAVE_SLV_SW_MCU_Ver_Major(void);
void IlPutTxSLAVE_SLV_SW_MCU_Ver_Major(u08 sigData);

u08 IlGetTxSLAVE_SLV_SW_MCU_Ver_Minor(void);
void IlPutTxSLAVE_SLV_SW_MCU_Ver_Minor(u08 sigData);

u08 IlGetTxSLAVE_SLV_SW_UWB_Ver_Major(void);
void IlPutTxSLAVE_SLV_SW_UWB_Ver_Major(u08 sigData);

u08 IlGetTxSLAVE_SLV_SW_UWB_Ver_Minor(void);
void IlPutTxSLAVE_SLV_SW_UWB_Ver_Minor(u08 sigData);

u08 IlGetTxSLAVE_SLV_SW_BLE_Ver_Major(void);
void IlPutTxSLAVE_SLV_SW_BLE_Ver_Major(u08 sigData);

u08 IlGetTxSLAVE_SLV_SW_BLE_Ver_Minor(void);
void IlPutTxSLAVE_SLV_SW_BLE_Ver_Minor(u08 sigData);

u08 IlGetTxSLAVE_SLV_DTC(void);
void IlPutTxSLAVE_SLV_DTC(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte0(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte0(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte1(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte1(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte2(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte2(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte3(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte3(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte4(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte4(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte5(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte5(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte6(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte6(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte7(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte7(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte8(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte8(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte9(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte9(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte10(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte10(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte11(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte11(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte12(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte12(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte13(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte13(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte14(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte14(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte15(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte15(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte16(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte16(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte17(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte17(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte18(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte18(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte19(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte19(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte20(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte20(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte21(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte21(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte22(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte22(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte23(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte23(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte24(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte24(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte25(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte25(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte26(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte26(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte27(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte27(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte28(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte28(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte29(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte29(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte30(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte30(u08 sigData);

u08 IlGetTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte31(void);
void IlPutTxSLAVE_L_TP_L_UWB_BLE_SLV_FD_BDC_FD_Byte31(u08 sigData);

u08 IlGetTxSLAVE_SNI_L_UWB_BLE_SLV_FD(void);
void IlPutTxSLAVE_SNI_L_UWB_BLE_SLV_FD(u08 sigData);

u08 IlGetTxSLAVE_CBV_RMR_L_UWB_BLE_SLV_FD(void);
void IlPutTxSLAVE_CBV_RMR_L_UWB_BLE_SLV_FD(u08 sigData);

u08 IlGetTxSLAVE_CBV_NMCoID_L_UWB_BLE_SLV_FD(void);
void IlPutTxSLAVE_CBV_NMCoID_L_UWB_BLE_SLV_FD(u08 sigData);

u08 IlGetTxSLAVE_CBV_NMCoSRB_L_UWB_BLE_SLV_FD(void);
void IlPutTxSLAVE_CBV_NMCoSRB_L_UWB_BLE_SLV_FD(u08 sigData);

u08 IlGetTxSLAVE_CBV_AWB_L_UWB_BLE_SLV_FD(void);
void IlPutTxSLAVE_CBV_AWB_L_UWB_BLE_SLV_FD(u08 sigData);

u08 IlGetTxSLAVE_CBV_PNIB_L_UWB_BLE_SLV_FD(void);
void IlPutTxSLAVE_CBV_PNIB_L_UWB_BLE_SLV_FD(u08 sigData);

u08 IlGetTxSLAVE_NRR_L_UWB_BLE_SLV_FD(void);
void IlPutTxSLAVE_NRR_L_UWB_BLE_SLV_FD(u08 sigData);

u08 IlGetTxSLAVE_NM_State_L_UWB_BLE_SLV_FD(void);
void IlPutTxSLAVE_NM_State_L_UWB_BLE_SLV_FD(u08 sigData);

u32 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD(u32 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_00(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_00(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_01(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_01(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_02(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_02(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_03(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_03(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_04(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_04(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_05(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_05(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_06(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_06(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_07(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_1_07(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_00(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_00(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_01(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_01(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_02(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_02(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_03(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_03(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_04(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_04(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_05(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_05(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_06(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_06(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_07(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_2_07(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_00(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_00(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_01(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_01(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_02(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_02(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_03(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_03(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_04(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_04(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_05(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_05(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_06(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_06(u08 sigData);

u08 IlGetTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_07(void);
void IlPutTxSLAVE_PNI_L_UWB_BLE_SLV_FD_3_07(u08 sigData);


u16 IlGetRxANCHOR_IAU_FD_Crc4Val(void);
void IlPutRxANCHOR_IAU_FD_Crc4Val(u16 sigData);

u08 IlGetRxANCHOR_IAU_FD_AlvCnt4Val(void);
void IlPutRxANCHOR_IAU_FD_AlvCnt4Val(u08 sigData);

u08 IlGetRxANCHOR_IAU_StartIdentifiedProfile_Ext(void);
void IlPutRxANCHOR_IAU_StartIdentifiedProfile_Ext(u08 sigData);

u08 IlGetRxANCHOR_IAU_ProfileIDRVal(void);
void IlPutRxANCHOR_IAU_ProfileIDRVal(u08 sigData);

u08 IlGetRxANCHOR_IAU_DigitalKeyProcessingSta(void);
void IlPutRxANCHOR_IAU_DigitalKeyProcessingSta(u08 sigData);

u08 IlGetRxANCHOR_IAU_DigitalKeyExit(void);
void IlPutRxANCHOR_IAU_DigitalKeyExit(u08 sigData);

u08 IlGetRxANCHOR_IAU_DigitalKeyEnblRVal(void);
void IlPutRxANCHOR_IAU_DigitalKeyEnblRVal(u08 sigData);

u08 IlGetRxANCHOR_IAU_OwnerPhnRegRVal(void);
void IlPutRxANCHOR_IAU_OwnerPhnRegRVal(u08 sigData);

u08 IlGetRxANCHOR_IAU_NFCCard1RegRVal(void);
void IlPutRxANCHOR_IAU_NFCCard1RegRVal(u08 sigData);

u08 IlGetRxANCHOR_IAU_NFCCard2RegRVal(void);
void IlPutRxANCHOR_IAU_NFCCard2RegRVal(u08 sigData);

u08 IlGetRxANCHOR_IAU_DISPWrng(void);
void IlPutRxANCHOR_IAU_DISPWrng(u08 sigData);

u08 IlGetRxANCHOR_IAU_DigitalKey2Opt(void);
void IlPutRxANCHOR_IAU_DigitalKey2Opt(u08 sigData);

u08 IlGetRxANCHOR_IAUwFRULearnState(void);
void IlPutRxANCHOR_IAUwFRULearnState(u08 sigData);

u08 IlGetRxANCHOR_IAUwFPMLearnState(void);
void IlPutRxANCHOR_IAUwFPMLearnState(u08 sigData);

u08 IlGetRxANCHOR_IAU_ValetDigitalkey(void);
void IlPutRxANCHOR_IAU_ValetDigitalkey(u08 sigData);

u08 IlGetRxANCHOR_IAU_DigitalKeyNumberOpt(void);
void IlPutRxANCHOR_IAU_DigitalKeyNumberOpt(u08 sigData);

u08 IlGetRxANCHOR_IAU_eSEReprogramSta(void);
void IlPutRxANCHOR_IAU_eSEReprogramSta(u08 sigData);

u08 IlGetRxANCHOR_IAU_DgtKeyGrpPrflRval2(void);
void IlPutRxANCHOR_IAU_DgtKeyGrpPrflRval2(u08 sigData);

u08 IlGetRxANCHOR_IAU_StartIdentifiedProfile(void);
void IlPutRxANCHOR_IAU_StartIdentifiedProfile(u08 sigData);

u08 IlGetRxANCHOR_IAU_DigitalKeyProfileRval2(void);
void IlPutRxANCHOR_IAU_DigitalKeyProfileRval2(u08 sigData);

u32 IlGetRxANCHOR_IAU_NFCCard1SN(void);
void IlPutRxANCHOR_IAU_NFCCard1SN(u32 sigData);

u08 IlGetRxANCHOR_RSPA_UWBRspaExtRngSta(void);
void IlPutRxANCHOR_RSPA_UWBRspaExtRngSta(u08 sigData);

u08 IlGetRxANCHOR_RSPA_CanFltSta(void);
void IlPutRxANCHOR_RSPA_CanFltSta(u08 sigData);

u08 IlGetRxANCHOR_RSPA_BLESigErrSta(void);
void IlPutRxANCHOR_RSPA_BLESigErrSta(u08 sigData);

u08 IlGetRxANCHOR_RSPA_ConStat(void);
void IlPutRxANCHOR_RSPA_ConStat(u08 sigData);

u16 IlGetRxANCHOR_IAU_FD_Crc5Val(void);
void IlPutRxANCHOR_IAU_FD_Crc5Val(u16 sigData);

u08 IlGetRxANCHOR_IAU_FD_AlvCnt5Val(void);
void IlPutRxANCHOR_IAU_FD_AlvCnt5Val(u08 sigData);

u08 IlGetRxANCHOR_IAU_DigitalKeyProfileRval(void);
void IlPutRxANCHOR_IAU_DigitalKeyProfileRval(u08 sigData);

u08 IlGetRxANCHOR_IAU_SharedPhnRegStat(void);
void IlPutRxANCHOR_IAU_SharedPhnRegStat(u08 sigData);

u08 IlGetRxANCHOR_IAU_CardKeyEnblRVal(void);
void IlPutRxANCHOR_IAU_CardKeyEnblRVal(u08 sigData);

u08 IlGetRxANCHOR_IAU_DrvDHLPhnDetect(void);
void IlPutRxANCHOR_IAU_DrvDHLPhnDetect(u08 sigData);

u08 IlGetRxANCHOR_IAU_AstDHLPhnDetect(void);
void IlPutRxANCHOR_IAU_AstDHLPhnDetect(u08 sigData);

u08 IlGetRxANCHOR_IAU_RLDHLPhnDetect(void);
void IlPutRxANCHOR_IAU_RLDHLPhnDetect(u08 sigData);

u08 IlGetRxANCHOR_IAU_RRDHLPhnDetect(void);
void IlPutRxANCHOR_IAU_RRDHLPhnDetect(u08 sigData);

u08 IlGetRxANCHOR_IAU_Manufacturer(void);
void IlPutRxANCHOR_IAU_Manufacturer(u08 sigData);

u08 IlGetRxANCHOR_IAU_VendorCode_00(void);
void IlPutRxANCHOR_IAU_VendorCode_00(u08 sigData);

u08 IlGetRxANCHOR_IAU_VendorCode_01(void);
void IlPutRxANCHOR_IAU_VendorCode_01(u08 sigData);

u08 IlGetRxANCHOR_IAU_VendorCode_02(void);
void IlPutRxANCHOR_IAU_VendorCode_02(u08 sigData);

u32 IlGetRxANCHOR_IAU_Serial(void);
void IlPutRxANCHOR_IAU_Serial(u32 sigData);

u16 IlGetRxANCHOR_IAU_Year(void);
void IlPutRxANCHOR_IAU_Year(u16 sigData);

u08 IlGetRxANCHOR_IAU_Month(void);
void IlPutRxANCHOR_IAU_Month(u08 sigData);

u16 IlGetRxANCHOR_IAU_Date(void);
void IlPutRxANCHOR_IAU_Date(u16 sigData);

u08 IlGetRxANCHOR_IAU_SWVerMajor1(void);
void IlPutRxANCHOR_IAU_SWVerMajor1(u08 sigData);

u08 IlGetRxANCHOR_IAU_SWVerMinor1(void);
void IlPutRxANCHOR_IAU_SWVerMinor1(u08 sigData);

u08 IlGetRxANCHOR_IAU_SWVerMinor2(void);
void IlPutRxANCHOR_IAU_SWVerMinor2(u08 sigData);

u08 IlGetRxANCHOR_CCU_01_Crc1Val(void);
void IlPutRxANCHOR_CCU_01_Crc1Val(u08 sigData);

u08 IlGetRxANCHOR_CCU_ForcedPowerOffReq(void);
void IlPutRxANCHOR_CCU_ForcedPowerOffReq(u08 sigData);

u08 IlGetRxANCHOR_CCU_01_AlvCnt1Val(void);
void IlPutRxANCHOR_CCU_01_AlvCnt1Val(u08 sigData);

u08 IlGetRxANCHOR_BDC_RndNum_Trgt(void);
void IlPutRxANCHOR_BDC_RndNum_Trgt(u08 sigData);

u08 IlGetRxANCHOR_BDC_RndNum_TRCod(void);
void IlPutRxANCHOR_BDC_RndNum_TRCod(u08 sigData);

u08 IlGetRxANCHOR_BDC_RndNum_Cmd(void);
void IlPutRxANCHOR_BDC_RndNum_Cmd(u08 sigData);

u08 IlGetRxANCHOR_BDC_RndNum_00(void);
void IlPutRxANCHOR_BDC_RndNum_00(u08 sigData);

u08 IlGetRxANCHOR_BDC_RndNum_01(void);
void IlPutRxANCHOR_BDC_RndNum_01(u08 sigData);

u08 IlGetRxANCHOR_BDC_RndNum_02(void);
void IlPutRxANCHOR_BDC_RndNum_02(u08 sigData);

u08 IlGetRxANCHOR_BDC_RndNum_03(void);
void IlPutRxANCHOR_BDC_RndNum_03(u08 sigData);

u08 IlGetRxANCHOR_BDC_RndNum_04(void);
void IlPutRxANCHOR_BDC_RndNum_04(u08 sigData);

u08 IlGetRxANCHOR_BDC_RndNum_05(void);
void IlPutRxANCHOR_BDC_RndNum_05(u08 sigData);

u08 IlGetRxANCHOR_BDC_Decrypt_FB(void);
void IlPutRxANCHOR_BDC_Decrypt_FB(u08 sigData);

u08 IlGetRxANCHOR_DKID_Set(void);
void IlPutRxANCHOR_DKID_Set(u08 sigData);

u08 IlGetRxANCHOR_DKID_Del(void);
void IlPutRxANCHOR_DKID_Del(u08 sigData);

u08 IlGetRxANCHOR_UWB_Ranging_Cmd_DKID(void);
void IlPutRxANCHOR_UWB_Ranging_Cmd_DKID(u08 sigData);

u08 IlGetRxANCHOR_UWB_Ranging_Cmd_Val(void);
void IlPutRxANCHOR_UWB_Ranging_Cmd_Val(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_00(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_00(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_01(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_01(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_02(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_02(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_03(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_03(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_04(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_04(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_05(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_05(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_06(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_06(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_07(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_07(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_08(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_08(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_09(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_09(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_10(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_10(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_11(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_11(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_12(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_12(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_13(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_13(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_14(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_14(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_15(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_15(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_16(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_16(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_17(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_17(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_18(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_18(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_19(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_19(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_20(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_20(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_21(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_21(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_22(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_22(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_23(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_23(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_24(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_24(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_25(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_25(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_26(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_26(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_27(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_27(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data1_28(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data1_28(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_00(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_00(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_01(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_01(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_02(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_02(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_03(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_03(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_04(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_04(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_05(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_05(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_06(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_06(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_07(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_07(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_08(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_08(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_09(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_09(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_10(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_10(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_11(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_11(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_12(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_12(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_13(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_13(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_14(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_14(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_15(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_15(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_16(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_16(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_17(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_17(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_18(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_18(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_19(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_19(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_20(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_20(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_21(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_21(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_22(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_22(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_23(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_23(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_24(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_24(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_25(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_25(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_26(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_26(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_27(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_27(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data2_28(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data2_28(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_00(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_00(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_01(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_01(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_02(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_02(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_03(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_03(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_04(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_04(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_05(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_05(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_06(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_06(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_07(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_07(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_08(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_08(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_09(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_09(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_10(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_10(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_11(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_11(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_12(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_12(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_13(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_13(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_14(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_14(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_15(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_15(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_16(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_16(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_17(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_17(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_18(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_18(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_19(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_19(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_20(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_20(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_21(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_21(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_22(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_22(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_23(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_23(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_24(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_24(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_25(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_25(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_26(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_26(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_27(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_27(u08 sigData);

u08 IlGetRxANCHOR_BDC_To_UWB_Enc_Data3_28(void);
void IlPutRxANCHOR_BDC_To_UWB_Enc_Data3_28(u08 sigData);

u16 IlGetRxANCHOR_L_UWB_BLE_MST_FD_Crc4Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_Crc4Val(u16 sigData);

u08 IlGetRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt4Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt4Val(u08 sigData);

u08 IlGetRxANCHOR_MST_RndNum_Trgt(void);
void IlPutRxANCHOR_MST_RndNum_Trgt(u08 sigData);

u08 IlGetRxANCHOR_MST_RndNum_TRCode(void);
void IlPutRxANCHOR_MST_RndNum_TRCode(u08 sigData);

u08 IlGetRxANCHOR_MST_RndNum_Cmd(void);
void IlPutRxANCHOR_MST_RndNum_Cmd(u08 sigData);

u08 IlGetRxANCHOR_MST_RndNum_00(void);
void IlPutRxANCHOR_MST_RndNum_00(u08 sigData);

u08 IlGetRxANCHOR_MST_RndNum_01(void);
void IlPutRxANCHOR_MST_RndNum_01(u08 sigData);

u08 IlGetRxANCHOR_MST_RndNum_02(void);
void IlPutRxANCHOR_MST_RndNum_02(u08 sigData);

u08 IlGetRxANCHOR_MST_RndNum_03(void);
void IlPutRxANCHOR_MST_RndNum_03(u08 sigData);

u08 IlGetRxANCHOR_MST_RndNum_04(void);
void IlPutRxANCHOR_MST_RndNum_04(u08 sigData);

u08 IlGetRxANCHOR_MST_RndNum_05(void);
void IlPutRxANCHOR_MST_RndNum_05(u08 sigData);

u16 IlGetRxANCHOR_L_UWB_BLE_MST_FD_Crc5Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_Crc5Val(u16 sigData);

u08 IlGetRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt5Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt5Val(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_00(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_00(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_01(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_01(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_02(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_02(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_03(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_03(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_04(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_04(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_05(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_05(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_06(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_06(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_07(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_07(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_08(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_08(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_09(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_09(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_10(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_10(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_11(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_11(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_12(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_12(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_13(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_13(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_14(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_14(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_15(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_15(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_16(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_16(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_17(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_17(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_18(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_18(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_19(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_19(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_20(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_20(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_21(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_21(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_22(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_22(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_23(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_23(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_24(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_24(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_25(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_25(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_26(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_26(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_27(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_27(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data1_28(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data1_28(u08 sigData);

u16 IlGetRxANCHOR_L_UWB_BLE_MST_FD_Crc6Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_Crc6Val(u16 sigData);

u08 IlGetRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt6Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt6Val(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_00(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_00(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_01(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_01(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_02(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_02(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_03(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_03(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_04(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_04(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_05(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_05(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_06(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_06(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_07(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_07(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_08(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_08(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_09(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_09(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_10(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_10(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_11(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_11(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_12(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_12(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_13(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_13(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_14(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_14(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_15(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_15(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_16(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_16(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_17(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_17(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_18(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_18(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_19(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_19(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_20(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_20(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_21(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_21(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_22(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_22(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_23(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_23(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_24(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_24(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_25(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_25(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_26(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_26(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_27(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_27(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data2_28(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data2_28(u08 sigData);

u16 IlGetRxANCHOR_L_UWB_BLE_MST_FD_Crc7Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_Crc7Val(u16 sigData);

u08 IlGetRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt7Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt7Val(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_00(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_00(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_01(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_01(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_02(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_02(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_03(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_03(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_04(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_04(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_05(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_05(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_06(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_06(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_07(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_07(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_08(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_08(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_09(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_09(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_10(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_10(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_11(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_11(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_12(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_12(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_13(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_13(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_14(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_14(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_15(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_15(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_16(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_16(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_17(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_17(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_18(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_18(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_19(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_19(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_20(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_20(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_21(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_21(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_22(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_22(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_23(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_23(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_24(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_24(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_25(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_25(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_26(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_26(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_27(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_27(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data3_28(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data3_28(u08 sigData);

u16 IlGetRxANCHOR_L_UWB_BLE_MST_FD_Crc8Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_Crc8Val(u16 sigData);

u08 IlGetRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt8Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt8Val(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_00(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_00(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_01(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_01(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_02(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_02(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_03(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_03(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_04(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_04(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_05(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_05(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_06(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_06(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_07(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_07(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_08(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_08(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_09(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_09(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_10(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_10(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_11(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_11(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_12(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_12(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_13(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_13(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_14(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_14(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_15(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_15(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_16(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_16(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_17(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_17(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_18(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_18(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_19(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_19(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_20(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_20(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_21(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_21(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_22(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_22(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_23(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_23(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_24(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_24(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_25(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_25(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_26(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_26(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_27(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_27(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data4_28(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data4_28(u08 sigData);

u16 IlGetRxANCHOR_L_UWB_BLE_MST_FD_Crc9Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_Crc9Val(u16 sigData);

u08 IlGetRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt9Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt9Val(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_00(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_00(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_01(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_01(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_02(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_02(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_03(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_03(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_04(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_04(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_05(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_05(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_06(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_06(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_07(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_07(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_08(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_08(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_09(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_09(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_10(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_10(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_11(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_11(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_12(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_12(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_13(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_13(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_14(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_14(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_15(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_15(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_16(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_16(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_17(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_17(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_18(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_18(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_19(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_19(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_20(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_20(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_21(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_21(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_22(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_22(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_23(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_23(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_24(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_24(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_25(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_25(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_26(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_26(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_27(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_27(u08 sigData);

u08 IlGetRxANCHOR_MST_To_UWB_Enc_Data5_28(void);
void IlPutRxANCHOR_MST_To_UWB_Enc_Data5_28(u08 sigData);

u16 IlGetRxANCHOR_L_UWB_BLE_MST_FD_Crc14Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_Crc14Val(u16 sigData);

u08 IlGetRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt14Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt14Val(u08 sigData);

u08 IlGetRxANCHOR_MST_OTA_Cmd(void);
void IlPutRxANCHOR_MST_OTA_Cmd(u08 sigData);

u16 IlGetRxANCHOR_L_UWB_BLE_MST_FD_Crc15Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_Crc15Val(u16 sigData);

u08 IlGetRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt15Val(void);
void IlPutRxANCHOR_L_UWB_BLE_MST_FD_AlvCnt15Val(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_00(void);
void IlPutRxANCHOR_MST_Download_Data_00(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_01(void);
void IlPutRxANCHOR_MST_Download_Data_01(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_02(void);
void IlPutRxANCHOR_MST_Download_Data_02(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_03(void);
void IlPutRxANCHOR_MST_Download_Data_03(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_04(void);
void IlPutRxANCHOR_MST_Download_Data_04(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_05(void);
void IlPutRxANCHOR_MST_Download_Data_05(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_06(void);
void IlPutRxANCHOR_MST_Download_Data_06(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_07(void);
void IlPutRxANCHOR_MST_Download_Data_07(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_08(void);
void IlPutRxANCHOR_MST_Download_Data_08(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_09(void);
void IlPutRxANCHOR_MST_Download_Data_09(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_10(void);
void IlPutRxANCHOR_MST_Download_Data_10(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_11(void);
void IlPutRxANCHOR_MST_Download_Data_11(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_12(void);
void IlPutRxANCHOR_MST_Download_Data_12(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_13(void);
void IlPutRxANCHOR_MST_Download_Data_13(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_14(void);
void IlPutRxANCHOR_MST_Download_Data_14(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_15(void);
void IlPutRxANCHOR_MST_Download_Data_15(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_16(void);
void IlPutRxANCHOR_MST_Download_Data_16(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_17(void);
void IlPutRxANCHOR_MST_Download_Data_17(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_18(void);
void IlPutRxANCHOR_MST_Download_Data_18(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_19(void);
void IlPutRxANCHOR_MST_Download_Data_19(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_20(void);
void IlPutRxANCHOR_MST_Download_Data_20(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_21(void);
void IlPutRxANCHOR_MST_Download_Data_21(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_22(void);
void IlPutRxANCHOR_MST_Download_Data_22(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_23(void);
void IlPutRxANCHOR_MST_Download_Data_23(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_24(void);
void IlPutRxANCHOR_MST_Download_Data_24(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_25(void);
void IlPutRxANCHOR_MST_Download_Data_25(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_26(void);
void IlPutRxANCHOR_MST_Download_Data_26(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_27(void);
void IlPutRxANCHOR_MST_Download_Data_27(u08 sigData);

u08 IlGetRxANCHOR_MST_Download_Data_28(void);
void IlPutRxANCHOR_MST_Download_Data_28(u08 sigData);

u16 IlGetRxANCHOR_L_UWB_BLE_SLV_FD_Crc4Val(void);
void IlPutRxANCHOR_L_UWB_BLE_SLV_FD_Crc4Val(u16 sigData);

u08 IlGetRxANCHOR_L_UWB_BLE_SLV_FD_AlvCnt4Val(void);
void IlPutRxANCHOR_L_UWB_BLE_SLV_FD_AlvCnt4Val(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_00(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_00(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_01(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_01(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_02(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_02(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_03(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_03(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_04(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_04(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_05(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_05(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_06(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_06(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_07(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_07(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_08(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_08(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_09(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_09(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_10(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_10(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_11(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_11(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_12(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_12(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_13(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_13(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_14(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_14(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_15(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_15(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_16(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_16(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_17(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_17(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_18(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_18(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_19(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_19(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_20(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_20(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_21(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_21(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_22(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_22(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_23(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_23(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_24(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_24(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_25(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_25(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_26(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_26(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_27(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_27(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data1_28(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data1_28(u08 sigData);

u16 IlGetRxANCHOR_L_UWB_BLE_SLV_FD_Crc5Val(void);
void IlPutRxANCHOR_L_UWB_BLE_SLV_FD_Crc5Val(u16 sigData);

u08 IlGetRxANCHOR_L_UWB_BLE_SLV_FD_AlvCnt5Val(void);
void IlPutRxANCHOR_L_UWB_BLE_SLV_FD_AlvCnt5Val(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_00(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_00(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_01(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_01(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_02(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_02(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_03(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_03(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_04(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_04(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_05(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_05(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_06(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_06(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_07(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_07(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_08(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_08(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_09(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_09(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_10(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_10(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_11(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_11(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_12(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_12(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_13(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_13(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_14(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_14(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_15(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_15(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_16(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_16(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_17(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_17(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_18(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_18(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_19(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_19(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_20(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_20(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_21(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_21(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_22(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_22(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_23(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_23(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_24(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_24(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_25(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_25(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_26(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_26(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_27(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_27(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data2_28(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data2_28(u08 sigData);

u16 IlGetRxANCHOR_L_UWB_BLE_SLV_FD_Crc6Val(void);
void IlPutRxANCHOR_L_UWB_BLE_SLV_FD_Crc6Val(u16 sigData);

u08 IlGetRxANCHOR_L_UWB_BLE_SLV_FD_AlvCnt6Val(void);
void IlPutRxANCHOR_L_UWB_BLE_SLV_FD_AlvCnt6Val(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_00(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_00(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_01(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_01(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_02(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_02(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_03(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_03(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_04(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_04(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_05(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_05(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_06(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_06(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_07(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_07(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_08(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_08(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_09(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_09(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_10(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_10(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_11(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_11(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_12(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_12(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_13(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_13(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_14(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_14(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_15(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_15(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_16(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_16(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_17(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_17(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_18(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_18(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_19(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_19(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_20(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_20(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_21(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_21(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_22(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_22(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_23(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_23(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_24(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_24(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_25(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_25(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_26(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_26(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_27(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_27(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data3_28(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data3_28(u08 sigData);

u16 IlGetRxANCHOR_L_UWB_BLE_SLV_FD_Crc7Val(void);
void IlPutRxANCHOR_L_UWB_BLE_SLV_FD_Crc7Val(u16 sigData);

u08 IlGetRxANCHOR_L_UWB_BLE_SLV_FD_AlvCnt7Val(void);
void IlPutRxANCHOR_L_UWB_BLE_SLV_FD_AlvCnt7Val(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_00(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_00(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_01(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_01(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_02(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_02(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_03(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_03(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_04(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_04(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_05(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_05(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_06(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_06(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_07(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_07(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_08(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_08(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_09(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_09(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_10(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_10(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_11(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_11(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_12(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_12(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_13(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_13(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_14(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_14(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_15(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_15(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_16(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_16(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_17(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_17(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_18(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_18(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_19(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_19(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_20(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_20(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_21(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_21(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_22(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_22(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_23(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_23(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_24(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_24(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_25(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_25(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_26(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_26(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_27(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_27(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data4_28(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data4_28(u08 sigData);

u16 IlGetRxANCHOR_L_UWB_BLE_SLV_FD_Crc8Val(void);
void IlPutRxANCHOR_L_UWB_BLE_SLV_FD_Crc8Val(u16 sigData);

u08 IlGetRxANCHOR_L_UWB_BLE_SLV_FD_AlvCnt8Val(void);
void IlPutRxANCHOR_L_UWB_BLE_SLV_FD_AlvCnt8Val(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_00(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_00(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_01(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_01(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_02(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_02(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_03(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_03(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_04(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_04(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_05(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_05(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_06(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_06(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_07(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_07(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_08(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_08(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_09(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_09(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_10(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_10(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_11(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_11(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_12(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_12(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_13(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_13(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_14(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_14(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_15(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_15(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_16(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_16(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_17(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_17(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_18(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_18(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_19(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_19(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_20(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_20(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_21(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_21(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_22(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_22(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_23(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_23(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_24(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_24(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_25(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_25(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_26(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_26(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_27(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_27(u08 sigData);

u08 IlGetRxANCHOR_SLV_To_MST_Enc_Data5_28(void);
void IlPutRxANCHOR_SLV_To_MST_Enc_Data5_28(u08 sigData);

u08 IlGetRxANCHOR_BodyType_Sta(void);
void IlPutRxANCHOR_BodyType_Sta(u08 sigData);

u08 IlGetRxANCHOR_BDC_TP_CAN_Sta(void);
void IlPutRxANCHOR_BDC_TP_CAN_Sta(u08 sigData);

u08 IlGetRxANCHOR_OPAdv_On_Cmd(void);
void IlPutRxANCHOR_OPAdv_On_Cmd(u08 sigData);

u08 IlGetRxANCHOR_WPC_Device_On_Cmd(void);
void IlPutRxANCHOR_WPC_Device_On_Cmd(u08 sigData);

u08 IlGetRxANCHOR_RgnTyp_Opt(void);
void IlPutRxANCHOR_RgnTyp_Opt(u08 sigData);

u08 IlGetRxANCHOR_SunRoofTyp_Opt(void);
void IlPutRxANCHOR_SunRoofTyp_Opt(u08 sigData);

u08 IlGetRxANCHOR_SNI_L_WPC_FD(void);
void IlPutRxANCHOR_SNI_L_WPC_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_L_WPC_FD(void);
void IlPutRxANCHOR_CBV_RMR_L_WPC_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_L_WPC_FD(void);
void IlPutRxANCHOR_CBV_NMCoID_L_WPC_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_L_WPC_FD(void);
void IlPutRxANCHOR_CBV_NMCoSRB_L_WPC_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_L_WPC_FD(void);
void IlPutRxANCHOR_CBV_AWB_L_WPC_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_L_WPC_FD(void);
void IlPutRxANCHOR_CBV_PNIB_L_WPC_FD(u08 sigData);

u08 IlGetRxANCHOR_NRR_L_WPC_FD(void);
void IlPutRxANCHOR_NRR_L_WPC_FD(u08 sigData);

u08 IlGetRxANCHOR_NM_State_L_WPC_FD(void);
void IlPutRxANCHOR_NM_State_L_WPC_FD(u08 sigData);

u32 IlGetRxANCHOR_PNI_L_WPC_FD(void);
void IlPutRxANCHOR_PNI_L_WPC_FD(u32 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_1_00(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_1_01(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_1_02(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_1_03(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_1_04(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_1_05(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_1_06(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_1_07(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_2_00(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_2_01(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_2_02(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_2_03(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_2_04(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_2_05(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_2_06(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_2_07(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_3_00(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_3_01(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_3_02(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_3_03(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_3_04(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_3_05(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_3_06(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_WPC_FD_3_07(void);
void IlPutRxANCHOR_PNI_L_WPC_FD_3_07(u08 sigData);

u08 IlGetRxANCHOR_SNI_L_UWB_BLE_MST_FD(void);
void IlPutRxANCHOR_SNI_L_UWB_BLE_MST_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_L_UWB_BLE_MST_FD(void);
void IlPutRxANCHOR_CBV_RMR_L_UWB_BLE_MST_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_L_UWB_BLE_MST_FD(void);
void IlPutRxANCHOR_CBV_NMCoID_L_UWB_BLE_MST_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_L_UWB_BLE_MST_FD(void);
void IlPutRxANCHOR_CBV_NMCoSRB_L_UWB_BLE_MST_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_L_UWB_BLE_MST_FD(void);
void IlPutRxANCHOR_CBV_AWB_L_UWB_BLE_MST_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_L_UWB_BLE_MST_FD(void);
void IlPutRxANCHOR_CBV_PNIB_L_UWB_BLE_MST_FD(u08 sigData);

u08 IlGetRxANCHOR_NRR_L_UWB_BLE_MST_FD(void);
void IlPutRxANCHOR_NRR_L_UWB_BLE_MST_FD(u08 sigData);

u08 IlGetRxANCHOR_NM_State_L_UWB_BLE_MST_FD(void);
void IlPutRxANCHOR_NM_State_L_UWB_BLE_MST_FD(u08 sigData);

u32 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD(u32 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_00(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_01(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_02(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_03(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_04(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_05(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_06(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_07(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_00(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_01(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_02(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_03(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_04(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_05(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_06(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_07(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_00(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_01(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_02(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_03(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_04(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_05(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_06(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_07(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_MST_FD_3_07(u08 sigData);

u08 IlGetRxANCHOR_SNI_L_UWB_BLE_SLV_FD(void);
void IlPutRxANCHOR_SNI_L_UWB_BLE_SLV_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_L_UWB_BLE_SLV_FD(void);
void IlPutRxANCHOR_CBV_RMR_L_UWB_BLE_SLV_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_L_UWB_BLE_SLV_FD(void);
void IlPutRxANCHOR_CBV_NMCoID_L_UWB_BLE_SLV_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_L_UWB_BLE_SLV_FD(void);
void IlPutRxANCHOR_CBV_NMCoSRB_L_UWB_BLE_SLV_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_L_UWB_BLE_SLV_FD(void);
void IlPutRxANCHOR_CBV_AWB_L_UWB_BLE_SLV_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_L_UWB_BLE_SLV_FD(void);
void IlPutRxANCHOR_CBV_PNIB_L_UWB_BLE_SLV_FD(u08 sigData);

u08 IlGetRxANCHOR_NRR_L_UWB_BLE_SLV_FD(void);
void IlPutRxANCHOR_NRR_L_UWB_BLE_SLV_FD(u08 sigData);

u08 IlGetRxANCHOR_NM_State_L_UWB_BLE_SLV_FD(void);
void IlPutRxANCHOR_NM_State_L_UWB_BLE_SLV_FD(u08 sigData);

u32 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD(u32 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_00(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_01(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_02(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_03(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_04(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_05(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_06(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_07(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_00(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_01(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_02(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_03(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_04(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_05(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_06(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_07(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_00(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_01(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_02(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_03(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_04(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_05(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_06(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_07(void);
void IlPutRxANCHOR_PNI_L_UWB_BLE_SLV_FD_3_07(u08 sigData);

u08 IlGetRxANCHOR_SNI_L_UWB_FR_FD(void);
void IlPutRxANCHOR_SNI_L_UWB_FR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_L_UWB_FR_FD(void);
void IlPutRxANCHOR_CBV_RMR_L_UWB_FR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_L_UWB_FR_FD(void);
void IlPutRxANCHOR_CBV_NMCoID_L_UWB_FR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_L_UWB_FR_FD(void);
void IlPutRxANCHOR_CBV_NMCoSRB_L_UWB_FR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_L_UWB_FR_FD(void);
void IlPutRxANCHOR_CBV_AWB_L_UWB_FR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_L_UWB_FR_FD(void);
void IlPutRxANCHOR_CBV_PNIB_L_UWB_FR_FD(u08 sigData);

u08 IlGetRxANCHOR_NRR_L_UWB_FR_FD(void);
void IlPutRxANCHOR_NRR_L_UWB_FR_FD(u08 sigData);

u08 IlGetRxANCHOR_NM_State_L_UWB_FR_FD(void);
void IlPutRxANCHOR_NM_State_L_UWB_FR_FD(u08 sigData);

u32 IlGetRxANCHOR_PNI_L_UWB_FR_FD(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD(u32 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_1_00(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_1_01(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_1_02(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_1_03(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_1_04(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_1_05(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_1_06(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_1_07(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_2_00(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_2_01(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_2_02(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_2_03(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_2_04(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_2_05(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_2_06(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_2_07(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_3_00(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_3_01(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_3_02(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_3_03(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_3_04(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_3_05(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_3_06(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FR_FD_3_07(void);
void IlPutRxANCHOR_PNI_L_UWB_FR_FD_3_07(u08 sigData);

u08 IlGetRxANCHOR_SNI_L_UWB_FRNK_FD(void);
void IlPutRxANCHOR_SNI_L_UWB_FRNK_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_L_UWB_FRNK_FD(void);
void IlPutRxANCHOR_CBV_RMR_L_UWB_FRNK_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_L_UWB_FRNK_FD(void);
void IlPutRxANCHOR_CBV_NMCoID_L_UWB_FRNK_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_L_UWB_FRNK_FD(void);
void IlPutRxANCHOR_CBV_NMCoSRB_L_UWB_FRNK_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_L_UWB_FRNK_FD(void);
void IlPutRxANCHOR_CBV_AWB_L_UWB_FRNK_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_L_UWB_FRNK_FD(void);
void IlPutRxANCHOR_CBV_PNIB_L_UWB_FRNK_FD(u08 sigData);

u08 IlGetRxANCHOR_NRR_L_UWB_FRNK_FD(void);
void IlPutRxANCHOR_NRR_L_UWB_FRNK_FD(u08 sigData);

u08 IlGetRxANCHOR_NM_State_L_UWB_FRNK_FD(void);
void IlPutRxANCHOR_NM_State_L_UWB_FRNK_FD(u08 sigData);

u32 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD(u32 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_1_00(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_1_01(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_1_02(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_1_03(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_1_04(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_1_05(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_1_06(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_1_07(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_2_00(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_2_01(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_2_02(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_2_03(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_2_04(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_2_05(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_2_06(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_2_07(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_3_00(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_3_01(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_3_02(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_3_03(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_3_04(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_3_05(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_3_06(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_FRNK_FD_3_07(void);
void IlPutRxANCHOR_PNI_L_UWB_FRNK_FD_3_07(u08 sigData);

u08 IlGetRxANCHOR_SNI_L_UWB_RL_FD(void);
void IlPutRxANCHOR_SNI_L_UWB_RL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_L_UWB_RL_FD(void);
void IlPutRxANCHOR_CBV_RMR_L_UWB_RL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_L_UWB_RL_FD(void);
void IlPutRxANCHOR_CBV_NMCoID_L_UWB_RL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_L_UWB_RL_FD(void);
void IlPutRxANCHOR_CBV_NMCoSRB_L_UWB_RL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_L_UWB_RL_FD(void);
void IlPutRxANCHOR_CBV_AWB_L_UWB_RL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_L_UWB_RL_FD(void);
void IlPutRxANCHOR_CBV_PNIB_L_UWB_RL_FD(u08 sigData);

u08 IlGetRxANCHOR_NRR_L_UWB_RL_FD(void);
void IlPutRxANCHOR_NRR_L_UWB_RL_FD(u08 sigData);

u08 IlGetRxANCHOR_NM_State_L_UWB_RL_FD(void);
void IlPutRxANCHOR_NM_State_L_UWB_RL_FD(u08 sigData);

u32 IlGetRxANCHOR_PNI_L_UWB_RL_FD(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD(u32 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_1_00(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_1_01(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_1_02(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_1_03(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_1_04(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_1_05(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_1_06(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_1_07(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_2_00(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_2_01(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_2_02(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_2_03(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_2_04(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_2_05(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_2_06(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_2_07(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_3_00(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_3_01(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_3_02(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_3_03(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_3_04(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_3_05(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_3_06(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RL_FD_3_07(void);
void IlPutRxANCHOR_PNI_L_UWB_RL_FD_3_07(u08 sigData);

u08 IlGetRxANCHOR_SNI_L_UWB_RR_FD(void);
void IlPutRxANCHOR_SNI_L_UWB_RR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_L_UWB_RR_FD(void);
void IlPutRxANCHOR_CBV_RMR_L_UWB_RR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_L_UWB_RR_FD(void);
void IlPutRxANCHOR_CBV_NMCoID_L_UWB_RR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_L_UWB_RR_FD(void);
void IlPutRxANCHOR_CBV_NMCoSRB_L_UWB_RR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_L_UWB_RR_FD(void);
void IlPutRxANCHOR_CBV_AWB_L_UWB_RR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_L_UWB_RR_FD(void);
void IlPutRxANCHOR_CBV_PNIB_L_UWB_RR_FD(u08 sigData);

u08 IlGetRxANCHOR_NRR_L_UWB_RR_FD(void);
void IlPutRxANCHOR_NRR_L_UWB_RR_FD(u08 sigData);

u08 IlGetRxANCHOR_NM_State_L_UWB_RR_FD(void);
void IlPutRxANCHOR_NM_State_L_UWB_RR_FD(u08 sigData);

u32 IlGetRxANCHOR_PNI_L_UWB_RR_FD(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD(u32 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_1_00(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_1_01(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_1_02(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_1_03(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_1_04(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_1_05(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_1_06(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_1_07(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_2_00(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_2_01(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_2_02(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_2_03(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_2_04(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_2_05(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_2_06(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_2_07(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_3_00(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_3_01(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_3_02(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_3_03(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_3_04(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_3_05(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_3_06(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_RR_FD_3_07(void);
void IlPutRxANCHOR_PNI_L_UWB_RR_FD_3_07(u08 sigData);

u08 IlGetRxANCHOR_SNI_L_UWB_TRNK_FD(void);
void IlPutRxANCHOR_SNI_L_UWB_TRNK_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_L_UWB_TRNK_FD(void);
void IlPutRxANCHOR_CBV_RMR_L_UWB_TRNK_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_L_UWB_TRNK_FD(void);
void IlPutRxANCHOR_CBV_NMCoID_L_UWB_TRNK_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_L_UWB_TRNK_FD(void);
void IlPutRxANCHOR_CBV_NMCoSRB_L_UWB_TRNK_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_L_UWB_TRNK_FD(void);
void IlPutRxANCHOR_CBV_AWB_L_UWB_TRNK_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_L_UWB_TRNK_FD(void);
void IlPutRxANCHOR_CBV_PNIB_L_UWB_TRNK_FD(u08 sigData);

u08 IlGetRxANCHOR_NRR_L_UWB_TRNK_FD(void);
void IlPutRxANCHOR_NRR_L_UWB_TRNK_FD(u08 sigData);

u08 IlGetRxANCHOR_NM_State_L_UWB_TRNK_FD(void);
void IlPutRxANCHOR_NM_State_L_UWB_TRNK_FD(u08 sigData);

u32 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD(u32 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_1_00(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_1_01(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_1_02(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_1_03(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_1_04(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_1_05(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_1_06(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_1_07(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_2_00(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_2_01(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_2_02(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_2_03(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_2_04(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_2_05(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_2_06(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_2_07(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_3_00(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_3_01(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_3_02(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_3_03(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_3_04(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_3_05(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_3_06(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_UWB_TRNK_FD_3_07(void);
void IlPutRxANCHOR_PNI_L_UWB_TRNK_FD_3_07(u08 sigData);

u08 IlGetRxANCHOR_SNI_L_DHL_FD(void);
void IlPutRxANCHOR_SNI_L_DHL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_L_DHL_FD(void);
void IlPutRxANCHOR_CBV_RMR_L_DHL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_L_DHL_FD(void);
void IlPutRxANCHOR_CBV_NMCoID_L_DHL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_L_DHL_FD(void);
void IlPutRxANCHOR_CBV_NMCoSRB_L_DHL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_L_DHL_FD(void);
void IlPutRxANCHOR_CBV_AWB_L_DHL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_L_DHL_FD(void);
void IlPutRxANCHOR_CBV_PNIB_L_DHL_FD(u08 sigData);

u08 IlGetRxANCHOR_NRR_L_DHL_FD(void);
void IlPutRxANCHOR_NRR_L_DHL_FD(u08 sigData);

u08 IlGetRxANCHOR_NM_State_L_DHL_FD(void);
void IlPutRxANCHOR_NM_State_L_DHL_FD(u08 sigData);

u32 IlGetRxANCHOR_PNI_L_DHL_FD(void);
void IlPutRxANCHOR_PNI_L_DHL_FD(u32 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_1_00(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_1_01(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_1_02(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_1_03(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_1_04(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_1_05(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_1_06(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_1_07(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_2_00(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_2_01(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_2_02(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_2_03(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_2_04(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_2_05(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_2_06(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_2_07(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_3_00(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_3_01(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_3_02(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_3_03(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_3_04(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_3_05(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_3_06(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHL_FD_3_07(void);
void IlPutRxANCHOR_PNI_L_DHL_FD_3_07(u08 sigData);

u08 IlGetRxANCHOR_SNI_L_DHR_FD(void);
void IlPutRxANCHOR_SNI_L_DHR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_L_DHR_FD(void);
void IlPutRxANCHOR_CBV_RMR_L_DHR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_L_DHR_FD(void);
void IlPutRxANCHOR_CBV_NMCoID_L_DHR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_L_DHR_FD(void);
void IlPutRxANCHOR_CBV_NMCoSRB_L_DHR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_L_DHR_FD(void);
void IlPutRxANCHOR_CBV_AWB_L_DHR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_L_DHR_FD(void);
void IlPutRxANCHOR_CBV_PNIB_L_DHR_FD(u08 sigData);

u08 IlGetRxANCHOR_NRR_L_DHR_FD(void);
void IlPutRxANCHOR_NRR_L_DHR_FD(u08 sigData);

u08 IlGetRxANCHOR_NM_State_L_DHR_FD(void);
void IlPutRxANCHOR_NM_State_L_DHR_FD(u08 sigData);

u32 IlGetRxANCHOR_PNI_L_DHR_FD(void);
void IlPutRxANCHOR_PNI_L_DHR_FD(u32 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_1_00(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_1_01(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_1_02(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_1_03(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_1_04(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_1_05(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_1_06(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_1_07(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_2_00(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_2_01(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_2_02(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_2_03(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_2_04(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_2_05(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_2_06(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_2_07(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_3_00(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_3_01(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_3_02(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_3_03(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_3_04(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_3_05(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_3_06(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHR_FD_3_07(void);
void IlPutRxANCHOR_PNI_L_DHR_FD_3_07(u08 sigData);

u08 IlGetRxANCHOR_SNI_L_DHRL_FD(void);
void IlPutRxANCHOR_SNI_L_DHRL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_L_DHRL_FD(void);
void IlPutRxANCHOR_CBV_RMR_L_DHRL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_L_DHRL_FD(void);
void IlPutRxANCHOR_CBV_NMCoID_L_DHRL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_L_DHRL_FD(void);
void IlPutRxANCHOR_CBV_NMCoSRB_L_DHRL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_L_DHRL_FD(void);
void IlPutRxANCHOR_CBV_AWB_L_DHRL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_L_DHRL_FD(void);
void IlPutRxANCHOR_CBV_PNIB_L_DHRL_FD(u08 sigData);

u08 IlGetRxANCHOR_NRR_L_DHRL_FD(void);
void IlPutRxANCHOR_NRR_L_DHRL_FD(u08 sigData);

u08 IlGetRxANCHOR_NM_State_L_DHRL_FD(void);
void IlPutRxANCHOR_NM_State_L_DHRL_FD(u08 sigData);

u32 IlGetRxANCHOR_PNI_L_DHRL_FD(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD(u32 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_1_00(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_1_01(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_1_02(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_1_03(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_1_04(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_1_05(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_1_06(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_1_07(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_2_00(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_2_01(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_2_02(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_2_03(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_2_04(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_2_05(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_2_06(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_2_07(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_3_00(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_3_01(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_3_02(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_3_03(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_3_04(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_3_05(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_3_06(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRL_FD_3_07(void);
void IlPutRxANCHOR_PNI_L_DHRL_FD_3_07(u08 sigData);

u08 IlGetRxANCHOR_SNI_L_DHRR_FD(void);
void IlPutRxANCHOR_SNI_L_DHRR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_L_DHRR_FD(void);
void IlPutRxANCHOR_CBV_RMR_L_DHRR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_L_DHRR_FD(void);
void IlPutRxANCHOR_CBV_NMCoID_L_DHRR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_L_DHRR_FD(void);
void IlPutRxANCHOR_CBV_NMCoSRB_L_DHRR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_L_DHRR_FD(void);
void IlPutRxANCHOR_CBV_AWB_L_DHRR_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_L_DHRR_FD(void);
void IlPutRxANCHOR_CBV_PNIB_L_DHRR_FD(u08 sigData);

u08 IlGetRxANCHOR_NRR_L_DHRR_FD(void);
void IlPutRxANCHOR_NRR_L_DHRR_FD(u08 sigData);

u08 IlGetRxANCHOR_NM_State_L_DHRR_FD(void);
void IlPutRxANCHOR_NM_State_L_DHRR_FD(u08 sigData);

u32 IlGetRxANCHOR_PNI_L_DHRR_FD(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD(u32 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_1_00(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_1_01(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_1_02(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_1_03(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_1_04(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_1_05(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_1_06(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_1_07(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_2_00(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_2_01(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_2_02(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_2_03(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_2_04(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_2_05(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_2_06(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_2_07(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_3_00(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_3_01(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_3_02(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_3_03(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_3_04(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_3_05(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_3_06(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_DHRR_FD_3_07(void);
void IlPutRxANCHOR_PNI_L_DHRR_FD_3_07(u08 sigData);

u08 IlGetRxANCHOR_SNI_CGW_CCU(void);
void IlPutRxANCHOR_SNI_CGW_CCU(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_CGW_CCU(void);
void IlPutRxANCHOR_CBV_RMR_CGW_CCU(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_CGW_CCU(void);
void IlPutRxANCHOR_CBV_NMCoID_CGW_CCU(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_CGW_CCU(void);
void IlPutRxANCHOR_CBV_NMCoSRB_CGW_CCU(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_CGW_CCU(void);
void IlPutRxANCHOR_CBV_AWB_CGW_CCU(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_CGW_CCU(void);
void IlPutRxANCHOR_CBV_PNIB_CGW_CCU(u08 sigData);

u08 IlGetRxANCHOR_NRR_CGW_CCU(void);
void IlPutRxANCHOR_NRR_CGW_CCU(u08 sigData);

u08 IlGetRxANCHOR_NM_State_CGW_CCU(void);
void IlPutRxANCHOR_NM_State_CGW_CCU(u08 sigData);

u32 IlGetRxANCHOR_PNI_CGW_CCU(void);
void IlPutRxANCHOR_PNI_CGW_CCU(u32 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_1_00(void);
void IlPutRxANCHOR_PNI_CGW_CCU_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_1_01(void);
void IlPutRxANCHOR_PNI_CGW_CCU_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_1_02(void);
void IlPutRxANCHOR_PNI_CGW_CCU_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_1_03(void);
void IlPutRxANCHOR_PNI_CGW_CCU_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_1_04(void);
void IlPutRxANCHOR_PNI_CGW_CCU_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_1_05(void);
void IlPutRxANCHOR_PNI_CGW_CCU_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_1_06(void);
void IlPutRxANCHOR_PNI_CGW_CCU_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_1_07(void);
void IlPutRxANCHOR_PNI_CGW_CCU_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_2_00(void);
void IlPutRxANCHOR_PNI_CGW_CCU_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_2_01(void);
void IlPutRxANCHOR_PNI_CGW_CCU_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_2_02(void);
void IlPutRxANCHOR_PNI_CGW_CCU_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_2_03(void);
void IlPutRxANCHOR_PNI_CGW_CCU_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_2_04(void);
void IlPutRxANCHOR_PNI_CGW_CCU_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_2_05(void);
void IlPutRxANCHOR_PNI_CGW_CCU_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_2_06(void);
void IlPutRxANCHOR_PNI_CGW_CCU_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_2_07(void);
void IlPutRxANCHOR_PNI_CGW_CCU_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_3_00(void);
void IlPutRxANCHOR_PNI_CGW_CCU_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_3_01(void);
void IlPutRxANCHOR_PNI_CGW_CCU_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_3_02(void);
void IlPutRxANCHOR_PNI_CGW_CCU_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_3_03(void);
void IlPutRxANCHOR_PNI_CGW_CCU_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_3_04(void);
void IlPutRxANCHOR_PNI_CGW_CCU_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_3_05(void);
void IlPutRxANCHOR_PNI_CGW_CCU_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_3_06(void);
void IlPutRxANCHOR_PNI_CGW_CCU_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_CGW_CCU_3_07(void);
void IlPutRxANCHOR_PNI_CGW_CCU_3_07(u08 sigData);

u08 IlGetRxANCHOR_SNI_GW_BDC_FD(void);
void IlPutRxANCHOR_SNI_GW_BDC_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_GW_BDC_FD(void);
void IlPutRxANCHOR_CBV_RMR_GW_BDC_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_GW_BDC_FD(void);
void IlPutRxANCHOR_CBV_NMCoID_GW_BDC_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_GW_BDC_FD(void);
void IlPutRxANCHOR_CBV_NMCoSRB_GW_BDC_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_GW_BDC_FD(void);
void IlPutRxANCHOR_CBV_AWB_GW_BDC_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_GW_BDC_FD(void);
void IlPutRxANCHOR_CBV_PNIB_GW_BDC_FD(u08 sigData);

u08 IlGetRxANCHOR_NRR_GW_BDC_FD(void);
void IlPutRxANCHOR_NRR_GW_BDC_FD(u08 sigData);

u08 IlGetRxANCHOR_NM_State_GW_BDC_FD(void);
void IlPutRxANCHOR_NM_State_GW_BDC_FD(u08 sigData);

u32 IlGetRxANCHOR_PNI_GW_BDC_FD(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD(u32 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_1_00(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_1_01(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_1_02(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_1_03(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_1_04(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_1_05(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_1_06(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_1_07(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_2_00(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_2_01(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_2_02(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_2_03(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_2_04(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_2_05(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_2_06(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_2_07(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_3_00(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_3_01(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_3_02(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_3_03(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_3_04(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_3_05(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_3_06(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_GW_BDC_FD_3_07(void);
void IlPutRxANCHOR_PNI_GW_BDC_FD_3_07(u08 sigData);

u08 IlGetRxANCHOR_SNI_L_SAL_FD(void);
void IlPutRxANCHOR_SNI_L_SAL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_RMR_L_SAL_FD(void);
void IlPutRxANCHOR_CBV_RMR_L_SAL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoID_L_SAL_FD(void);
void IlPutRxANCHOR_CBV_NMCoID_L_SAL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_NMCoSRB_L_SAL_FD(void);
void IlPutRxANCHOR_CBV_NMCoSRB_L_SAL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_AWB_L_SAL_FD(void);
void IlPutRxANCHOR_CBV_AWB_L_SAL_FD(u08 sigData);

u08 IlGetRxANCHOR_CBV_PNIB_L_SAL_FD(void);
void IlPutRxANCHOR_CBV_PNIB_L_SAL_FD(u08 sigData);

u08 IlGetRxANCHOR_NRR_L_SAL_FD(void);
void IlPutRxANCHOR_NRR_L_SAL_FD(u08 sigData);

u08 IlGetRxANCHOR_NM_State_L_SAL_FD(void);
void IlPutRxANCHOR_NM_State_L_SAL_FD(u08 sigData);

u32 IlGetRxANCHOR_PNI_L_SAL_FD(void);
void IlPutRxANCHOR_PNI_L_SAL_FD(u32 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_1_00(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_1_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_1_01(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_1_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_1_02(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_1_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_1_03(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_1_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_1_04(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_1_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_1_05(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_1_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_1_06(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_1_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_1_07(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_1_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_2_00(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_2_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_2_01(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_2_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_2_02(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_2_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_2_03(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_2_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_2_04(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_2_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_2_05(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_2_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_2_06(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_2_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_2_07(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_2_07(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_3_00(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_3_00(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_3_01(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_3_01(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_3_02(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_3_02(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_3_03(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_3_03(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_3_04(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_3_04(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_3_05(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_3_05(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_3_06(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_3_06(u08 sigData);

u08 IlGetRxANCHOR_PNI_L_SAL_FD_3_07(void);
void IlPutRxANCHOR_PNI_L_SAL_FD_3_07(u08 sigData);

u16 IlGetTxANCHOR_L_UWB_FD_Crc1Val(void);
void IlPutTxANCHOR_L_UWB_FD_Crc1Val(u16 sigData);

u08 IlGetTxANCHOR_L_UWB_FD_AlvCnt1Val(void);
void IlPutTxANCHOR_L_UWB_FD_AlvCnt1Val(u08 sigData);

u08 IlGetTxANCHOR_UWB_UWB_Decrypt_FB(void);
void IlPutTxANCHOR_UWB_UWB_Decrypt_FB(u08 sigData);

u08 IlGetTxANCHOR_UWB_MST_Decrypt_FB(void);
void IlPutTxANCHOR_UWB_MST_Decrypt_FB(u08 sigData);

u08 IlGetTxANCHOR_UWB_OTA_Rsp(void);
void IlPutTxANCHOR_UWB_OTA_Rsp(u08 sigData);

u16 IlGetTxANCHOR_L_UWB_FD_Crc2Val(void);
void IlPutTxANCHOR_L_UWB_FD_Crc2Val(u16 sigData);

u08 IlGetTxANCHOR_L_UWB_FD_AlvCnt2Val(void);
void IlPutTxANCHOR_L_UWB_FD_AlvCnt2Val(u08 sigData);

u08 IlGetTxANCHOR_UWB_FOB_RSD_Enc_Result_00(void);
void IlPutTxANCHOR_UWB_FOB_RSD_Enc_Result_00(u08 sigData);

u08 IlGetTxANCHOR_UWB_FOB_RSD_Enc_Result_01(void);
void IlPutTxANCHOR_UWB_FOB_RSD_Enc_Result_01(u08 sigData);

u08 IlGetTxANCHOR_UWB_FOB_RSD_Enc_Result_02(void);
void IlPutTxANCHOR_UWB_FOB_RSD_Enc_Result_02(u08 sigData);

u08 IlGetTxANCHOR_UWB_FOB_RSD_Enc_Result_03(void);
void IlPutTxANCHOR_UWB_FOB_RSD_Enc_Result_03(u08 sigData);

u08 IlGetTxANCHOR_UWB_FOB_RSD_Enc_Result_04(void);
void IlPutTxANCHOR_UWB_FOB_RSD_Enc_Result_04(u08 sigData);

u08 IlGetTxANCHOR_UWB_FOB_RSD_Enc_Result_05(void);
void IlPutTxANCHOR_UWB_FOB_RSD_Enc_Result_05(u08 sigData);

u08 IlGetTxANCHOR_UWB_FOB_RSD_Enc_Result_06(void);
void IlPutTxANCHOR_UWB_FOB_RSD_Enc_Result_06(u08 sigData);

u08 IlGetTxANCHOR_UWB_FOB_RSD_Enc_Result_07(void);
void IlPutTxANCHOR_UWB_FOB_RSD_Enc_Result_07(u08 sigData);

u16 IlGetTxANCHOR_L_UWB_FD_Crc3Val(void);
void IlPutTxANCHOR_L_UWB_FD_Crc3Val(u16 sigData);

u08 IlGetTxANCHOR_L_UWB_FD_AlvCnt3Val(void);
void IlPutTxANCHOR_L_UWB_FD_AlvCnt3Val(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_00(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_00(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_01(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_01(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_02(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_02(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_03(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_03(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_04(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_04(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_05(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_05(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_06(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_06(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_07(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_07(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_08(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_08(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_09(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_09(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_10(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_10(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_11(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_11(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_12(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_12(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_13(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_13(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_14(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_14(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_15(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_15(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_16(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_16(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_17(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_17(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_18(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_18(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_19(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_19(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_20(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_20(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_21(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_21(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_22(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_22(u08 sigData);

u08 IlGetTxANCHOR_UWB_Ranging_Enc_Result_23(void);
void IlPutTxANCHOR_UWB_Ranging_Enc_Result_23(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_00(void);
void IlPutTxANCHOR_UWB_Dvp_Data_00(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_01(void);
void IlPutTxANCHOR_UWB_Dvp_Data_01(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_02(void);
void IlPutTxANCHOR_UWB_Dvp_Data_02(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_03(void);
void IlPutTxANCHOR_UWB_Dvp_Data_03(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_04(void);
void IlPutTxANCHOR_UWB_Dvp_Data_04(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_05(void);
void IlPutTxANCHOR_UWB_Dvp_Data_05(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_06(void);
void IlPutTxANCHOR_UWB_Dvp_Data_06(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_07(void);
void IlPutTxANCHOR_UWB_Dvp_Data_07(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_08(void);
void IlPutTxANCHOR_UWB_Dvp_Data_08(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_09(void);
void IlPutTxANCHOR_UWB_Dvp_Data_09(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_10(void);
void IlPutTxANCHOR_UWB_Dvp_Data_10(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_11(void);
void IlPutTxANCHOR_UWB_Dvp_Data_11(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_12(void);
void IlPutTxANCHOR_UWB_Dvp_Data_12(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_13(void);
void IlPutTxANCHOR_UWB_Dvp_Data_13(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_14(void);
void IlPutTxANCHOR_UWB_Dvp_Data_14(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_15(void);
void IlPutTxANCHOR_UWB_Dvp_Data_15(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_16(void);
void IlPutTxANCHOR_UWB_Dvp_Data_16(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_17(void);
void IlPutTxANCHOR_UWB_Dvp_Data_17(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_18(void);
void IlPutTxANCHOR_UWB_Dvp_Data_18(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_19(void);
void IlPutTxANCHOR_UWB_Dvp_Data_19(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_20(void);
void IlPutTxANCHOR_UWB_Dvp_Data_20(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_21(void);
void IlPutTxANCHOR_UWB_Dvp_Data_21(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_22(void);
void IlPutTxANCHOR_UWB_Dvp_Data_22(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_23(void);
void IlPutTxANCHOR_UWB_Dvp_Data_23(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_24(void);
void IlPutTxANCHOR_UWB_Dvp_Data_24(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_25(void);
void IlPutTxANCHOR_UWB_Dvp_Data_25(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_26(void);
void IlPutTxANCHOR_UWB_Dvp_Data_26(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_27(void);
void IlPutTxANCHOR_UWB_Dvp_Data_27(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_28(void);
void IlPutTxANCHOR_UWB_Dvp_Data_28(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_29(void);
void IlPutTxANCHOR_UWB_Dvp_Data_29(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_30(void);
void IlPutTxANCHOR_UWB_Dvp_Data_30(u08 sigData);

u08 IlGetTxANCHOR_UWB_Dvp_Data_31(void);
void IlPutTxANCHOR_UWB_Dvp_Data_31(u08 sigData);

u16 IlGetTxANCHOR_L_UWB_FD_Crc10Val(void);
void IlPutTxANCHOR_L_UWB_FD_Crc10Val(u16 sigData);

u08 IlGetTxANCHOR_L_UWB_FD_AlvCnt10Val(void);
void IlPutTxANCHOR_L_UWB_FD_AlvCnt10Val(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status1(void);
void IlPutTxANCHOR_UWB_Status1(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status2(void);
void IlPutTxANCHOR_UWB_Status2(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status3(void);
void IlPutTxANCHOR_UWB_Status3(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status4(void);
void IlPutTxANCHOR_UWB_Status4(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status5(void);
void IlPutTxANCHOR_UWB_Status5(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status6(void);
void IlPutTxANCHOR_UWB_Status6(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status7(void);
void IlPutTxANCHOR_UWB_Status7(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status8(void);
void IlPutTxANCHOR_UWB_Status8(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status9(void);
void IlPutTxANCHOR_UWB_Status9(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status10(void);
void IlPutTxANCHOR_UWB_Status10(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status11(void);
void IlPutTxANCHOR_UWB_Status11(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status12(void);
void IlPutTxANCHOR_UWB_Status12(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status13(void);
void IlPutTxANCHOR_UWB_Status13(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status14(void);
void IlPutTxANCHOR_UWB_Status14(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status15(void);
void IlPutTxANCHOR_UWB_Status15(u08 sigData);

u08 IlGetTxANCHOR_UWB_Status16(void);
void IlPutTxANCHOR_UWB_Status16(u08 sigData);

u08 IlGetTxANCHOR_UWB_HW_Ver_Major(void);
void IlPutTxANCHOR_UWB_HW_Ver_Major(u08 sigData);

u08 IlGetTxANCHOR_UWB_HW_Ver_Minor(void);
void IlPutTxANCHOR_UWB_HW_Ver_Minor(u08 sigData);

u08 IlGetTxANCHOR_UWB_SW_MCU_Ver_Major(void);
void IlPutTxANCHOR_UWB_SW_MCU_Ver_Major(u08 sigData);

u08 IlGetTxANCHOR_UWB_SW_MCU_Ver_Minor(void);
void IlPutTxANCHOR_UWB_SW_MCU_Ver_Minor(u08 sigData);

u08 IlGetTxANCHOR_UWB_SW_IC_Ver_Major(void);
void IlPutTxANCHOR_UWB_SW_IC_Ver_Major(u08 sigData);

u08 IlGetTxANCHOR_UWB_SW_IC_Ver_Minor(void);
void IlPutTxANCHOR_UWB_SW_IC_Ver_Minor(u08 sigData);

u08 IlGetTxANCHOR_UWB_DTC(void);
void IlPutTxANCHOR_UWB_DTC(u08 sigData);

u08 IlGetTxANCHOR_SNI_L_UWB_FD(void);
void IlPutTxANCHOR_SNI_L_UWB_FD(u08 sigData);

u08 IlGetTxANCHOR_CBV_RMR_L_UWB_FD(void);
void IlPutTxANCHOR_CBV_RMR_L_UWB_FD(u08 sigData);

u08 IlGetTxANCHOR_CBV_NMCoID_L_UWB_FD(void);
void IlPutTxANCHOR_CBV_NMCoID_L_UWB_FD(u08 sigData);

u08 IlGetTxANCHOR_CBV_NMCoSRB_L_UWB_FD(void);
void IlPutTxANCHOR_CBV_NMCoSRB_L_UWB_FD(u08 sigData);

u08 IlGetTxANCHOR_CBV_AWB_L_UWB_FD(void);
void IlPutTxANCHOR_CBV_AWB_L_UWB_FD(u08 sigData);

u08 IlGetTxANCHOR_CBV_PNIB_L_UWB_FD(void);
void IlPutTxANCHOR_CBV_PNIB_L_UWB_FD(u08 sigData);

u08 IlGetTxANCHOR_NRR_L_UWB_FD(void);
void IlPutTxANCHOR_NRR_L_UWB_FD(u08 sigData);

u08 IlGetTxANCHOR_NM_State_L_UWB_FD(void);
void IlPutTxANCHOR_NM_State_L_UWB_FD(u08 sigData);

u32 IlGetTxANCHOR_PNI_L_UWB_FD(void);
void IlPutTxANCHOR_PNI_L_UWB_FD(u32 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_1_00(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_1_00(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_1_01(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_1_01(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_1_02(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_1_02(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_1_03(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_1_03(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_1_04(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_1_04(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_1_05(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_1_05(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_1_06(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_1_06(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_1_07(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_1_07(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_2_00(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_2_00(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_2_01(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_2_01(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_2_02(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_2_02(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_2_03(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_2_03(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_2_04(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_2_04(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_2_05(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_2_05(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_2_06(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_2_06(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_2_07(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_2_07(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_3_00(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_3_00(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_3_01(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_3_01(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_3_02(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_3_02(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_3_03(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_3_03(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_3_04(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_3_04(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_3_05(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_3_05(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_3_06(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_3_06(u08 sigData);

u08 IlGetTxANCHOR_PNI_L_UWB_FD_3_07(void);
void IlPutTxANCHOR_PNI_L_UWB_FD_3_07(u08 sigData);

#ifdef __cplusplus
}
#endif

#endif /* __DEFINE_CANOE_H__ */
