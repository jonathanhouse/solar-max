#include "controller.h"
#include <stdio.h>


// Controller* get_controller(){
//     return &controller;
// }

void print_controller(Controller* controller){
    printf("Controller state: %d\n", controller->c_state);
    printf("System voltage: %f\n", controller->c_bat_voltage);
    printf("System current: %f\n", controller->c_current);
    printf("PWM vaue: %d\n", controller->c_pwm_dc);
    printf("\n");
}

void run(Controller* controller){

    static int first_run = 1;
    if(first_run == 1){
        initialize();
        #ifndef HARDWARE
        print_controller(controller);
        #endif
        first_run = 0;
    }

    update_controller(controller);
    #ifndef HARDWARE
    print_controller(controller);
    #endif

    switch(controller->c_state){

        case PWM_MAINTAIN: 
            pwm_maintain(controller);
            break;

        case MPPT_CHARGE:
            mppt_charge(controller);
            break;

        case SAFE: 
            safe();
            break;

        default: 
            error(controller);
            break;
    }

}


void initialize(){

    init_adc();
    init_pwm();
    init_mppt();

}

void pwm_maintain(Controller* controller){

    stay_pwm(controller);
    controller->c_pwm_dc = 50; // set to halfway

}

void mppt_charge(Controller* controller){

    step_mppt(controller);

}

void safe(){

    //

}

void error(Controller* controller){

    controller->c_state = SAFE; 

}

void update_controller(Controller* controller){


    #ifdef HARDWARE 
    controller->c_current = get_current();
    controller->c_sol_voltage = get_sol_voltage();
    controller->c_bat_voltage = get_bat_voltage();
    #endif 

    // if no hardware, just keep the value the same 
    update_state(controller);

}

void update_state(Controller* controller){

    if (controller->c_bat_voltage >= CONSTANTS.CHARGED_VOLTAGE){
        controller->c_state = PWM_MAINTAIN;
    }
    else if (controller->c_bat_voltage < CONSTANTS.CHARGED_VOLTAGE && controller->c_bat_voltage > 0){
        controller->c_state = MPPT_CHARGE;
    }
    else { // error has occured, switch to safe mode 
        controller->c_state = SAFE;
    }

}

