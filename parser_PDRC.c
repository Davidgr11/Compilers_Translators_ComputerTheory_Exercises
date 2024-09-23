#include <stdio.h>
#include <stdlib.h>

#define TRUE  (-1)
#define FALSE ( 0)

#define SIMBOLO_TERMINAL_programa 1
#define SIMBOLO_TERMINAL_if 2
#define SIMBOLO_TERMINAL_else 3
#define SIMBOLO_TERMINAL_while 4
#define SIMBOLO_TERMINAL_AND 5
#define SIMBOLO_TERMINAL_OR 6
#define SIMBOLO_TERMINAL_NumeroEntero 7
#define SIMBOLO_TERMINAL_NumeroReal 8
#define SIMBOLO_TERMINAL_PuntoYComa 9
#define SIMBOLO_TERMINAL_LlaveIzq 10
#define SIMBOLO_TERMINAL_LlaveDer 11
#define SIMBOLO_TERMINAL_ParentesisIzq 12
#define SIMBOLO_TERMINAL_ParentesisDer 13
#define SIMBOLO_TERMINAL_Interrogacion 14
#define SIMBOLO_TERMINAL_Exclamacion 15
#define SIMBOLO_TERMINAL_Suma 16
#define SIMBOLO_TERMINAL_Resta 17
#define SIMBOLO_TERMINAL_Multiplicacion 18
#define SIMBOLO_TERMINAL_Division 19
#define SIMBOLO_TERMINAL_Igual 20
#define SIMBOLO_TERMINAL_IgualIgual 21
#define SIMBOLO_TERMINAL_Mayor 22
#define SIMBOLO_TERMINAL_Menor 23
#define SIMBOLO_TERMINAL_MayorIgual 24
#define SIMBOLO_TERMINAL_MenorIgual 25
#define SIMBOLO_TERMINAL_Diferente 26
#define SIMBOLO_TERMINAL_Potencia 27
#define SIMBOLO_TERMINAL_Espacio 28
#define SIMBOLO_TERMINAL_Tabulador 29
#define SIMBOLO_TERMINAL_SaltoLinea 30
#define SIMBOLO_TERMINAL_EOF 31
#define SIMBOLO_TERMINAL_ID 32
#define SIMBOLO_TERMINAL_for 33
#define SIMBOLO_TERMINAL_do 34
#define SIMBOLO_TERMINAL_Coma 35
#define SIMBOLO_TERMINAL_DosPuntos 36
#define SIMBOLO_TERMINAL_Sumasuma 37

#define SIMBOLO_NO_TERMINAL_S 1
#define SIMBOLO_NO_TERMINAL_InstruccionCompuesta 2
#define SIMBOLO_NO_TERMINAL_BloqueInstrucciones 3
#define SIMBOLO_NO_TERMINAL_Instruccion 4
#define SIMBOLO_NO_TERMINAL_InstruccionAsignacion 5
#define SIMBOLO_NO_TERMINAL_InstruccionIf 6
#define SIMBOLO_NO_TERMINAL_InstruccionWhile 7
#define SIMBOLO_NO_TERMINAL_InstruccionImprime 8
#define SIMBOLO_NO_TERMINAL_Expresion 9
#define SIMBOLO_NO_TERMINAL_ExpRelacional 10
#define SIMBOLO_NO_TERMINAL_ExpCompuesta 11
#define SIMBOLO_NO_TERMINAL_ExpSimple 12
#define SIMBOLO_NO_TERMINAL_Factor 13
#define SIMBOLO_NO_TERMINAL_Termino 14
#define SIMBOLO_NO_TERMINAL_OpAditivo 15
#define SIMBOLO_NO_TERMINAL_OpMultiplicativo 16
#define SIMBOLO_NO_TERMINAL_OpRelacional 17
#define SIMBOLO_NO_TERMINAL_OpLogico 18
#define SIMBOLO_NO_TERMINAL_OpPon 19
#define SIMBOLO_NO_TERMINAL_Numero 20


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

