#include "controller.h"


static Controller controller = {INITALIZE,0,0,0,0};

Controller* get_controller(){
    return &controller;
}

void run(){

    initialize();
    while(1){

        update_controller();

        switch(controller.c_state){

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

    stay_pwm();

}

void mppt_charge(){

    step_mppt();

}

void safe(){

    //

}

void error(){

    controller.c_state = SAFE; 

}

void update_controller(){

    controller.c_current = get_current();
    controller.c_sol_voltage = get_sol_voltage();
    controller.c_bat_voltage = get_bat_voltage();
    update_state();

}

void update_state(){

    if (controller.c_bat_voltage >= CONSTANTS.CHARGED_VOLTAGE){
        controller.c_state = PWM_MAINTAIN;
    }
    else {
        controller.c_state = MPPT_CHARGE;
    }

}

