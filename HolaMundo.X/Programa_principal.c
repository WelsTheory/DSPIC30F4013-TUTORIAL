/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 20 de marzo de 2020, 05:14 PM
 */


#include "xc.h"
#include "Configuracion.h"
#include <libpic30.h>

int main(void) {
    ADPCFG = 0x1FFF; //TODOS los pines Digitales
    TRISB = 0; //SALIDA
    LATB = 0;
    while(1){
        LATBbits.LATB0 = 1;
        __delay_ms(200);
        LATBbits.LATB0 = 0;
        __delay_ms(200);
    }
    
}
