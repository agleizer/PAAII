#include <stdio.h>

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

    // Percorrer cada tamanho de 1 até o tamanho completo
    for (int i = 1; i <= tamanho; i++)
    {
        int maxReceita = -1;

        // Calcula a receita máxima considerando todos os possíveis cortes
        for (int j = 1; j <= i; j++)
        {

            // calcula a receita obtida ao cortar a haste de tamanho i em duas partes: um pedaço de comprimento j. outro restante do comprimento (i - j).
            int receitaAtual = precos[j - 1] + receitaMaxima[i - j];

            // compara a receita atual calculada (receitaAtual) com a receita máxima registrada até agora (maxReceita)
            maxReceita = maximo(receitaAtual, maxReceita);
        }

        receitaMaxima[i] = maxReceita; // Armazena a receita máxima para o comprimento i
    }

    return receitaMaxima[tamanho]; // Retorna a receita máxima para o tamanho completo
}

// Exemplo de uso
int main()
{
    int precos[] = {1, 5, 8, 9, 10, 17, 17, 20};      // Preços por tamanho
    int tamanho = sizeof(precos) / sizeof(precos[0]); // Comprimento da haste

    printf("Receita máxima: %d\n", corte_haste(precos, tamanho));

    return 0;
}