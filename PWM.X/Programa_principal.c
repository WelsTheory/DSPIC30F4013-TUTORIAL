/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 20 de marzo de 2020, 05:14 PM
 */


#include "xc.h"
#include "Configuracion.h"
#include <libpic30.h>

int16_t i;
void Timer1_Init(void);
void Timer3_Init_32(void);
void __attribute__((interrupt,auto_psv)) _T1Interrupt(void);
void __attribute__((interrupt,auto_psv)) _T3Interrupt(void);

int main(void) {
    ADPCFG = 0x1FFF; //TODOS los pines Digitales
    TRISB = 0; //SALIDA
    LATB = 1;
    Timer1_Init();
    Timer3_Init_32();
    while(1){
            //__delay_ms(1);
    }
}


/*
PRX = FCY*TIEMPO/Pres - 1;
PRX = 24000000*100*10^-3/256 - 1 = 9374; => 0x249E
PRX = 24000000*50*10^-3/64 - 1 = 37499; => 0x927B
PRX = 24000000*50*10^-3/8 - 1 = 299999;
PRX = 24000000*50*10^-3/1 - 1 = 2399999;
*/

void Timer1_Init(void){

/*_________Módulo Temporizador__________*/
    PR1=  0x927B;
    TMR1=  0;
    T1CONbits.TCS = 0;
    T1CONbits.TCKPS = 2;
    T1CONbits.TGATE = 0;
    //T1CONbits.TGATE = 0;
    //T1CONbits.TON = 1;
/*______ Manejo de Interrupción_________*/
    IFS0bits.T1IF =  0;
    IPC0bits.T1IP =  5;
    IEC0bits.T1IE =  1;
/*_______ Iniciar el Temporizador_______*/
    T1CONbits.TON =  1;
}


void __attribute__((interrupt,auto_psv)) _T1Interrupt(void){
    IFS0bits.T1IF =  0;
    LATBbits.LATB0 = ~LATBbits.LATB0;
    
}

void Timer3_Init_32(void){

/*_________Módulo Temporizador__________*/
    PR3 = 0x016E;
    PR2 = 0x35FF;
    TMR3 = 0;
    TMR2 = 0;
    T2CONbits.T32 = 1;
    T2CONbits.TCKPS = 0;
/*______ Manejo de Interrupción_________*/
    IFS0bits.T3IF =  0;
    IPC1bits.T3IP =  7;
    IEC0bits.T3IE =  1;
/*_______ Iniciar el Temporizador_______*/
    T2CONbits.TON =  1;
}


void __attribute__((interrupt,auto_psv)) _T3Interrupt(void){
    IFS0bits.T3IF =  0;
    LATBbits.LATB1 = ~LATBbits.LATB1;
}