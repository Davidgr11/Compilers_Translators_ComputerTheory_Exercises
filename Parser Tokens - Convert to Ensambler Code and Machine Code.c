#include <stdio.h>
#include <stdlib.h>

#define TRUE  (-1)
#define FALSE ( 0)

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

#define SIMBOLO_NO_TERMINAL_Programa 1
#define SIMBOLO_NO_TERMINAL_Instruccion 2
#define SIMBOLO_NO_TERMINAL_InstrVuelta 3
#define SIMBOLO_NO_TERMINAL_InstrAvanza 4
#define SIMBOLO_NO_TERMINAL_InstrSiChocas 5
#define SIMBOLO_NO_TERMINAL_InstrObjeto 6

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

t_token *ptrCurrentToken; //Apuntador al Token Actual que analiza el parser
int boolParserError;

int CurrentToken(int intSimboloT)
{
    int boolRes = FALSE;
    if(!boolParserError)
    {
        if(ptrCurrentToken->intTokenCodigo == intSimboloT)
            boolRes = TRUE;
        else
            boolRes = FALSE;
    }
    return boolRes;
}//CurrentToken

void Expect(int intSimboloT)
{
    if(!boolParserError)
    {
        if(CurrentToken(intSimboloT))
        {
            printf("Token sintacticamente correcto = %s, Renglon = %d, Columna = %d\n",
            ptrCurrentToken->strTokenTextoFuente,
            ptrCurrentToken->intRenglon,
            ptrCurrentToken->intColumna);

            ptrCurrentToken = ptrCurrentToken->ptrSig;
        }
        else
        {
            boolParserError = TRUE;

            printf("Error Sintactico = %s, Renglon = %d, Columna = %d\n",
            ptrCurrentToken->strTokenTextoFuente,
            ptrCurrentToken->intRenglon,
            ptrCurrentToken->intColumna);
        }
    }
}//Expect

void Programa()
{
    if(!boolParserError)
    {
        Instruccion();
        Expect(SIMBOLO_TERMINAL_PuntoYComa);

        while(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_Instruccion))
        {
            Instruccion();
            Expect(SIMBOLO_TERMINAL_PuntoYComa);
        }
    }
}

//Instruccion ::= InstrVuelta | InstrAvanza | InstrSiChocas | InstrObjeto
void Instruccion()
{
    if(!boolParserError)
    {
        if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_InstrVuelta))
        {
           InstrVuelta();
        }
        else if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_InstrAvanza))
        {
           InstrAvanza();
        }
        else if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_InstrSiChocas))
        {
           InstrSiChocas();
        }
        else //if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_InstrObjeto))
        {
           InstrObjeto();
        }
    }
}

//InstrVuelta ::= "VDER" | "VIZQ"
void InstrVuelta()
{
    if(!boolParserError)
    {
        if(CurrentToken(SIMBOLO_TERMINAL_VDER))
        {
           Expect(SIMBOLO_TERMINAL_VDER);
        }
        else //if(CurrentToken(SIMBOLO_TERMINAL_VIZQ)
        {
           Expect(SIMBOLO_TERMINAL_VIZQ);
        }
    }
}

//InstrAvanza ::= "AVANZA" "Num"
void InstrAvanza()
{
    if(!boolParserError)
    {
        Expect(SIMBOLO_TERMINAL_AVANZA);
        Expect(SIMBOLO_TERMINAL_Num);
    }
}

//InstrSiChocas ::= "SI_CHOCAS" Instruccion
void InstrSiChocas();
//Instruccion InstrObjeto ::= "RECOGE" | "DEJA"
void InstrObjeto();


