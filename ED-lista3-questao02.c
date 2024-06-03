/*
** Função : Implementar rotinas para ler, escrever e excluir registros do tipo "empregado".
** Autor : Felipe Nóbrega de Almeida
** Data : 02/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

typedef struct empregado
{
    int rg;
    char nome[50];
    int dataNascimento;
    int dataAdmissao;
    float salario;
} empregado;

void interface();
void exibirEmpregados(empregado **empregados);
void cadastrarEmpregado(empregado **empregados);
void excluirEmpregado(empregado **empregados);
empregado *criarEmpregado(int rg, char nome[50], int dataNascimento, int dataAdmissao, float salario);
empregado **listaEmpregados();

int main()
{
    setlocale(LC_ALL, "Portugese");

    int opcao;
    empregado **empregados = listaEmpregados();
    while (opcao != 4)
    {
        interface();
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("Empregados: \n");
            exibirEmpregados(empregados);
            break;
        case 2:
            printf("Digites os dados abaixo:\n");
            cadastrarEmpregado(empregados);
            break;
        case 3:
            excluirEmpregado(empregados);
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }

    return 0;
}

void interface()
{
    printf("\n");
    printf("Menu:\n");
    printf("1 - Exibir empregados\n");
    printf("2 - Cadastrar empregado\n");
    printf("3 - Excluir empregado\n");
    printf("4 - Sair\n");
    printf("\n");
}

empregado *criarEmpregado(int rg, char nome[50], int dataNascimento, int dataAdmissao, float salario)
{
    empregado *e = (empregado *)malloc(sizeof(empregado));
    e->rg = rg;
    strcpy(e->nome, nome);
    e->dataNascimento = dataNascimento;
    e->dataAdmissao = dataAdmissao;
    e->salario = salario;

    return e;
}

empregado **listaEmpregados()
{
    empregado **empregados = (empregado **)malloc(10 * sizeof(empregado *));
    for (int i = 0; i < 10; i++)
    {
        empregados[i] = NULL;
    }

    return empregados;
}

void exibirEmpregados(empregado **empregados)
{
    for (int i = 0; i < 10; i++)
    {
        if (empregados[i] != NULL)
        {
            printf("\n");
            printf("----- Empregado %d -----\n", i + 1);
            printf("RG: %d\n", empregados[i]->rg);
            printf("Nome: %s\n", empregados[i]->nome);
            printf("Data de nascimento: %d\n", empregados[i]->dataNascimento);
            printf("Data de admissão: %d\n", empregados[i]->dataAdmissao);
            printf("Salário: %.2f\n", empregados[i]->salario);
            printf("------------------------\n");
        }
    }
}

void cadastrarEmpregado(empregado **empregados)
{
    int rg, dataNascimento, dataAdmissao;
    char nome[50];
    float salario;

    printf("\n");
    printf("Digite o RG: ");
    scanf("%d", &rg);
    printf("Digite o nome: ");
    scanf("%s", nome);
    printf("Digite a data de nascimento: ");
    scanf("%d", &dataNascimento);
    printf("Digite a data de admissão: ");
    scanf("%d", &dataAdmissao);
    printf("Digite o salário: ");
    scanf("%f", &salario);
    printf("\n");

    empregado *e = criarEmpregado(rg, nome, dataNascimento, dataAdmissao, salario);
    for (int i = 0; i < 10; i++)
    {
        if (empregados[i] == NULL)
        {
            empregados[i] = e;
            break;
        }
    }
}

void excluirEmpregado(empregado **empregados)
{
    int rg;
    printf("\n");
    printf("Digite o RG do empregado que deseja excluir: ");
    scanf("%d", &rg);
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        if (empregados[i] != NULL && empregados[i]->rg == rg)
        {
            free(empregados[i]);
            empregados[i] = NULL;
            printf("Empregado excluído com sucesso!\n");
            break;
        }
    }
}