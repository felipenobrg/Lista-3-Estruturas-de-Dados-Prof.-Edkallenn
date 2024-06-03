/*
** Função: Implementar rotinas para ler, escrever e excluir registros do tipo "aeroporto"
** Autor : Felipe Nóbrega de Almeida
** Data : 02/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct aeroporto
{
    char sigla[3];
    char cidade[50];
    char pais[30];
    float taxa;
    int capacidade;
} aeroporto;

aeroporto **listaAeroportos(int n);
aeroporto *criarAeroporto(char sigla[3], char cidade[50], char pais[30], float taxa, int capacidade);
void cadastrarAeroporto(aeroporto **aeroportos);
void exibirAeroportos(aeroporto **aeroportos);
void excluirAeroporto(aeroporto **aeroportos);
void interface();

int n;
int main()
{
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o número de aeroportos máximo para a empresa: ");
    scanf("%d", &n);
    fflush(stdin);

    int opcao;
    aeroporto **aeroportos = listaAeroportos(n);

    while (opcao != 4)
    {
        interface();
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        fflush(stdin);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("Aeroportos: \n");
            exibirAeroportos(aeroportos);
            break;
        case 2:
            printf("Digites os dados abaixo:\n");
            cadastrarAeroporto(aeroportos);
            break;
        case 3:
            excluirAeroporto(aeroportos);
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
    printf("1 - Exibir aeroportos\n");
    printf("2 - Cadastrar aeroporto\n");
    printf("3 - Excluir aeroporto\n");
    printf("4 - Sair\n");
}

aeroporto **listaAeroportos(int n)
{
    aeroporto **aeroportos = (aeroporto **)malloc(n * sizeof(aeroporto *));
    if (aeroportos == NULL)
    {
        printf("Memória insuficiente\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        aeroportos[i] = NULL;
    }
    return aeroportos;
}

void exibirAeroportos(aeroporto **aeroportos)
{
    for (int i = 0; i < n; i++)
    {
        if (aeroportos[i] != NULL)
        {
            printf("\n");
            printf("----- Aeroporto %d -----\n", i + 1);
            printf("Sigla: %s\n", aeroportos[i]->sigla);
            printf("Cidade: %s", aeroportos[i]->cidade);
            printf("País: %s", aeroportos[i]->pais);
            printf("Taxa: %.2f\n", aeroportos[i]->taxa);
            printf("Capacidade: %d\n", aeroportos[i]->capacidade);
            printf("------------------------\n");
        }
    }
}

aeroporto *criarAeroporto(char sigla[3], char cidade[50], char pais[30], float taxa, int capacidade)
{
    aeroporto *a = (aeroporto *)malloc(sizeof(aeroporto));
    if (a == NULL)
    {
        printf("Memória insuficiente\n");
        exit(1);
    }

    strcpy(a->sigla, sigla);
    strcpy(a->cidade, cidade);
    strcpy(a->pais, pais);
    a->taxa = taxa;
    a->capacidade = capacidade;

    return a;
}

void cadastrarAeroporto(aeroporto **aeroportos)
{
    char sigla[3], cidade[50], pais[30];
    float taxa;
    int capacidade;

    printf("Sigla: ");
    fgets(sigla, 3, stdin);
    fflush(stdin);
    printf("Cidade: ");
    fgets(cidade, 50, stdin);
    fflush(stdin);
    printf("País: ");
    fgets(pais, 30, stdin);
    fflush(stdin);
    printf("Taxa: ");
    scanf("%f", &taxa);
    fflush(stdin);
    printf("Capacidade: ");
    scanf("%d", &capacidade);
    fflush(stdin);

    aeroporto *a = criarAeroporto(sigla, cidade, pais, taxa, capacidade);
    for (int i = 0; i < n; i++)
    {
        if (aeroportos[i] == NULL)
        {
            aeroportos[i] = a;
            break;
        }
    }
}

void excluirAeroporto(aeroporto **aeroportos)
{
    char sigla[3];
    printf("Digite a sigla do aeroporto a ser excluído: ");
    fgets(sigla, 3, stdin);
    fflush(stdin);

    for (int i = 0; i < n; i++)
    {
        if (aeroportos[i] != NULL)
        {
            if (strcmp(aeroportos[i]->sigla, sigla) == 0)
            {
                free(aeroportos[i]);
                aeroportos[i] = NULL;
                break;
            }
        }
    }
}