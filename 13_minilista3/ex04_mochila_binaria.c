/*
1. (PROBLEMA DA MOCHILA 0/1) Dado um conjunto S de itens s1, s2, ... , sn, onde
cada item si possui um valor vi e peso wi, para todo 1 ≤ i ≤ n, e uma capacidade W da
mochila. Determine o valor má ximo de itens que se pode colocar dentro da mochila
sem exceder a capacidade W . Nã o é permitido fracionar os itens. Escreva uma versã o
recursiva (backtracking) e uma versã o de programaçã o dinâ mica (top-down ou bottom-
up).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função recursiva de backtracking para resolver o problema da mochila
int mochilaRecursiva(int capacidade, int pesos[], int valores[], int n)
{
    // Caso base: sem itens ou capacidade zero
    if (n == 0 || capacidade == 0)
    {
        return 0;
    }

    // Se o peso do item atual excede a capacidade, ignoramos o item
    if (pesos[n - 1] > capacidade)
    {
        return mochilaRecursiva(capacidade, pesos, valores, n - 1);
    }
    else
    {
        // Retorna o máximo entre incluir e não incluir o item
        int incluir = valores[n - 1] + mochilaRecursiva(capacidade - pesos[n - 1], pesos, valores, n - 1);
        int naoIncluir = mochilaRecursiva(capacidade, pesos, valores, n - 1);
        return (incluir > naoIncluir) ? incluir : naoIncluir;
    }
}

// Função de programação dinâmica para resolver o problema da mochila (bottom-up)
int mochilaPD(int capacidade, int pesos[], int valores[], int n)
{
    int dp[n + 1][capacidade + 1];

    // Preenchemos a matriz dp
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacidade; j++)
        {
            // Caso base: sem itens ou capacidade zero
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (pesos[i - 1] <= j)
            {
                // Escolhe o máximo entre incluir ou não incluir o item
                int incluir = valores[i - 1] + dp[i - 1][j - pesos[i - 1]];
                int naoIncluir = dp[i - 1][j];
                dp[i][j] = (incluir > naoIncluir) ? incluir : naoIncluir;
            }
            else
            {
                // Não incluir o item se o peso for maior que a capacidade atual
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacidade]; // Retorna o valor máximo com os itens e capacidade total
}

int main()
{
    int n, capacidade;

    // Entrada do número de itens e capacidade da mochila
    printf("Digite o número de itens e a capacidade da mochila: ");
    scanf("%d %d", &n, &capacidade);

    int pesos[n], valores[n];

    // Entrada de valores e pesos de cada item
    printf("Digite os pesos e valores dos itens:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &pesos[i], &valores[i]);
    }

    // Solução com backtracking recursivo
    int maxValorRecursivo = mochilaRecursiva(capacidade, pesos, valores, n);
    printf("Valor máximo (Backtracking Recursivo): %d\n", maxValorRecursivo);

    // Solução com programação dinâmica
    int maxValorPD = mochilaPD(capacidade, pesos, valores, n);
    printf("Valor máximo (Programação Dinâmica): %d\n", maxValorPD);

    return 0;
}
