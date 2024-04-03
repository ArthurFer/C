#include <stdio.h>
#include <string.h>
#include <locale.h>

/*
  Programa para gerenciar estoque de produtos.
  Foi implementado funções para adicionar e listar os estoques.

  Autor: Arthur Fernando
*/

#define MAX_PROD 10

typedef struct
{
  char nome[50];
  char segmento[50];
  float precoCompra;
  float precoVenda;
  char unidadeComercial[10];
  int quantidade;
} Produto;

void addProduto(Produto estoque[], int *numProdutos);
void exibirEstoque(Produto estoque[], int numProdutos);

int main()
{
  setlocale(LC_ALL, "Portuguese");
  Produto estoque[MAX_PROD];
  int numProdutos = 0;
  int opcao;
  int codigo;

  printf("Gerenciamento de Estoque\n");
  while (1)
  {
    printf("\nOpções disponíveis;\n");
    printf("1. Adicionar produto\n");
    printf("2. Exibir estoque\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {

    case 1:
      addProduto(estoque, &numProdutos);
      break;
    case 2:
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

void addProduto(Produto estoque[], int *numProdutos)
{
  if (*numProdutos >= MAX_PROD)
  {
    printf("Capacidade maxima de registros!\n");
    return;
  }

  printf("\nNovo Produto\n");
  printf("Nome: ");
  scanf(" %[^\n]s", estoque[*numProdutos].nome);
  printf("Segmento: ");
  scanf(" %[^\n]s", estoque[*numProdutos].segmento);
  printf("Preço de Compra: ");
  scanf("%f", &estoque[*numProdutos].precoCompra);
  printf("Preço de Venda: ");
  scanf("%f", &estoque[*numProdutos].precoVenda);
  printf("Unidade comercial: ");
  scanf(" %[^\n]s", estoque[*numProdutos].unidadeComercial);
  printf("Quantidade: ");
  scanf("%d", &estoque[*numProdutos].quantidade);

  (*numProdutos)++;

  printf("Produto salvo no estoque.\n");
}

void exibirEstoque(Produto estoque[], int numProdutos)
{
  printf("\n Estoque: \n");
  for (int i = 0; i < numProdutos; i++)
  {
    printf("Nome: %s | Segmento: %s | Preço Compra: %.2f | Preço Venda: %.2f | Unidade Comercial: %s | Quantidade: %d\n",
           estoque[i].nome, estoque[i].segmento, estoque[i].precoCompra, estoque[i].precoVenda, estoque[i].unidadeComercial, estoque[i].quantidade);
  }
  printf("Estoque total: %d\n", numProdutos);
}
