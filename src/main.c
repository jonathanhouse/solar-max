/**
 * @file main.c
 * @author Jonathan House (jahfhz@mst.edu)
 * @brief The controller driver 
 * @version 0.1
 * @date 2024-06-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "controller/controller.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

void cloud_track_model_iv(Controller* controller){

    static int it = 1;
    //static double MODEL_MAX_V = 15.0;
    static double MODEL_MAX_V = 16.5;
    printf("MODEL_MAX_V: %f\n",MODEL_MAX_V);
    if((it % 100) == 0){ MODEL_MAX_V = 14.0; };
    if(MODEL_MAX_V == 14.0){ printf("Cloud Coverage\n"); }
    float v_step = 16.5/100.0 * controller->c_step_state;
    
    double SCALE_PARAM = 1.0/(exp(MODEL_MAX_V) + 1.0);
    float v_curr = controller->c_bat_voltage;
    if((v_curr + v_step <= MODEL_MAX_V) && (v_curr + v_step > 0.0)){ controller->c_bat_voltage += v_step; }
    controller->c_current = 1.0 - SCALE_PARAM*(exp(controller->c_bat_voltage) - 1.0);

    it += 1;
}

void track_model_iv(Controller* controller){

    const static double MODEL_MAX_V = 16.5;
    float v_step = MODEL_MAX_V/100.0 * controller->c_step_state;
    //float v_step = 0.15 * controller->c_step_state;
    double SCALE_PARAM = 1.0/(exp(MODEL_MAX_V) + 1.0);
    float v_curr = controller->c_bat_voltage;
    if((v_curr + v_step <= MODEL_MAX_V) && (v_curr + v_step > 0.0)){ controller->c_bat_voltage += v_step; }
    controller->c_current = 1.0 - SCALE_PARAM*(exp(controller->c_bat_voltage) - 1.0);

}

int main(){

    Controller controller = {INITALIZE,0,0,0,0,1};
    int opt;
    printf("1. Set V_BAT=5V\n");
    printf("2. Set V_BAT=12.7V\n");
    printf("3. Set V_BAT=0V\n");
    printf("4. Track IV-curve w/ model 1-A(exp(x)-1)\n");
    printf("5. Cloud coverage w/ IV model\n");
    printf("Enter a simulation case:");
    scanf("%d", &opt);
    printf("Selected option %d\n", opt);
    if(opt == 1){
        controller.c_bat_voltage = 5.0;
        controller.c_current = 1.0;
    }
    else if (opt == 2){
        controller.c_bat_voltage = 14.6;
        controller.c_current = 1.0;
    }
    else if(opt == 3){
        controller.c_bat_voltage = 0;
    }
    else if(opt == 4){

        while(1){
            run(&controller);
            track_model_iv(&controller);
            usleep(50000);
        }

    }
    else if(opt == 5){

        while(1){
            run(&controller);
            cloud_track_model_iv(&controller);
            usleep(100000);
        }

    }


    while(1){
        run(&controller);
        usleep(100000);
    }

    return 0;

}