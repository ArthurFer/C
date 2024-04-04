#include <stdio.h>
#include <stdlib.h>

int find_max(const int *array, size_t len)
{   
    int max = 0;
    for (size_t i = 0; i < len; i++) // Laço for percorre o array e atribui o valor maximo
    {
        if (max < array[i]) // Se o valor que está na variável max for menor que o valor do array, max recebera o valor do array na posição i
        {
            max = array[i];
        }
    }
    return max;
}

int main()
{
    int array[] = {1, 2, 32, 4, 5, 10, 6, 77, 8, 9, 17};

    // Calcula o tamanho do array, pegando o total do tamanho em bytes e divide pelo tamanho de um elemento
    size_t len = sizeof(array) / sizeof(array[0]);

    int max = find_max(array, len);

    printf("Max: %d\n", max);

    return 0;
}