/*
 * Copyright (c) 2018-2023, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== spicontroller.c ========
 */
#include <stddef.h>
#include <stdint.h>
#include <string.h>

/* POSIX Header files */
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/SPI.h>
#include <ti/display/Display.h>

/* Driver configuration */
#include "ti_drivers_config.h"


//----------------------------------------------
//  Definitions
//----------------------------------------------
#define THREADSTACKSIZE (1024)

#define SPI_MSG_LENGTH (0x90)
#define CONTROLLER_MSG ("Hello from controller, msg#: ")

#define MAX_LOOP (10)

#define INITIATOR_ENABLE 0
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
    eTYPE_TRANSMIT_NONE = 0,
    eTYPE_TRANSMIT_REQUEST,
    eTYPE_TRANSMIT_RESPONSE_1,
    eTYPE_TRANSMIT_RESPONSE_2,
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

typedef struct
{
    unsigned int nSendname;
    unsigned int nSendlength;
} structUciTable;

#define INIT_COUNTER_MAX        6

#if INITIATOR_ENABLE
const uint8_t CIR_LOG[] = {0x20,0x04,0x00,0x0A,0x02,0xF4,0x01,0x01,0xF6,0x04,0xFF,0xFF,0x07,0x00};
const uint8_t SESSION_INIT_CMD[] = {0x21,0x00,0x00,0x05,0xCA,0xFE,0xFA,0xCE,0xA0};
const uint8_t SESSION_SET_APP_CONFIG_CMD1[] = {0x21,0x03,0x00,0x25,
    0xCA,0xFE,0xFA,0xCE,
    0x09,                                       //  number of parameters
    0x04,0x01,0x09,                             //  channel number korea = 9
    0x05,0x01,0x04,                             //  number of controller 1??
    0x06,0x02,0x00,0x00,                        //  device type
    0x08,0x02,0x60,0x09,                        //  slot duration 2400rtsu = 2000us)
    0x09,0x04,0xE0,0x01,0x00,0x00,              //  ranging interval D8:216ms 60:96ms 01E0:480ms
    0x11,0x01,0x00,                             //  role 00:responder 01:initial
    0xF2,0x01,0x3C,                             //  transmit power
    0x1B,0x01,0x0C,                             //  slot per round
    0x2C,0x01,0x03                              //  hopping mode 00?
};
const uint8_t SESSION_SET_APP_CONFIG_CMD2[] = {0x21,0x03,0x00,0x08,0xCA,0xFE,0xFA,0xCE,0x01,0x1E,0x01,0x00};
const uint8_t SESSION_SET_APP_CONFIG_CMD_CIR[] = {0x21,0x03,0x00,0x0D,0xCA,0xFE,0xFA,0xCE,0x02,0xF7,0x02,0x00,0x00,0xF8,0x02,0x00,0x04};

const uint8_t RANGE_START_CMD[] = {0x22, 0x00, 0x00, 0x04, 0xCA, 0xFE, 0xFA, 0xCE};
const uint8_t RANGE_STOP_CMD[]  = {0x22, 0x01, 0x00, 0x04, 0xCA, 0xFE, 0xFA, 0xCE};

static structUciTable m_InitTable[INIT_COUNTER_MAX] = {
    {(unsigned int)CIR_LOG,                         sizeof(CIR_LOG)},
    {(unsigned int)SESSION_INIT_CMD,                sizeof(SESSION_INIT_CMD)},
    {(unsigned int)SESSION_SET_APP_CONFIG_CMD1,     sizeof(SESSION_SET_APP_CONFIG_CMD1)},
    {(unsigned int)SESSION_SET_APP_CONFIG_CMD2,     sizeof(SESSION_SET_APP_CONFIG_CMD2)},
    {(unsigned int)SESSION_SET_APP_CONFIG_CMD_CIR,  sizeof(SESSION_SET_APP_CONFIG_CMD_CIR)},
    {(unsigned int)RANGE_START_CMD,                 sizeof(RANGE_START_CMD)}
};

#else

