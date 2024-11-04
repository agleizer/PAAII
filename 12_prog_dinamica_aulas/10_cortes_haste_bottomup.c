// complexidade O(n^2)

#include <stdio.h>
#include <limits.h>
#include <locale.h>

#define MAX 100 // Define o tamanho máximo para as hastes

// Função para calcular a receita máxima da corte de hastes usando abordagem bottom-up
int corte_haste(int precos[], int tamanho)
{
    int receitaMaxima[MAX]; // Array para armazenar a receita máxima para cada tamanho de 0 até n

    receitaMaxima[0] = 0; // Receita para haste de tamanho 0 é 0

    // Preenche receitaMaxima para cada comprimento de haste de 1 até tamanho
    for (int j = 1; j <= tamanho; j++)
    {
        int maxReceita = INT_MIN; // Inicializa a receita máxima para o comprimento j

        // Calcula a receita máxima considerando todos os possíveis cortes i
        for (int i = 1; i <= j; i++)
        {
            int receitaAtual = precos[i] + receitaMaxima[j - i];
            if (receitaAtual > maxReceita)
            {
                maxReceita = receitaAtual;
            }
        }

        receitaMaxima[j] = maxReceita; // Armazena a receita máxima para o comprimento j
    }

    return receitaMaxima[tamanho]; // Retorna a receita máxima para o tamanho completo
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int n;

    printf("Digite o tamanho da haste: ");
    scanf("%d", &n);

    int precos[MAX]; // Array para armazenar os preços dos diferentes tamanhos de cortes

    printf("Digite os preços para cada tamanho de corte (1 até %d):\n", n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &precos[i]);
    }

    // Calcula e imprime a receita máxima para o tamanho da haste
    int resultado = corte_haste(precos, n);
    printf("A receita máxima para a haste de tamanho %d é: %d\n", n, resultado);

    return 0;
}
