/*
 * func.h
 *
 *  Created on:
 *      Author: haythem
 */

#ifndef CONFIG_FUNC_H_
#define CONFIG_FUNC_H_
uint32_t current_value(uint32_t raw_data);
uint32_t voltage_value(uint32_t raw_data);
uint32_t power_value(uint32_t current,uint32_t voltage);
uint32_t  voltage;
uint32_t current;
uint32_t power;


// fonction to read the current
uint32_t current_value(uint32_t raw_data)
{
 uint32_t current_sensor_RAW = sensor_value[0];
 uint32_t voltage_raw =   (5.0 / 4096.0)*current_sensor_RAW; // Read the voltage from the current  sensor
 uint32_t voltage =  voltage_raw - 0.5 * 5 + 0.012 ;// 0.000 is a value to make voltage zero when there is no current
 uint32_t A = voltage / 0.066; //0.066 is the sensitivity of the module , can be found in the datta sheet, module used is ACS712ELCTR-30A-T
 return(A);
}

//fonction to read the voltage
uint32_t voltage_value(uint32_t raw_data)
{
 uint32_t R1 = 7000;  //the resistor on the top
 uint32_t R2 = 1150;  //the resistor on the buttom
 uint32_t voltage_sensor_RAW = sensor_value[1];
 uint32_t voltage_raw = (5.0 / 4096.0)*voltage_sensor_RAW; // Read the voltage from the current  sensor
 uint32_t V = voltage_raw * (R1+R2) / R2;

 return(V);
}

//fonction to calculate power
uint32_t power_value(uint32_t current,uint32_t voltage)
{
	return(current*voltage);
}


#endif /* CONFIG_FUNC_H_ */
