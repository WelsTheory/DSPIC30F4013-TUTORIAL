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
    while(1){
    }
    
}

void Timer_16bits(void){
}

void Timer_32bits(void){
}

void __attribute__((interrupt,auto_psv)) _T1Interrupt(void){
}

void __attribute__((interrupt,auto_psv)) _T3Interrupt(void){
}