#include <stdio.h>
#include <limits.h>

// Define o valor máximo permitido (evitar valores muito altos).
#define MAX 100

// Função para calcular o mínimo entre dois valores.
int minimo(int a, int b)
{
    return (a < b) ? a : b;
}

// Função que calcula o número mínimo de moedas para formar um valor.
int trocoMinimoIt(int valor, int moedas[], int qtdMoedas)
{

    // Criar e inicializar vetor para armazenar o troco para cada valor total i.
    int troco[valor + 1];

    // Inicializa o vetor: 0 para troco[0], e INT_MAX para os demais.
    troco[0] = 0;
    for (int i = 1; i <= valor; i++)
    {
        troco[i] = INT_MAX;
    }

    // Dois loops para calcular o troco mínimo.
    for (int i = 1; i <= valor; i++)
    {
        for (int j = 0; j < qtdMoedas; j++)
        {

            // moedas[j] <= i verifica se a moeda atual (moedas[j]) pode ser usada para formar o valor i.
            // troco[i - moedas[j]] != INT_MAX garante que o valor restante após usar a moeda atual (i - moedas[j]) pode ser formado com as moedas disponíveis.
            // troco[i - moedas[j]] representa o número mínimo de moedas necessário para formar o valor i - moedas[j]
            if (moedas[j] <= i && troco[i - moedas[j]] != INT_MAX)
            {

                // troco[i - moedas[j]] representa o número mínimo de moedas necessário para formar o valor restante após usar a moeda atual.
                // troco[i - moedas[j]] + 1 adiciona uma moeda ao total necessário para formar o valor restante.
                troco[i] = minimo(troco[i], troco[i - moedas[j]] + 1);
            }
        }
    }

    // Se troco[valor] ainda for INT_MAX, significa que não foi possível formar o valor.
    return (troco[valor] == INT_MAX) ? -1 : troco[valor];
}

// Função principal para testar.
int main()
{
    int moedas[] = {1, 3, 4}; // Conjunto de moedas disponíveis.
    int qtdMoedas = sizeof(moedas) / sizeof(moedas[0]);
    int valor = 6; // Valor alvo.

    int resultado = trocoMinimoIt(valor, moedas, qtdMoedas);

    if (resultado == -1)
    {
        printf("Não é possível formar o valor %d com as moedas disponíveis.\n", valor);
    }
    else
    {
        printf("O número mínimo de moedas para formar o valor %d é: %d\n", valor, resultado);
    }

    return 0;
}
