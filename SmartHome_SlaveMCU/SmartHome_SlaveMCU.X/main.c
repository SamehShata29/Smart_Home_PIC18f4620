

#include "mcc_generated_files/mcc.h"

uint8_t RecTC74_A7_TempVal = 0;

static void Custom_I2C_SlaveDefRdInterruptHandler() {
    RecTC74_A7_TempVal = SSPBUF;
}


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();


    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();
    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    I2C_Open();
    I2C_SlaveSetReadIntHandler(Custom_I2C_SlaveDefRdInterruptHandler);
    while (1)
    {
        if(RecTC74_A7_TempVal > 35){
            Motor_P1_SetHigh();
            Motor_P2_SetLow();
        }
        else{
            Motor_P1_SetLow();
            Motor_P2_SetLow();
        }
    }
}