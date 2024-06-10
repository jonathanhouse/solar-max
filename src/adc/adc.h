/**
 * @file adc.h
 * @author Jonathan House 
 * @brief The ADC operation functions
 * @version 0.1
 * @date 2024-06-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef ADC_H
#define ADC_H

/**
 * @brief The ADC initialization function.
 * 
 */
void init_adc();

/**
 * @brief Read current via ADC.
 * @return The battery's current current [A].
 */
float get_current();

/**
 * @brief Read voltage via ADC.
 * @return The battery's current voltage [V].
 */
float get_voltage();

/**
 * @brief Get power via calls 
 * @details Calls get_current() and get_voltage()
 * @return The current power transfer [W].
 */
float get_power();

#endif 