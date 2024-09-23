#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE  (-1)
#define FALSE ( 0)

#define ESPACIOS_POR_TAB 8

#define SCANNER_ERROR   -1
#define TOKEN_RECONOCIDO -1

#define TIPO_NODO_Intermedio        1
#define TIPO_NODO_Final             2
#define TIPO_NODO_IntermedioFinal   3

#define SIMBOLO_TERMINAL_VDER 1
#define SIMBOLO_TERMINAL_VIZQ 2
#define SIMBOLO_TERMINAL_AVANZA 3
#define SIMBOLO_TERMINAL_SI_CHOCAS 4
#define SIMBOLO_TERMINAL_RECOGE 5
#define SIMBOLO_TERMINAL_DEJA 6
#define SIMBOLO_TERMINAL_Num 7
#define SIMBOLO_TERMINAL_PuntoYComa 8
#define SIMBOLO_TERMINAL_Espacio 9
#define SIMBOLO_TERMINAL_Tabulador 10
#define SIMBOLO_TERMINAL_SaltoLinea 11
#define SIMBOLO_TERMINAL_EOF 12

#define AUTOMATA_ESTADOS_NUM 39
#define AUTOMATA_SIMBOLOS_ENTRADA_Y_CONTROL 33

#define AUTOMATA_TIPO_NODO (AUTOMATA_SIMBOLOS_ENTRADA_Y_CONTROL - 2)
#define AUTOMATA_CODIGO_SALIDA (AUTOMATA_SIMBOLOS_ENTRADA_Y_CONTROL - 1)

int MT[AUTOMATA_ESTADOS_NUM][AUTOMATA_SIMBOLOS_ENTRADA_Y_CONTROL] = {
   {8,-1,29,-1,-1,-1,-1,-1,-1,-1,-1,23,14,1,-1,33,33,33,33,33,33,33,33,33,33,-1,34,35,36,37,38,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,2,-1,-1,-1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_VDER},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_VIZQ},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,-1,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_AVANZA},
   {-1,-1,-1,-1,-1,-1,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,16,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {21,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_SI_CHOCAS},
   {-1,-1,-1,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,26,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,28,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_RECOGE},
   {-1,-1,-1,30,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,31,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_DEJA},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,33,33,33,33,33,33,33,33,33,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_Num},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_PuntoYComa},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_Espacio},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_Tabulador},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_SaltoLinea},
   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_EOF}
};

struct t_token
{
    int intTokenCodigo;
    char *strTokenTextoFuente;
    int intRenglon;
    int intColumna;
    struct t_token *ptrSig;
};
typedef struct t_token t_token;
//t_token *ptrTokenList = NULL;
t_token *ptrTokenList;

void InsertarEnTokenList(int intTokenCodigo, char *strTokenTextoFuente, int intRenglon, int intColumna)
{
    t_token *ptrTmp = ptrTokenList;

    //Creación e inicialización del nuevo token
    t_token *ptrTokenNuevo = (t_token *)malloc(sizeof(t_token));
    ptrTokenNuevo->intTokenCodigo = intTokenCodigo;
    ptrTokenNuevo->strTokenTextoFuente = (char *)malloc(strlen(strTokenTextoFuente)+1);
    ptrTokenNuevo->strTokenTextoFuente[0] = '\0';
    strcpy(ptrTokenNuevo->strTokenTextoFuente, strTokenTextoFuente);
    ptrTokenNuevo->intRenglon = intRenglon;
    ptrTokenNuevo->intColumna = intColumna;
    ptrTokenNuevo->ptrSig = NULL;

    if(ptrTmp == NULL) //La lista está vacía
    {
        ptrTokenList = ptrTokenNuevo;
    }//if
    else //La lista tiene elementos
    {
        while(ptrTmp->ptrSig != NULL)
        {
            ptrTmp = ptrTmp->ptrSig;
        }//while
        ptrTmp->ptrSig = ptrTokenNuevo;
    }//else

}//InsertarEnTokenList

void ListaTokens_Imprime()
{
    t_token *ptrAux = ptrTokenList;

    printf("\nImpresion de Lista\n");

    while(ptrAux != NULL)
    {
        printf("Token Reconocido[%d,%d]:[%d]-Codigo:[%s]\n",
               ptrAux->intRenglon, ptrAux->intColumna,
               ptrAux->intTokenCodigo, ptrAux->strTokenTextoFuente);
        ptrAux = ptrAux->ptrSig;
    }//while
}//ListaTokens_Imprime

