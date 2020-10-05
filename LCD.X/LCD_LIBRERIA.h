/* DATA_PORT defines the port to which the LCD data lines are connected */
#define DATA_PORT  PORTD
#define TRIS_DATA_PORT  TRISD

/* CTRL_PORT defines the port where the control lines are connected.
 * These are just samples, change to match your application.
 */
#define RW_PIN   LATBbits.LATB10   /* PORT for RW */
#define TRIS_RW  TRISBbits.TRISB10    /* TRIS for RW */
#define RS_PIN   LATBbits.LATB9   /* PORT for RS */
#define TRIS_RS  TRISBbits.TRISB9    /* TRIS for RS */
#define E_PIN    LATBbits.LATB11   /* PORT for E  */
#define TRIS_E   TRISBbits.TRISB11    /* TRIS for E  */

