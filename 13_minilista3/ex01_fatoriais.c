/*
1. (FATORIAIS) Queremos representa um número N como a soma de k fatoriais, de forma a
minimizar k. A entrada consiste de um inteiro N (1 ≤ 105). O programa deve mostrar
como resultado um inteiro que representa a menor quantidade de números fatoriais cuja
soma seja igual ao valor de N .
Entrada: 10
Saída : 3
Explicação:
10 = 1! + 1! + 1! + 1! + 1! + 1! + 1! + 1! + 1! + 1!
= 2! + 2! + 2! + 1! + 1! + 1! + 1!
= 3! + 1! + 1! + 1! + 1!
= 3! + 2! + 2!
A menor combinação é 3! + 2! + 2! = 10 com 3 números fatoriais.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 12 // Definimos o máximo de fatoriais para calcular (0! a 11!)

// Função para calcular o fatorial de um número até MAX
int calcularFatorial(int n)
{
    int fatorial = 1; // Inicializamos o fatorial como 1
    for (int i = 1; i <= n; i++)
    {
        fatorial *= i; // Calcula o fatorial multiplicando os valores sucessivos até n
    }
    return fatorial; // Retorna o valor do fatorial calculado
}

// Função principal para encontrar a quantidade mínima de fatoriais que somam N
int encontrarMinimoFatoriais(int numero)
{
    int fatoriais[MAX];

    // Preenche o array com os fatoriais de 0! a 11!
    for (int i = 0; i < MAX; i++)
    {
        fatoriais[i] = calcularFatorial(i); // Calcula e armazena cada fatorial
    }

    int quantidadeFatoriais = 0; // Contador para a quantidade de fatoriais utilizados
    int i = MAX - 1;             // Inicia do maior fatorial (11!)

    // Processo guloso para decompor o número em somas de fatoriais
    while (numero > 0)
    { // Continua até que numero seja reduzido a zero
        // Verifica se o fatorial atual pode ser subtraído de numero
        if (fatoriais[i] <= numero)
        {
            numero -= fatoriais[i]; // Subtrai o maior fatorial possível de numero
            quantidadeFatoriais++;  // Incrementa o contador de fatoriais utilizados
        }
        else
        {
            i--; // Passa para o próximo fatorial menor se o atual não puder ser usado
        }
    }

    return quantidadeFatoriais; // Retorna a quantidade mínima de fatoriais
}

int main()
{
    int numero;

    // Leitura do número N
    printf("Digite um número: ");
    scanf("%d", &numero);

    // Calcula a quantidade mínima de fatoriais necessários para somar N
    int resultado = encontrarMinimoFatoriais(numero);

    // Imprime o resultado
    printf("Quantidade mínima de fatoriais: %d\n", resultado);

    return 0;
}
