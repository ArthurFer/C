#include <stdio.h>
#include <stdlib.h>

_Bool contains_duplicates(const int *array, size_t len)
{
    for (int i = 0; i < len - 1; i++)
    {
    /*For percorre j de 0 a 1 enquanto i permanece em 0, e compara i com j, na proxima iteração i=1 e 
    j é percorrido até a última posição do Array até comparar todas as posições do array*/

        for (int j = i + 1; j < len; j++) 
        {
            if (array[i] == array[j])
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20};
    size_t len = sizeof(array) / sizeof(array[0]);

    int result = contains_duplicates(array, len);

    if (result == 1)
    {
        printf("The array contains duplicate values!\n");
    }
    else
    {
        printf("The array does not contain duplicate values!\n");
    }
    return 0;
}
