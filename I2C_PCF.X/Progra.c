/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 20 de marzo de 2020, 05:14 PM
 */


#include "xc.h"
#include "Configuracion.h"
#include "I2C_Libreria.h"
#include <libpic30.h>

int i;
int main(void) {
    ADPCFG = 0x1FFF; //TODOS los pines Digitales
    I2CCONbits.I2CEN = 1; // HABILITAR I2C
    IFS0bits.MI2CIF = 0;
    I2CBRG = 217;// 100KHz
    while(1){
        for(i = 0;i<16;i++){
            I2C_Start();
            I2C_Tx(0x40);
            I2C_Tx(i);
            I2C_Stop();
            __delay_ms(500);
        }
    }
    
}
