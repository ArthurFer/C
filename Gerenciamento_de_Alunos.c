#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

/*
    Programa que gerencia os alunos de uma escola.
    Foi implementado funÁıes de adiÁ„o, remoÁ„o, alteraÁ„o e listagem de alunos.
    Autor: Arthur Fernando
*/

#define MAX_ALUNOS 100

typedef struct
{
    int matricula;
    char nome[100];
    char curso[50];
    char endereco[150];
    bool ativo;
} Alunos;

void cadastrarAluno(Alunos registros[], int *numAlunos);
void removerAluno(Alunos registros[], int *numAlunos, int matricula);
void relatorioAlunos(Alunos registros[], int numAlunos);
void alterarEndereco(Alunos registros[], int *numAlunos, int matricula, char novoEndereco[150]);
void alterarCurso(Alunos registros[], int *numAlunos, int matricula, char novoCurso[50]);

int main()
{

    setlocale(LC_ALL, "Portuguese");

    Alunos registros[MAX_ALUNOS];
    int numAlunos = 0;
    int opcao;
    int matricula;

    printf("Programa de Gerenciamento de Alunos\n");
    while (1)
    {
        printf("\nOpùùes disponùveis:\n");
        printf("1. Adicionar alunos\n");
        printf("2. Remover alunos\n");
        printf("3. Listar alunos\n");
        printf("4. Alterar curso\n");
        printf("5. Alterar endereùo\n");
        printf("0. Sair\n");
        printf("Escolha uma opùùo: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            cadastrarAluno(registros, &numAlunos);
            break;
        case 2:
            printf("Informe a matrùcula do aluno a ser removido: ");
            scanf("%d", &matricula);
            removerAluno(registros, &numAlunos, matricula);
            break;
        case 3:
            relatorioAlunos(registros, numAlunos);
            break;
        case 4:
            printf("Alteraùùo de curso: \n\n");
            relatorioAlunos(registros, numAlunos);
            printf("\nInforme a matrùcula do aluno que deseja alterar o curso: ");
            scanf("%d", &matricula);
            printf("Novo curso: ");
            char novoCurso[50];
            scanf(" %[^\n]s", novoCurso);
            alterarCurso(registros, &numAlunos, matricula, novoCurso);
            break;
        case 5:
            printf("Alteraùùo de endereùo: \n\n");
            relatorioAlunos(registros, numAlunos);
            printf("\nInforme a matrùcula do aluno que deseja alterar o endereùo: ");
            scanf("%d", &matricula);
            printf("Novo endereùo: ");
            char novoEndereco[150];
            scanf(" %[^\n]s", novoEndereco);
            alterarEndereco(registros, &numAlunos, matricula, novoEndereco);
            break;
        case 0:
            printf("Encerrando o programa...\n");
            return 0;
        default:
            printf("Opùùo invùlida. Por favor, selecione uma opùùo vùlida.\n");
        }
    }

    return 0;
}

void cadastrarAluno(Alunos registros[], int *numAlunos)
{
    if (*numAlunos >= MAX_ALUNOS)
    {
        printf("Capacidade maxima de registros!\n");
        return;
    }

    printf("\nNovo Aluno\n");
    printf("Matrùcula: ");
    scanf("%d", &registros[*numAlunos].matricula);
    printf("Nome: ");
    scanf(" %[^\n]s", registros[*numAlunos].nome);
    printf("Curso: ");
    scanf(" %[^\n]s", registros[*numAlunos].curso);
    printf("Endereùo: ");
    scanf(" %[^\n]s", registros[*numAlunos].endereco);
    printf("Ativo (1 para sim e 0 para nùo): ");
    scanf("%d", &registros[*numAlunos].ativo);

    (*numAlunos)++;

    printf("Aluno cadastrado.\n");
}

void removerAluno(Alunos registros[], int *numAlunos, int matricula)
{
    int index = -1;

    for (int i = 0; i < *numAlunos - 1; i++)
    {
        if (registros[i].matricula == matricula)
            ;
        index = i;
        break;
    }
    if (index == -1)
    {
        printf("Matrùcula %d do aluno nùo localizada!\n", matricula);
        return;
    }

    registros[index].ativo = false;

    printf("Aluno removido do registro.\n");
}

void relatorioAlunos(Alunos registros[], int numAlunos)
{   
    int contador = 0;
    printf("\nListagem de Alunos: \n");
    for (int i = 0; i < numAlunos; i++)
    {
        if (registros[i].ativo)
        {
            printf("Matricula: %d | Nome: %s | Curso: %s | Endereùo: %s | Ativo: %s\n",
                   registros[i].matricula, registros[i].nome, registros[i].curso, registros[i].endereco, registros[i].ativo ? "Sim" : "Nao");
            contador++;
        }
    }
    printf("Total de alunos ativos: %d\n\n", contador);
}

void alterarEndereco(Alunos registros[], int *numAlunos, int matricula, char novoEndereco[150]){
    int index = -1;

    for (int i = 0; i < *numAlunos - 1; i++)
    {
        if (registros[i].matricula == matricula)
            ;
        index = i;
        break;
    }
    if (index == -1)
    {
        printf("Matrùcula %d do aluno nùo localizada!\n", matricula);
        return;
    }

    strcpy(registros[index].endereco, novoEndereco);

    printf("Endereùo alterado.\n");
}

void alterarCurso(Alunos registros[], int *numAlunos, int matricula, char novoCurso[50]){
    int index = -1;

    for (int i = 0; i < *numAlunos - 1; i++)
    {
        if (registros[i].matricula == matricula)
            ;
        index = i;
        break;
    }
    if (index == -1)
    {
        printf("Matrùcula %d do aluno nùo localizada!\n", matricula);
        return;
    }

    strcpy(registros[index].curso, novoCurso);

    printf("Curso alterado.\n");
}