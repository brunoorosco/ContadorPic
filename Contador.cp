#line 1 "C:/Users/sn1017167/Desktop/MikroC/Contador/Contador.c"








sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;



int setPecas = 0;
int setBatidas = 0;
int batidas = 0;
int pecas = 0;
char ESTADO = 0;
char ESTADO_ANTERIOR = 0;





void interrupt()
{
}

void main()
{

 bit flagTela;








 while (1)
 {
 switch (ESTADO)
 {

 case  1 :
 ESTADO_ANTERIOR =  5 ;

 break;

 case  2 :
 ESTADO_ANTERIOR =  1 ;

 break;

 case  3 :
 ESTADO_ANTERIOR =  2 ;

 break;

 case  4 :
 ESTADO_ANTERIOR =  3 ;

 break;

 case  5 :
 ESTADO_ANTERIOR =  4 ;

 break;


 default:
 ESTADO =  1 ;
 break;
 }
 }
}
