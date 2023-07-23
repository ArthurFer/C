#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATOS 100

// Estrutura para armazenar informações dos candidatos
typedef struct {
  char nome[50];
  char cargo[50];
  int votos;
} Candidato;

void exibirMenuCandidatos(Candidato candidatos[], int numCandidatos);
int cadastrarCandidatos(Candidato candidatos[]);
Candidato* encontrarCandidato(Candidato candidatos[], int numCandidatos, int voto);
void imprimirVotosCandidatos(Candidato candidatos[], int numCandidatos);

int main() {
  Candidato candidatos[MAX_CANDIDATOS];
  int numCandidatos = 0;
  int voto;

  printf("Urna eletrônica - Eleições 2023\n");

  while (1) {
    printf("\nOpções disponíveis:\n");
    printf("1. Cadastrar candidatos\n");
    printf("2. Iniciar votação\n");
    printf("0. Resultado da votação\n");
    printf("Escolha uma opção: ");
    scanf("%d", &voto);

    switch (voto) {
    case 1:
      numCandidatos = cadastrarCandidatos(candidatos);
      break;
    case 2:
      if (numCandidatos == 0) {
        printf("Nenhum candidato cadastrado. Por favor, cadastre candidatos "
               "primeiro.\n");
        break;
      }

      printf("\nVotação iniciada.\n");
      while (1) {
        printf("\nSelecione o candidato pelo número correspondente:\n");
        exibirMenuCandidatos(candidatos, numCandidatos);
        printf("0. Voltar ao menu anterior\n");
        scanf("%d", &voto);
        system("cls||clear"); 

        if (voto == 0) {
          printf("Votação encerrada.\n");
          break;
        }

        if (voto < 1 || voto > numCandidatos) {
          printf("Opção inválida. Por favor, selecione um número válido.\n");
          continue;
        }

        Candidato* candidatoSelecionado =
            encontrarCandidato(candidatos, numCandidatos, voto);
        candidatoSelecionado->votos++;
        printf("Voto computado para %s - %s.\n", candidatoSelecionado->nome,
               candidatoSelecionado->cargo);
      }
      break;
    case 0:
      printf("Encerrando o programa...\n");
      imprimirVotosCandidatos(candidatos, numCandidatos);
      return 0;
    default:
      printf("Opção inválida. Por favor, selecione um número válido.\n");
    }
  }

  return 0;
}


// Função para exibir o menu de candidatos
void exibirMenuCandidatos(Candidato candidatos[], int numCandidatos) {
  printf("----- Candidatos Disponíveis -----\n");
  for (int i = 0; i < numCandidatos; i++) {
    printf("%d. %s - %s\n", i + 1, candidatos[i].nome, candidatos[i].cargo);
  }
  printf("----------------------------------\n");
}

// Função para cadastrar os candidatos
int cadastrarCandidatos(Candidato candidatos[]) {
  int numCandidatos;
  printf("Quantos candidatos deseja cadastrar? ");
  scanf("%d", &numCandidatos);
  fflush(stdin);
  __fpurge(stdin); // Limpar o buffer do teclado

  for (int i = 0; i < numCandidatos; i++) {
    printf("\nCandidato %d:\n", i + 1);
    printf("Nome: ");
    fgets(candidatos[i].nome, 50, stdin);
    candidatos[i].nome[strcspn(candidatos[i].nome, "\n")] =
        '\0'; // Remover o caractere de nova linha
    printf("Cargo: ");
    fgets(candidatos[i].cargo, 50, stdin);
    candidatos[i].cargo[strcspn(candidatos[i].cargo, "\n")] =
        '\0'; // Remover o caractere de nova linha
    candidatos[i].votos = 0;
  }

  return numCandidatos;
}

// Função para encontrar o candidato pelo número correspondente
Candidato* encontrarCandidato(Candidato candidatos[], int numCandidatos, int voto) {
  return &candidatos[voto - 1];
}

// Função para imprimir os votos para cada candidato
void imprimirVotosCandidatos(Candidato candidatos[], int numCandidatos) {
  printf("\n----- Resultado dos Votos -----\n");
  for (int i = 0; i < numCandidatos; i++) {
    printf("%s - %s: %d voto(s)\n", candidatos[i].nome, candidatos[i].cargo, candidatos[i].votos);
  }
  printf("-------------------------------\n");
}
