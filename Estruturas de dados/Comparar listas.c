#include <stdio.h>
#include <stdlib.h>
 

int main (void){

  int lista1[6], lista2[6], i, j, aux,controle=0;
    printf("Programa para comparativo de listas\n\n");
  for (i = 0; i<5; i++){    //inicialização do vetor 1
    printf("Digite os 5 valores da primeira lista: ");
    scanf("%d", &lista1[i]);    
  }
    for (j = 0; j<5; j++){   //inicialização do vetor 2
    
      printf("Digite os 5 valores da segunda lista: ");
      scanf("%d", &lista2[j]);
    }
     
   
  for (j=0;j<5;j++){  //verificação condicional dos números iguais
    for (i = 0; i<5; i++){
      if (lista1[i] == lista2[j]){
         aux = lista1[i];
         controle = 1;
          if (controle == 1){
            printf ("Os números iguais são: %d\n", aux);
          } 
           
      }  
      
    }   
  } 
  if (controle != 1){
    printf ("Não existem números iguais entre as listas\n");
          }
    return 0;
  
}