#include "state.h"
#include <stdio.h>

void run(){

    Controller* c_ptr = get_controller();
    while(1){

        update_controller();

        switch(c_ptr->c_state){

            case INITALIZE:
                initialize();
                break;

            case PWM_MAINTAIN: 
                pwm_maintain();
                break;

            case MPPT_CHARGE:
                mppt_charge();
                break;

            case SAFE: 
                safe();
                break;

            default: 
                error();
                break;
        }

    }

}


void initialize(){

    init_adc();
    init_pwm();
    init_mppt();

}

void pwm_maintain(){

    //

}

void mppt_charge(){

    //

}

void safe(){

    //

}

void error(){

    Controller* c_ptr = get_controller();
    c_ptr->c_state = SAFE; 

}

void update_controller(){

    Controller* c_ptr = get_controller();

    c_ptr->c_current = get_current();
    c_ptr->c_sol_voltage = get_voltage();
    c_ptr->c_bat_voltage = get_voltage();

    if (c_ptr->c_bat_voltage >= CONSTANTS.CHARGED_VOLTAGE){
        c_ptr->c_state = PWM_MAINTAIN;
    }
    else {
        c_ptr->c_state = MPPT_CHARGE;
    }

}

