#include <stdio.h>
#include <math.h>

int main(){
  float num1, num2, soma, subtracao, divisao, multiplicacao;
  int operador;
  
  
  do{
    printf("Escolha uma operação para iniciar a calculadora:\n\n");
    
    printf(" (1) SOMA\n (2) SUBTRACAO\n (3) DIVISAO\n (4)MULTIPLICACAO\n Para SAIR digite 0 0 0\n Operação:\n ");
    
    scanf("%d", &operador);
    
    printf("Digite o numero 1\n");
    scanf("%f",&num1);
    printf("Digite o numero 2\n");
    scanf("%f",&num2);
    
    switch (operador)
      {
      case 1:
        soma = num1 + num2;
        printf("A soma dos dois números é %.1f\n",soma);
        break;
    
      case 2:
        subtracao = num1 - num2;
        printf("A subtração dos dois números é %.1f\n",subtracao);
        break;
    
      case 3:
        if (num2 != 0){
        divisao = num1 / num2;
        printf("A divisão dos dois números é %.3f\n", divisao);
        }
        else 
        printf("Não é possível divisão por 0\n");
        break;

      case 4:
        multiplicacao = num1 * num2;
        printf("A multiplicação dos dois números é %.2f\n", multiplicacao);
        break;
      
      default:
          if(operador == 0)
            printf(" Fechando calculadora!\n\n ");
          
      }
  }
    while (operador != 0);
}