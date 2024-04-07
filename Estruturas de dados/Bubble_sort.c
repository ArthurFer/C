#include <stdio.h>

int bubbleSort(int array[], int n)
{
    int aux, i, j;
    for (j = 1; j <= n; j++)
        for (i = 0; i < n - 1; i++)
            if (array[i] > array[i + 1])
            {
                aux = array[i]; 
                array[i] = array[i + 1];
                array[i + 1] = aux;
            }
}

int main()
{
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    return 0;
}