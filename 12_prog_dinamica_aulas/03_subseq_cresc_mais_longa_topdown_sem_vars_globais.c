#include <stdio.h>

#define NAO_CALCULADO -1 // Define um valor para indicar que um índice ainda não foi calculado

// Função auxiliar para retornar o valor máximo entre dois números
int valor_maximo(int a, int b)
{
    return (a > b) ? a : b;
}

// Função recursiva para calcular a LIS até o índice atual
int calcular_LIS(int indice, int sequencia[], int comprimento_LIS[], int tamanho)
{
    // Verifica se o comprimento da LIS para o índice atual já foi calculado
    if (comprimento_LIS[indice] != NAO_CALCULADO)
    {
        return comprimento_LIS[indice]; // Retorna o valor memoizado
    }

    // Caso base: se o índice é 0, a LIS até essa posição é 1
    if (indice == 0)
    {
        return comprimento_LIS[indice] = 1;
    }

    // Inicializa o comprimento máximo da LIS até o índice atual com valor 1
    int comprimento_maximo = 1;

    // Itera de 0 até o índice - 1 para verificar todas as subsequências anteriores
    for (int i = 0; i < indice; i++)
    {
        // Verifica se sequencia[i] é menor que sequencia[indice] para manter a sequência crescente
        if (sequencia[i] < sequencia[indice])
        {
            // Atualiza 'comprimento_maximo' com o valor máximo entre o valor atual e LIS(i) + 1
            comprimento_maximo = valor_maximo(comprimento_maximo, calcular_LIS(i, sequencia, comprimento_LIS, tamanho) + 1);
        }
    }

    // Armazena o resultado no array de comprimento da LIS e retorna
    return comprimento_LIS[indice] = comprimento_maximo;
}

// Função principal para encontrar a subsequência crescente mais longa em uma sequência
int encontrar_subsequencia_crescente_mais_longa(int sequencia[], int tamanho)
{
    int comprimento_LIS[tamanho];   // Array para armazenar o comprimento da LIS para cada posição
    int comprimento_maximo_LIS = 1; // Variável para armazenar o comprimento da LIS máxima

    // Inicializa o array comprimento_LIS com NAO_CALCULADO
    for (int i = 0; i < tamanho; i++)
    {
        comprimento_LIS[i] = NAO_CALCULADO;
    }

    // Calcula a LIS para cada índice e atualiza o maior comprimento
    for (int i = 0; i < tamanho; i++)
    {
        comprimento_maximo_LIS = valor_maximo(comprimento_maximo_LIS, calcular_LIS(i, sequencia, comprimento_LIS, tamanho));
    }

    // Retorna o comprimento da maior subsequência crescente
    return comprimento_maximo_LIS;
}

int main()
{
    int tamanho;

    printf("Digite o tamanho da sequência: ");
    scanf("%d", &tamanho);

    int sequencia[tamanho];
    printf("Digite a sequência de %d números: ", tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &sequencia[i]);
    }

    // Calcula e imprime o comprimento da subsequência crescente mais longa
    printf("Comprimento da subsequência crescente mais longa: %d\n", encontrar_subsequencia_crescente_mais_longa(sequencia, tamanho));

    return 0;
}
