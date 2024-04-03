#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

/*
    Programa que gerencia os alunos de uma escola.
    Foi implementado fun��es de adi��o, remo��o, altera��o e listagem de alunos.
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
        printf("\nOp��es dispon�veis:\n");
        printf("1. Adicionar alunos\n");
        printf("2. Remover alunos\n");
        printf("3. Listar alunos\n");
        printf("4. Alterar curso\n");
        printf("5. Alterar endere�o\n");
        printf("0. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            cadastrarAluno(registros, &numAlunos);
            break;
        case 2:
            printf("Informe a matr�cula do aluno a ser removido: ");
            scanf("%d", &matricula);
            removerAluno(registros, &numAlunos, matricula);
            break;
        case 3:
            relatorioAlunos(registros, numAlunos);
            break;
        case 4:
            printf("Altera��o de curso: \n\n");
            relatorioAlunos(registros, numAlunos);
            printf("\nInforme a matr�cula do aluno que deseja alterar o curso: ");
            scanf("%d", &matricula);
            printf("Novo curso: ");
            char novoCurso[50];
            scanf(" %[^\n]s", novoCurso);
            alterarCurso(registros, &numAlunos, matricula, novoCurso);
            break;
        case 5:
            printf("Altera��o de endere�o: \n\n");
            relatorioAlunos(registros, numAlunos);
            printf("\nInforme a matr�cula do aluno que deseja alterar o endere�o: ");
            scanf("%d", &matricula);
            printf("Novo endere�o: ");
            char novoEndereco[150];
            scanf(" %[^\n]s", novoEndereco);
            alterarEndereco(registros, &numAlunos, matricula, novoEndereco);
            break;
        case 0:
            printf("Encerrando o programa...\n");
            return 0;
        default:
            printf("Op��o inv�lida. Por favor, selecione uma op��o v�lida.\n");
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
    printf("Matr�cula: ");
    scanf("%d", &registros[*numAlunos].matricula);
    printf("Nome: ");
    scanf(" %[^\n]s", registros[*numAlunos].nome);
    printf("Curso: ");
    scanf(" %[^\n]s", registros[*numAlunos].curso);
    printf("Endere�o: ");
    scanf(" %[^\n]s", registros[*numAlunos].endereco);
    printf("Ativo (1 para sim e 0 para n�o): ");
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
        printf("Matr�cula %d do aluno n�o localizada!\n", matricula);
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
            printf("Matricula: %d | Nome: %s | Curso: %s | Endere�o: %s | Ativo: %s\n",
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
        printf("Matr�cula %d do aluno n�o localizada!\n", matricula);
        return;
    }

    strcpy(registros[index].endereco, novoEndereco);

    printf("Endere�o alterado.\n");
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
        printf("Matr�cula %d do aluno n�o localizada!\n", matricula);
        return;
    }

    strcpy(registros[index].curso, novoCurso);

    printf("Curso alterado.\n");
}