const uint8_t CIR_LOG[] = {0x20,0x04,0x00,0x04,0x01,0x01,0x01,0x00};
const uint8_t TRIM_VALUES[] = {0x2E,0x26,0x00,0x03,0x01,0x04,0x00};
const uint8_t SESSION_INIT_CMD[] = {0x21,0x00,0x00,0x05,0x01,0x00,0x00,0x00,0xA0};
const uint8_t SESSION_SET_APP_CONFIG_CMD1[] = { 0x21,0x03,0x00,0x32,
    0x01,0x00,0x00,0x00,
    0x0D,0x04,0x01,0x09,
    0x05,0x01,0x08,0x06,
    0x02,0x00,0x01,0x08,
    0x02,0x60,0x09,0x09,
    0x04,0x20,0x01,0x00,
    0x00,0x11,0x01,0x01,
    0x14,0x01,0x09,0x15,
    0x01,0xFF,0xF2,0x01,
    0x00,0x1B,0x01,0x0C,
    0x2C,0x01,0x00,0xA4,
    0x02,0x00,0x00,0xA5,
    0x01,0x22
};

const uint8_t SESSION_SET_APP_CONFIG_CMD2[] = {0x22,0x00,0x00,0x04,0x01,0x00,0x00,0x00};
const uint8_t RANGE_START_CMD[] = {0x22, 0x00, 0x00, 0x04, 0xCA, 0xFE, 0xFA, 0xCE};
const uint8_t RANGE_STOP_CMD[]  = {0x22, 0x01, 0x00, 0x04, 0xCA, 0xFE, 0xFA, 0xCE};

static structUciTable m_InitTable[INIT_COUNTER_MAX] = {
    {(unsigned int)CIR_LOG,                         sizeof(CIR_LOG)},
    {(unsigned int)TRIM_VALUES,                     sizeof(TRIM_VALUES)},
    {(unsigned int)SESSION_INIT_CMD,                sizeof(SESSION_INIT_CMD)},
    {(unsigned int)SESSION_SET_APP_CONFIG_CMD1,     sizeof(SESSION_SET_APP_CONFIG_CMD1)},
    {(unsigned int)SESSION_SET_APP_CONFIG_CMD2,     sizeof(SESSION_SET_APP_CONFIG_CMD2)},
    {(unsigned int)RANGE_START_CMD,                 sizeof(RANGE_START_CMD)}
};


#endif






//----------------------------------------------
//  Variables
//----------------------------------------------
static Display_Handle display;

unsigned char controllerRxBuffer[SPI_MSG_LENGTH];
unsigned char controllerTxBuffer[SPI_MSG_LENGTH];
unsigned char controllerZeroBuffer[SPI_MSG_LENGTH];

static volatile unsigned char m_UciTemp[4];

static int m_nUciStep = eSTEP_UCI_IDLE;
static int m_nFlowStep = eSTEP_FLOW_IDLE;
static int m_nFlowNext = eSTEP_FLOW_IDLE;
static int m_nTransmitType = eTYPE_TRANSMIT_NONE;

static int m_nGID;
static int m_nOPID;

extern void simpleCopy(unsigned char *pDest, unsigned char *pSrc, int cbData);

static int m_nInitCounter;
static int m_nNumberSendsize = 0;
static int m_nNumberReadsize = 0;

static bool m_bInitDone = false;
static bool m_bResponseDone = false;
/* Semaphore to block controller until peripheral is ready for transfer */
sem_t controllerSem;



//----------------------------------------------
//  Function
//----------------------------------------------

static void procUci(SPI_Transaction transaction, SPI_Handle controllerSpi;);
static void procFlow(void);
void my_delay(int milliseconds);

/*
 *  ======== peripheralReadyFxn ========
 *  Callback function for the GPIO interrupt on CONFIG_SPI_PERIPHERAL_READY.
 */
void peripheralReadyFxn(uint_least8_t index)
{
    sem_post(&controllerSem);
}

/*
 *  ======== controllerThread ========
 *  Controller SPI sends a message to peripheral while simultaneously receiving a
 *  message from the peripheral.
 */
