#ifndef TYPES_H
#define TYPES_H


struct constants {

    float CHARGED_VOLTAGE;

};
extern const struct constants CONSTANTS;


/**
 * @brief Enumeration of the possible controller states
 * 
 */
typedef enum {

    INITALIZE,
    PWM_MAINTAIN,
    MPPT_CHARGE,
    SAFE

} State;

/**
 * @brief The controller's current state structure.
 * 
 */
typedef struct {

    /// @brief The current controller mode.
    /// 
    State c_state;

    /// @brief The battery's current voltage.
    ///
    float c_bat_voltage;

    /// @brief The battery's current current.
    ///
    float c_current;

    /// @brief The solar panel's current voltage.
    float c_sol_voltage;

    /// @brief The PWM's current duty cycle.
    ///
    float c_pwm_dc;

} Controller; 

#endif