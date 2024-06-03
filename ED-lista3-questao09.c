/*
** Função: Função para ordenar elementos de um vetor usando o método "BubbleSort".
** Autor : Felipe Nóbrega de Almeida
** Data : 02/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int *criarVetor(int n);
void exibirVetor(int *v, int n);
void bubbleSort(int *v, int n);

int trocas = 0;

int main()
{
    setlocale(LC_ALL, "Portugese");

    int n;

    while (1)
    {
        printf("Digite o tamanho do vetor: ");
        scanf("%d", &n);
        fflush(stdin);

        if (n > 0)
        {
            break;
        }
        printf("O tamanho do vetor deve ser maior que 0.\n");
    }

    int *vetor = criarVetor(n);
    printf("Vetor original: ");
    exibirVetor(vetor, n);

    bubbleSort(vetor, n);
    printf("Vetor ordenado: ");
    exibirVetor(vetor, n);

    printf("\n");
    printf("Número de ifs: %d\n", trocas);
    printf("Número de trocas: %d\n", trocas);

    return 0;
}

int *criarVetor(int n)
{
    int *v = (int *)malloc(n * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 100;
    }

    return v;
}

void exibirVetor(int *v, int n)
{
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf(" ]\n");
}

void bubbleSort(int *v, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocas++;
            }
        }
    }
}