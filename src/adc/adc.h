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

#ifdef HARDWARE
#if defined(__ICCAVR__)
#include "ioavr.h"
#include "inavr.h"
#else
#include <avr/io.h>
#include <avr/interrupt.h>
#endif
#endif 

#include <stdint.h>
#include <stdlib.h>
#define CURRENT_CHN 0
#define VOLT_BAT_CHN 1
#define VOLT_SOL_CHN 2
#define V_REF 5.0
#define ITS_AVG 3
#define I_SCALE 1.0

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
 * @return The battery's voltage [V].
 */
float get_bat_voltage();

/**
 * @brief Read voltage via ADC.
 * @return The solar voltage [V].
 */
float get_sol_voltage();

/**
 * @brief Get power via calls 
 * @details Calls get_current() and get_voltage()
 * @return The current power transfer [W].
 */
float get_power();

/**
 * @brief Reads the ADC off a specified channel
 * 
 * @param channel The channel to read off of 
 * @return uint16_t The 10b returm
 */
uint16_t read_adc(uint8_t channel);

#endif 