void ListaTokens_Liberar()
{
    t_token *ptrAux = ptrTokenList;
    t_token *ptrAnt;

    while(ptrAux != NULL)
    {
        ptrAnt = ptrAux;
        ptrAux = ptrAux->ptrSig;

        if (ptrAnt->strTokenTextoFuente != NULL)
            free(ptrAnt->strTokenTextoFuente);

        free(ptrAnt);
    }//while

    ptrTokenList = NULL;
}//ListaTokens_Liberar

int ObtenerCodigoSimboloEntrada(char c)
{
    int intCodigoSimboloSalida = -1;

    switch(c)
    {
        case 'A' : intCodigoSimboloSalida = 0; break;
        case 'C' : intCodigoSimboloSalida = 1; break;
        case 'D' : intCodigoSimboloSalida = 2; break;
        case 'E' : intCodigoSimboloSalida = 3; break;
        case 'G' : intCodigoSimboloSalida = 4; break;
        case 'H' : intCodigoSimboloSalida = 5; break;
        case 'I' : intCodigoSimboloSalida = 6; break;
        case 'J' : intCodigoSimboloSalida = 7; break;
        case 'N' : intCodigoSimboloSalida = 8; break;
        case 'O' : intCodigoSimboloSalida = 9; break;
        case 'Q' : intCodigoSimboloSalida = 10; break;
        case 'R' : intCodigoSimboloSalida = 11; break;
        case 'S' : intCodigoSimboloSalida = 12; break;
        case 'V' : intCodigoSimboloSalida = 13; break;
        case 'Z' : intCodigoSimboloSalida = 14; break;
        case '0' : intCodigoSimboloSalida = 15; break;
        case '1' : intCodigoSimboloSalida = 16; break;
        case '2' : intCodigoSimboloSalida = 17; break;
        case '3' : intCodigoSimboloSalida = 18; break;
        case '4' : intCodigoSimboloSalida = 19; break;
        case '5' : intCodigoSimboloSalida = 20; break;
        case '6' : intCodigoSimboloSalida = 21; break;
        case '7' : intCodigoSimboloSalida = 22; break;
        case '8' : intCodigoSimboloSalida = 23; break;
        case '9' : intCodigoSimboloSalida = 24; break;
        case '_' : intCodigoSimboloSalida = 25; break;
        case ';' : intCodigoSimboloSalida = 26; break;
        case ' ' : intCodigoSimboloSalida = 27; break;
        case '\t': intCodigoSimboloSalida = 28; break;
        case '\n': intCodigoSimboloSalida = 29; break;
        case -1  : intCodigoSimboloSalida = 30; break;
    }//switch

    return intCodigoSimboloSalida;
}//ObtenerCodigoSimboloEntrada

char *ObtenerEtiquetaDelSimboloTerminal(int intCodigoSimboloTerminal)
{
    char *strTokenSimboloTerminal = (char *)malloc(255);

    switch(intCodigoSimboloTerminal)
    {
        case SIMBOLO_TERMINAL_VDER:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_VDER");
            break;
        case SIMBOLO_TERMINAL_VIZQ:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_VIZQ");
            break;
        case SIMBOLO_TERMINAL_AVANZA:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_AVANZA");
            break;
        case SIMBOLO_TERMINAL_SI_CHOCAS:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_SI_CHOCAS");
            break;
        case SIMBOLO_TERMINAL_RECOGE:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_RECOGE");
            break;
        case SIMBOLO_TERMINAL_DEJA:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_DEJA");
            break;
        case SIMBOLO_TERMINAL_Num:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_Num");
            break;
        case SIMBOLO_TERMINAL_PuntoYComa:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_PuntoYComa");
            break;
        case SIMBOLO_TERMINAL_Espacio:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_Espacio");
            break;
        case SIMBOLO_TERMINAL_Tabulador:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_Tabulador");
            break;
        case SIMBOLO_TERMINAL_SaltoLinea:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_SaltoLinea");
            break;
        case SIMBOLO_TERMINAL_EOF:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_EOF");
            break;
    }//switch

    return strTokenSimboloTerminal;
}//ObtenerEtiquetaDelSimboloTerminal

