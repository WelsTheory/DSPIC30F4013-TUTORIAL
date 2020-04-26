/*
 * File:   Timer_Temporizador
 * Author: Wels
 *
 * Created on 17 de abril de 2020, 12:14 PM
 */


#include "xc.h"
#include "Configuracion.h"
#include <libpic30.h>

/*Formula de Temporización
 * PRX = FCY*TIEMPO/Pres - 1;
 * PRX = 100mseg*24000000/1 - 1 = X
 * PRX = 100mseg*24000000/8 - 1 = X
 * PRX = 100mseg*24000000/64 - 1 = 37499
 * PRX = 100mseg*24000000/256 - 1 = 9374
 * 
*/

void Timer_32bits(void);
void Timer_16bits(void);

void __attribute__((interrupt,auto_psv)) _T1Interrupt(void);
void __attribute__((interrupt,auto_psv)) _T3Interrupt(void);

int main(void) {
    ADPCFG = 0x1FFF; //TODOS los pines Digitales
    TRISB = 0;       //SALIDA
    LATB = 0;
    Timer_16bits();
    Timer_32bits();
    while(1){
    }
    
}

void Timer_16bits(void){
    T1CONbits.TON = 0;
    T1CONbits.TCS = 0; // Temporizador
    T1CONbits.TGATE = 0;
    T1CONbits.TSIDL = 0;
    T1CONbits.TCKPS = 2;
    PR1 = 37499;
    TMR1 = 0;
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    IPC0bits.T1IP = 4;
    T1CONbits.TON = 1;
}

void Timer_32bits(void){
    T2CONbits.TON = 1;
    T2CONbits.T32 = 1;
    T2CONbits.TGATE = 0;
    T2CONbits.TSIDL = 0;
    T2CONbits.TCS = 0;
    PR2 = 0XC6BF;
    PR3 = 0X002D;
    TMR2 = 0;
    TMR3 = 0;
    T2CONbits.TCKPS = 0xb01;
    IFS0bits.T3IF = 0;
    IEC0bits.T3IE = 1;
    IPC1bits.T3IP = 4;
}

/*Formula de Temporización
 * PRX = FCY*TIEMPO/Pres - 1;
 * PRX = 1seg*24000000/1 - 1 = 23999999
 * PRX = 1seg*24000000/8 - 1 = 2999999
 * PRX = 1seg*24000000/64 - 1 = 374999
 * PRX = 1seg*24000000/256 - 1 = 93749
 * 
*/

void __attribute__((interrupt,auto_psv)) _T1Interrupt(void){
    IFS0bits.T1IF = 0;
    LATBbits.LATB0 = ~LATBbits.LATB0;
}

void __attribute__((interrupt,auto_psv)) _T3Interrupt(void){
    IFS0bits.T3IF = 0;
    LATBbits.LATB1 = ~LATBbits.LATB1;
}





