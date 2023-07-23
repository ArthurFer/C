#include <stdio.h>
#include <stdlib.h>

int aleatorio();
void dicas(int number, int password, int attempt);

int main(){
  int continuar=1;
  int number, password, attempt;

   do
    {
        system("cls || clear");
        printf("Sorteando numero entre 1 e 1000...\n");
        password = aleatorio();

        printf("Comecou! Tente adivinhar o numero!\n\n");
        attempt = 0;

        do
        {
            attempt++;
            printf("Tentativa %d: ", attempt);
            scanf("%d", &number);
            dicas(number,password,attempt);
        }
        while( number != password);

        printf("Digite 0 para sair, ou qualquer outro numero para continuar: ");
        scanf("%d", &continuar);
    }
    while(continuar);
  
}

int aleatorio(){
  srand(time(NULL));
  return (1 + rand()%1000);
}
void dicas (int number, int password, int attempt){
  if (number > password)
    printf("O número sorteado é menor que %d ",number);
  else
    if (number < password)
      printf ("O número sorteado é maior que %d ", number);
  else
      printf ("Parabéns! Você acertou o número em %d tentativas.",attempt);
}