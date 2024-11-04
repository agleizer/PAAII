// complexidade O(n^2)

#include <stdio.h>
#include <limits.h>

#define MAX 100 // Define o tamanho máximo para as hastes

// Função para calcular a receita máxima da corte de hastes com memoização
int corte_haste(int precos[], int tamanho, int receitaMaxima[])
{
    // Verifica se a receita máxima para o tamanho atual já foi calculada
    if (receitaMaxima[tamanho] >= 0)
    {
        return receitaMaxima[tamanho];
    }

    // Caso base: se o tamanho da haste é zero, a receita é zero
    if (tamanho == 0)
    {
        return 0;
    }

    int maxReceita = INT_MIN; // Inicializa a receita máxima com um valor mínimo

    // Loop para encontrar o máximo possível ao dividir a haste em pedaços
    for (int i = 1; i <= tamanho; i++)
    {
        int receitaAtual = precos[i] + corte_haste(precos, tamanho - i, receitaMaxima);
        if (receitaAtual > maxReceita)
        {
            maxReceita = receitaAtual;
        }
    }

    receitaMaxima[tamanho] = maxReceita; // Armazena o valor calculado para o tamanho atual
    return maxReceita;                   // Retorna a receita máxima para o tamanho atual
}

int main()
{
    int n;

    printf("Digite o tamanho da haste: ");
    scanf("%d", &n);

    int precos[MAX];        // Array para armazenar os preços dos diferentes tamanhos de cortes
    int receitaMaxima[MAX]; // Array para armazenar a receita máxima com memoização

    printf("Digite os preços para cada tamanho de corte (1 até %d):\n", n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &precos[i]);
    }

    // Inicializa o array receitaMaxima com -∞ para indicar valores não calculados
    for (int i = 0; i <= n; i++)
    {
        receitaMaxima[i] = INT_MIN;
    }

    // Calcula e imprime a receita máxima para o tamanho da haste
    int resultado = corte_haste(precos, n, receitaMaxima);
    printf("A receita máxima para a haste de tamanho %d é: %d\n", n, resultado);

    return 0;
}
