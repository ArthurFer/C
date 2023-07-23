#include <stdio.h>


int main (void){

  float base, altura, area;
  printf("Programa para calcular a Área do triângulo\n\n");
  printf("Digite a base do triângulo em cm: ");
  scanf("%f",&base);
  printf("Digite a altura do triângulo em cm: ");
  scanf("%f",&altura);

  area = (base * altura) / 2;
  printf ("A área do triângulo é: \n %.2f cm \n", area);
  

  //Atribuir o valor 1 para a variável controle caso as condições forem aceitas
  int a = 5, b = 2, c;

  if (a > b){ //condição verdadeira linha será executada
    printf("5 é maior que 2 \n");    
  } 
  else if (a < b){ //condição falsa linha não será executada
    printf ("5 não é maior que 2 \n");
  }
  if (a == 5 && b == 2){ //condição verdadeira linha será executada
    printf ("A é igual a 5 e b é igual a 2 \n");
  }
  
}