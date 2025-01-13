/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v7.0
processor: S32K144
package_id: S32K144_LQFP100
mcu_data: s32sdk_s32k1xx_rtm_401
processor_version: 0.0.0
pin_labels:
- {pin_num: '9', pin_signal: PTE4, label: CAN_RX, identifier: CAN_RX}
- {pin_num: '8', pin_signal: PTE5, label: CAN_TX, identifier: CAN_TX}
- {pin_num: '22', pin_signal: PTD15, label: led0_evb, identifier: led0_evb}
- {pin_num: '21', pin_signal: PTD16, label: led1_evb, identifier: led1_evb}
- {pin_num: '40', pin_signal: PTC0, label: led0_mb, identifier: led0_mb}
- {pin_num: '39', pin_signal: PTC1, label: led1_mb, identifier: led1_mb}
- {pin_num: '50', pin_signal: PTC12, label: btn2, identifier: btn2}
- {pin_num: '49', pin_signal: PTC13, label: btn1, identifier: btn1}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External variable could be made static.
 * The external variables will be used in other source files in application code.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 11.4, Conversion between a pointer and integer type.
 * The cast is required to initialize a pointer with an unsigned long define, representing an address.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 11.6, Cast from unsigned int to pointer.
 * The cast is required to initialize a pointer with an unsigned long define, representing an address.
 *
 */

