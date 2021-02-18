
#include <xc.h>
#include "ADC_Libreria.h"

void ADC_Init(void){
    ADPCFG = 0x1FFE;//RB0 ANALOG
    ADCON2bits.VCFG = 0b000;// VSS VDD
    ADCHSbits.CH0SA = 0b0000;//Canal 0
    // ADCS = 2*(TAD/TCY) - 1 
    //      = 2*(334nS/(1/24MHZ)) - 1
    //      = 15.032
    ADCON3bits.ADCS = 15;
    ADCON3bits.ADRC = 0;
    ADCON3bits.SAMC = 14;
    ADCON1bits.SSRC = 0b001;//INT0
    ADCON1bits.FORM = 0b00;
    ADCON1bits.ADON = 1; //ACtiva el ADC
}
