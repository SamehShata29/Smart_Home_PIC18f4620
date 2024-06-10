/* 
 * File:   TempSensor_TC74.h
 * Author: sameh
 *
 * Created on September 17, 2023, 5:31 PM
 */

#ifndef TEMPSENSOR_TC74_H
#define	TEMPSENSOR_TC74_H
#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"

uint8_t TempSensor_TC74_Read_Temp(i2c_address_t TC74_Address);

#endif	/* TEMPSENSOR_TC74_H */