int CurrentTokenInFirst(int intSimboloNT)
{
    int boolRes = FALSE;
    if(!boolParserError)
    {
        switch(intSimboloNT)
        {
            case SIMBOLO_NO_TERMINAL_S:
                if(CurrentToken(SIMBOLO_TERMINAL_programa))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_InstruccionCompuesta:
                if(CurrentToken(SIMBOLO_TERMINAL_LlaveIzq))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_BloqueInstrucciones:
                if(CurrentToken(SIMBOLO_TERMINAL_ID))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_if))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_while))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_Interrogacion))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_LlaveIzq))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_Instruccion:
                if(CurrentToken(SIMBOLO_TERMINAL_ID))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_if))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_while))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_Interrogacion))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_LlaveIzq))boolRes = TRUE;

                break;

            case SIMBOLO_NO_TERMINAL_InstruccionAsignacion:
                if(CurrentToken(SIMBOLO_TERMINAL_ID))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_InstruccionIf:
                if(CurrentToken(SIMBOLO_TERMINAL_if))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_InstruccionWhile:
                if(CurrentToken(SIMBOLO_TERMINAL_while))boolRes = TRUE;
                break;


            case SIMBOLO_NO_TERMINAL_InstruccionImprime:
                if(CurrentToken(SIMBOLO_TERMINAL_Interrogacion))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_Expresion:
                if(CurrentToken(SIMBOLO_TERMINAL_NumeroEntero))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_NumeroReal))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_ID))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_ParentesisIzq))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_Exclamacion))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_ExpRelacional:
                if(CurrentToken(SIMBOLO_TERMINAL_NumeroEntero))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_NumeroReal))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_ID))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_ParentesisIzq))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_Exclamacion))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_ExpCompuesta:
                if(CurrentToken(SIMBOLO_TERMINAL_NumeroEntero))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_NumeroReal))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_ID))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_ParentesisIzq))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_Exclamacion))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_ExpSimple:
                if(CurrentToken(SIMBOLO_TERMINAL_NumeroEntero))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_NumeroReal))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_ID))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_ParentesisIzq))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_Exclamacion))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_Factor:
                if(CurrentToken(SIMBOLO_TERMINAL_NumeroEntero))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_NumeroReal))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_ID))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_ParentesisIzq))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_Exclamacion))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_Termino:
                if(CurrentToken(SIMBOLO_TERMINAL_NumeroEntero))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_NumeroReal))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_ID))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_ParentesisIzq))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_Exclamacion))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_OpAditivo:
                if(CurrentToken(SIMBOLO_TERMINAL_Suma))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_Resta))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_OpMultiplicativo:
                if(CurrentToken(SIMBOLO_TERMINAL_Multiplicacion))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_Division))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_OpRelacional:
                if(CurrentToken(SIMBOLO_TERMINAL_Mayor))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_Menor))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_MayorIgual))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_MenorIgual))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_IgualIgual))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_Diferente))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_OpLogico:
                if(CurrentToken(SIMBOLO_TERMINAL_AND))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_OR))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_OpPon:
                if(CurrentToken(SIMBOLO_TERMINAL_Potencia))boolRes = TRUE;
                break;

            case SIMBOLO_NO_TERMINAL_Numero:
                if(CurrentToken(SIMBOLO_TERMINAL_NumeroEntero))boolRes = TRUE;
                if(CurrentToken(SIMBOLO_TERMINAL_NumeroReal))boolRes = TRUE;
                break;
        }
    }
    return boolRes;
}//CurrentTokenInFirst

void S();
void InstruccionCompuesta();
void BloqueInstrucciones();
void Instruccion();
void InstruccionAsignacion();
void InstruccionIf();
void InstruccionWhile();
void InstruccionImprime();
void Expresion();
void ExpRelacional();
void ExpCompuesta();
void ExpSimple();
void Factor();
void Termino();
void OpAditivo();
void OpMultiplicativo();
void OpRelacional();
void OpLogico();
void OpPon();
void Numero();
void InstruccionFor();
void InstruccionDo();


