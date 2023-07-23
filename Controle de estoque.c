#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constante da quantidade maxima de produtos na lista
 #define MAX_PROD 100

// Estrutura para guardar/armazenar os dados do produto
typedef struct {
  int codigo;
  char nome[50];
  int quantidade;
} Produto;

// Função para adicionar os produtos ao estoque
void addProduto(Produto estoque[], int *numProdutos){
  if (*numProdutos >= MAX_PROD){
    printf("Capacidade maxima de registros!\n");
    return;
  }

    printf("\nNovo Produto\n");
    printf("Codigo: ");
    scanf("%d", &estoque[*numProdutos].codigo);
    printf("Nome: ");
    scanf(" %[^\n]s", estoque[*numProdutos].nome);
    printf("Quantidade: ");
    scanf("%d", &estoque[*numProdutos].quantidade);

    (*numProdutos)++;

    printf("Produto salvo no estoque.\n");
  }
  // Função para remover o produto do estoque
  void remProduto(Produto estoque[], int *numProdutos, int codigo){
    int index = -1;

    for (int i = 0; i < *numProdutos -1; i++){
      if (estoque[i].codigo == codigo);
      break;
    }
    if (index == -1){
      printf("Codigo %d do produto não localizado!\n", codigo);
      return;
    }

    for (int i = index; i < *numProdutos -1; i++){
      estoque[i] = estoque [i + 1];
    }

    (*numProdutos)--;

    printf("Produto removido do estoque.\n");
  }

// listar nosso estoque
void exibirEstoque (Produto estoque[], int numProdutos){
  printf ("\n Estoque: \n");
  for (int i = 0; i < numProdutos; i++){
    printf ("Codigo: %d | Nome: %s | Quantidade: %d\n", estoque[i].codigo, estoque[i].nome, estoque[i].quantidade);
  }
  printf ("Estoque total: %d\n", numProdutos);
}

int main(){
  Produto estoque[MAX_PROD];
  int numProdutos = 0;
  int opcao;
  int codigo;

  printf ("Controle de Estoque Top Alunos\n");
  while(1){
    printf("\nOpções disponíveis;\n");
    printf("1. Adicionar produto\n");
    printf("2. Remover produto\n");
    printf("3. Exibir estoque\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {

      case 1:
        addProduto(estoque, &numProdutos);
        break;
      case 2:
         printf("Informe o código do produto a ser removido: ");
      scanf("%d", &codigo);
      remProduto(estoque, &numProdutos, codigo);
      break;
    case 3:
      exibirEstoque(estoque, numProdutos);
      break;
    case 0:
      printf("Encerrando o programa...\n");
      return 0;
    default:
      printf("Opção inválida. Por favor, selecione uma opção válida.\n");
    }
  }

  return 0;
}