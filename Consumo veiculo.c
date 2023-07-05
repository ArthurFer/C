//Programa para calular consumo do veículo por distância percorrida

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define max_veiculos 20

//Estrutura para armazenar dados do veículo
typedef struct{
char veiculo[20];
float consumo;
}Dados;

//Protótipos das funções 
int cadastroVeiculos(Dados carro[], int* numVeiculo);
void exibirVeiculos(Dados carro[], int numVeiculo);
Dados encontrarVeiculo(Dados carro[], int numVeiculo, int opcao);
void calcularConsumo(Dados veiculo, float distancia);


//Função principal
int main(){
  Dados carro[max_veiculos];
  float distancia = 0;
  int numVeiculo=0;
  unsigned int opcao;
  char entrada[2];
  int i = 0;
  

  do{
    
    printf("Calculadora de consumo de Veiculos\n\n");
    
    printf("1. Cadastrar novo veículo\n");
    printf("2. Exibir lista de veículos\n");
    printf("3. Calcular consumo\n");
    printf("0. Encerrar programa\n\n");
    
    printf("Digite a opção desejada: ");
    scanf("%s", entrada);

    // Verifica se cada caractere da entrada é um dígito
    
    while (entrada[i] != '\0') {
        if (!isdigit(entrada[i])) {
            printf("Entrada inválida! Digite apenas números inteiros.\n");
            return 1; // Encerra o programa com código de erro
        }
        i++;
    }

    // Converte a entrada para um número inteiro
    opcao = atoi(entrada);
  
     switch (opcao){

      case 1:
        cadastroVeiculos(carro, &numVeiculo);
        break;

      case 2:
        exibirVeiculos(carro, numVeiculo);
        break;

      case 3:
        if (numVeiculo > 0){//Condição para executar somente se tiver veículo cadastrado
          printf("Informe a distância percorrida em quilômetros: \n");
          scanf("%f", &distancia);

          printf("Selecione o veículo: \n\n");
          exibirVeiculos(carro, numVeiculo);
          printf("Opção: ");
          scanf("%u", &opcao);

        if(opcao >=1 && opcao <= numVeiculo){
          //Condicional só vai entrar quando a opção escolhida for maior ou igual a 1 e menor ou igual ao número de veículos cadastrado
          Dados veiculo = encontrarVeiculo(carro, numVeiculo, opcao);
          //Declaração de variável veiculo do tipo Dados recebe a função encontrarVeiculo para guardar veiculo escolhido no scanf opcao
          calcularConsumo (veiculo, distancia);
          //Chamada da função calcularConsumo passando os parâmetros veiculo e distancia para retorno do calulo
          } else{
          printf("Opção invalida");
          }
        }else {
          printf("Nenhum veiculo cadastrado");      
        }
        
        break;

       case 0:
       printf("Programa encerrado");
   
    
  }
    
  }while(opcao != 0);
  

  return 0;
}

//Função para cadastro dos veículos, é utilizado um ponteiro em numVeiculo para que outras funções possam usar esse valor armazenado na memória
int cadastroVeiculos(Dados carro[], int* numVeiculo){
  printf("Quantos veículos deseja cadastrar?\n");
  scanf("%d", numVeiculo);
  printf("Adição de veiculo ao catálogo\n");
    for (int i=0; i< *numVeiculo; i++){
      printf("Veiculo: ");
      

      scanf(" %[^\n]s", carro[i].veiculo);
      fflush(stdin);
      __fpurge(stdin);
      
      printf("Consumo km/L: ");
       scanf("%f", &carro[i].consumo);
      printf("\n");
    }

    printf("Carros cadastrados no sistema!\n\n");
    
  return *numVeiculo;
  }

//Função para exibir lista dos veículos cadastrados
void exibirVeiculos(Dados carro[], int numVeiculo){
  system ("cls || clear");
  printf("Veiculos Cadastrados\n\n");
  for (int i = 0; i < numVeiculo; i++){
    printf("%d. %s \n", i+1, carro[i].veiculo);
  }
}

//Função para escolher veículo para cálculo pelo número armazenado no vetor
Dados encontrarVeiculo(Dados carro[], int numVeiculo, int opcao) {
  return carro[opcao - 1];
}

//Função para calular o consumo
void calcularConsumo(Dados veiculo, float distancia){
  system ("cls || clear");
  float consumo_total;
  consumo_total = distancia / veiculo.consumo;
  printf ("O consumo do veículo %s para %.2f de distância é de %.2f litros\n", veiculo.veiculo, distancia, consumo_total);
}