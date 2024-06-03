/*
** Função: Classificar os elementos de um vetor em ordem crescente usando o algoritmo “quicksort”.
** Autor : Felipe Nóbrega de Almeida
** Data : 02/05/2024
** Observações:
*/

#include <stdio.h>
#include <math.h>
#include <locale.h>

int *criarVetor(int n);
void exibirVetor(int *v, int n);
void quicksort(int *v, int n);

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

    quicksort(vetor, n);
    printf("Vetor ordenado: ");
    exibirVetor(vetor, n);

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

void quicksort(int *v, int n)
{
    if (n <= 1)
    {
        return;
    }

    int p = v[n / 2];
    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));
    int i, ja = 0, jb = 0;

    for (i = 0; i < n; i++)
    {
        if (i == n / 2)
        {
            continue;
        }
        if (v[i] < p)
        {
            a[ja++] = v[i];
        }
        else
        {
            b[jb++] = v[i];
        }
    }

    quicksort(a, ja);
    quicksort(b, jb);

    for (i = 0; i < ja; i++)
    {
        v[i] = a[i];
    }
    v[i] = p;
    for (i = 0; i < jb; i++)
    {
        v[ja + 1 + i] = b[i];
    }

    free(a);
    free(b);
}