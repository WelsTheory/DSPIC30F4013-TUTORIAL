
#include "xc.h"
#include "Configuracion.h"
#include <libpic30.h>
#include "LCD_Libreria.h"

void LCD_Init(void){
    TRIS_DATA_LCD = 0xf0;//RD0 - RD3 -> 0 Salida
    TRIS_RW = 0;
    TRIS_E = 0;
    TRIS_RS = 0;
    LCD_Comando(0x30);
    __delay_ms(1);
    LCD_Comando(0x30);
    __delay_ms(1);
    LCD_Comando(0x32);// 4 bits
    __delay_ms(1);
    LCD_Comando(0x28);// 2 Lineas 5x8
    LCD_Comando(0x0c);// Display ON
    LCD_Comando(0x01);// Borrar LCD
    LCD_Comando(0x06);// Incremento
    __delay_ms(100);
    
}

void LCD_Comando(unsigned char cmd){//0x30
    DATA_LCD &= 0xf0;
    DATA_LCD |= (cmd>>4)&0x0f; //0x30 >>4 = 0x03
    RW_PIN = 0; // ESCRITURA
    RS_PIN = 0; //MODO COMANDO
    __delay_us(1);
    E_PIN = 1;
    __delay_us(1);
    E_PIN = 0;
    __delay_ms(1);
    
    DATA_LCD &= 0xf0;
    DATA_LCD |= (cmd&0x0f); //0x30 &0x0F = 0x00
    RW_PIN = 0; // ESCRITURA
    RS_PIN = 0; //MODO COMANDO
    __delay_us(1);
    E_PIN = 1;
    __delay_us(1);
    E_PIN = 0;
    __delay_ms(50);
}

void LCD_Caracter(unsigned char data){//0x30
    DATA_LCD &= 0xf0;
    DATA_LCD |= (data>>4)&0x0f; //0x30 >>4 = 0x03
    RW_PIN = 0; // ESCRITURA
    RS_PIN = 1; //MODO CARACTER
    __delay_us(1);
    E_PIN = 1;
    __delay_us(1);
    E_PIN = 0;
    __delay_ms(1);
    
    DATA_LCD &= 0xf0;
    DATA_LCD |= (data&0x0f); //0x30 &0x0F = 0x00
    RW_PIN = 0; // ESCRITURA
    RS_PIN = 1; //MODO CARACTER
    __delay_us(1);
    E_PIN = 1;
    __delay_us(1);
    E_PIN = 0;
    __delay_ms(50);
}

void LCD_XY(int x,int y){
    //1 Linea 0x80
    if(x>0){
        LCD_Comando(0xC0+y);
    }
    else{
        LCD_Comando(0x80+y);
    }
    //2 Linea 0xC0
}

void LCD_String(char *dat){//*dat = "Hola\0"
    while(*dat != '\0'){
        LCD_Caracter(*dat);
        dat++;            
    }
}
