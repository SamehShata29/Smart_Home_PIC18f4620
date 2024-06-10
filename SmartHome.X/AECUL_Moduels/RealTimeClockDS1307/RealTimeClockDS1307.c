/* 
 * File:   RealTimeClockDS1307.h
 * Author: sameh
 *
 * Created on September 16, 2023, 12:52 PM
 */

#include "RealTimeClockDS1307.h"

static RealTimeClockDS1307_t RTC;
 /* "Year" : "Month" : "Day" *  "Hours" : "Minutes" : "Seconds"*/
static uint8_t RealTimeClockDS1307_Pack[18];

RealTimeClockDS1307_t RealTimeClockDS1307_Get_Date_Time(void){
    RTC.Seconds = I2C_Read1ByteRegister(0xD0, 0x00);
    RTC.Minutes = I2C_Read1ByteRegister(0xD0, 0x01);
    RTC.Hours   = I2C_Read1ByteRegister(0xD0, 0x02);
    RTC.Day     = I2C_Read1ByteRegister(0xD0, 0x03);
    RTC.Month   = I2C_Read1ByteRegister(0xD0, 0x04);
    RTC.Year    = I2C_Read1ByteRegister(0xD0, 0x05);
    return RTC;
}

void Print_RealTimeClockDS1307(void){
    /* RTC output is in BCD format */
    RealTimeClockDS1307_Pack[0] = ((RTC.Day >> 4) + '0'); 
    RealTimeClockDS1307_Pack[1] = ((RTC.Day & 0x0F) + '0'); 
    RealTimeClockDS1307_Pack[2] = '-';
    RealTimeClockDS1307_Pack[3] = ((RTC.Month >> 4) + '0');
    RealTimeClockDS1307_Pack[4] = ((RTC.Month & 0x0F) + '0');
    RealTimeClockDS1307_Pack[5] = '-';
    RealTimeClockDS1307_Pack[6] = ((RTC.Year >> 4) + '0');
    RealTimeClockDS1307_Pack[7] = ((RTC.Year & 0x0F) + '0');
    RealTimeClockDS1307_Pack[8] = '/';
    RealTimeClockDS1307_Pack[9] = ((RTC.Hours >> 4) + '0');
    RealTimeClockDS1307_Pack[10] = ((RTC.Hours & 0x0F) + '0');
    RealTimeClockDS1307_Pack[11] = '-';
    RealTimeClockDS1307_Pack[12] = ((RTC.Minutes >> 4) + '0');
    RealTimeClockDS1307_Pack[13] = ((RTC.Minutes & 0x0F) + '0');
    RealTimeClockDS1307_Pack[14] = '-';
    RealTimeClockDS1307_Pack[15]= ((RTC.Seconds >> 4) + '0');
    RealTimeClockDS1307_Pack[16]= ((RTC.Seconds & 0x0F) + '0');
    RealTimeClockDS1307_Pack[17]= '\r';
    
    UART_LoggingDebugData_Send_String("Date : ", 7);
    UART_LoggingDebugData_Send_String(RealTimeClockDS1307_Pack, 18);
}
