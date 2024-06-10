/* 
 * File:   UART_LoggingDebugData.h
 * Author: sameh
 *
 * Created on September 16, 2023, 11:38 PM
 */
#include "UART_LoggingDebugData.h"

void UART_LoggingDebugData_Send_String(uint8_t *Str, uint16_t Str_len){
    uint16_t l_Str_len = 0;
    for(l_Str_len = 0; l_Str_len < Str_len; ++l_Str_len){
        EUSART_Write(*Str++);
    }
}