void *controllerThread(void *arg0)
{
    SPI_Handle controllerSpi;
    SPI_Params spiParams;
    SPI_Transaction transaction;
    uint32_t i;
    bool transferOK;
    int32_t status;

    /*
     * CONFIG_SPI_CONTROLLER_READY & CONFIG_SPI_PERIPHERAL_READY are GPIO pins connected
     * between the controller & peripheral.  These pins are used to synchronize
     * the controller & peripheral applications via a small 'handshake'.  The pins
     * are later used to synchronize transfers & ensure the controller will not
     * start a transfer until the peripheral is ready.  These pins behave
     * differently between spicontroller & spiperipheral examples:
     *
     * spicontroller example:
     *     * CONFIG_SPI_CONTROLLER_READY is configured as an output pin.  During the
     *       'handshake' this pin is changed from low to high output.  This
     *       notifies the peripheral the controller is ready to run the application.
     *       Afterwards, the pin is used by the controller to notify the peripheral it
     *       has opened CONFIG_SPI_CONTROLLER.  When CONFIG_SPI_CONTROLLER is opened, this
     *       pin will be pulled low.
     *
     *     * CONFIG_SPI_PERIPHERAL_READY is configured as an input pin. During the
     *       'handshake' this pin is read & a high value will indicate the peripheral
     *       ready to run the application.  Afterwards, a falling edge interrupt
     *       will be configured on this pin.  When the peripheral is ready to perform
     *       a transfer, it will pull this pin low.
     *
     * Below we set CONFIG_SPI_CONTROLLER_READY & CONFIG_SPI_PERIPHERAL_READY initial
     * conditions for the 'handshake'.
     */
    //GPIO_setConfig(CONFIG_SPI_CONTROLLER_READY, GPIO_CFG_OUTPUT | GPIO_CFG_OUT_LOW);
    //GPIO_setConfig(CONFIG_SPI_PERIPHERAL_READY, GPIO_CFG_INPUT);

    /*
     * Handshake - Set CONFIG_SPI_CONTROLLER_READY high to indicate controller is ready
     * to run.  Wait CONFIG_SPI_PERIPHERAL_READY to be high.
     */
    //GPIO_write(CONFIG_SPI_CONTROLLER_READY, 1);
    //while (GPIO_read(CONFIG_SPI_PERIPHERAL_READY) == 0) {}

    /* Handshake complete; now configure interrupt on CONFIG_SPI_PERIPHERAL_READY */
    //GPIO_setConfig(CONFIG_SPI_PERIPHERAL_READY, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);
    //GPIO_setCallback(CONFIG_SPI_PERIPHERAL_READY, peripheralReadyFxn);
    //GPIO_enableInt(CONFIG_SPI_PERIPHERAL_READY);

    /*
     * Create synchronization semaphore; the controller will wait on this semaphore
     * until the peripheral is ready.
     */
    status = sem_init(&controllerSem, 0, 0);
    if (status != 0)
    {
        Display_printf(display, 0, 0, "Error creating controllerSem\n");

        while (1) {}
    }

    /* Open SPI as controller (default) */
    SPI_Params_init(&spiParams);
    spiParams.frameFormat = SPI_POL0_PHA1;
    /* See device-specific technical reference manual for supported speeds */
    spiParams.bitRate     = 1000000;
    controllerSpi         = SPI_open(CONFIG_SPI_CONTROLLER, &spiParams);
    if (controllerSpi == NULL)
    {
        Display_printf(display, 0, 0, "Error initializing controller SPI\n");
        while (1) {}
    }
    else
    {
        Display_printf(display, 0, 0, "Controller SPI initialized\n");
    }

    /*
     * Controller has opened CONFIG_SPI_CONTROLLER; set CONFIG_SPI_CONTROLLER_READY high to
     * inform the peripheral.
     */
    //GPIO_write(CONFIG_SPI_CONTROLLER_READY, 0);

    /* Copy message to transmit buffer */
    strncpy((char *)controllerTxBuffer, CONTROLLER_MSG, SPI_MSG_LENGTH);

    for (i = 0; i < MAX_LOOP; i++)
    {
        /*
         * Wait until peripheral is ready for transfer; peripheral will pull
         * CONFIG_SPI_PERIPHERAL_READY low.
         */
        sem_wait(&controllerSem);

        /* Initialize controller SPI transaction structure */
        controllerTxBuffer[sizeof(CONTROLLER_MSG) - 1] = (i % 10) + '0';
        memset((void *)controllerRxBuffer, 0, SPI_MSG_LENGTH);
        transaction.count = SPI_MSG_LENGTH;
        transaction.txBuf = (void *)controllerTxBuffer;
        transaction.rxBuf = (void *)controllerRxBuffer;

        /* Toggle user LED, indicating a SPI transfer is in progress */
        GPIO_toggle(CONFIG_GPIO_LED_1);

        /* Perform SPI transfer */
        transferOK = SPI_transfer(controllerSpi, &transaction);
        if (transferOK)
        {
            Display_printf(display, 0, 0, "Controller received: %s", controllerRxBuffer);
        }
        else
        {
            Display_printf(display, 0, 0, "Unsuccessful controller SPI transfer");
        }

        /* Sleep for a bit before starting the next SPI transfer  */
        sleep(3);
    }

    SPI_close(controllerSpi);

    /* Example complete - set pins to a known state */
    //GPIO_disableInt(CONFIG_SPI_PERIPHERAL_READY);
    //GPIO_setConfig(CONFIG_SPI_PERIPHERAL_READY, GPIO_CFG_OUTPUT | GPIO_CFG_OUT_LOW);
    //GPIO_write(CONFIG_SPI_CONTROLLER_READY, 0);

    Display_printf(display, 0, 0, "\nDone");

    return (NULL);
}



