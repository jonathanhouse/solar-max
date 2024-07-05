#include "mppt.h"

void init_mppt(){

    //

}

void step_mppt(){

    static float last_power;
    float c_power = get_power();

    if (last_power < c_power) { // if the new calculated power is greater than previous power.
        inc_pwm(); // keep walking up the hill.
        
    }
    else if (last_power > c_power) { // of the new calculated power is less than the previous power.
        dec_pwm(); // stepped down the hill, walk back up.
    }
    else { // we're at the top of the hill
        // maintain this same power point
    }
    last_power = c_power;

}