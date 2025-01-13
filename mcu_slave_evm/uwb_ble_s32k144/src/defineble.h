//  MCU---BLE Can message definition
#ifndef __DEFINE_BLE_H__
#define __DEFINE_BLE_H__

#ifdef __cplusplus
extern "C"
{
#endif


#define START                   0x01
#define STOP                    0x02

//ERROR
#define ERR_MSG_INVALID         0x01
#define ERR_MSG_TYPE_INVALID    0x02

#define ERR_BODY_SIZE_INVALID   0x31
//#define ERR_BODY_ITEM_INVALID   0x32
#define ERR_BODY_VAL_INVALID    0x33

#define ERR_NOT_IMPLEMENTED_YET 0xFF


////////////////////////////////////////////
// Response code & reason definition
////////////////////////////////////////////

// RC: Response Code
#define RC_UNDEFINED            0x00
#define RC_SUCCESS              0x01
#define RC_SUCCESS_RCV_ONLY     0x02
#define RC_SUCCESS_NO_BODY      0x02
#define RC_FAIL                 0x03

// R: Reason
#define R_UNDEFINED             0x0000
#define R_MSG_DECODE_FAIL       0x0010


#define R_NO_ERROR              0x00
// ...

typedef struct
{
    unsigned char resp_code;
    unsigned short reason;
} bst_resp_body;



// MESSAGE format
// ----------------------------------------------------------------
// | 1byte | 1byte    | 1byte  | 1byte | variable | 1byte | 1byte |
// ----------------------------------------------------------------
// | SOF   | bMsgType | bMsgId | bodyL | body     | FCS   |  EOFF |
// ----------------------------------------------------------------



// Req MESSAGE example
// ----------------------------------------------------------------
// | 1byte | 1byte    | 1byte  | 1byte | variable | 1byte | 1byte |
// ----------------------------------------------------------------
// | SOF   | bMsgType | bMsgId | bodyL | body     | FCS   |  EOFF |
// ----------------------------------------------------------------
// | 0xCD  | 0x01     | 0x03   | 0x01  | 0x03     | 0xFF  |  0x0A |
// ----------------------------------------------------------------


// Res MESSAGE example - FAIL message
// ------------------------------------------------------------------------
// | 1byte | 1byte    | 1byte  | 1byte | variable         | 1byte | 1byte |
// ------------------------------------------------------------------------
// | SOF   | bMsgType | bMsgId | bodyL | body             | FCS   |  EOFF |
// ------------------------------------------------------------------------
// | 0xCD  | 0x02     | bMsgId | 0x03  | resp_code(1byte) | 0xFF  |  0x0A |
// |       |          |        |       | f_reason(2byte)  |       |       |
// ------------------------------------------------------------------------

// Res MESSAGE example - SUCCESS with NO body
// ------------------------------------------------------------------------
// | 1byte | 1byte    | 1byte  | 1byte | variable         | 1byte | 1byte |
// ------------------------------------------------------------------------
// | SOF   | bMsgType | bMsgId | bodyL | body             | FCS   |  EOFF |
// ------------------------------------------------------------------------
// | 0xCD  | 0x02     | bMsgId | 0x01  | resp_code(1byte) | 0xFF  |  0x0A |
// ------------------------------------------------------------------------

// Res MESSAGE example - SUCCESS with body
// ------------------------------------------------------------------------
// | 1byte | 1byte    | 1byte  | 1byte | variable         | 1byte | 1byte |
// ------------------------------------------------------------------------
// | SOF   | bMsgType | bMsgId | bodyL | body             | FCS   |  EOFF |
// ------------------------------------------------------------------------
// | 0xCD  | 0x02     | bMsgId | 1+X   | resp_code(1byte) | 0xFF  |  0x0A |
// |       |          |        |       | body_data(X byte)|       |       |
// ------------------------------------------------------------------------


#define SOF                     0xCD
#define DUMMY                   0xFF
#define DUMMY_FCS               0xFF
#define EOFF                    0x0A


// bMsgType    (prefix: Bmt - bMsgType)
#define BmtReq                  0x01
#define BmtRes                  0x02
#define BmtEvt                  0x03
#define BmtEvtConfirm           0x04
#define BmtNoti                 0x05
#define BmtNotiConfirm          0x06

//                                                            [msg direction]                           [CanMsgId]
// BDC outgoing msg                                         BDC -- MCU_M -- MCU_S
#define bMsg_CCU_01_00ms                    0x01    // EC : BDC -> MCU_ALL                              0x43F
#define bMsg_IAU_FD_04_200ms                0x02    // PE : BDC -> MCU_ALL                              0x351
#define bMsg_IAU_FD_05_200ms                0x03    // PE : BDC -> MCU_ALL                              0x352
#define bMsg_L_BDC_FD_IAU_02_00ms           0x04    // EC : BDC -> MCU_ALL                              0x04000051
#define bMsg_L_BDC_FD_IAU_03_00ms           0x05    // EC : BDC -> MCU_ALL                              0x04000052
#define bMsg_L_BDC_FD_IAU_04_00ms           0x06    // EC : BDC -> MCU_ALL                              0x04000053
#define bMsg_L_BDC_FD_IAU_10_200ms          0x07    // PE : BDC -> MCU_ALL          BDC_TP_CAN_Sta      0x08000050
                                                    //      BDC -> MCU_M            OPAdv_On_Cmd
#define bMsg_L_TP_BDC_FD_L_UWB_BLE_MST_FD   0x08    // TP : BDC -> MCU_M                                0x0C000100
#define bMsg_L_TP_BDC_FD_L_UWB_BLE_SLV_FD   0x09    // TP : BDC ----------> MCU_S                       0x0C000102


// MST outgoing msg
#define bMsg_L_UWB_BLE_MST_FD_01_00ms       0x21    // EC : BDC <- MCU_M            MST_BLE_Decrypt_FB  0x040000A0
                                                    //             MCU_M -> MCU_S   MST_SLV_Decrypt_FB
#define bMsg_L_UWB_BLE_MST_FD_04_00ms       0x22    // EC :        MCU_M -> MCU_S                       0x040000A3
#define bMsg_L_UWB_BLE_MST_FD_05_00ms       0x23    // EC :        MCU_M -> MCU_S                       0x040000A4
#define bMsg_L_UWB_BLE_MST_FD_06_00ms       0x24    // EC :        MCU_M -> MCU_S                       0x040000A5
#define bMsg_L_UWB_BLE_MST_FD_07_00ms       0x25    // EC :        MCU_M -> MCU_S                       0x040000A6
#define bMsg_L_UWB_BLE_MST_FD_08_00ms       0x26    // EC :        MCU_M -> MCU_S                       0x040000A7
#define bMsg_L_UWB_BLE_MST_FD_09_00ms       0x27    // EC :        MCU_M -> MCU_S                       0x040000A8
#define bMsg_L_UWB_BLE_MST_FD_10_00ms       0x28    // EC : BDC <- MCU_M                                0x040000A9
#define bMsg_L_UWB_BLE_MST_FD_11_00ms       0x29    // EC : BDC <- MCU_M                                0x040000AA
#define bMsg_L_UWB_BLE_MST_FD_20_200ms      0x2A    // PE : BDC <- MCU_M                                0x080000A0
#define bMsg_L_TP_L_UWB_BLE_MST_FD_BDC_FD   0x2B    // TP : BDC <- MCU_M                                0x0C000101
#define bMsg_L_UWB_BLE_MST_FD_21_200ms      0x2C    // PE : BDC <- MCU_M                                0x080000A1


// SLV outgoing msg
#define bMsg_L_UWB_BLE_SLV_FD_01_00ms       0x31    // EC : BDC <---------- MCU_S   SLV_BLE_Decrypt_FB  0x040000B0
                                                    //             MCU_M <- MCU_S   SLV_MST_Decrypt_FB
#define bMsg_L_UWB_BLE_SLV_FD_04_00ms       0x32    // EC :        MCU_M <- MCU_S                       0x040000B3
#define bMsg_L_UWB_BLE_SLV_FD_05_00ms       0x33    // EC :        MCU_M <- MCU_S                       0x040000B4
#define bMsg_L_UWB_BLE_SLV_FD_06_00ms       0x34    // EC :        MCU_M <- MCU_S                       0x040000B5
#define bMsg_L_UWB_BLE_SLV_FD_07_00ms       0x35    // EC :        MCU_M <- MCU_S                       0x040000B6
#define bMsg_L_UWB_BLE_SLV_FD_08_00ms       0x36    // EC :        MCU_M <- MCU_S                       0x040000B7
#define bMsg_L_UWB_BLE_SLV_FD_20_200ms      0x37    // PE : BDC <---------- MCU_S   all signal          0x080000B0
                                                    //             MCU_M <- MCU_S   SLV_BLE_BondingDataStatus
#define bMsg_L_TP_L_UWB_BLE_SLV_FD_BDC_FD   0x38    // TP :        MCU_M <- MCU_S                       0x0C000103
#define bMsg_L_UWB_BLE_SLV_FD_21_200ms      0x39    // PE : BDC <---------- MCU_S                       0x080000B1

#define bMsg_L_UWB_BLE_MST_FD_14_00ms		0x3A	//	BSWedit

//structure definition for CAN message
// bst - BLE structure

////////////////////////////////////////////
// BDC outgoing msg
////////////////////////////////////////////
#define FORCED_RESET_OFF                        0x00
#define FORCED_RESET_ON_NON_SLEEP_STATE         0x01
#define FORCED_RESET_ON_NORMAL_SLEEP_STATE      0x02
typedef struct
{
    unsigned char CCU_ForcedPowerOffReq;        //  0x00: off
                                                //  0x01: ON in the non-sleep state
                                                //  0x02: ON in the normal-sleep state
} bst_CCU_01_00ms;

#define OWNER_PHN_REG_STAT_DEFAULT              0x00
#define OWNER_PHN_REG_STAT_UNREGISTERED         0x01
#define OWNER_PHN_REG_STAT_REGISTERED           0x02
#define OWNER_PHN_REG_STAT_INVALID              0x03
typedef struct
{
    unsigned char IAU_OwnerPhnRegRVal;          //  0x00 : Default (Unregistered),
                                                //  0x01 : Unregistered,
                                                //  0x02 : Registered,
                                                //  0x03 : Invalid
} bst_IAU_FD_04_200ms;

#define SHARED_PHN_REG_STAT_DEFAULT             0x00
#define SHARED_PHN_REG_STAT_UNREGISTERED        0x01
#define SHARED_PHN_REG_STAT_REGISTERED          0x02
#define SHARED_PHN_REG_STAT_INVALID             0x03
typedef struct
{
    unsigned char IAU_SharedPhnRegStat;         //  0x00 : Default (Unregistered),
                                                //  0x01 : Registered,
                                                //  0x02 : Reserve,
                                                //  0x03 : Invalid
} bst_IAU_FD_05_200ms;


#define BDC_RN_TRGT_DEFAULT                     0x00
#define BDC_RN_TRGT_BLE                         0x01
#define BDC_RN_TRGT_UWB                         0x02
#define BDC_RN_TRGT_ALL                         0x03

#define BDC_RN_TRCOD_DEFAULT                    0x00
#define BDC_RN_TRCOD_REQ_FOR_ENC_DATA           0x01
#define BDC_RN_TRCOD_REQ_FOR_RECEIVE            0x02
#define BDC_RN_TRCOD_REQ_FOR_ENC_CMD_RESULT     0x03

#define BDC_RN_CMD_DEFAULT                      0x00
//#define BDC_RN_CMD_MIN                        0x01        //????
//#define BDC_RN_CMD_MAX                        0x07        //????

#define BDC_DEC_FB_DEFAULT                      0x00
#define BDC_DEC_FB_POSITIE                      0x01
#define BDC_DEC_FB_NEGATIVE                     0x02
#define BDC_DEC_FB_INVALID                      0x03

#define DKID_SET_DEFAULT                        0x00
#define DKID_SET_01                             0x01
#define DKID_SET_02                             0x02
#define DKID_SET_03                             0x03
#define DKID_SET_04                             0x04
#define DKID_SET_05                             0x05
#define DKID_SET_06                             0x06
#define DKID_SET_NEW                            0x11
#define DKID_SET_INVALID                        0xFF

#define DKID_DEL_DEFAULT                        0x00
#define DKID_DEL_01                             0x01
#define DKID_DEL_02                             0x02
#define DKID_DEL_03                             0x03
#define DKID_DEL_04                             0x04
#define DKID_DEL_05                             0x05
#define DKID_DEL_06                             0x06
#define DKID_DEL_NEW                            0x11
#define DKID_DEL_ALL                            0x12
#define DKID_DEL_INVALID                        0xFF

typedef struct
{
    unsigned char BDC_RndNum_Trgt;              //  0x00 : Default
                                                //  0x01 : BLE (UWB_BLE Master)
                                                //  0x02 : UWB (UWB_BLE Master & UWB Anchor)  --> UWB_BLE Master는 아닌거 같은데??? or UWB_BLE_Slave ??
                                                //  0x03 : ALL
    unsigned char BDC_RndNum_TRCod;             //  0x00 : Default
                                                //  0x01 : Request for encryptedData (Cr_CMD 에 대한 암호화된 데이터 송신 요청)
                                                //  0x02 : Request for Receive (Cr_CMD 에 대한 암호화된 데이터 수신 요청)
                                                //  0x03 : Request for encryptedCMDResult(Cr_CMD 에 대한 작동 결과 요청)
    unsigned char BDC_RndNum_Cmd;               //  0x00 : Default
                                                //  0x01 ~ 0x07 : 암호화 통신 종류별 Signal 구분Table참조
    unsigned char BDC_RndNum[6];                //  48 bit length random number for integrity check
    unsigned char BDC_Decrypt_FB;               //  0x00 : Default (Unregistered),
                                                //  0x01 : Positive,
                                                //  0x02 : Negative,
                                                //  0x03 : Invalid
    unsigned char DKID_Set;                     //  0x0 : Default, 0x1:DK#1, 0x2:DK#2, 0x3:DK#3, 0x4:DK#4, 0x5:DK#5
                                                //  0x6:DK#6, 0x7:DK#7, 0x8:DK#8, 0x09:DK#9
                                                //  0x0A:DK#10, 0x0B:DK#11, 0x0C:DK#12, 0x0D:DK#13, 0x0E:DK#14, 0x0F:DK#15,0x10:DK#16
                                                //  0x11:DK#NEW
                                                //  0x12~0xFE : Reserved
                                                //  0xFF:Invalid
    unsigned char DKID_Del;                     //  0x0 : Default, 0x1:DK#1, 0x2:DK#2, 0x3:DK#3, 0x4:DK#4, 0x5:DK#5
                                                //  0x6:DK#6, 0x7:DK#7, 0x8:DK#8, 0x09:DK#9
                                                //  0x0A:DK#10, 0x0B:DK#11, 0x0C:DK#12, 0x0D:DK#13, 0x0E:DK#14, 0x0F:DK#15,0x10:DK#16
                                                //  0x11:DK#NEW
                                                //  0x12:DK#ALL
                                                //  0x13~0xFE : Reserved
                                                //  0xFF:Invalid
    unsigned char UWB_Ranging_Cmd_DKID;
    unsigned char UWB_Ranging_Cmd_Val;

} bst_L_BDC_FD_IAU_02_00ms;


typedef struct
{
    unsigned char BDC_To_BLE_Enc_Data1[29];     //  Encrypted 메시지
                                                //  상세 사양 BDC_IAU_UWBBLEMaster_Encrypted_Comm_System_Spec 참조
} bst_L_BDC_FD_IAU_03_00ms;

typedef struct
{
    unsigned char BDC_To_BLE_Enc_Data2[29];     //  Encrypted 메시지
                                                //  상세 사양 BDC_IAU_UWBBLEMaster_Encrypted_Comm_System_Spec 참조
                                                //  BDCToBLEEncryptData1/2/3/4/5/6BDC_To_BLE_Enc_Data1/2  ???
} bst_L_BDC_FD_IAU_04_00ms;


#define BDC_TP_CAN_STA_IDLE                 0x00
#define BDC_TP_CAN_STA_PROC_FOR_WPC         0x01
#define BDC_TP_CAN_STA_PROC_FOR_DHL         0x02
#define BDC_TP_CAN_STA_PROC_FOR_DHR         0x03
#define BDC_TP_CAN_STA_PROC_FOR_BLE_TRX     0x04
#define BDC_TP_CAN_STA_PROC_FOR_DHRL        0x05
#define BDC_TP_CAN_STA_PROC_FOR_DHRR        0x06
#define BDC_TP_CAN_STA_PROC_FOR_BLE2_TRX    0x07

#define OPADV_ON_CMD_DEFAULT                0x00
#define OPADV_ON_CMD_START_ENABLE           0x01
#define OPADV_ON_CMD_INVALID                0x02

typedef struct
{
    unsigned char BDC_TP_CAN_Sta;               //  0x00 : Idle
                                                //  0x01 : Process for WPC
                                                //  0x02 : Process for DHL
                                                //  0x03 : Process for DHR
                                                //  0x04 : Process for BLE_TRX
                                                //  0x05 : Process for DHRL
                                                //  0x06 : Process for DHRR
                                                //  0x07 : Process for BLE2_TRX
    unsigned char OPAdv_On_Cmd;                 //  0x00 : Default (Stop)
                                                //  0x01 : Start Enable
                                                //  0x02 : Reserved
                                                //  0x03 : Invalid
} bst_L_BDC_FD_IAU_10_200ms;

typedef struct
{
    unsigned char L_TP_BDC_FD_L_UWB_BLE_MST_FD[32];   //TP Data (BDC -> Master)
} bst_L_TP_BDC_FD_L_UWB_BLE_MST_FD;

typedef struct
{
    unsigned char L_TP_BDC_FD_L_UWB_BLE_SLV_FD[32];   //TP Data (BDC -> Slave)
} bst_L_TP_BDC_FD_L_UWB_BLE_SLV_FD;



////////////////////////////////////////////
// MST outgoing msg
////////////////////////////////////////////

#define MST_BLE_DEC_FB_DEFAULT              0x00
#define MST_BLE_DEC_FB_POSITIVE             0x01
#define MST_BLE_DEC_FB_NEGATIVE             0x02

#define MST_SLV_DEC_FB_DEFAULT              0x00
#define MST_SLV_DEC_FB_POSITIVE             0x01
#define MST_SLV_DEC_FB_NEGATIVE             0x02

typedef struct
{
    unsigned char MST_BLE_Decrypt_FB;         //0x00 : Default
                                        //0x01 : Positive   //decrypt success
                                        //0x02 : Negative   //decrypt fail
    unsigned char MST_SLV_Decrypt_FB;         //0x00 : Default
                                        //0x01 : Positive   //decrypt success
                                        //0x02 : Negative   //decrypt fail
} bst_L_UWB_BLE_MST_FD_01_00ms;


#define MST_RN_TRGT_DEFAULT                 0x00
#define MST_RN_TRGT_SLAVE_BLE_IC            0x01
#define MST_RN_TRGT_ANCHOR_UWB_IC           0x02        //????
#define MST_RN_TRGT_SLAVE_MCU               0x03        //????
#define MST_RN_TRGT_UWB_MCU                 0x04        //????
#define MST_RN_TRGT_ALL                     0x05

#define MST_RN_TRCOD_DEFAULT                0x00
#define MST_RN_TRCOD_REQ_FOR_ENC_DATA       0x01
#define MST_RN_TRCOD_REQ_FOR_RECEIVE        0x02
#define MST_RN_TRCOD_REQ_FOR_ENC_CMD_RESULT 0x03
#define MST_RN_TRCOD_REQ_FOR_UPDATE_AUTH    0x04

#define MST_RN_CMD_DEFAULT                  0x00
//#define MST_RN_CMD_MIN                      0x01        //????
//#define MST_RN_CMD_MAX                      0x07        //????

typedef struct
{
    unsigned char MST_RndNum_Trgt;            //0x00 : Default
                                        //0x01 : slave BLE IC
                                        //0x02 : anchor UWB IC
                                        //0x03 : Slave MCU
                                        //0x04 : UWB MCU
                                        //0x05: All
    unsigned char MST_RndNum_TRCode;          //0x00 : Default
                                        //0x01 : Request for encryptedData (Cr_CMD 에 대한 암호화된 데이터 송신 요청)
                                        //0x02 : Request for Receive (Cr_CMD 에 대한 암호화된 데이터 수신 요청)
                                        //0x03 : Request for  encryptedCMDResult (Cr_CMD 에 대한 작동 결과 요청)
                                        //0x04 : Request for Update Auth.
    unsigned char MST_RndNum_Cmd;             //0x00 : Default
                                        //0x01~0x07 : 암호화 통신 종류별 Signal 구분 Table 참조
    unsigned char MST_RndNum[6];              //48 bit length random number for integrity check

} bst_L_UWB_BLE_MST_FD_04_00ms;

typedef struct
{
    unsigned char MST_To_UWB_Enc_Data1[29];   //Encrypted 메시지 - 상세 사양 참조
                                        //BDC_IAU_UWBBLEMaster_Encrypted_Comm_System_Spec
} bst_L_UWB_BLE_MST_FD_05_00ms;

typedef struct
{
    unsigned char MST_To_UWB_Enc_Data2[29];   //Encrypted 메시지 - 상세 사양 참조
                                        //BDC_IAU_UWBBLEMaster_Encrypted_Comm_System_Spec
} bst_L_UWB_BLE_MST_FD_06_00ms;

typedef struct
{
    unsigned char MST_To_UWB_Enc_Data3[29];   //Encrypted 메시지 - 상세 사양 참조
                                        //BDC_IAU_UWBBLEMaster_Encrypted_Comm_System_Spec
} bst_L_UWB_BLE_MST_FD_07_00ms;

typedef struct
{
    unsigned char MST_To_UWB_Enc_Data4[29];   //Encrypted 메시지 - 상세 사양 참조
                                        //BDC_IAU_UWBBLEMaster_Encrypted_Comm_System_Spec
} bst_L_UWB_BLE_MST_FD_08_00ms;

typedef struct
{
    unsigned char MST_To_UWB_Enc_Data5[29];   //Encrypted 메시지 - 상세 사양 참조
                                        //BDC_IAU_UWBBLEMaster_Encrypted_Comm_System_Spec
} bst_L_UWB_BLE_MST_FD_09_00ms;

typedef struct
{
    unsigned char MST_BLE_To_BDC_Enc_Data1[29];   //Encrypted 메시지
                                            //BDC_IAU_UWBBLEMaster_Encrypted_Comm_System_Spec 참조
} bst_L_UWB_BLE_MST_FD_10_00ms;

typedef struct
{
    unsigned char MST_BLE_To_BDC_Enc_Data2[29];   //Encrypted 메시지
                                            //BDC_IAU_UWBBLEMaster_Encrypted_Comm_System_Spec 참조
} bst_L_UWB_BLE_MST_FD_11_00ms;

//	BSWedit insert
typedef struct
{
	unsigned char MST_OTA_CMD;
} bst_L_UWB_BLE_MST_FD_14_00ms;
//


#define MST_BLE_CONNECTED_DEV_IDLE          0x0000
#define MST_BLE_CONNECTED_DEV_01            0x0001
#define MST_BLE_CONNECTED_DEV_02            0x0002
#define MST_BLE_CONNECTED_DEV_03            0x0004
#define MST_BLE_CONNECTED_DEV_04            0x0008
#define MST_BLE_CONNECTED_DEV_05            0x0010
#define MST_BLE_CONNECTED_DEV_06            0x0020

#define MST_BLE_OP_ADV_STAT__OFF            0x00
#define MST_BLE_OP_ADV_STAT__ON             0x01
#define MST_BLE_PASSIVE_ADV_STAT__OFF       0x00
#define MST_BLE_PASSIVE_ADV_STAT__ON        0x01

#define MST_BLE_NEW_DEV_CONN_STATE_DEFAULT      0x00
#define MST_BLE_NEW_DEV_CONN_STATE_CONNECTED    0x01
#define MST_BLE_NEW_DEV_CONN_STATE_DISCONNECTED 0x02
#define MST_BLE_NEW_DEV_CONN_STATE_INVALID      0x03

#define MST_BLE_PAIRING_RESULT_DEFAULT      0x00
#define MST_BLE_PAIRING_RESULT_START        0x01
#define MST_BLE_PAIRING_RESULT_COMPLETE     0x02
#define MST_BLE_PAIRING_RESULT_FAIL         0x03

typedef struct
{
    unsigned char MST_BLE_DK_ID1;               //  0x00:Default, 0x01:DK#1,  0x02:DK#2,  0x03:DK#3,  0x04:DK#4,  0x05:DK#5
                                                //  0x06:DK#6,    0x07:DK#7,  0x08:DK#8,  0x09:DK#9,  0x0A:DK#10, 0x0B:DK#11
                                                //  0x0C:DK#12,   0x0D:DK#13, 0x0E:DK#14, 0x0F:DK#15, 0x10:DK#16
                                                //  0x11:DK#NEW
                                                //  0x12~0xFE : Reserved
                                                //  0xFF:Invalid
    unsigned char MST_BLE_RSSI1;                //  0x00:Default
                                                //  0x01~0xFE : 출력 세기 정의 (ex -8dB = 0x55) ??
                                                //  0xFF:Invalid
    unsigned char MST_BLE_DK_ID2;
    unsigned char MST_BLE_RSSI2;
    unsigned char MST_BLE_DK_ID3;
    unsigned char MST_BLE_RSSI3;
    unsigned char MST_BLE_DK_ID4;
    unsigned char MST_BLE_RSSI4;
    unsigned char MST_BLE_BTAddIRK_Update[2];   //  SHA256(BTAdd||IRK) Hash 값의 상위 2Bytes
//  unsigned short MST_BLE_BTAddIRK_Update;     //  SHA256(BTAdd||IRK) Hash 값의 상위 2Bytes
    unsigned char MST_BLE_ConnectedDeviceInfo[2];
                                                //  0b00000000_00000000 : 폰 연결 없음 (Idle)    0x0000
                                                //  0b00000000_00000001 : 1번 기기 연결          0x0001
                                                //  0b00000000_00000010 : 2번 기기 연결          0x0002 ~
                                                //  0b01000000_00000000 : 15번 기기 연결         0x4000
                                                //  0b10000000_00000000 : 16번 기기 연결         0x8000
    //unsigned short MST_BLE_ConnectedDeviceInfo;
    unsigned char MST_BLE_OP_ADV_State;         //  0x00 : Advertising Off
                                                //  0x01 : Advertising On
    unsigned char MST_BLE_Passive_ADV_State;    //  0x00 : Advertising Off
                                                //  0x01 : Advertising On
    unsigned char MST_BLE_NewDeviceConnetStatus;//  0x00 : Default,
                                                //  0x01 : Connected
                                                //  0x02 : Disconnected
                                                //  0x03 : Invalid
    unsigned char MST_BLE_PairingResult;        //  0x00 : Default
                                                //  0x01 : BLE_Pairing_Start
                                                //  0x02 : BLE_Pairing_Complete
                                                //  0x03 : BLE_Pairing_Fail
} bst_L_UWB_BLE_MST_FD_20_200ms;

typedef struct
{
    unsigned char L_TP_L_UWB_BLE_MST_FD_BDC_FD[32];     //  TP Data (Master -> BDC)
} bst_L_TP_L_UWB_BLE_MST_FD_BDC_FD;

typedef struct
{

} bst_L_UWB_BLE_MST_FD_21_200ms;



////////////////////////////////////////////
// SLV outgoing msg
////////////////////////////////////////////

#define SLV_BLE_DEC_FB_DEFAULT              0x00
#define SLV_BLE_DEC_FB_POSITIVE             0x01
#define SLV_BLE_DEC_FB_NEGATIVE             0x02

#define SLV_MST_DEC_FB_DEFAULT              0x00
#define SLV_MST_DEC_FB_POSITIVE             0x01
#define SLV_MST_DEC_FB_NEGATIVE             0x02
typedef struct
{
    unsigned char SLV_BLE_Decrypt_FB;         //0x00 : Default
                                        //0x01 : Positive    (decrypt해서 정상)
                                        //0x02 : Negative    (decrypt해서 비정상)
    unsigned char SLV_MST_Decrypt_FB;         //0x00 : Default
                                        //0x01 : Positive    (decrypt해서 정상)
                                        //0x02 : Negative    (decrypt해서 비정상)
} bst_L_UWB_BLE_SLV_FD_01_00ms;

typedef struct
{
    unsigned char SLV_To_MST_Enc_Data1[29];   //Encrypted 메시지
                                        //BDC_IAU_UWBBLEMaster_Encrypted_Comm_System_Spec 참조
} bst_L_UWB_BLE_SLV_FD_04_00ms;

typedef struct
{
    unsigned char SLV_To_MST_Enc_Data2[29];   //Encrypted 메시지
                                        //BDC_IAU_UWBBLEMaster_Encrypted_Comm_System_Spec 참조
} bst_L_UWB_BLE_SLV_FD_05_00ms;

typedef struct
{
    unsigned char SLV_To_MST_Enc_Data3[29];   //Encrypted 메시지
                                        //BDC_IAU_UWBBLEMaster_Encrypted_Comm_System_Spec 참조
} bst_L_UWB_BLE_SLV_FD_06_00ms;

typedef struct
{
    unsigned char SLV_To_MST_Enc_Data4[29];   //Encrypted 메시지
                                        //BDC_IAU_UWBBLEMaster_Encrypted_Comm_System_Spec 참조
} bst_L_UWB_BLE_SLV_FD_07_00ms;

typedef struct
{
    unsigned char SLV_To_MST_Enc_Data5[29];   //Encrypted 메시지
                                        //BDC_IAU_UWBBLEMaster_Encrypted_Comm_System_Spec 참조
} bst_L_UWB_BLE_SLV_FD_08_00ms;


#define SLV_BLE_CONNECTED_DEV_IDLE          0x0000
#define SLV_BLE_CONNECTED_DEV_01            0x0001
#define SLV_BLE_CONNECTED_DEV_02            0x0002
#define SLV_BLE_CONNECTED_DEV_03            0x0004
#define SLV_BLE_CONNECTED_DEV_04            0x0008
#define SLV_BLE_CONNECTED_DEV_05            0x0010
#define SLV_BLE_CONNECTED_DEV_06            0x0020

#define SLV_BLE_PASSIVE_ADV_STAT__OFF       0x00
#define SLV_BLE_PASSIVE_ADV_STAT__ON        0x01

#define SLV_BLE_NEW_DEV_CONN_STATE_DEFAULT      0x00
#define SLV_BLE_NEW_DEV_CONN_STATE_CONNECTED    0x01
#define SLV_BLE_NEW_DEV_CONN_STATE_DISCONNECTED 0x02
#define SLV_BLE_NEW_DEV_CONN_STATE_INVALID      0x03

#define SLV_BLE_PAIRING_RESULT_DEFAULT      0x00
#define SLV_BLE_PAIRING_RESULT_START        0x01
#define SLV_BLE_PAIRING_RESULT_COMPLETE     0x02
#define SLV_BLE_PAIRING_RESULT_FAIL         0x03

#define SLV_BLE_BONDING_STAT_IDLE           0x0000
#define SLV_BLE_BONDING_STAT_01             0x0001
#define SLV_BLE_BONDING_STAT_02             0x0002
#define SLV_BLE_BONDING_STAT_03             0x0004
#define SLV_BLE_BONDING_STAT_04             0x0008
#define SLV_BLE_BONDING_STAT_05             0x0010
#define SLV_BLE_BONDING_STAT_06             0x0020

typedef struct
{
    unsigned char SLV_BLE_DK_ID1;             //0x0 : Default, 0x1:DK#1, 0x2:DK#2, 0x3:DK#3, 0x4:DK#4, 0x5:DK#5
                                        //0x6:DK#6, 0x7:DK#7, 0x8:DK#8, 0x09:DK#9
                                        //0x0A:DK#10, 0x0B:DK#11, 0x0C:DK#12, 0x0D:DK#13, 0x0E:DK#14, 0x0F:DK#15,0x10:DK#16
                                        //0x11:DK#NEW
                                        //0x12~0xFE : Reserved
                                        //0xFF:Invalid
    unsigned char SLV_BLE_RSSI1;              //0x00 : Default
                                        //0x01~0xFE : 출력 세기 정의 (ex -8dB = 0x55) ??
                                        //0xFF : Invalid
    unsigned char SLV_BLE_DK_ID2;
    unsigned char SLV_BLE_RSSI2;
    unsigned char SLV_BLE_DK_ID3;
    unsigned char SLV_BLE_RSSI3;
    unsigned char SLV_BLE_DK_ID4;
    unsigned char SLV_BLE_RSSI4;
    unsigned char SLV_BLE_BTAddIRK_Update[2]; //SHA256(BTAdd||IRK) Hash 값의 상위 2Bytes
//    unsigned short SLV_BLE_BTAddIRK_Update; //SHA256(BTAdd||IRK) Hash 값의 상위 2Bytes
    unsigned char SLV_BLE_ConnectedDeviceInfo[2]; //0b00000000_00000000 : 폰 연결 없음 (Idle)  0x0000
                                            //0b00000000_00000001 : 1번 기기 연결         0x0001
                                            //0b00000000_00000010 : 2번 기기 연결         0x0002
                                            //0b00000000_00000100 : 3번 기기 연결         0x0004
                                            //0b00000000_00001000 : 4번 기기 연결         0x0008
                                            //0b00000000_00010000 : 5번 기기 연결         0x0010
                                            //0b00000000_00100000 : 6번 기기 연결         0x0020
                                            //0b00000000_01000000 : 7번 기기 연결         0x0040
                                            //0b00000000_10000000 : 8번 기기 연결         0x0080
                                            //0b00000001_00000000 : 9번 기기 연결         0x0100
                                            //0b00000010_00000000 : 10번 기기 연결        0x0200
                                            //0b00000100_00000000 : 11번 기기 연결        0x0400
                                            //0b00001000_00000000 : 12번 기기 연결        0x0800
                                            //0b00010000_00000000 : 13번 기기 연결        0x1000
                                            //0b00100000_00000000 : 14번 기기 연결        0x2000
                                            //0b01000000_00000000 : 15번 기기 연결        0x4000
                                            //0b10000000_00000000 : 16번 기기 연결        0x8000
    //unsigned short SLV_BLE_ConnectedDeviceInfo;
    unsigned char SLV_BLE_Passive_ADV_State;      //0x00 : Advertising Off
                                            //0x01 : Advertising On
    unsigned char SLV_BLE_NewDeviceConnetStatus;  //0x00 : Default,
                                            //0x01 : Connected
                                            //0x02 : Disconnected
                                            //0x03 : Invalid
    unsigned char SLV_BLE_PairingResult;          //0x00:Default
                                            //0x01:BLE_Pairing_Start
                                            //0x02:BLE_Pairing_Complete
                                            //0x03:BLE_Pairing_Fail
    unsigned char SLV_BLE_BondingDataStatus[2];   //0b00000000_00000000 : 폰 연결 없음 (Idle)      0x0000
                                            //0b00000000_00000001 : 1번 기기 Pairing 완료   0x0001
                                            //0b00000000_00000010 : 2번 기기 Pairing 완료   0x0002
                                            //0b00000000_00000100 : 3번 기기 Pairing 완료   0x0004
                                            //0b00000000_00001000 : 4번 기기 Pairing 완료   0x0008
                                            //0b00000000_00010000 : 5번 기기 Pairing 완료   0x0010
                                            //0b00000000_00100000 : 6번 기기 Pairing 완료   0x0020
                                            //0b00000000_01000000 : 7번 기기 Pairing 완료   0x0040
                                            //0b00000000_10000000 : 8번 기기 Pairing 완료   0x0080
                                            //0b00000001_00000000 : 9번 기기 Pairing 완료   0x0100
                                            //0b00000010_00000000 : 10번 기기 Pairing 완료  0x0200
                                            //0b00000100_00000000 : 11번 기기 Pairing 완료  0x0400
                                            //0b00001000_00000000 : 12번 기기 Pairing 완료  0x0800
                                            //0b00010000_00000000 : 13번 기기 Pairing 완료  0x1000
                                            //0b00100000_00000000 : 14번 기기 Pairing 완료  0x2000
                                            //0b01000000_00000000 : 15번 기기 Pairing 완료  0x4000
                                            //0b10000000_00000000 : 16번 기기 Pairing 완료  0x8000
    //unsigned short SLV_BLE_BondingDataStatus;
} bst_L_UWB_BLE_SLV_FD_20_200ms;

typedef struct
{
    unsigned char L_TP_L_UWB_BLE_SLV_FD_BDC_FD[32];   //TP Data (Slave → BDC)
} bst_L_TP_L_UWB_BLE_SLV_FD_BDC_FD;

typedef struct
{
    unsigned char SLV_SW_BLE_Ver_Major;
    unsigned char SLV_SW_BLE_Ver_Minor;
} bst_L_UWB_BLE_SLV_FD_21_200ms;



#ifdef __cplusplus
}
#endif

#endif //__DEFINE_BLE_H__