#include "pin_mux.h"

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0}
- pin_list:
  - {pin_num: '9', peripheral: CAN0, signal: 'rxd, rxd', pin_signal: PTE4}
  - {pin_num: '8', peripheral: CAN0, signal: 'txd, txd', pin_signal: PTE5}
  - {pin_num: '22', peripheral: PORTD, signal: 'port, 15', pin_signal: PTD15, direction: OUTPUT}
  - {pin_num: '21', peripheral: PORTD, signal: 'port, 16', pin_signal: PTD16, direction: OUTPUT}
  - {pin_num: '40', peripheral: PORTC, signal: 'port, 0', pin_signal: PTC0, direction: OUTPUT}
  - {pin_num: '39', peripheral: PORTC, signal: 'port, 1', pin_signal: PTC1, direction: OUTPUT}
  - {pin_num: '50', peripheral: PORTC, signal: 'port, 12', pin_signal: PTC12, direction: INPUT}
  - {pin_num: '49', peripheral: PORTC, signal: 'port, 13', pin_signal: PTC13, direction: INPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

  /* Generate array of configured pin structures */
  pin_settings_config_t g_pin_mux_InitConfigArr0[NUM_OF_CONFIGURED_PINS0] = {
    {
        .base            = PORTC,
        .pinPortIdx      = 0U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTC,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTC,
        .pinPortIdx      = 1U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTC,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTC,
        .pinPortIdx      = 12U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTC,
        .direction       = GPIO_INPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTC,
        .pinPortIdx      = 13U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTC,
        .direction       = GPIO_INPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTD,
        .pinPortIdx      = 15U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTD,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
    {
        .base            = PORTD,
        .pinPortIdx      = 16U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTD,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
	//	CAN
    {
        .base            = PORTE,
        .pinPortIdx      = 4U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT5,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
    {
        .base            = PORTE,
        .pinPortIdx      = 5U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT5,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },

	//	REPROGRAM + with BLE
    {
        .base            = PORTA,
        .pinPortIdx      = 12U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTA,
        .digitalFilter   = false,
		.initValue		 = 1U,
    },

	//	SPI + with BLE
    {
        .base            = PORTA,
        .pinPortIdx      = 2U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTA,
        .digitalFilter   = false,
    },
	{
        .base            = PORTA,
        .pinPortIdx      = 3U,
        .pullConfig      = PORT_INTERNAL_PULL_UP_ENABLED,
        .driveSelect     = PORT_HIGH_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
//        .intConfig       = PORT_INT_FALLING_EDGE,
		.intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTA,
        .digitalFilter   = false,
    },
	//	SPI with BLE
    {
        .base            = PORTB,
        .pinPortIdx      = 14U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT3,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
#if 0
    {
        .base            = PORTB,
        .pinPortIdx      = 15U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT3,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
#else
    {
        .base            = PORTD,
        .pinPortIdx      = 1U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT3,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
#endif
    {
        .base            = PORTB,
        .pinPortIdx      = 16U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT3,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
	{
		.base            = PORTB,
		.pinPortIdx      = 17U,
		.pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
		.driveSelect     = PORT_LOW_DRIVE_STRENGTH,
		.passiveFilter   = false,
		.mux             = PORT_MUX_ALT3,
		.pinLock         = false,
		.intConfig       = PORT_DMA_INT_DISABLED,
		.clearIntFlag    = false,
		.gpioBase        = NULL,
		.digitalFilter   = false,
	},
	//	REPROGRAM + with UWB
	{
		.base            = PORTB,
		.pinPortIdx      = 0U,
		.pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
		.driveSelect     = PORT_LOW_DRIVE_STRENGTH,
		.passiveFilter   = false,
		.mux             = PORT_MUX_AS_GPIO,
		.pinLock         = false,
		.intConfig       = PORT_DMA_INT_DISABLED,
		.clearIntFlag    = false,
        .gpioBase        = PTB,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 1U,
	},
	{
		.base            = PORTB,
		.pinPortIdx      = 1U,
		.pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
		.driveSelect     = PORT_LOW_DRIVE_STRENGTH,
		.passiveFilter   = false,
		.mux             = PORT_MUX_AS_GPIO,
		.pinLock         = false,
		.intConfig       = PORT_DMA_INT_DISABLED,
		.clearIntFlag    = false,
        .gpioBase        = PTB,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 1U,
	},
    {
        .base            = PORTC,
        .pinPortIdx      = 5U,
        .pullConfig      = PORT_INTERNAL_PULL_UP_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTC,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
    },
	//	SPI + with UWB
    {
        .base            = PORTE,
        .pinPortIdx      = 0U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTE,
		.direction		 = GPIO_INPUT_DIRECTION,
        .digitalFilter   = false,
    },
	{
        .base            = PORTE,
        .pinPortIdx      = 9U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_HIGH_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_AS_GPIO,
        .pinLock         = false,
		.intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = PTE,
		.direction		 = GPIO_INPUT_DIRECTION,
        .digitalFilter   = false,
    },
	//	SPI with UWB : LPSPI0
    {
        .base            = PORTB,
        .pinPortIdx      = 2U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT3,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
    {
        .base            = PORTB,
        .pinPortIdx      = 3U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT3,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
    {
        .base            = PORTB,
        .pinPortIdx      = 4U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT3,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
	{
		.base            = PORTB,
		.pinPortIdx      = 5U,
		.pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
		.driveSelect     = PORT_LOW_DRIVE_STRENGTH,
		.passiveFilter   = false,
		.mux             = PORT_MUX_AS_GPIO,
		.pinLock         = false,
		.intConfig       = PORT_DMA_INT_DISABLED,
		.clearIntFlag    = false,
        .gpioBase        = PTB,
        .direction       = GPIO_OUTPUT_DIRECTION,
        .digitalFilter   = false,
        .initValue       = 0U,
	},
	//	UART
	{
		.base            = PORTC,
	    .pinPortIdx      = 6U,
	    .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
	    .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
	    .passiveFilter   = false,
	    .mux             = PORT_MUX_ALT2,
	    .pinLock         = false,
	    .intConfig       = PORT_DMA_INT_DISABLED,
	    .clearIntFlag    = false,
	    .gpioBase        = NULL,
	    .digitalFilter   = false,
	},
	{
	    .base            = PORTC,
	    .pinPortIdx      = 7U,
	    .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
	    .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
	    .passiveFilter   = false,
	    .mux             = PORT_MUX_ALT2,
	    .pinLock         = false,
	    .intConfig       = PORT_DMA_INT_DISABLED,
	    .clearIntFlag    = false,
	    .gpioBase        = NULL,
	    .digitalFilter   = false,
	},
#if 1
    {
        .base            = PORTA,
        .pinPortIdx      = 8U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT2,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
#else
    {
        .base            = PORTD,
        .pinPortIdx      = 17U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT3,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
#endif
    {
        .base            = PORTA,
        .pinPortIdx      = 9U,
        .pullConfig      = PORT_INTERNAL_PULL_NOT_ENABLED,
        .driveSelect     = PORT_LOW_DRIVE_STRENGTH,
        .passiveFilter   = false,
        .mux             = PORT_MUX_ALT2,
        .pinLock         = false,
        .intConfig       = PORT_DMA_INT_DISABLED,
        .clearIntFlag    = false,
        .gpioBase        = NULL,
        .digitalFilter   = false,
    },
  };
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
