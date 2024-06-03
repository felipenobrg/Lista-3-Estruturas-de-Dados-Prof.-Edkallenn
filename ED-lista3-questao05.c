/*
** Função: Mostrar que a Conjectura de Goldbach é verdadeira para todo número par em um intervalo definido pelo usuário.
** Autor : Felipe Nóbrega de Almeida
** Data : 02/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n;

void popularVetor(int *vetor, int inicio);
int checaPrimo(int n);
void conjecturaGoldbach(int *vetor);

int main()
{
    setlocale(LC_ALL, "Portugese");

    while (1)
    {
        printf("Digite o número de elementos pares para a conjectura de Goldbach: ");
        scanf("%d", &n);
        fflush(stdin);

        if (n > 2)
        {
            break;
        }
        printf("Digite um número maior que 2\n");
    }

    int vetor[n];
    popularVetor(vetor, 4);
    conjecturaGoldbach(vetor);

    return 0;
}

void popularVetor(int *vetor, int inicio)
{
    for (int i = 0; i < n;)
    {
        if (inicio % 2 == 0)
        {
            vetor[i] = inicio;
            i++;
        }
        inicio++;
    }
}

void conjecturaGoldbach(int *vetor)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < vetor[i]; j++)
        {
            if (checaPrimo(j) && checaPrimo(vetor[i] - j))
            {
                if (vetor[i] % 10 == 0)
                    printf("\n");
                printf("%d = %d + %d | ", vetor[i], j, vetor[i] - j);
                break;
            }
        }
    }
}

int checaPrimo(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}