//S ::= "programa" InstruccionCompuesta
void S()
{
    Expect(SIMBOLO_TERMINAL_programa);
    InstruccionCompuesta();
}

//InstruccionCompuesta ::= "{" BloqueInstrucciones "}"
void InstruccionCompuesta()
{
    Expect(SIMBOLO_TERMINAL_LlaveIzq);
    BloqueInstrucciones();
    Expect(SIMBOLO_TERMINAL_LlaveDer);
}

//BloqueInstrucciones ::= Instruccion { ";" Instruccion }
void BloqueInstrucciones()
{
    Instruccion();
    while(CurrentToken(SIMBOLO_TERMINAL_PuntoYComa))
    {
      Expect(SIMBOLO_TERMINAL_PuntoYComa);
      Instruccion();
    }
}

//Instruccion ::= InstruccionAsignacion | InstruccionIf | InstruccionWhile | InstruccionImprime | InstruccionCompuesta | InstruccionDo | InstruccionFor
void Instruccion()
{
    if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_InstruccionAsignacion))
    {
      InstruccionAsignacion();
    }
    else if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_InstruccionIf))
    {
      InstruccionIf();
    }
    else if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_InstruccionWhile))
    {
      InstruccionWhile();
    }
    else if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_InstruccionImprime))
    {
      InstruccionImprime();
    }
    else if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_InstruccionCompuesta))
    {
      InstruccionCompuesta();
    }

}

//InstruccionAsignacion ::= ID "=" Expresion
void InstruccionAsignacion()
{
    Expect(SIMBOLO_TERMINAL_ID);
    Expect(SIMBOLO_TERMINAL_Igual);
    Expresion();
}

//InstruccionIf ::= "if" "("  Expresion ")" Instruccion [ "else" Instruccion ]
void InstruccionIf()
{
    Expect(SIMBOLO_TERMINAL_if);
    Expect(SIMBOLO_TERMINAL_ParentesisIzq);
    Expresion();
    Expect(SIMBOLO_TERMINAL_ParentesisDer);
    Instruccion();
    if(CurrentToken(SIMBOLO_TERMINAL_else))
    {
        Expect(SIMBOLO_TERMINAL_else);
        Instruccion();
    }
}

//InstruccionWhile ::= "while" "(" Expresion ")" Instruccion
void InstruccionWhile()
{
    Expect(SIMBOLO_TERMINAL_while);
    Expect(SIMBOLO_TERMINAL_ParentesisIzq);
    Expresion();
    Expect(SIMBOLO_TERMINAL_ParentesisDer);
    Instruccion();
}


//InstruccionImprime ::= "?" Expresion
void InstruccionImprime()
{
    Expect(SIMBOLO_TERMINAL_Interrogacion);
    Expresion();
}

//Expresion ::= ExpRelacional { OpLogico ExpRelacional }
void Expresion()
{
    ExpRelacional();
    while(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_OpLogico))
    {
        OpLogico();
        ExpRelacional();
    }
}

//ExpRelacional ::= ExpCompuesta { OpRelacional ExpCompuesta }
void ExpRelacional()
{
    ExpCompuesta();
    while(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_OpRelacional))
    {
        OpRelacional();
        ExpCompuesta();
    }
}

//ExpCompuesta ::= ExpSimple { OpAditivo ExpSimple }
void ExpCompuesta()
{
    ExpSimple();
    while(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_OpAditivo))
    {
        OpAditivo();
        ExpSimple();
    }
}

//ExpSimple ::= Factor { OpMultiplicativo Factor }
void ExpSimple()
{
    Factor();
    while(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_OpMultiplicativo))
    {
        OpMultiplicativo();
        Factor();
    }
}

//Factor ::= Termino [ OpPon Termino ]
void Factor()
{
    Termino();
    if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_OpPon))
    {
        OpPon();
        Termino();
    }
}

