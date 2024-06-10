/**
 * @file state.h
 * @author Jonathan House (jahfhz@mst.edu)
 * @brief The state logic functions
 * @version 0.1
 * @date 2024-06-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef STATE_H
#define STATE_H

#include "../mppt/mppt.h"
#include "../pwm/pwm.h"
#include "../adc/adc.h"
#include "../types/types.h"
#include "../controller/controller.h"

/**
 * @brief Initialize the MCU
 * 
 */
void initialize();

/**
 * @brief The PWM battery maintenance operation 
 * 
 */
void pwm_maintain();

/**
 * @brief The MPPT battery charging mode 
 * 
 */
void mppt_charge();

/**
 * @brief The safe, non-charging mode 
 * 
 */
void safe();


/**
 * @brief Function call in case of invalid controller data
 * 
 */
void error();

/**
 * @brief Start the MCU operations
 * 
 */
void run();

/**
 * @brief Updates the controllers current values.
 * 
 */
void update_controller();

#endif 