
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
void pwm_maintain(Controller* controller);

/**
 * @brief The MPPT battery charging mode 
 * 
 */
void mppt_charge(Controller* controller);

/**
 * @brief The safe, non-charging mode 
 * 
 */
void safe();


/**
 * @brief Function call in case of invalid controller data
 * 
 */
void error(Controller* controller);

/**
 * @brief Start the MCU operations
 * 
 */
void run(Controller* controller);

/**
 * @brief Updates the controllers current values.
 * 
 */
void update_controller(Controller* controller);

/**
 * @brief The logic for updating the current state
 * 
 */
void update_state(Controller* controller);

/**
 * @brief Get the controller 
 * 
 */
//Controller* get_controller();

#endif 
