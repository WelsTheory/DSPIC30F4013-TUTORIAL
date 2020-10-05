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
    LCD_Init();
    LCD_Caracter('E');
}
