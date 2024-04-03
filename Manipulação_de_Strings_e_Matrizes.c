#include <stdio.h>
#include <locale.h>

/*
Programa para manipular strings e matrizes para gerar uma imagem com um X e um quadrado na tela.
Autor: Arthur Fernando
*/

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	char matrix[100][100];
	char matrixQuadrado[100][100];
	int dim, dimQUadrado;

	printf("Digite as dimens�es da imagem:\n");
	scanf("%d", &dim);

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{

			if (i == j || i + j == dim - 1)
			{
				matrix[i][j] = '#';
			}
			else
			{
				matrix[i][j] = ' ';
			}
		}
	}

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{

			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}

	printf("Digite as dimens�es da imagem, para gerar o quadrado:\n");
	scanf("%d", &dimQUadrado);

	for (int i = 0; i < dimQUadrado; i++)
	{
		for (int j = 0; j < dimQUadrado; j++)
		{

			if (i == 0 || i == dimQUadrado - 1 || j == 0 || j == dimQUadrado - 1)
			{
				matrixQuadrado[i][j] = '#';
			}
			else
			{
				matrixQuadrado[i][j] = ' ';
			}
		}
	}

	for (int i = 0; i < dimQUadrado; i++)
	{
		for (int j = 0; j < dimQUadrado; j++)
		{

			printf("%c", matrixQuadrado[i][j]);
		}
		printf("\n");
	}

	return 0;
}