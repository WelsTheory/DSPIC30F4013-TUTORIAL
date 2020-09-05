
#include "xc.h"
#include "Configuracion.h"
#include <libpic30.h>
#include "I2C_Libreria.h"


void I2C_Start(void){
    IFS0bits.MI2CIF = 0;
    I2CCONbits.SEN = 1;
    while(IFS0bits.MI2CIF == 0);
}

void I2C_Stop(void){
    IFS0bits.MI2CIF = 0;
    I2CCONbits.PEN = 1;
    while(IFS0bits.MI2CIF == 0);
}

void I2C_Ack(void){
    IFS0bits.MI2CIF = 0;
    I2CCONbits.ACKEN = 1;
    I2CCONbits.ACKDT = 0;//ACK
    while(IFS0bits.MI2CIF == 0);
}

void I2C_Nack(void){
    IFS0bits.MI2CIF = 0;
    I2CCONbits.ACKEN = 1;
    I2CCONbits.ACKDT = 1;//NACK
    while(IFS0bits.MI2CIF == 0);
}

void I2C_Tx(char data){
    IFS0bits.MI2CIF = 0;
    I2CTRN = data;
    while(IFS0bits.MI2CIF == 0);
}

char I2C_Rx(void){
    IFS0bits.MI2CIF = 0;
    I2CCONbits.RCEN = 1;
    while(IFS0bits.MI2CIF == 0);
    return I2CRCV;
}