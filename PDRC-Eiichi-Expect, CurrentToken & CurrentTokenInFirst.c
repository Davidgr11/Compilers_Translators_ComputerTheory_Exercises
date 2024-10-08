int CurrentToken(int intSimboloT)
{
	int bolRes = FALSE;
	
	if(ptrCurrentToken -> intTokenCodigo == intSimboloT)
		bolRes = TRUE;
	else
		bolRes = FALSE;

	return bolRes
}



void Expect(int intSimboloT)
{
	if(CurrentToken(intSimboloT))
	{
		printf("Token sintaticamente correcto=%s, Renglon=%d, Columna=%d\n",
			trCurrentToken -> strTokenTextoFuente, 
			ptrCurrentToken -> intRenglon, 
			ptrCurrentToken -> intColumna);

		ptrCurrentToken = ptrCurrentToken -> ptrSig;
	}
	else
	{
		printf("Error sintactico=%s, Renglon=%d, Columna=%d\n",
			ptrCurrentToken -> strTokenTextoFuente, 
			ptrCurrentToken -> intRenglon, 
			ptrCurrentToken -> intColumna);
	}
}

int CurrentTokenInFirst(int intSimboloNT)
{
	int boolRes = FALSE;
	
	switch()
	{
		case SIMBOLO_NO_TERMINAL_Programa:
			if(CurrentToken(SIMBOLO_TERMINAL_VDER)) boolRes = TRUE;
			if(CurrentToken(SIMBOLO_TERMINAL_VIZQ)) boolRes = TRUE;
			if(CurrentToken(SIMBOLO_TERMINAL_AVANZA)) boolRes = TRUE;
			if(CurrentToken(SIMBOLO_TERMINAL_SI_CHOCAS)) boolRes = TRUE;
			if(CurrentToken(SIMBOLO_TERMINAL_RECOGE)) boolRes = TRUE;
			if(CurrentToken(SIMBOLO_TERMINAL_DEJA)) boolRes = TRUE;
			break;
		case SIMBOLO_NO_TERMINAL_Instrucción:
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

	return boolRes;
}



//S::= "Programa" InstruccionCompuesta 
void S()
{
	Expect(SIMBOLO_TERMINAL_programa); 
	InstruccionCompuesta();
}


//InstruccionCompuesta ::= "{" BloqueInstrucciones "}" void InstruccionCompuesta()
{
Expect(SIMBOLO_TERMINAL_LLAVE_QUE_ABRE);
BloqueInstrucciones(); Expect(SIMBOLO_TERMINAL_LLAVE_QUE_CIERRA);
}
//BloqueInstrucciones ::= Instruccion {";" Instruccion }
LEXAL:
//InstrAvanza ::= "AVANZA" "NUM" void InstrAvanza()
{
Expect(SIMBOLO_TERMINAL_AVANZA);
if (CurrentToken(SIMBOLO_TERMINAL_Num
{
Expect(SIMBOLO_TERMINAL_Num);
}
}
//InstrSiChocas ::= "SI CHOCAS" Instruccion void InstrSiChocas()
{
Expect(SIMBOLO_TERMINAL_SI_CHOCAS);
Instruccion();
}
//InstrObjeto ::= "RECOGE" | "DEJA" void InstrObjeto()
{
if(CurrentToken(SIMBOLO_TERMINAL_RECOGE) Expect(SIMBOLO_TERMINAL_RECOGE);
else
Expect(SIMBOLO_TERMINAL_DEJA);
}
/*
Programa ::= Instruccion; {Instruccion;}
Instruccion ::= InstrVuelta | InstrAvanza | InstrSiChocas | InstrObjeto InstruccionVuelta ::= "VDER" | "VIZQ"
InstruccionAvanza ::= "AVANZA "Num" InstrSiChocas ::= "SI_CHOCAS" Instruccion InstrObjeto ::= "RECOGE" | "DEJA"
*/
void BloqueInstrucciones() //REGLA 5, EL ";" SI ES TERMINAL
{
Instruccion(); while(CurrentToken(SIMBOLO_TERMINAL_PUNTO_Y_COMA))
{
Expect(SIMBOLO_TERMINAL_PUNTO_Y_COMA);
Instruccion();
}
}
