/*
3. (CORTE DAS HASTES DE AÇ O) Dada uma haste de tamanho n e uma tabela de
preç os pi para i = 1, 2, · · · , n, escreva um algoritmo que determine a receita má xima
rn obtida pelo corte de uma haste de aç o e pela subsequente venda de suas partes.
Escreva uma versã o recursiva (backtracking) e uma versã o de programaçã o dinâ mica
(top-down ou bottom-up).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função recursiva para calcular o valor máximo pelo corte da haste
int corteHasteRecursivo(int n, int precos[])
{
    // Caso base: haste de comprimento zero gera receita zero
    if (n == 0)
    {
        return 0;
    }

    int receitaMaxima = 0;

    // Tenta cortar a haste em todas as posições possíveis
    for (int i = 1; i <= n; i++)
    {
        // Calcula a receita para o corte atual e escolhe o máximo
        int receitaAtual = precos[i - 1] + corteHasteRecursivo(n - i, precos);
        if (receitaAtual > receitaMaxima)
        {
            receitaMaxima = receitaAtual;
        }
    }

    return receitaMaxima;
}

// Função de programação dinâmica para calcular a receita máxima (bottom-up)
int corteHastePD(int n, int precos[])
{
    int dp[n + 1]; // Array para armazenar receitas máximas para cada comprimento
    dp[0] = 0;     // Caso base: comprimento zero gera receita zero

    // Preenche o array dp de 1 até n
    for (int i = 1; i <= n; i++)
    {
        int receitaMaxima = 0;
        // Testa todos os cortes possíveis para o comprimento i
        for (int j = 1; j <= i; j++)
        {
            int receitaAtual = precos[j - 1] + dp[i - j];
            if (receitaAtual > receitaMaxima)
            {
                receitaMaxima = receitaAtual;
            }
        }
        dp[i] = receitaMaxima;
    }

    return dp[n]; // Retorna a receita máxima para a haste de comprimento n
}

int main()
{
    int n;

    // Leitura do comprimento da haste
    printf("Digite o comprimento da haste: ");
    scanf("%d", &n);

    int precos[n];

    // Leitura dos preços para cada comprimento de 1 até n
    printf("Digite os preços para cada comprimento:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &precos[i]);
    }

    // Solução com backtracking recursivo
    int maxReceitaRecursivo = corteHasteRecursivo(n, precos);
    printf("Receita máxima (Backtracking Recursivo): %d\n", maxReceitaRecursivo);

    // Solução com programação dinâmica
    int maxReceitaPD = corteHastePD(n, precos);
    printf("Receita máxima (Programação Dinâmica): %d\n", maxReceitaPD);

    return 0;
}
