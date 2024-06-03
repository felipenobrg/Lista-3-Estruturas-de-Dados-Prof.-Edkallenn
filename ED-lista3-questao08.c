/*
** Função: Operações com números complexos.
** Autor : Felipe Nóbrega de Almeida
** Data : 02/05/2024
** Observações:
*/

#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef struct
{
    double real;
    double img;
} Complexo;

Complexo *criarComplexo(double real, double img);
Complexo *somarComplexos(Complexo *num1, Complexo *num2);
Complexo *subtrairComplexos(Complexo *num1, Complexo *num2);
Complexo *multiplicarComplexos(Complexo *num1, Complexo *num2);
Complexo *dividirComplexos(Complexo *num1, Complexo *num2);
void destruirComplexo(Complexo *num);
void exibirComplexo(Complexo *num);

int main()
{
    setlocale(LC_ALL, "Portugese");

    Complexo *num1 = criarComplexo(2.0, 3.0);
    Complexo *num2 = criarComplexo(1.0, 4.0);

    printf("Número complexo 1: ");
    exibirComplexo(num1);
    printf("Número complexo 2: ");
    exibirComplexo(num2);

    printf("Soma: ");
    Complexo *soma = somarComplexos(num1, num2);
    exibirComplexo(soma);

    printf("Subtração: ");
    Complexo *subtracao = subtrairComplexos(num1, num2);
    exibirComplexo(subtracao);

    printf("Multiplicação: ");
    Complexo *multiplicacao = multiplicarComplexos(num1, num2);
    exibirComplexo(multiplicacao);

    printf("Divisão: ");
    Complexo *divisao = dividirComplexos(num1, num2);
    exibirComplexo(divisao);

    destruirComplexo(num1);
    destruirComplexo(num2);
    destruirComplexo(soma);
    destruirComplexo(subtracao);
    destruirComplexo(multiplicacao);
    destruirComplexo(divisao);

    return 0;
}

Complexo *criarComplexo(double real, double img)
{
    Complexo *num = (Complexo *)malloc(sizeof(Complexo));
    if (num != NULL)
    {
        num->real = real;
        num->img = img;
    }
    return num;
}

void destruirComplexo(Complexo *num)
{
    free(num);
}

Complexo *somarComplexos(Complexo *num1, Complexo *num2)
{
    Complexo *soma = criarComplexo(num1->real + num2->real, num1->img + num2->img);
    return soma;
}

Complexo *subtrairComplexos(Complexo *num1, Complexo *num2)
{
    Complexo *subtracao = criarComplexo(num1->real - num2->real, num1->img - num2->img);
    return subtracao;
}

Complexo *multiplicarComplexos(Complexo *num1, Complexo *num2)
{
    Complexo *multiplicacao = criarComplexo(num1->real * num2->real - num1->img * num2->img, num1->real * num2->img + num1->img * num2->real);
    return multiplicacao;
}

Complexo *dividirComplexos(Complexo *num1, Complexo *num2)
{
    double denominador = num2->real * num2->real + num2->img * num2->img;
    Complexo *divisao = criarComplexo((num1->real * num2->real + num1->img * num2->img) / denominador, (num1->img * num2->real - num1->real * num2->img) / denominador);
    return divisao;
}

void exibirComplexo(Complexo *num)
{
    printf("(%f, %f)\n", num->real, num->img);
}