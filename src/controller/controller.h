
#ifndef CONTROLLER_H
#define CONTROLLER_H

//#include <stdio.h>
#include "../mppt/mppt.h"
#include "../pwm/pwm.h"
#include "../adc/adc.h"
#include "../types/types.h"

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

/**
 * @brief The logic for updating the current state
 * 
 */
void update_state();

/**
 * @brief Get the controller 
 * 
 */
Controller* get_controller();

#endif 
