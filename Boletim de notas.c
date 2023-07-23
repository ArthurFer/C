#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 

int main (void){

  struct cadastro_alunos
  {
    char nome[60];
    char disciplina[30];
    float nota_prova1, nota_prova2; 
  };

  struct cadastro_alunos aluno;
  float media;

  printf("CADASTRO DE ALUNOS / BOLETIM DE NOTAS\n\n\n");

  printf("Entre com o nome do aluno, a disciplina e as 2 notas das provas\n\n");
  
  printf("Nome do aluno: ");
  fflush(stdin);
  fgets(aluno.nome, 59, stdin);

  printf("Disciplina: ");
  fflush(stdin);
  fgets(aluno.disciplina, 29, stdin);

  printf("Digite a primeira nota: ");
  scanf("%f", &aluno.nota_prova1);

  printf("Digite a segunda nota: ");
  scanf("%f", &aluno.nota_prova2);

  system("cls|| clear");
    
  media = (aluno.nota_prova1 + aluno.nota_prova2) / 2;

  printf("\n\nNome do aluno: %s", aluno.nome);
  printf("Disciplina: %s", aluno.disciplina);
  printf("Nota da primeira prova: %.2f\n" , aluno.nota_prova1);
  printf("Nota da segunda prova: %.2f\n" , aluno.nota_prova2);
  printf("A média do aluno é: %.2f\n\n", media);

  if(media > 5){
    printf("%s está aprovado na disciplina %s!", aluno.nome, aluno.disciplina);
    }
  else
    printf("%s está reprovado na disciplina %s! ", aluno.nome,aluno.disciplina);



}