// complexidade O(T*n)

#include <stdio.h>
#include <limits.h>
#include <locale.h>

#define MAX 1000 // Definindo um limite máximo para o valor de T

int memo[MAX];   // Array para memoização
int moedas[MAX]; // Array para armazenar os valores das moedas

// Função para inicializar o array memo com -1, indicando que nenhum valor foi calculado
void inicializa_memo(int T)
{
    for (int i = 0; i <= T; i++)
    {
        memo[i] = -1;
    }
}

// Função recursiva para calcular o número mínimo de moedas para alcançar o valor T
int conta_moedas(int T, int n)
{
    // Caso base: se T é zero, precisamos de zero moedas
    if (T == 0)
    {
        return 0;
    }
    // Caso em que T é negativo, retornamos infinito (não é possível)
    if (T < 0)
    {
        return INT_MAX;
    }
    // Verifica se o valor já foi calculado
    if (memo[T] != -1)
    {
        return memo[T];
    }

    int menor = INT_MAX; // Inicializa o menor número de moedas com infinito

    // Laço para verificar cada moeda disponível
    for (int i = 0; i < n; i++)
    {
        int resultado = conta_moedas(T - moedas[i], n);
        if (resultado != INT_MAX && resultado + 1 < menor)
        {
            menor = resultado + 1; // Atualiza o menor número de moedas
        }
    }

    // Armazena o resultado calculado no array memo e o retorna
    memo[T] = menor;
    return memo[T];
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int n, T;

    printf("Digite o número de tipos de moedas: ");
    scanf("%d", &n);

    printf("Digite os valores das moedas:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &moedas[i]);
    }

    printf("Digite o valor de T: ");
    scanf("%d", &T);

    // Inicializa o array memo para o valor alvo T
    inicializa_memo(T);

    // Chama a função para calcular o número mínimo de moedas
    int resultado = conta_moedas(T, n);

    if (resultado == INT_MAX)
    {
        printf("Não é possível formar o valor T com as moedas disponíveis.\n");
    }
    else
    {
        printf("O número mínimo de moedas necessário é: %d\n", resultado);
    }

    return 0;
}
