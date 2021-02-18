

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef INTERRUPCION_H
#define	INTERRUPCION_H

#include <xc.h> // include processor files - each processor file is guarded.  

void INT0_Init(void);

void __attribute__((interrupt,auto_psv)) _INT0Interrupt(void);

#endif	/* XC_HEADER_TEMPLATE_H */

