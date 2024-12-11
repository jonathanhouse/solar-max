/**
 * @file mppt.h
 * @author Jonathan House
 * @brief 
 * @version 0.1
 * @date 2024-06-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef MPPT_H
#define MPPT_H

#include "../adc/adc.h"
#include "../pwm/pwm.h"
#include "../types/types.h"

/**
 * @brief Initalize the MCU for MPPT
 * 
 */
void init_mppt();

/**
 * @brief Run through one iteration of the MPPT algorithm
 * 
 */
void step_mppt(Controller* controller);

#endif 