/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 20 de marzo de 2020, 05:14 PM
 */


#include "xc.h"
#include "Configuracion.h"
#include <libpic30.h>

void INT1_Init(void);
void INT0_Init(void);
void __attribute__((interrupt,auto_psv)) _INT0Interrupt(void);
void __attribute__((interrupt,auto_psv)) _INT1Interrupt(void);

void INT1_Init(void){
    INTCON2bits.INT1EP = 1;
    IFS1bits.INT1IF = 0;
    IEC1bits.INT1IE = 1;
    IPC4bits.INT1IP = 5;
}

void INT0_Init(void){
    INTCON2bits.INT0EP = 0;
    IFS0bits.INT0IF = 0;
    IEC0bits.INT0IE = 1;
    IPC0bits.INT0IP = 3;
}

int main(void) {
    ADPCFG = 0x1FFF; //TODOS los pines Digitales
    TRISB = 0; //SALIDA
    LATB = 0;
    TRISAbits.TRISA11 = 1; //INT0
    TRISDbits.TRISD8 = 1; //INT1
    TRISDbits.TRISD0 = 0;
    INT0_Init();
    INT1_Init();
    while(1){
        LATBbits.LATB0 = 1;
        __delay_ms(200);
        LATBbits.LATB0 = 0;
        __delay_ms(200);
    }
    
}

void __attribute__((interrupt,auto_psv)) _INT0Interrupt(void){
    LATBbits.LATB1 = ~LATBbits.LATB1;
    IFS0bits.INT0IF = 0;
}

void __attribute__((interrupt,auto_psv)) _INT1Interrupt(void){
    LATDbits.LATD0 = ~LATDbits.LATD0;
    IFS1bits.INT1IF = 0;
}
