#define DATA_LCD PORTD
#define TRIS_DATA_LCD TRISD

#define RW_PIN LATBbits.LATB10     /* PORT for RW */
#define TRIS_RW  TRISBbits.TRISB10    /* TRIS for RW */
#define RS_PIN   LATBbits.LATB9   /* PORT for RS */
#define TRIS_RS  TRISBbits.TRISB9    /* TRIS for RS */
#define E_PIN    LATBbits.LATB11   /* PORT for E  */
#define TRIS_E   TRISBbits.TRISB11    /* TRIS for E  */

void LCD_XY(int x,int y);
void LCD_Caracter(unsigned char data);
void LCD_Comando(unsigned char cmd);
void LCD_Init(void);
void LCD_String(char *dat);