//Termino ::= Numero | ID ["++"] | "(" Expresion ")" | "!" "(" Expresion ")"
void Termino()
{
    if(CurrentTokenInFirst(SIMBOLO_NO_TERMINAL_Numero))
    {
        Numero();
    }
    else if(CurrentToken(SIMBOLO_TERMINAL_ID))
    {
        Expect(SIMBOLO_TERMINAL_ID);
        if(CurrentToken(SIMBOLO_TERMINAL_Sumasuma)){
          Expect(SIMBOLO_TERMINAL_Sumasuma);
        }
    }
    else if(CurrentToken(SIMBOLO_TERMINAL_ParentesisIzq))
    {
        Expect(SIMBOLO_TERMINAL_ParentesisIzq);
        Expresion();
        Expect(SIMBOLO_TERMINAL_ParentesisDer);
    }
    else //if(CurrentToken(SIMBOLO_TERMINAL_Admiracion))
    {
        Expect(SIMBOLO_TERMINAL_Exclamacion);
        Expect(SIMBOLO_TERMINAL_ParentesisIzq);
        Expresion();
        Expect(SIMBOLO_TERMINAL_ParentesisDer);
    }
}

//OpAditivo ::= "+" | "-"
void OpAditivo()
{
    if(CurrentToken(SIMBOLO_TERMINAL_Suma))
    {
        Expect(SIMBOLO_TERMINAL_Suma);
    }
    else //if(CurrentToken(SIMBOLO_TERMINAL_Resta))
    {
        Expect(SIMBOLO_TERMINAL_Resta);
    }
}

//OpMultiplicativo ::= "*" | "/"
void OpMultiplicativo()
{
    if(CurrentToken(SIMBOLO_TERMINAL_Multiplicacion))
    {
        Expect(SIMBOLO_TERMINAL_Multiplicacion);
    }
    else //if(CurrentToken(SIMBOLO_TERMINAL_Division))
    {
        Expect(SIMBOLO_TERMINAL_Division);
    }
}

//OpRelacional ::= ">" | "<" | ">=" | "<=" | "==" | "!="
void OpRelacional()
{
    if(CurrentToken(SIMBOLO_TERMINAL_Mayor))
    {
        Expect(SIMBOLO_TERMINAL_Mayor);
    }
    else if(CurrentToken(SIMBOLO_TERMINAL_Menor))
    {
        Expect(SIMBOLO_TERMINAL_Menor);
    }
    else if(CurrentToken(SIMBOLO_TERMINAL_MayorIgual))
    {
        Expect(SIMBOLO_TERMINAL_MayorIgual);
    }
    else if(CurrentToken(SIMBOLO_TERMINAL_MenorIgual))
    {
        Expect(SIMBOLO_TERMINAL_MenorIgual);
    }
    else if(CurrentToken(SIMBOLO_TERMINAL_IgualIgual))
    {
        Expect(SIMBOLO_TERMINAL_IgualIgual);
    }
    else //if(CurrentToken(SIMBOLO_TERMINAL_DiferenteQue))
    {
        Expect(SIMBOLO_TERMINAL_Diferente);
    }
}

//OpLogico ::= "AND" | "OR"
void OpLogico()
{
    if(CurrentToken(SIMBOLO_TERMINAL_AND))
    {
        Expect(SIMBOLO_TERMINAL_AND);
    }
    else //if(CurrentToken(SIMBOLO_TERMINAL_OR))
    {
        Expect(SIMBOLO_TERMINAL_OR);
    }
}

//OpPon ::= "^"
void OpPon()
{
    Expect(SIMBOLO_TERMINAL_Potencia);
}

//Numero ::= NumeroEntero | NumeroReal
void Numero()
{
    if(CurrentToken(SIMBOLO_TERMINAL_NumeroEntero))
    {
        Expect(SIMBOLO_TERMINAL_NumeroEntero);
    }
    else //if(CurrentToken(SIMBOLO_TERMINAL_NumReal))
    {
        Expect(SIMBOLO_TERMINAL_NumeroReal);
    }
}

void parser_PDRC()
{
    boolParserError = FALSE;
    ptrCurrentToken = ptrTokenList; //Se apunta al 1er nodo de la lista
    S();
}
