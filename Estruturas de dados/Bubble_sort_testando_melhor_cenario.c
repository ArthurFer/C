#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10000

int main()
{
    int array[TAM];
    int n, aux, i, troca;
    clock_t t;

    srand(time(NULL));
    for (i = 0; i < TAM; i++)
    {
        array[i] = rand() % TAM;
    }

    n = 1;
    troca = 1;

    printf("20 array desordenados dentre os 10 mil de teste: \n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n\n");

    t = clock(); // armazena tempo

    while (n <= TAM && troca == 1)
    {
        troca = 0;
        for (i = 0; i < TAM; i++)
        {
            if (array[i] > array[i + 1])
            {
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
                troca = 1;
            }
        }
        n++;
    }

    t = clock() - t;

    printf("20 array ordenados dentre os 10 mil de teste: \n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n\n");

    printf("Tempo de execucao após ordenação dos 10 mil valores: %.2lf milisegundos", ((double)t) / ((CLOCKS_PER_SEC / 1000)));
    return 0;
}