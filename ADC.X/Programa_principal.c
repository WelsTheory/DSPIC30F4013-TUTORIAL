/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 20 de marzo de 2020, 05:14 PM
 */


#include "xc.h"
#include "Configuracion.h"
#include <libpic30.h>

void ADC_Init(void);
int ADCValue;

int main(void) {
    ADPCFG = 0x1FFE; //TODOS los pines Digitales
    TRISBbits.TRISB0 = 1; //ENTRADA
    LATB = 0;
    //Timer1_Init();
    //Timer3_Init_32();
    ADC_Init();
    while(1){
        ADCON1bits.SAMP = 1;
        __delay_ms(100);
        ADCON1bits.SAMP = 0;
        while (!ADCON1bits.DONE); // conversion done?
        ADCValue = ADCBUF0;
            //__delay_ms(1);
    }
}

void ADC_Init(void){
    ADCHSbits.CH0SA = 0;// RA0
    ADCON2bits.VCFG = 0;// Vdd y VSS
    ADCON3bits.ADCS = 15; // 15 
    ADCON3bits.SAMC =  1; // 1tad
    ADCON3bits.ADRC = 0;
    ADCON1bits.FORM = 0; //entero
    ADCON1bits.SSRC = 0; //manual
    ADCON1bits.ADON = 1;
}
