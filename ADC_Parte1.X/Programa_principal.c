/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 20 de marzo de 2020, 05:14 PM
 */


#include "xc.h"
#include <stdint.h>
#include <stdio.h>
#include "Configuracion.h"
#include <libpic30.h>
#include "LCD_Libreria.h"
#include "ADC_Libreria.h"

uint16_t valor_adc = 0;
float voltaje = 0.0;
char datos[10];

int main(void) {
    ADC_Init();
    //ADPCFG = 0x1FFF; //TODOS los pines Digitales
    LCD_Init();
    LCD_XY(1,5);
    LCD_Caracter('E');
    LCD_XY(0,1);
    LCD_String("Hola Como estas");
    __delay_ms(500);
    LCD_XY(0,1);
    LCD_String(" Suscribete :D ");
    LCD_Comando(0x01);
    while(1){
        ADCON1bits.SAMP = 1;
        __delay_ms(100);
        ADCON1bits.SAMP = 0;
        while(!ADCON1bits.DONE);
        valor_adc = ADCBUF0;
        voltaje = valor_adc*(5.0/4096);// 5/ 4096
        sprintf(datos,"Voltaje es: %0.2F V",voltaje);//2.45
        LCD_XY(0,0);
        LCD_String(datos);
    }
    
}

