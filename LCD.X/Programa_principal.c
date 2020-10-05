/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 23 de mayo de 2020, 04:32 PM
 */


#include "xc.h"
#include "Configuracion.h"
#include "LCD_LIBRERIA.h"


int main(void) {
    ADPCFG= 0x1FFF;      // Configurando el Puerto B como I/O Digital
    LATB  = 0x0000;
    TRISB = 0x0000;      // Configurando todo el Puerto B como salida Digital
    LATD  = 0x00;
    TRISD = 0x00;        // Configurando el Puerto D como salida Digital
}
