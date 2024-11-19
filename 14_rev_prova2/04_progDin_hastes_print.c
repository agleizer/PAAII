#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Função para encontrar o maior valor entre dois números
int maximo(int a, int b)
{
    return (a > b) ? a : b;
}

// Função para calcular a receita máxima da corte de hastes usando abordagem bottom-up
int corte_haste(int precos[], int tamanho)
{
    // Vetor para armazenar as receitas máximas para cada corte
    int receitaMaxima[tamanho + 1];
    receitaMaxima[0] = 0; // Receita para tamanho zero é zero

    printf("Iniciando cálculo da receita máxima para tamanhos de 1 a %d...\n", tamanho);

    // Percorrer cada tamanho de 1 até o tamanho completo
    for (int i = 1; i <= tamanho; i++)
    {
        int maxReceita = -1;

        printf("Calculando receita máxima para tamanho %d:\n", i);

        // Calcula a receita máxima considerando todos os possíveis cortes
        for (int j = 1; j <= i; j++)
        {
            // calcula a receita obtida ao cortar a haste de tamanho i em duas partes: um pedaço de comprimento j, outro restante do comprimento (i - j).
            int receitaAtual = precos[j - 1] + receitaMaxima[i - j];

            printf("  Cortando em %d e %d: receita = precos[%d] (%d) + receitaMaxima[%d] (%d) = %d\n",
                   j, i - j, j - 1, precos[j - 1], i - j, receitaMaxima[i - j], receitaAtual);

            // compara a receita atual calculada (receitaAtual) com a receita máxima registrada até agora (maxReceita)
            maxReceita = maximo(receitaAtual, maxReceita);

            printf("  Receita máxima atualizada: %d\n", maxReceita);
        }

        receitaMaxima[i] = maxReceita; // Armazena a receita máxima para o comprimento i
        printf("Receita máxima armazenada para tamanho %d: %d\n", i, receitaMaxima[i]);
    }

    return receitaMaxima[tamanho]; // Retorna a receita máxima para o tamanho completo
}

// Exemplo de uso
int main()
{
    // setlocale(LC_ALL, "pt_BR.UTF-8");
    system("chcp 65001 > nul");
    int precos[] = {1, 5, 8, 9, 10, 17, 17, 20};      // Preços por tamanho
    int tamanho = sizeof(precos) / sizeof(precos[0]); // Comprimento da haste

    printf("Preços por tamanho:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("  Tamanho %d: R$ %d\n", i + 1, precos[i]);
    }

    printf("\nCalculando a receita máxima...\n");
    int receita = corte_haste(precos, tamanho);
    printf("\nReceita máxima para comprimento %d: %d\n", tamanho, receita);

    return 0;
}
