#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
unsigned long int a, b, auxiliar, i, n;
  a = 0;
  b = 1;

  printf("Digite o número da sequência desejada:\n");
  scanf ("%d", &n);
  printf("Sequência de fibonnaci\n");
  printf("%d\n%d\n",a,b);

    for (i = 0; i < n; i++){
      auxiliar = a + b;
      a = b;
      b = auxiliar;
      printf ("%d\n", auxiliar);
    }
}  