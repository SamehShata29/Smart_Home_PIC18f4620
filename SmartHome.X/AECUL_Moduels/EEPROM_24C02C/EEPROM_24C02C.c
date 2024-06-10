/* 
 * File:   EEPROM_24C02C.h
 * Author: sameh
 *
 * Created on September 17, 2023, 12:29 AM
 */

#include "EEPROM_24C02C.h"

void EEPROM_24C02C_Write_Byte(i2c_address_t EEPORM_Address, i2c_address_t Byte_Address, uint8_t Data){
    I2C_Write1ByteRegister(EEPORM_Address, Byte_Address, Data);
}
uint8_t EEPROM_24C02C_Read_Byte(i2c_address_t EEPORM_Address, i2c_address_t Byte_Address){
    uint8_t received_val = 0;
    received_val = I2C_Read1ByteRegister(EEPORM_Address, Byte_Address);
    return received_val;
}