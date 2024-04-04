//Programa para transformar um tempo dado em segundo para horas, minutos e segundos
#include <stdio.h>
#include <stdlib.h>

int main(){
int entrada, horas, minutos, segundos;
  printf("Entre com o tempo em segundos\n");
  scanf("%d", &entrada);
  minutos = entrada / 60;
  if (minutos < 60) {
  horas = 0;
  minutos = entrada / 60;
  segundos = entrada % 60; 
  printf("O tempo em segundos equivale a %d horas, %d minutos e %d segundos", horas, minutos, segundos);
  }
  else if (minutos > 60){
  horas = minutos / 60;
  minutos = horas % 60;
  segundos = minutos % 60;
  printf("O tempo em segundos equivale a %d horas, %d minutos e %d segundos", horas, minutos, segundos);
  }
}