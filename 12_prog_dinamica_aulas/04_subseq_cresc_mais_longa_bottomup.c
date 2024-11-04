// complexidade O(n^2)

#include <stdio.h>

#define MAX 1000

// Função para encontrar o comprimento da subsequência crescente mais longa em um array usando abordagem bottom-up
int subsequencia_crescente_mais_longa(int num[], int n)
{
    int L[MAX]; // Array para armazenar o comprimento da LIS até cada índice i

    // Passo 1: Inicializa todos os valores de L[i] com 1, pois o mínimo comprimento de uma LIS é 1 (o próprio elemento)
    for (int i = 0; i < n; i++)
    {
        L[i] = 1;
    }

    int maior = 1; // Variável para armazenar o comprimento máximo da subsequência crescente

    // Passo 2: Laço para calcular a LIS até cada índice i
    for (int i = 1; i < n; i++)
    {
        // Laço interno para verificar todos os elementos anteriores ao índice i
        for (int j = 0; j < i; j++)
        {
            // Verifica se num[j] é menor que num[i] para formar uma subsequência crescente
            if (num[j] < num[i])
            {
                // Atualiza L[i] com o maior valor entre o atual e L[j] + 1
                if (L[i] < L[j] + 1)
                {
                    L[i] = L[j] + 1;
                }
            }
        }
        // Atualiza o comprimento máximo da subsequência crescente
        if (maior < L[i])
        {
            maior = L[i];
        }
    }

    // Passo 3: Retorna o comprimento máximo da subsequência crescente mais longa
    return maior;
}

int main()
{
    int n;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int num[MAX];

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    // Chama a função para encontrar a subsequência crescente mais longa e imprime o resultado
    int resultado = subsequencia_crescente_mais_longa(num, n);
    printf("O comprimento da subsequência crescente mais longa é: %d\n", resultado);

    return 0;
}
