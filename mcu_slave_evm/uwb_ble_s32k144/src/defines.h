#ifndef _DEFINES_H_
#define _DEFINES_H_


#ifdef __cplusplus
}
#endif

#include "util.h"

#define QUEUE_SUCCESS			1
#define QUEUE_FAIL				0
#define QUEUE_FUZZY				-1

//	DEBUG
#define BLE_DEBUG_SEND
//#define UWB_DEBUG_SEND

//	FLASH
#define HEADER_BLE_FLASH_WRITE
//#define HEADER_UWB_FLASH_WRITE

#define FLASH_SIZE_BLE_HEADER	0x10
#define FLASH_SIZE_UWB_HEADER	0x10

#define FLASH_ADDR_BLE_HEADER	0x00040000		//	size, version, CRC32, signature-confirm(not used)
#define FLASH_ADDR_BLE_PROGRAM	(FLASH_ADDR_BLE_HEADER + FLASH_SIZE_BLE_HEADER)
#define FLASH_ADDR_UWB_HEADER	0x00068000		//	size, version, CRC32, signature-confirm(not used)
#define FLASH_ADDR_UWB_PROGRAM	(FLASH_ADDR_UWB_HEADER + FLASH_SIZE_UWB_HEADER)


//	BUTTON TEST
//	1=CAN, 2=BLE, 3=UWB
#define BUTTON_TEST				2


//	EVENT
enum
{
	eEVENT_SYSTICK = 0,
	eEVENT_BTN1,
	eEVENT_BTN2,
	eEVENT_RXUART1,
	eEVENT_TXUART1,
	eEVENT_RXUART2,
	eEVENT_TXUART2,
	eEVENT_SPIREADY,
	eEVENT_SPIINT,
	eEVENT_SPITO,
	eEVENT_UCIREADY,
	eEVENT_UCIINT,
	eEVENT_UCITO,
};

#define EVENT_NONE				0

#define EVENT_SYSTICK			(1 << eEVENT_SYSTICK)
#define EVENT_BTN1				(1 << eEVENT_BTN1)
#define EVENT_BTN2				(1 << eEVENT_BTN2)
#define EVENT_RXUART1			(1 << eEVENT_RXUART1)
#define EVENT_TXUART1			(1 << eEVENT_TXUART1)
#define EVENT_RXUART2			(1 << eEVENT_RXUART2)
#define EVENT_TXUART2			(1 << eEVENT_TXUART2)
#define EVENT_SPIREADY			(1 << eEVENT_SPIREADY)
#define EVENT_SPIINT			(1 << eEVENT_SPIINT)
#define EVENT_SPITO				(1 << eEVENT_SPITO)
#define EVENT_UCIREADY			(1 << eEVENT_UCIREADY)
#define EVENT_UCIINT			(1 << eEVENT_UCIINT)
#define EVENT_UCITO				(1 << eEVENT_SPITO)


enum
{
    eEVENT_BUTTON_LEFT          = 0,
    eEVENT_BUTTON_RIGHT,
    eEVENT_TIMER,
    eEVENT_SPI_CONTROLLER,
    eEVENT_SPI_PERIPHERAL,
    eEVENT_SPI_SLAVE_READY,
    eEVENT_SPI_SLAVE_DATAREADY,
    eEVENT_UART_RECV,
    eEVENT_UART_SEND_TO,
};


#define EVENT_BUTTON_LEFT               (1 << eEVENT_BUTTON_LEFT)
#define EVENT_BUTTON_RIGHT              (1 << eEVENT_BUTTON_RIGHT)
#define EVENT_TIMER                     (1 << eEVENT_TIMER)
#define EVENT_SPI_CONTROLLER            (1 << eEVENT_SPI_CONTROLLER)
#define EVENT_SPI_PERIPHERAL            (1 << eEVENT_SPI_PERIPHERAL)
#define EVENT_SPI_SLAVE_READY           (1 << eEVENT_SPI_SLAVE_READY)
#define EVENT_SPI_SLAVE_DATAREADY       (1 << eEVENT_SPI_SLAVE_DATAREADY)
#define EVENT_UART_RECV                 (1 << eEVENT_UART_RECV)
#define EVENT_UART_SEND_TO              (1 << eEVENT_UART_SEND_TO)

#define EVENT_PROCESS                   (EVENT_BUTTON_LEFT | EVENT_BUTTON_RIGHT | EVENT_TIMER | EVENT_SPI_CONTROLLER | EVENT_SPI_SLAVE_READY | EVENT_SPI_SLAVE_DATAREADY | EVENT_UART_RECV)



//	BUTTON + LED
#define BTN_PORT        		PORTC
#define BTN_GPIO        		PTC
#define BTN1_PIN        		13U
#define BTN2_PIN        		12U

#define LED_PORT        		PORTD
#define LED_GPIO				PTD
#define LED0            		15U
#define LED1            		16U

