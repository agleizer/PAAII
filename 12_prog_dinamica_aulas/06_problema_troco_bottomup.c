// complexidade O(T*n)

#include <stdio.h>
#include <limits.h>
#include <locale.h>

#define MAX 1000 // Define o limite máximo para o valor de T

int moedas[MAX]; // Array para armazenar os valores das moedas

// Função para calcular o número mínimo de moedas para alcançar o valor T usando abordagem bottom-up
int conta_moedas(int T, int n)
{
    int troco[MAX]; // Array para armazenar o número mínimo de moedas necessário para cada valor de 0 até T

    // Inicializa troco[0] com 0, pois não precisamos de moedas para alcançar o valor 0
    troco[0] = 0;

    // Inicializa o array troco com infinito para valores de 1 até T (indica que ainda não foi calculado)
    for (int i = 1; i <= T; i++)
    {
        troco[i] = INT_MAX;
    }

    // Laço externo para calcular o número mínimo de moedas para cada valor de 1 até T
    for (int i = 1; i <= T; i++)
    {
        // Laço interno para cada moeda disponível
        for (int j = 0; j < n; j++)
        {
            // Verifica se a moeda atual pode ser usada (i >= moedas[j])
            if (i >= moedas[j] && troco[i - moedas[j]] != INT_MAX)
            {
                // Atualiza troco[i] com o valor mínimo entre o atual e troco[i - moedas[j]] + 1
                if (troco[i] > troco[i - moedas[j]] + 1)
                {
                    troco[i] = troco[i - moedas[j]] + 1;
                }
            }
        }
    }

    // Retorna o resultado para troco[T], ou -1 se não for possível formar o valor T
    return (troco[T] == INT_MAX) ? -1 : troco[T];
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

    // Chama a função para calcular o número mínimo de moedas e imprime o resultado
    int resultado = conta_moedas(T, n);

    if (resultado == -1)
    {
        printf("Não é possível formar o valor T com as moedas disponíveis.\n");
    }
    else
    {
        printf("O número mínimo de moedas necessário é: %d\n", resultado);
    }

    return 0;
}
