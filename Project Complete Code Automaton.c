
//TEORÍA COMPUTACIONAL
//Caballero Angeles Karina
//David Alejandro Gonzalez Robles
//Grupo: 501
#include <stdio.h>
#include <stdlib.h>
#define TRUE (-1)
#define FALSE (0)
#define ESPACIOS_POR_TAB 8
#define SCANNER_ERROR -1
#define TOKEN_RECONOCIDO -1
#define TIPO_NODO_Intermedio 1
#define TIPO_NODO_Final 2
#define TIPO_NODO_IntermedioFinal 3
#define SIMBOLO_TERMINAL_TMIST 1
#define SIMBOLO_TERMINAL_TSHOWER 2
#define SIMBOLO_TERMINAL_TJET 3
#define SIMBOLO_TERMINAL_AVANZA 4
#define SIMBOLO_TERMINAL_VDER 5
#define SIMBOLO_TERMINAL_VIZQ 6
#define SIMBOLO_TERMINAL_RECOGE 7
#define SIMBOLO_TERMINAL_DEJA 8
#define SIMBOLO_TERMINAL_SI_CHOCAS 9
#define SIMBOLO_TERMINAL_CSUBE 10
#define SIMBOLO_TERMINAL_CBAJA 11
#define SIMBOLO_TERMINAL_Num 12
#define SIMBOLO_TERMINAL_PuntoYComa 13
#define SIMBOLO_TERMINAL_Espacio 14
#define SIMBOLO_TERMINAL_Tabulador 15
#define SIMBOLO_TERMINAL_SaltoLinea 16
#define SIMBOLO_TERMINAL_FinalDelArchivo 17


#define AUTOMATA_ESTADOS_NUM 62
#define AUTOMATA_SIMBOLOS_ENTRADA_Y_CONTROL 38

#define AUTOMATA_TIPO_NODO (AUTOMATA_SIMBOLOS_ENTRADA_Y_CONTROL - 2)
#define AUTOMATA_CODIGO_SALIDA (AUTOMATA_SIMBOLOS_ENTRADA_Y_CONTROL -1)


int MT[AUTOMATA_ESTADOS_NUM][AUTOMATA_SIMBOLOS_ENTRADA_Y_CONTROL]={
       {15,-1,47,34,-1,-1,-1,-1,-1,-1,-1,-1,-1,28,38,1,-1,21,-1,-1,56,56,56,56,56,56,56,56,56,56,-1,57,58,59,60,61,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,12,2,-1,-1,-1,-1,6,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_TMIST},
  {-1,-1,-1,-1,-1,-1,7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,8,-1,28,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_TSHOWER},
  {-1,-1,-1,-1,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_TJET},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_AVANZA},
  {-1,-1,-1,22,-1,-1,-1,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_VDER},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,26,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_VIZQ},
  {-1,-1,-1,-1,29,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,30,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,31,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,33,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_RECOGE},
  {-1,-1,-1,-1,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,36,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {37,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_DEJA},
  {-1,-1,-1,-1,-1,-1,-1,39,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,40,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,41,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,42,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,43,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {45,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,46,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_SI_CHOCAS},
  {-1,52,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,49,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_CSUBE},
  {53,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,54,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Intermedio,SCANNER_ERROR},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_CBAJA},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,56,56,56,56,56,56,56,56,56,56,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_Num},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_PuntoYComa},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_Espacio},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_Tabulador},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_SaltoLinea},
  {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_FinalDelArchivo},


};
struct t_token
{
    int intTokenCodigo;
    char * strTokenTextoFuente;
    int intRenglon;
    int intColumna;
    struct t_token * ptrSig;
};
typedef struct t_token t_token;
t_token * ptrTokenList = NULL;

