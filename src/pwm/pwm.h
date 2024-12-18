/**
 * @file pwm.h
 * @author Jonathan House 
 * @brief 
 * @version 0.1
 * @date 2024-06-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef PWM_H
#define PWM_H

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
#include "../controller/controller.h"
#include "../types/types.h"
#define PWM_FREQUENCY 1000
#define INIT_DUTY_CYCLE 50

/**
 * @brief Initialize for MCU for PWM usage
 * 
 */
void init_pwm();

/**
 * @brief Set the duty cycle on the MCU
 * 
 * @param new_dc The new duty cycle value (between 0-100)
 */
void set_duty_cycle(uint8_t new_dc);

/**
 * @brief Increment the PWM duty cycle 
 * 
 */
void inc_pwm(Controller *c);

/**
 * @brief Decrement the PWM duty cycle
 * 
 */
void dec_pwm(Controller *c);

/**
 * @brief Keep the current PWM duty cycle
 * @note Avoid using this function - will pause PWM for no reason
 * 
 */
void stay_pwm(Controller *c);

#endif
