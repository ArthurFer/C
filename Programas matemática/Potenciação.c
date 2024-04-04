#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 

int main (void){

  int resultado, aux, a = 1,b=1, i, n;
  int exp;
  printf ("Digite o número de termos n\n");
  scanf("%d", &n);
  printf ("Laço\n\n");
  for(i=0; i<n;i++){
    resultado = a +b;
    aux = resultado + resultado;
    a = a + a;
    b = b +b;
    printf ("n %d = %d\n", i+1, resultado);
      }
  printf("\n\nExponencial\n\n");
  for (i=1; i<=n; i++){
  exp = pow(2, i);
    printf("2^%d = %d\n", i, exp);
  }
}