void InsertarEnTokenList(int intTokenCodigo,char* strTokenTextoFuente,int intRenglon,int intColumna){
  t_token * ptrTmp = ptrTokenList;

  t_token * ptrTokenNuevo = (t_token*)malloc (sizeof(t_token));
  ptrTokenNuevo->intTokenCodigo = intTokenCodigo;
  ptrTokenNuevo->strTokenTextoFuente = (char*) malloc (strlen(strTokenTextoFuente)+1);
  ptrTokenNuevo->strTokenTextoFuente[0]= '\0';
  strcpy(ptrTokenNuevo->strTokenTextoFuente,strTokenTextoFuente);
  ptrTokenNuevo->intRenglon=intRenglon;
  ptrTokenNuevo->intColumna=intColumna;
  ptrTokenNuevo->ptrSig=NULL;

  if(ptrTmp==NULL)//la lista esta vacia
  {
      ptrTokenList = ptrTokenNuevo;

  }
  else{

    while(ptrTmp->ptrSig !=NULL){
        ptrTmp = ptrTmp->ptrSig;
    }
    ptrTmp->ptrSig = ptrTokenNuevo;
  }

}
void  ListaTokens_Imprime(){
    t_token * ptrAux = ptrTokenList;
    printf("Impresion de la lista\n");
    while (ptrAux !=NULL){
        printf("Token reconocido[%d,%d]:[%d]-Codigo[%s]\n",ptrAux->intRenglon,ptrAux->intColumna,ptrAux->intTokenCodigo,ptrAux->strTokenTextoFuente);
        ptrAux = ptrAux->ptrSig;
    }
}
void ListaTokens_Liberar(){
    t_token * ptrAux = ptrTokenList;
    t_token * ptrAnt;
    while(ptrAux != NULL){
        ptrAnt = ptrAux;
        ptrAux= ptrAux->ptrSig;

        if(ptrAnt->strTokenTextoFuente != NULL){
            free(ptrAnt->strTokenTextoFuente);
        free(ptrAnt);
        }
    }
    ptrTokenList = NULL;
}
int ObtenerCodigoSimboloEntrada (char c){
    int intCodigoSimboloSalida = -1;
    switch(c){
        case'A':intCodigoSimboloSalida=0;break;
        case'B':intCodigoSimboloSalida=1;break;
        case'C':intCodigoSimboloSalida=2;break;
        case'D':intCodigoSimboloSalida=3;break;
        case'E':intCodigoSimboloSalida=4;break;
        case'G':intCodigoSimboloSalida=5;break;
        case'H':intCodigoSimboloSalida=6;break;
        case'I':intCodigoSimboloSalida=7;break;
        case'J':intCodigoSimboloSalida=8;break;
        case'M':intCodigoSimboloSalida=9;break;
        case'N':intCodigoSimboloSalida=10;break;
        case'O':intCodigoSimboloSalida=11;break;
        case'Q':intCodigoSimboloSalida=12;break;
        case'R':intCodigoSimboloSalida=13;break;
        case'S':intCodigoSimboloSalida=14;break;
        case'T':intCodigoSimboloSalida=15;break;
        case'U':intCodigoSimboloSalida=16;break;
        case'V':intCodigoSimboloSalida=17;break;
        case'W':intCodigoSimboloSalida=18;break;
        case'Z':intCodigoSimboloSalida=19;break;
        case'0':intCodigoSimboloSalida=20;break;
        case'1':intCodigoSimboloSalida=21;break;
        case'2':intCodigoSimboloSalida=22;break;
        case'3':intCodigoSimboloSalida=23;break;
        case'4':intCodigoSimboloSalida=24;break;
        case'5':intCodigoSimboloSalida=25;break;
        case'6':intCodigoSimboloSalida=26;break;
        case'7':intCodigoSimboloSalida=27;break;
        case'8':intCodigoSimboloSalida=28;break;
        case'9':intCodigoSimboloSalida=29;break;
        case'_':intCodigoSimboloSalida=30;break;
        case';':intCodigoSimboloSalida=31;break;
        case' ':intCodigoSimboloSalida=32;break;
        case'\t':intCodigoSimboloSalida=33;break;
        case'\n':intCodigoSimboloSalida=34;break;
        case -1:intCodigoSimboloSalida=35;break;



    }
    return intCodigoSimboloSalida;
}//ObtenerCodigoSimboloEntrada
char *ObtenerCodigoSimboloTerminal (int intCodigoSimboloTerminal){
    char *strTokenSimboloTerminal = (char *)malloc(255);
    switch(intCodigoSimboloTerminal)
    {
    case SIMBOLO_TERMINAL_TMIST:
        strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_TMIST");
        break;
    case SIMBOLO_TERMINAL_TSHOWER:
        strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_TSHOWER");
        break;
    case SIMBOLO_TERMINAL_TJET:
        strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_TJET");
        break;
    case SIMBOLO_TERMINAL_AVANZA:
        strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_AVANZA");
        break;
    case SIMBOLO_TERMINAL_VDER:
        strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_VDER");
        break;
    case SIMBOLO_TERMINAL_VIZQ:
        strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_VIZQ");
        break;
    case SIMBOLO_TERMINAL_RECOGE:
        strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_RECOGE");
        break;
    case SIMBOLO_TERMINAL_DEJA:
        strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_DEJA");
        break;
    case SIMBOLO_TERMINAL_SI_CHOCAS:
        strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_SI_CHOCAS");
        break;
    case SIMBOLO_TERMINAL_CSUBE:
        strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_CSUBE");
        break;
    case SIMBOLO_TERMINAL_CBAJA:
        strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_CBAJA");
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
        strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_SaltoDeLinea");
        break;
    case SIMBOLO_TERMINAL_FinalDelArchivo:
        strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_FinalDelArchivo");
        break;


    }
    return strTokenSimboloTerminal;
}//Obtener etiqueta simbolo terminal

