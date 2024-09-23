#include <stdio.h>
#include <stdlib.h>

struct t_token
{
    int intTokenCodigo;
    char *strTokenTextoFuente;
    int intRenglon;
    int intColumna;
    struct t_token *ptrSig;
};
typedef struct t_token t_token;
t_token *ptrTokenList = NULL;

void scanner(char *strArchivoFuente);
void ListaTokens_Imprime();
void ListaTokens_Liberar();
void parser_PDRC();

int main()
{
    scanner("fuente.txt");

    ListaTokens_Imprime();
    parser_PDRC();
    ListaTokens_Liberar();

    printf("Hello world!\n");
    return 0;
}
