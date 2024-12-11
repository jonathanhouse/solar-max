#include "mppt.h"

void init_mppt(){

    //

}

void step_mppt(Controller* controller){

    static float last_power = 0.0;
    int did_inc = controller->c_step_state; // previous step taken
    float c_power = controller->c_bat_voltage * controller->c_current;//get_power();

    if(did_inc == 1){ // if we previously increased the voltage
        if(c_power > last_power){ // and power transfer increased 
            inc_pwm(controller); // keep walking up the hill.
        }
        else if(last_power > c_power){ // and power decreased 
            dec_pwm(controller); // stepped down the hill, walk back up.
        }
    }
    else if(did_inc == -1){ // previously decreased voltage 
        if(c_power > last_power){ // and power transfer increased 
            dec_pwm(controller); // keep walking down the hill.
        }
        else if(last_power > c_power){ // and power transfer decreased 
            inc_pwm(controller); // stepped down the hill, walk back up.
         }

    }
    else if (did_inc == 0){ // we're at the top of the hill
         // maintain this same power point
         // @todo add some random allowed error for optimization? 
         stay_pwm(controller);
    }
    
    last_power = c_power;

}