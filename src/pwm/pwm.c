#include "pwm.h"

void init_pwm(){

    #ifdef HARDWARE
    // Sets to non-inverting PWM mode. Setting COM1A1 should correspond to 
    // the OC1A pin, which is the PDB pin.
    TCCR1A |= (1 << WGM11) | (1 << COM1A1); 
    TCCR1B |= (1 << WGM13) | (1 << WGM12);

    // Set the prescaler to 64 
    TCCR1B |= (1 << CS11) | (1 << CS10);

    // The ICR1 register defines the top value of the PWM counter 
    ICR1 = (F_CPU / (PWM_FREQUENCY * 64)) - 1;

    // Set the duty cycle of the output control register for 
    // output control match A (OC1A) pin
    OCR1A = (ICR1 + 1) * INIT_DUTY_CYCLE / 100;

    // Set PD5 (OC1A pin) as output (for ATmega32); PB5 is OC1A for ATmega64
    DDRB |= (1 << PD5);
    #endif

}

void set_duty_cycle(uint8_t new_dc){
    #ifdef HARDWARE
    TCCR1A &= ~(1 << COM1A1); // Clear COM1A1 bit to temporarily turn off PWM
    OCR1A = (ICR1 + 1) * new_dc / 100; // Calculate and assign a new duty cycle 
    TCCR1A |= (1 << COM1A1); // Set COM1A1 bit to turn back on PWM 
    #endif
}

void stay_pwm(Controller* controller){
    // no need to re-update this value
    controller->c_step_state = 0;
    //set_duty_cycle(controller->c_pwm_dc);
}

void inc_pwm(Controller* c) {

    if((c->c_pwm_dc + 1) <= 100){
        c->c_pwm_dc++;
        c->c_step_state = 1;
        set_duty_cycle(c->c_pwm_dc);
    }
    else {
        c->c_step_state = 0;
    }
}

void dec_pwm(Controller* c) {

    if((c->c_pwm_dc - 1) > 0){
        c->c_pwm_dc--;
        c->c_step_state = -1;
        set_duty_cycle(c->c_pwm_dc);
    }
    else {
        c->c_step_state = 0;
    }
}