int EsTokenSeparador(int intCodigoSimboloTerminal)
{
    int boolRespuesta = FALSE;

    switch(intCodigoSimboloTerminal)
    {
        case SIMBOLO_TERMINAL_Espacio:
            boolRespuesta = TRUE;
            break;
        case SIMBOLO_TERMINAL_Tabulador:
            boolRespuesta = TRUE;
            break;
        case SIMBOLO_TERMINAL_SaltoLinea:
            boolRespuesta = TRUE;
            break;
    }//switch

    return boolRespuesta;
}//EsTokenSeparador

void scanner(char *strArchivoFuente)
{
    FILE *ptrArchivoFuente;
    //s := s0;
        int intEstadoActual = 0;
    char c;
    int intEstadoSiguiente;
    int intCodigoSimboloEntrada;
    int intTipoNodo;
    int intCodigoSimboloTerminal;
    int boolBanderaLee = TRUE;
    char *strTokenSimboloEntrada;
    char *strBuffer = (char *)malloc(1024);
    strBuffer[0]='\0'; //strBuffer = "";
    int intLenAux;
    int intRenglon = 1;
    int intColumna = 0;
    int intRenglonToken;
    int intColumnaToken;

    ptrArchivoFuente = fopen(strArchivoFuente,"r");

    if (ptrArchivoFuente == NULL)
    {
        perror("Error en Archivo Fuente.\n");
    }
    else
    {
        do
        {
            if (boolBanderaLee)
            {
                c = getc(ptrArchivoFuente);

                if (c == '\n')
                {
                    intRenglon++;
                    intColumna = 0;
                }//if
                else
                {
                    if (c == '\t')
                    {
                        intColumna = intColumna + (ESPACIOS_POR_TAB - (intColumna % ESPACIOS_POR_TAB));
                    }
                    else
                        intColumna++;
                }//else
            }//if

            //printf("%c\n",c);

            if (intEstadoActual == 0)
            {
                intRenglonToken = intRenglon;
                intColumnaToken = intColumna;
            }//if

            if(!boolBanderaLee)
            {
                boolBanderaLee = TRUE;
            }//if

            intCodigoSimboloEntrada = ObtenerCodigoSimboloEntrada(c);

            //  s := mov[s,c];
            intEstadoSiguiente = MT[intEstadoActual][intCodigoSimboloEntrada];
            intTipoNodo = MT[intEstadoActual][AUTOMATA_TIPO_NODO];

            //Si no hay transición pero es un nodo Final, acabamos de reconocer un elemento
            if ((intEstadoSiguiente == TOKEN_RECONOCIDO)
                 && ((intTipoNodo == TIPO_NODO_Final)
                    || (intTipoNodo == TIPO_NODO_IntermedioFinal)))
            {//Se acaba de reconocer un token o elemento
                //if s está en F then
                //  return "si"
                intCodigoSimboloTerminal = MT[intEstadoActual][AUTOMATA_CODIGO_SALIDA];

                if (!EsTokenSeparador(intCodigoSimboloTerminal))
                {
                    strTokenSimboloEntrada = ObtenerEtiquetaDelSimboloTerminal(intCodigoSimboloTerminal);

                    printf("Token Reconocido r[%d]c[%d] - Codigo:[%d]-Etiqueta:[%s]-Buffer[%s]\n",
                           intRenglonToken, intColumnaToken,
                           intCodigoSimboloTerminal, strTokenSimboloEntrada, strBuffer);

                    InsertarEnTokenList(intCodigoSimboloTerminal, strBuffer,
                                        intRenglonToken, intColumnaToken);

                    free(strTokenSimboloEntrada);
                }//if

                intEstadoActual = 0;
                boolBanderaLee = FALSE;
                strBuffer[0]='\0';
            }//if
            else if (intEstadoSiguiente == SCANNER_ERROR)
            {
                //if s está en F then
                //else
                //  return "no"; -> Error
                printf("Error Lexico r[%d]c[%d] - Buffer[%s]\n",
                       intRenglonToken, intColumnaToken, strBuffer);
                intEstadoActual = 0;
                boolBanderaLee = TRUE;
                strBuffer[0]='\0';
            }
            else
            {
                intEstadoActual = intEstadoSiguiente;

                intLenAux = strlen(strBuffer);
                strBuffer[intLenAux] = c;
                strBuffer[intLenAux+1] = '\0';
            }//else
        } while (c != EOF);
        //do while c <> eof
        //end;
        InsertarEnTokenList(SIMBOLO_TERMINAL_EOF, "SIMBOLO_TERMINAL_EOF",
                            intRenglonToken, intColumnaToken);
        fclose(ptrArchivoFuente);
    }//else
    free(strBuffer);
}//scanner
