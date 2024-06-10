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

/**
 * @brief Initialize for MCU for PWM usage
 * 
 */
void init_pwm();

/**
 * @brief Increment the PWM duty cycle 
 * 
 */
void inc_pwm();

/**
 * @brief Decrement the PWM duty cycle
 * 
 */
void dec_pwm();

#endif