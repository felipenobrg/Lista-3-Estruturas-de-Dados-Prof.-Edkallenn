/*
** Função: Função para calcular a raiz quadrada de um número n com aproximação de 0.0001.
** Autor : Felipe Nóbrega de Almeida
** Data : 02/05/2024
** Observações:
*/

#include <stdio.h>
#include <math.h>
#include <locale.h>

#define EPSILON 0.0001

double raizQuadrada(double n);

int main()
{
    setlocale(LC_ALL, "Portugese");

    double n;

    printf("Digite um número: ");
    scanf("%lf", &n);
    fflush(stdin);

    double r = raizQuadrada(n);

    printf("A raiz quadrada de %f é %f\n", n, r);

    return 0;
}

double raizQuadrada(double n)
{
    double x = 1;
    double r = 0;

    while (1)
    {
        r = (x + n / x) / 2;
        if (fabs(r - x) < EPSILON)
        {
            break;
        }
        x = r;
    }

    return r;
}