int CurrentTokenInFirst(int intSimboloNT)
{
    int boolRes = FALSE;
    if(!boolParserError)
    {
        switch(intSimboloNT)
        {
            case SIMBOLO_NO_TERMINAL_Programa:
                if(CurrentToken(SIMBOLO_TERMINAL_VDER)) boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_VIZQ)) boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_AVANZA)) boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_SI_CHOCAS)) boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_RECOGE)) boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_DEJA)) boolRes = TRUE;
            break;

            case SIMBOLO_NO_TERMINAL_Instruccion:
                if(CurrentToken(SIMBOLO_TERMINAL_VDER)) boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_VIZQ)) boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_AVANZA)) boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_SI_CHOCAS)) boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_RECOGE)) boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_DEJA)) boolRes = TRUE;
            break;

            case SIMBOLO_NO_TERMINAL_InstrVuelta:
                if(CurrentToken(SIMBOLO_TERMINAL_VDER)) boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_VIZQ)) boolRes = TRUE;
            break;

            case SIMBOLO_NO_TERMINAL_InstrAvanza:
                if(CurrentToken(SIMBOLO_TERMINAL_AVANZA)) boolRes = TRUE;
            break;

            case SIMBOLO_NO_TERMINAL_InstrSiChocas:
                if(CurrentToken(SIMBOLO_TERMINAL_SI_CHOCAS)) boolRes = TRUE;
            break;

            case SIMBOLO_NO_TERMINAL_InstrObjeto:
                if(CurrentToken(SIMBOLO_TERMINAL_RECOGE)) boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_DEJA)) boolRes = TRUE;
            break;
        }
    }
    return boolRes;
}//CurrentTokenInFirst

//Programa ::= Instruccion ; {Instruccion;}
void Programa()
{
    if(!boolParserError)
    {
        Instruccion();
        Expect(SIMBOLO_TERMINAL_PuntoYComa);

        while(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_Instruccion))
        {
            Instruccion();
            Expect(SIMBOLO_TERMINAL_PuntoYComa);
        }
    }
}

//Instruccion ::= InstrVuelta | InstrAvanza | InstrSiChocas | InstrObjeto
void Instruccion()
{
    if(!boolParserError)
    {
        if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_InstrVuelta))
        {
           InstrVuelta();
        }
        else if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_InstrAvanza))
        {
           InstrAvanza();
        }
        else if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_InstrSiChocas))
        {
           InstrSiChocas();
        }
        else //if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_InstrObjeto))
        {
           InstrObjeto();
        }
    }
}

//InstrVuelta ::= "VDER" | "VIZQ"
void InstrVuelta()
{
    if(!boolParserError)
    {
        if(CurrentToken(SIMBOLO_TERMINAL_VDER))
        {
           Expect(SIMBOLO_TERMINAL_VDER);
        }
        else //if(CurrentToken(SIMBOLO_TERMINAL_VIZQ)
        {
           Expect(SIMBOLO_TERMINAL_VIZQ);
        }
    }
}

//InstrAvanza ::= "AVANZA" "Num"
void InstrAvanza()
{
    if(!boolParserError)
    {
        Expect(SIMBOLO_TERMINAL_AVANZA);
        Expect(SIMBOLO_TERMINAL_Num);
    }
}

//InstrSiChocas ::= "SI_CHOCAS" Instruccion
void InstrSiChocas()
{
    if(!boolParserError)
    {
        Expect(SIMBOLO_TERMINAL_SI_CHOCAS);
        Instruccion();
    }
}

//Instruccion InstrObjeto ::= "RECOGE" | "DEJA"
void InstrObjeto()
{
    if(!boolParserError)
    {
        if(CurrentToken(SIMBOLO_TERMINAL_RECOGE))
        {
            Expect(SIMBOLO_TERMINAL_RECOGE);
        }
        else //if(CurrentToken(SIMBOLO_TERMINAL_DEJA))
        {
           Expect(SIMBOLO_TERMINAL_DEJA);
        }
    }
}

void parser_PDRC()
{
    boolParserError = FALSE;
    ptrCurrentToken = ptrTokenList; //Se apunta al 1er nodo de la lista
    Programa();
}
