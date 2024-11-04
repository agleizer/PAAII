// complexidade O(n)

#include <stdio.h>

// Função para calcular o n-ésimo número de Fibonacci usando a abordagem bottom-up
int fib(int n)
{
    // Declara um array para armazenar os valores de Fibonacci até n
    int f[n + 1];

    // Passo 1: Define os valores iniciais para f[0] e f[1]
    f[0] = 0;
    f[1] = 1;

    // Passo 2: Calcula os próximos valores de Fibonacci de forma iterativa
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2]; // Calcula f[i] como a soma dos dois anteriores
    }

    // Passo 3: Retorna o valor de Fibonacci de n
    return f[n];
}

int main()
{
    int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    // Chama a função 'fib' e imprime o resultado
    printf("Fibonacci de %d = %d\n", n, fib(n));

    return 0;
}
