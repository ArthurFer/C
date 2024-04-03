#include <string.h>
#include <stdio.h>
#include <locale.h>

/*
Programa para encontrar o n�mero de ocorr�ncias de uma palavra em uma string.
Autor: Arthur Fernando
*/

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    char frase[104], palavraProcurada[5], stringAux[104];
    char *ponteiroChar = NULL;
    int ocorrencias = 0;

    strcpy(frase, "cara caramba, cara cara�\ncara caramba, cara cara�\ncara caramba, cara cara�\ncara caramba, cara cara�");
    strcpy(palavraProcurada, "cara");
    strcpy(stringAux, frase);
    ponteiroChar = strstr(stringAux, palavraProcurada);

    while (ponteiroChar != NULL)
    {
        ponteiroChar = strstr(ponteiroChar + 1, palavraProcurada);
        ocorrencias++;
    }

    printf("%s\n\n", frase);
    printf("A palavra '%s' aparece %d vezes na frase.\n", palavraProcurada, ocorrencias);

    return 0;
}