int EsTokenSeparador(intCodigoSimboloTerminal){

int boolRespuesta= FALSE;


switch(intCodigoSimboloTerminal)
{
    case SIMBOLO_TERMINAL_Espacio:
    boolRespuesta = TRUE;
    break;
    case SIMBOLO_TERMINAL_SaltoLinea:
    boolRespuesta = TRUE;
    break;
    case SIMBOLO_TERMINAL_Tabulador:
    boolRespuesta = TRUE;
    break;

}//switch

return boolRespuesta;

}//EsTokenSeparador


void scanner (char* strArchivoFuente)
{
    FILE * ptrArchivoFuente;
   // s:=0;
        int intEstadoActual=0;
    char c;
    char *strTokenSimboloEntrada;
    int intEstadoSiguiente;
    int intCodigoSimboloEntrada;
    int intTipoNodo;
    int intCodigoSimboloTerminal;
    int boolBanderaLee = TRUE;
    char * strBuffer = (char*)malloc(1024);
    strBuffer[0] = '\0';
    int intLenAux;
    int intReglon=1;
    int intColumna=0;
    int intReglonToken = 0;
    int intColumnaToken = 0;
 printf("**---PROYECTO FINAL---**\n");

    ptrArchivoFuente=fopen(strArchivoFuente,"r");
    if(ptrArchivoFuente==NULL)
    {
        perror("Error en el archivo fuente\n");
    }
    else
    {
        do{

        if(boolBanderaLee)
        {

            c=getc(ptrArchivoFuente);
           if( c=='\n'){
            intReglon ++;
            intColumna=0;
           }else{
               if(c== '\t'){

                intColumna = intColumna + (ESPACIOS_POR_TAB -(intColumna % ESPACIOS_POR_TAB));

               }
               else{
               intColumna++;
               }
           }

        }

        //c:=siguientecaracter;

        //printf("%c\n",c);
        if(intEstadoActual==0){
            intReglonToken = intReglon;
            intColumnaToken = intColumna;
        }

        intCodigoSimboloEntrada = ObtenerCodigoSimboloEntrada(c);
        if(!boolBanderaLee)
        {
            boolBanderaLee = TRUE;
        }
        //s:=mov(s,c);
        intEstadoSiguiente=MT[intEstadoActual][intCodigoSimboloEntrada];
        intTipoNodo= MT[intEstadoActual][AUTOMATA_TIPO_NODO];

        //Si no hay transcion pero es nodo final,acabamos de reconocer un elemento
        if((intEstadoSiguiente == TOKEN_RECONOCIDO)&&(intTipoNodo == TIPO_NODO_Final)||(intTipoNodo == TIPO_NODO_IntermedioFinal)){ //Se acaba de reconocer un token o elemento
            /*
        if s esta en F tehn
        return "si" */

           intCodigoSimboloTerminal = MT[intEstadoActual][AUTOMATA_CODIGO_SALIDA];

           if(!EsTokenSeparador(intCodigoSimboloTerminal)){ //Si es token separador

             strTokenSimboloEntrada = ObtenerCodigoSimboloTerminal (intCodigoSimboloTerminal);
             printf("Token Reconocido r[%d]c[%d]- Codigo [%d]-Etiqueta:[%s]-Buffer:[%s]\n",intReglonToken,intColumnaToken,intCodigoSimboloTerminal,strTokenSimboloEntrada,strBuffer);
            InsertarEnTokenList(intCodigoSimboloTerminal,strBuffer,intReglonToken,intColumnaToken);
             free(strTokenSimboloEntrada);
           }//if

           intEstadoActual=0;
           strBuffer[0]='\0';
           boolBanderaLee=FALSE;
        }
        else if (intEstadoSiguiente == SCANNER_ERROR)
        { //ocurre un error lexico
             /* if s esta en F tehn else
            return "no"
            */
           printf("Error Lexico r[%d]c[%d] - Buffer[%s]\n",intReglonToken,intColumnaToken,strBuffer);
            intEstadoActual=0;
            boolBanderaLee=TRUE;
            strBuffer[intLenAux+1]='\0';
        }
        else
        {//recorriendo el automata reconociendo el token actual
            intEstadoActual=intEstadoSiguiente;
            intLenAux= strlen (strBuffer);
            strBuffer[intLenAux]=c;
            strBuffer[intLenAux+1]='\0';
        }




        }while(c != EOF);
        //while c<> eof fo
        //end;
        InsertarEnTokenList(SIMBOLO_TERMINAL_FinalDelArchivo,"SIMBOLO_TERMINAL_FinalDelArchivo",intReglonToken,intColumnaToken);
        fclose(ptrArchivoFuente);
    }
  free(strBuffer);

}//scanner
int main()
{

    scanner("fuente.txt");
    ListaTokens_Imprime();
    ListaTokens_Liberar();

    return 0;
}
