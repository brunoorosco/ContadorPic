                                                      //DEFINI��ES DO PROGRAMA
#define INICIO 1
#define SETBAT 2
#define SETPEC 3
#define MENU 5
#define PRINCIPAL 4

// configura��o dos pinos do LCD
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


//VARIAVEIS GLOBAIS
int setPecas = 0;
int setBatidas = 0;
int batidas = 0;
int pecas = 0;
char ESTADO = 0;
char ESTADO_ANTERIOR = 0;

//DECLARA��O DE SUBROTINA


//TRATAMENTO DE INTERRUP��O
void interrupt()
{
}

void main()
{
    //VARIAVEIS LOCAIS
    bit flagTela;

    //CONFIGURA��ES INICIAS DE PROGRAMA
    //INTERRUP��O

    //INICIALIZA��O DOS MODULOS


    //LOOP DO PROGRGAMA
    while (1)
    {
        switch (ESTADO) //VERIFICA EM QUAL TELA ESTA POSICIONADO
        {
        //TELA COM INFORMA��ES DA IN�CIO
        case INICIO:
            ESTADO_ANTERIOR = MENU; //GUARDA A INFORMA��O DA ULTIMA TELA CASO PRECISE RETORNAR

            break;

        case SETBAT:
            ESTADO_ANTERIOR = INICIO; //GUARDA A INFORMA��O DA TELA ANTERIOR CASO PRECISE RETORNAR

            break;

        case SETPEC:
            ESTADO_ANTERIOR = SETBAT; //GUARDA A INFORMA��O DA TELA ANTERIOR CASO PRECISE RETORNAR

            break;

        case PRINCIPAL:
            ESTADO_ANTERIOR = SETPEC; //GUARDA A INFORMA��O DA TELA ANTERIOR CASO PRECISE RETORNAR

            break;

        case MENU:
            ESTADO_ANTERIOR = PRINCIPAL; //GUARDA A INFORMA��O DA TELA ANTERIOR CASO PRECISE RETORNAR

            break;

        //ESTADO DE ERRO ENTRADA AQUI E FAZ O RESET
        default:
            ESTADO = INICIO;
            break;
        }
    }
}