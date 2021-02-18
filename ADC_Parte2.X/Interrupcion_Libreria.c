
#include "xc.h"
#include "Interrupcion_Libreria.h"

void INT0_Init(void){
    TRISAbits.TRISA11 = 1;
    TRISBbits.TRISB1 = 0;
    INTCON2bits.INT0EP = 0;
    IFS0bits.INT0IF = 0;
    IEC0bits.INT0IE = 1;
    IPC0bits.INT0IP = 3;
}

void __attribute__((interrupt,auto_psv)) _INT0Interrupt(void){
    LATBbits.LATB1 = ~LATBbits.LATB1;
    IFS0bits.INT0IF = 0;
}
