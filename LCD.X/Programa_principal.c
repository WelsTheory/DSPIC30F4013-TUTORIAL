/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 20 de marzo de 2020, 05:14 PM
 */


#include "xc.h"
#include "Configuracion.h"
#include <libpic30.h>
#include "LCD_Libreria.h"

int main(void) {
    ADPCFG = 0x1FFF; //TODOS los pines Digitales
    LCD_Init();
    LCD_XY(1,5);
    LCD_Caracter('E');
    LCD_XY(0,1);
    LCD_String("Hola Como estas");
    __delay_ms(500);
    LCD_XY(0,1);
    LCD_String(" Suscribete :D ");
    while(1){
    }
    
}