void *uwb_Thread(void *arg0)
{
       SPI_Handle controllerSpi;
       SPI_Params spiParams;
       SPI_Transaction transaction;

       int32_t status;

       GPIO_setConfig(CONFIG_SPI_UWB_INT, GPIO_CFG_INPUT);
       GPIO_setConfig(CONFIG_SPI_UWB_READY, GPIO_CFG_INPUT);
       GPIO_setConfig(CONFIG_GPIO_SPI_CS, GPIO_CFG_OUTPUT | GPIO_CFG_OUT_HIGH);
       GPIO_setConfig(CONFIG_GPIO_RESET, GPIO_CFG_OUTPUT | GPIO_CFG_OUT_LOW);

       /* Handshake complete; now configure interrupt on CONFIG_SPI_PERIPHERAL_READY
       GPIO_setConfig(CONFIG_SPI_PERIPHERAL_READY, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);
       GPIO_setCallback(CONFIG_SPI_PERIPHERAL_READY, peripheralReadyFxn);
       GPIO_enableInt(CONFIG_SPI_PERIPHERAL_READY);
        */

       /*
       * Create synchronization semaphore; the controller will wait on this semaphore
       * until the peripheral is ready.
       */
       status = sem_init(&controllerSem, 0, 0);
       if (status != 0)
       {
         Display_printf(display, 0, 0, "Error creating controllerSem\n");

         while (1) {}
       }

       /* Open SPI as controller (default) */
       SPI_Params_init(&spiParams);
       spiParams.frameFormat = SPI_POL0_PHA1;
       /* See device-specific technical reference manual for supported speeds */
       spiParams.bitRate     = 1000000;
       controllerSpi         = SPI_open(CONFIG_SPI_CONTROLLER, &spiParams);
       if (controllerSpi == NULL)
       {
         Display_printf(display, 0, 0, "Error initializing controller SPI\n");
         while (1) {}
       }
       else
       {
         Display_printf(display, 0, 0, "Controller SPI initialized\n");
       }


      // sem_wait(&controllerSem);
       m_nFlowNext = eSTEP_FLOW_RESET_RELEASE;
       while(1)
       {
           procUci(transaction, controllerSpi);
           procFlow();

       }
       return (NULL);
}

