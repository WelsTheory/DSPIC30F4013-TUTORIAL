#include <xc.h>
#include "Configuracion.h"
#include "LCD_LIBRERIA.h"

void LCD_Init(void){
    TRIS_DATA_PORT = 0xf0;// RD0 - RD3 -> Salidas
    TRIS_RW = 0;
    TRIS_RS = 0;
    TRIS_E = 0;
    LCD_Comando(0x30);
    __delay_ms(1);
    LCD_Comando(0x30);
    __delay_ms(1);
    LCD_Comando(0x30);
    __delay_ms(1);
    LCD_Comando(0x32);
    LCD_Comando(0x28);// 2 lINEAS 5X8
    LCD_Comando(0x0C);// dISPLAY ON CURSON OFF
    LCD_Comando(0x01);// BORRANDO DISPLAY
    LCD_Comando(0x06);// INCR 
    __delay_ms(1);
    //0x30
}

void LCD_Comando(unsigned char cmd){ 
    //cmd -> 0x30
    DATA_PORT &= 0xf0;// RD0 - RD3 = 0
    DATA_PORT |= (cmd>>4)& 0x0f; //0x30 >>4 0x03
    RW_PIN = 0;// ESCRITURA
    RS_PIN = 0;// MODO COMANDO
    __delay_us(1);
    E_PIN = 1;
    __delay_us(1);
    E_PIN = 0;
    __delay_ms(50);
    
    DATA_PORT &= 0xf0;// RD0 - RD3 = 0
    DATA_PORT |= cmd & 0x0f; //0x30 & 0x0F
    RW_PIN = 0;// ESCRITURA
    RS_PIN = 0;// MODO COMANDO
    __delay_us(1);
    E_PIN = 1;
    __delay_us(1);
    E_PIN = 0;
    __delay_ms(50);
}

void LCD_Caracter(unsigned char data){// 'H' -> 0x51
    DATA_PORT &= 0xf0;// RD0 - RD3 = 0
    DATA_PORT |= (data>>4)& 0x0f; //0x30 >>4 0x03
    RW_PIN = 0;// ESCRITURA
    RS_PIN = 1;// MODO ESCRITURA
    __delay_us(1);
    E_PIN = 1;
    __delay_us(1);
    E_PIN = 0;
    __delay_ms(50);
    
    DATA_PORT &= 0xf0;// RD0 - RD3 = 0
    DATA_PORT |= data & 0x0f; //0x30 & 0x0F
    RW_PIN = 0;// ESCRITURA
    RS_PIN = 0;// MODO COMANDO
    __delay_us(1);
    E_PIN = 1;
    __delay_us(1);
    E_PIN = 0;
    __delay_ms(50);
}