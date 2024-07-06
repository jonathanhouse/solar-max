#include "adc.h"

void init_adc(){

    #ifdef HARDWARE
    // ADMUX = REFS1 REFS0 (0 1) = AVCC with external capacitor at AREF pin.
    ADMUX |= (1 << REFS0);
    ADMUX &= ~(1 << REFS1);

    ADCSRA |= (1 << ADPS2) | (1 << ADPS1); // set pre-scalar to 64; arbitrary for now. For a 8MHz clock, this gives 125kHz sampling

    ADCSRA &= ~(1 << ADPS0); // clear this bit 
    ADCSRA |= (1 << ADEN); // now, enable the ADC
    #endif 

}

uint16_t read_adc(uint8_t channel) {

    #ifdef HARDWARE
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F); // keep init settings and set the specificed channel
    ADCSRA |= (1 << ADSC); // start the conversion 
    while (ADCSRA & (1 << ADSC)); // wait for conversion to complete (ADSC returns to 0)
    return ADC; // return the converted value
    #endif 
    
    return 0x00;
}

float convert_adc(uint16_t val){
    return (val / 1023.0) * V_REF;
}

float get_current(){ return convert_adc(read_adc(CURRENT_CHN)); }

float get_bat_voltage(){ return convert_adc(read_adc(VOLT_BAT_CHN)); }

float get_sol_voltage(){ return convert_adc(read_adc(VOLT_SOL_CHN)); }

float get_power(){ return get_bat_voltage() * get_current(); }
