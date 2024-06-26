#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define TAM 10000 

int bubbleSort(int array[])
{
    int aux, i, j;
    for (j = 1; j <= TAM; j++)
        for (i = 0; i < TAM - 1; i++)
            if (array[i] > array[i + 1])
            {
                aux = array[i]; 
                array[i] = array[i + 1];
                array[i + 1] = aux;
            }
}

int main()
{
    int array[TAM];
    int i;
    clock_t t;

    srand(time(NULL));
    for (i = 0; i < TAM; i++)
    {
        array[i] = rand() % TAM;
    }
    printf("20 array desordenados dentre os 10 mil de teste: \n");
    for (int i = 0; i < 20; i++){
        printf("%d ", array[i]);
    }

    printf("\n\n");

    t = clock(); 
    bubbleSort(array);

    t = clock() - t; 
    
    printf("20 array ordenados dentre os 10 mil de teste: \n");
    for (int i = 0; i < 20; i++){
        printf("%d ", array[i]);
    }
    
    printf("\n\n");
    
    printf("Tempo de execucao ap�s ordena��o dos 10 mil valores: %.2lf milisegundos", ((double)t) / ((CLOCKS_PER_SEC / 1000)));
    return 0;
}