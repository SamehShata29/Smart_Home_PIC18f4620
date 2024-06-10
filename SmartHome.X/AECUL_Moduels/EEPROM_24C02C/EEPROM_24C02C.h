/* 
 * File:   EEPROM_24C02C.h
 * Author: sameh
 *
 * Created on September 17, 2023, 12:29 AM
 */

#include "../../mcc_generated_files/examples/i2c_master_example.h"

#ifndef EEPROM_24C02C_H
#define	EEPROM_24C02C_H

void EEPROM_24C02C_Write_Byte(i2c_address_t EEPORM_Address, i2c_address_t Byte_Address, uint8_t Data);
uint8_t EEPROM_24C02C_Read_Byte(i2c_address_t EEPORM_Address, i2c_address_t Byte_Address);

#endif	/* EEPROM_24C02C_H */

