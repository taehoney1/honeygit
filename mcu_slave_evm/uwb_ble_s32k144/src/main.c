//----------------------------------------------
//----------------------------------------------
#include <interrupt_manager.h>
#include <stdint.h>
#include <stdbool.h>

#include "sdk_project_config.h"

#include "defineble.h"
#include "definecanoe.h"

#include "defines.h"

#include "commpc.h"
#include "commcanoe.h"
#include "commble.h"
#include "commuwb.h"


//----------------------------------------------
//	Definitions
//----------------------------------------------


//----------------------------------------------
//	Variables
//----------------------------------------------
volatile unsigned int m_nEvent;

volatile int exit_code = 0;


//----------------------------------------------
//	Prototype Functions
//----------------------------------------------
static void buttonISR(void);

static void BoardInit(void);
static void GPIOInit(void);

static unsigned int getAllEvents(void);


//----------------------------------------------
//	Functions
//----------------------------------------------
int main(void)
{
	//	Do the initializations required for this application
    BoardInit();
    GPIOInit();

    initPC();
    initBLE();
    initUWB();
    initCANOE();

    //	OSIF_TimeDelay_baremetal_Activity : WARNNING!!! If it operates for 49 to 50 days, a critical error occurs.!!!
    OSIF_TimeDelay(1);

    while(1)
    {
    	unsigned int nEvent;

    	nEvent = getAllEvents();

    	commCANOE(nEvent);
    	commPC(nEvent);
    	commBLE(nEvent);
    	commUWB(nEvent);
    }

    for(;;)
    {
    	if(exit_code != 0)
    	{
    		break;
    	}
    }

    return exit_code;
}


//----------------------------------------------
//	CALLBACK Functions
//----------------------------------------------
static void buttonISR(void)
{
	//	Check if one of the buttons was pressed
    unsigned int nButtonsPressed = PINS_DRV_GetPortIntFlag(BTN_PORT) & ((1 << BTN1_PIN) | (1 << BTN2_PIN));

	switch(nButtonsPressed)
    {
	case (1 << BTN1_PIN):
		setEvent(EVENT_BTN1);
        PINS_DRV_ClearPinIntFlagCmd(BTN_PORT, BTN1_PIN);
        break;
    case (1 << BTN2_PIN):
    	setEvent(EVENT_BTN2);
        PINS_DRV_ClearPinIntFlagCmd(BTN_PORT, BTN2_PIN);
        break;
    default:
    	if(nButtonsPressed)
    	{
    		PINS_DRV_ClearPortIntFlagCmd(BTN_PORT);
        }
    	break;
    }
}


//----------------------------------------------
//	initial
//----------------------------------------------
static void BoardInit(void)
{
    CLOCK_DRV_Init(&clockMan1_InitConfig0);

    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    //	initialize DMA
    EDMA_DRV_Init(&dmaController_State, &dmaController_InitConfig, edmaChnStateArray, edmaChnConfigArray, EDMA_CONFIGURED_CHANNELS_COUNT);
}

static void GPIOInit(void)
{
	//	Output direction for LEDs
    PINS_DRV_SetPinsDirection(LED_GPIO, (1 << LED1) | (1 << LED0));

    PINS_DRV_SetPins(LED_GPIO, (1 << LED0));
    PINS_DRV_ClearPins(LED_GPIO, (1 << LED1));

    //	Setup button pin
    PINS_DRV_SetPinsDirection(BTN_GPIO, ~((1 << BTN1_PIN) | (1 << BTN2_PIN)));

    PINS_DRV_SetPinIntSel(BTN_PORT, BTN1_PIN, PORT_INT_RISING_EDGE);
    PINS_DRV_SetPinIntSel(BTN_PORT, BTN2_PIN, PORT_INT_RISING_EDGE);

    //	Install buttons ISR
    INT_SYS_InstallHandler(BTN_PORT_IRQn, &buttonISR, NULL);
    //	Enable buttons interrupt
    INT_SYS_EnableIRQ(BTN_PORT_IRQn);
}


//----------------------------------------------
//	Event
//----------------------------------------------
static unsigned int getAllEvents(void)
{
	unsigned int nEvent;

	INT_SYS_DisableIRQGlobal();
	nEvent = m_nEvent;
	m_nEvent = 0;
	INT_SYS_EnableIRQGlobal();

	return nEvent;
}

void setEvent(unsigned int nEvent)
{
	INT_SYS_DisableIRQGlobal();
	m_nEvent = m_nEvent | nEvent;
	INT_SYS_EnableIRQGlobal();
}


//----------------------------------------------
//	IO
//----------------------------------------------
void toggleLed()
{
	PINS_DRV_TogglePins(LED_GPIO, (1 << LED0));
}
