#include <stdio.h>
#include <stdlib.h>

 

int main (void){

  int lista[5], i;

  //inicialização do vetor
  for (i = 0; i<5; i++){
    printf("Digite um valor: ");
    scanf("%d", &lista[i]);
    
  }
//impressão do vetor invertido
  for (i=4;i>=0;i--){
    printf("Valor array posição é %d \n", lista[i]);
  }

  
    return 0;
  
}