void my_delay(int milliseconds) {
    // 밀리초를 초 단위로 변환
    int iterations = milliseconds * 1000;

    // 임의의 반복문을 통해 지연 구현
    for (volatile int i = 0; i < iterations; i++);
}
void procUci(SPI_Transaction transaction,  SPI_Handle controllerSpi)
{
    bool transferOK;

    switch(m_nUciStep)
    {
    case eSTEP_UCI_IDLE:
        if(GPIO_read(CONFIG_SPI_UWB_INT) == 0)
        {
            GPIO_write(CONFIG_GPIO_SPI_CS , 0); //cs low
            m_nUciStep = eSTEP_UCI_RECVSTART;
        }
        else if(m_nTransmitType == eTYPE_TRANSMIT_REQUEST)
        {
            GPIO_write(CONFIG_GPIO_SPI_CS , 0); //cs low
            m_nUciStep = eSTEP_UCI_CHECKREADY;
        }
        break;
    case eSTEP_UCI_CHECKREADY:
        if(GPIO_read(CONFIG_SPI_UWB_READY) == 0)
        {
            m_nUciStep = eSTEP_UCI_SENDSTART;
        }
        else
        {
            m_nUciStep = eSTEP_UCI_IDLE;
        }
        break;
    case eSTEP_UCI_SENDSTART:
        m_nGID = controllerTxBuffer[0] & 0x0F;
        m_nOPID = controllerTxBuffer[1] & 0xFF;

        memset((void *)controllerRxBuffer, 0, SPI_MSG_LENGTH);
        transaction.count = m_nNumberSendsize;
        transaction.txBuf = (void *)controllerTxBuffer;
        transaction.rxBuf = (void *)controllerRxBuffer;
        transferOK = SPI_transfer(controllerSpi, &transaction);
        if (transferOK)
        {
            Display_printf(display, 0, 0, "TX : 0x%02x 0x%02x 0x%02x 0x%02x   0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x",
                                               controllerTxBuffer[0], controllerTxBuffer[1], controllerTxBuffer[2], controllerTxBuffer[3], controllerTxBuffer[4],
                                               controllerTxBuffer[5], controllerTxBuffer[6], controllerTxBuffer[7], controllerTxBuffer[8], controllerTxBuffer[9],
                                               controllerTxBuffer[10], controllerTxBuffer[11], controllerTxBuffer[12], controllerTxBuffer[13], controllerTxBuffer[14]);
           m_nUciStep = eSTEP_UCI_SENDDONE;
        }
        else
        {
            m_nUciStep = eSTEP_UCI_IDLE;
           Display_printf(display, 0, 0, "Unsuccessful controller SPI transfer");
        }
        break;
    case eSTEP_UCI_SENDDONE:
            m_nTransmitType = eTYPE_TRANSMIT_NONE;
            GPIO_write(CONFIG_GPIO_SPI_CS , 1); //cs high
            m_nUciStep = eSTEP_UCI_IDLE;
            break;
    case eSTEP_UCI_RECVSTART:
            memset((void *)controllerRxBuffer, 0, SPI_MSG_LENGTH);

            transaction.count = 1;
            transaction.txBuf = controllerZeroBuffer;
            transaction.rxBuf = (void *)controllerRxBuffer;
            transferOK = SPI_transfer(controllerSpi, &transaction);
            transaction.count = 4;
            transferOK = SPI_transfer(controllerSpi, &transaction);
            if(transferOK)
            {
                m_nNumberReadsize = controllerRxBuffer[3];
                transaction.count = m_nNumberReadsize;
                transaction.rxBuf = (void *)controllerRxBuffer + 4;
                transferOK = SPI_transfer(controllerSpi, &transaction);
                if(transferOK)
                {
                    m_nUciStep = eSTEP_UCI_RECVDONE;
                    Display_printf(display, 0, 0, "RX : 0x%02x 0x%02x 0x%02x 0x%02x   0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x",
                                   controllerRxBuffer[0], controllerRxBuffer[1], controllerRxBuffer[2], controllerRxBuffer[3], controllerRxBuffer[4],
                                   controllerRxBuffer[5], controllerRxBuffer[6], controllerRxBuffer[7], controllerRxBuffer[8], controllerRxBuffer[9],
                                   controllerRxBuffer[10], controllerRxBuffer[11], controllerRxBuffer[12], controllerRxBuffer[13], controllerRxBuffer[14],
                                   controllerRxBuffer[15], controllerRxBuffer[16], controllerRxBuffer[17], controllerRxBuffer[18], controllerRxBuffer[19],
                                   controllerRxBuffer[20], controllerRxBuffer[21], controllerRxBuffer[22], controllerRxBuffer[23], controllerRxBuffer[24],
                                   controllerRxBuffer[25], controllerRxBuffer[26]);
                }
            }
            else
            {
                m_nUciStep = eSTEP_UCI_IDLE;
                Display_printf(display, 0, 0, "Unsuccessful controller SPI transfer");
            }
            break;
    case eSTEP_UCI_RECVDONE:
        GPIO_write(CONFIG_GPIO_SPI_CS , 1); //cs high
        m_nUciStep = eSTEP_UCI_IDLE;

        if(((controllerRxBuffer[0] & 0x0F) == m_nGID) && (controllerRxBuffer[1] == m_nOPID) && (m_bResponseDone == false))
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
            GPIO_write(CONFIG_GPIO_RESET, 0);
            sleep(2);
            GPIO_write(CONFIG_GPIO_RESET, 1);

            m_nFlowStep = eSTEP_FLOW_INIT_BUILD;
            //m_nFlowStep = eSTEP_FLOW_IDLE;
            m_nInitCounter = 0;
        break;
    case eSTEP_FLOW_INIT_BUILD:
            m_nNumberSendsize = m_InitTable[m_nInitCounter].nSendlength;
            simpleCopy((unsigned char *)controllerTxBuffer, (unsigned char *)m_InitTable[m_nInitCounter].nSendname, m_nNumberSendsize);
    //      m_UciTemp[0] = m_UciSend[0];            // ???
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
    case eSTEP_FLOW_START_BUILD:
        m_nNumberSendsize = sizeof(RANGE_START_CMD);
        simpleCopy((unsigned char *)controllerTxBuffer, (unsigned char *)RANGE_START_CMD, m_nNumberSendsize);
        m_UciTemp[0] = controllerTxBuffer[0];            // ???
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
    }
}

