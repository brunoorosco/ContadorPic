
_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;Contador.c,36 :: 		void interrupt()
;Contador.c,38 :: 		}
L_end_interrupt:
L__interrupt11:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt

_main:

;Contador.c,40 :: 		void main()
;Contador.c,52 :: 		while (1)
L_main0:
;Contador.c,54 :: 		switch (ESTADO) //VERIFICA EM QUAL TELA ESTA POSICIONADO
	GOTO       L_main2
;Contador.c,57 :: 		case INICIO:
L_main4:
;Contador.c,58 :: 		ESTADO_ANTERIOR = MENU; //GUARDA A INFORMA플O DA ULTIMA TELA CASO PRECISE RETORNAR
	MOVLW      5
	MOVWF      _ESTADO_ANTERIOR+0
;Contador.c,60 :: 		break;
	GOTO       L_main3
;Contador.c,62 :: 		case SETBAT:
L_main5:
;Contador.c,63 :: 		ESTADO_ANTERIOR = INICIO; //GUARDA A INFORMA플O DA TELA ANTERIOR CASO PRECISE RETORNAR
	MOVLW      1
	MOVWF      _ESTADO_ANTERIOR+0
;Contador.c,65 :: 		break;
	GOTO       L_main3
;Contador.c,67 :: 		case SETPEC:
L_main6:
;Contador.c,68 :: 		ESTADO_ANTERIOR = SETBAT; //GUARDA A INFORMA플O DA TELA ANTERIOR CASO PRECISE RETORNAR
	MOVLW      2
	MOVWF      _ESTADO_ANTERIOR+0
;Contador.c,70 :: 		break;
	GOTO       L_main3
;Contador.c,72 :: 		case PRINCIPAL:
L_main7:
;Contador.c,73 :: 		ESTADO_ANTERIOR = SETPEC; //GUARDA A INFORMA플O DA TELA ANTERIOR CASO PRECISE RETORNAR
	MOVLW      3
	MOVWF      _ESTADO_ANTERIOR+0
;Contador.c,75 :: 		break;
	GOTO       L_main3
;Contador.c,77 :: 		case MENU:
L_main8:
;Contador.c,78 :: 		ESTADO_ANTERIOR = PRINCIPAL; //GUARDA A INFORMA플O DA TELA ANTERIOR CASO PRECISE RETORNAR
	MOVLW      4
	MOVWF      _ESTADO_ANTERIOR+0
;Contador.c,80 :: 		break;
	GOTO       L_main3
;Contador.c,83 :: 		default:
L_main9:
;Contador.c,84 :: 		ESTADO = INICIO;
	MOVLW      1
	MOVWF      _ESTADO+0
;Contador.c,85 :: 		break;
	GOTO       L_main3
;Contador.c,86 :: 		}
L_main2:
	MOVF       _ESTADO+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_main4
	MOVF       _ESTADO+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_main5
	MOVF       _ESTADO+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_main6
	MOVF       _ESTADO+0, 0
	XORLW      4
	BTFSC      STATUS+0, 2
	GOTO       L_main7
	MOVF       _ESTADO+0, 0
	XORLW      5
	BTFSC      STATUS+0, 2
	GOTO       L_main8
	GOTO       L_main9
L_main3:
;Contador.c,87 :: 		}
	GOTO       L_main0
;Contador.c,88 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
