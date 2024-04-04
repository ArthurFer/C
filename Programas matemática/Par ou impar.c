#include <stdio.h>
#include <stdlib.h>

int main(){
  int numero, calculo;
  printf("Programa para saber se o número é par ou ímpar\n Se desejar encerrar digite 0\n\n");
  while (numero != 0){
  printf("Digite um número inteiro:\n");
  scanf("%d",&numero);
  calculo = numero % 2;
  if (calculo == 0)
    printf("Encerrando execução\n\n");
  else
    printf("O número é impar\n\n");
  }
}