void simpleCopy(unsigned char *pDest, unsigned char *pSrc, int cbData)
{
    while(cbData--)
        *pDest++ = *pSrc++;
}

/*
 *  ======== mainThread ========
 */
void *mainThread(void *arg0)
{
    pthread_t thread0;
    pthread_attr_t attrs;
    struct sched_param priParam;
    int retc;
    int detachState;

    /* Call driver init functions. */
    Display_init();
    GPIO_init();
    SPI_init();

    /* Configure the LED pins */
    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(CONFIG_GPIO_LED_1, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    /* Open the display for output */
    display = Display_open(Display_Type_UART, NULL);
    if (display == NULL)
    {
        /* Failed to open display driver */
        while (1) {}
    }

    /* Turn on user LED */
    GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);

    Display_printf(display, 0, 0, "Starting the SPI controller example");
    Display_printf(display,
                   0,
                   0,
                   "This example requires external wires to be "
                   "connected to the header pins. Please see the Readme.html and Board.html for details.\n");

    /* Create application threads */
    pthread_attr_init(&attrs);

    detachState = PTHREAD_CREATE_DETACHED;
    /* Set priority and stack size attributes */
    retc        = pthread_attr_setdetachstate(&attrs, detachState);
    if (retc != 0)
    {
        /* pthread_attr_setdetachstate() failed */
        while (1) {}
    }

    retc |= pthread_attr_setstacksize(&attrs, THREADSTACKSIZE);
    if (retc != 0)
    {
        /* pthread_attr_setstacksize() failed */
        while (1) {}
    }

    /* Create controller thread */
    priParam.sched_priority = 1;
    pthread_attr_setschedparam(&attrs, &priParam);

    retc = pthread_create(&thread0, &attrs, uwb_Thread, NULL);
    if (retc != 0)
    {
        /* pthread_create() failed */
        while (1) {}
    }

    return (NULL);
}