#define BTN_PORT_IRQn  			 PORTC_IRQn



//	COMM
enum
{
	eSPI_LINK_BLE = 0,
	eSPI_LINK_UWB,
	eSPI_LINK_MAX,
};

enum
{
    eBDC = 0,
    eMST,
    eSLV,
    eUWB_FL,
    eUWB_FR,
    eUWB_RL,
    eUWB_RR,
    eUWB_TRNK,
    eUWB_FRNK,
    eDOWN,
};

enum
{
	eMSG_TYPE_REQ = 1,
	eMSG_TYPE_RES,
	eMSG_TYPE_EVT,
	eMSG_TYPE_EVT_CONFIRM,
	eMSG_TYPE_NOTI,
	eMSG_TYPE_NOTI_CONFIRM,
};

enum
{
    ePROC_STATE_DOWN_START = 0,
    ePROC_STATE_DOWN_ERASE,
    ePROC_STATE_DOWN_INFO_ADDR,
    ePROC_STATE_DOWN_INFO_DATA,
    ePROC_STATE_DOWN_ADDR,
    ePROC_STATE_DOWN_DATA,
    ePROC_STATE_DOWN_VERIFY,
    ePROC_STATE_DOWN_VERSION,
};


#define COMM_IDF                0x7D
#define COMM_EOF                0x7E

#define COMM_ACK                0xCC
#define COMM_NAK                0x33

#define COMMAND_PING            0x20            //  3
#define COMMAND_DOWNLOAD        0x21            //  11
#define COMMAND_GET_STATUS      0x23            //  3
#define COMMAND_SEND_DATA       0x24            //  4 ~ 0xFF
#define COMMAND_RESET           0x25            //  3
#define COMMAND_SECTOR_ERASE    0x26            //  7
#define COMMAND_CRC32           0x27            //  15
#define COMMAND_GET_CHIP_ID     0x28            //  3
#define COMMAND_MEMORY_READ     0x2A            //  9
#define COMMAND_MEMORY_WRITE    0x2B            //  9 ~ 0xFF
#define COMMAND_BANK_ERASE      0x2C            //  3
#define COMMAND_SET_CCFG        0x2D            //  11
#define COMMAND_DOWNLOAD_CRC  	0x2F            //  15

#define COMMAND_BLE				0x42			// 'B'
#define COMMAND_BLE_COMM		(COMMAND_BLE + 0)
#define COMMAND_BLE_REPROGRAM	(COMMAND_BLE + 1)
#define COMMAND_BLE_SET_HDR		(COMMAND_BLE + 2)
#define COMMAND_BLE_RES_HDR		(COMMAND_BLE + 3)
#define COMMAND_BLE_SET_FILE	(COMMAND_BLE + 4)
#define COMMAND_BLE_RES_FILE	(COMMAND_BLE + 5)
#define COMMAND_BLE_REQ_CRC32	(COMMAND_BLE + 6)
#define COMMAND_BLE_RES_CRC32	(COMMAND_BLE + 7)
#if BUTTON_TEST == 2
#define COMMAND_BLE_TEST		(COMMAND_BLE + 10)
#endif

#define COMMAND_UWB				0x55			// 'U'
#define COMMAND_UWB_COMM		(COMMAND_UWB + 0)
#define COMMAND_UWB_REPROGRAM	(COMMAND_UWB + 1)
#define COMMAND_UWB_SET_HDR		(COMMAND_UWB + 2)
#define COMMAND_UWB_RES_HDR		(COMMAND_UWB + 3)
#define COMMAND_UWB_SET_FILE	(COMMAND_UWB + 4)
#define COMMAND_UWB_RES_FILE	(COMMAND_UWB + 5)
#define COMMAND_UWB_REQ_CRC32	(COMMAND_UWB + 6)
#define COMMAND_UWB_RES_CRC32	(COMMAND_UWB + 7)

#define COMMAND_HEARTBEAT       0x60            //  8

#define COMMAND_DEBUG           0x61            //  4 ~ 0xFF
#define COMMAND_COMMAND			0x62


#define COMMAND_MCU_FLASH_ERASE		0x85           //2024.05.09 Taeheon
#define COMMAND_MCU_FLASH_WRITE		0x86		   //2024.05.09 Taeheon
#define COMMAND_CRC_CHECK			0x87		   //2024.05.09 Taeheon

#define COMMAND_SOF				0xCD
#define COMMAND_FCS				0xFF
#define COMMAND_EOF				0x0A

#define RESPONSE_SUCCESS		0x00

#define RESPONSE_ERROR_ERASE	0xF0
#define RESPONSE_ERROR_BLANK	0xF1
#define RESPONSE_ERROR_PROGRAM	0xF2
#define RESPONSE_ERROR_CRC32	0xF3

#define FLASH_BUFFER_MAX        0x80

#ifdef __cplusplus
}
#endif

#endif
