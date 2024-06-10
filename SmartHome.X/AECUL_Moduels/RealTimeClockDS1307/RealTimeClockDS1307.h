/* 
 * File:   RealTimeClockDS1307.h
 * Author: sameh
 *
 * Created on September 16, 2023, 12:52 PM
 */

#ifndef REALTIMECLOCKDS1307_H
#define	REALTIMECLOCKDS1307_H

#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"
#include "../UART_LoggingDebugData/UART_LoggingDebugData.h"

typedef struct{
    uint8_t Hours;
    uint8_t Minutes;
    uint8_t Seconds;
    uint8_t Year;
    uint8_t Day;
    uint8_t Month;
}RealTimeClockDS1307_t;

RealTimeClockDS1307_t RealTimeClockDS1307_Get_Date_Time(void);
void Print_RealTimeClockDS1307(void);

#endif	/* REALTIMECLOCKDS1307_H */

