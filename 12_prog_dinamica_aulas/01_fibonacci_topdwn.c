// complexidade O(n)

#include <stdio.h>
#include <locale.h>

// Define o tamanho máximo para a sequência de Fibonacci
#define MAX 100

// Declara o array para memorizar os valores já calculados
int memo[MAX];

// Função para inicializar o array de memoização
void inicializa_memo()
{
    for (int i = 0; i < MAX; i++)
    {
        memo[i] = -1; // -1 indica que o valor ainda não foi calculado
    }
}

// Função para calcular o n-ésimo número de Fibonacci usando a abordagem top-down
int fib(int n)
{
    // Caso base: se n for 0 ou 1, retornamos o próprio n
    if (n == 0 || n == 1)
    {
        memo[n] = n;
        return n;
    }

    // Verifica se o valor já foi calculado e armazenado no array 'memo'
    if (memo[n] != -1)
    {                   // -1 indica que o valor não foi calculado
        return memo[n]; // Retorna o valor já calculado
    }

    // Se o valor ainda não foi calculado, chamamos recursivamente a função para calcular
    memo[n] = fib(n - 1) + fib(n - 2); // Armazena o resultado no array 'memo'
    return memo[n];                    // Retorna o valor calculado e armazenado
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    // Inicializa o array 'memo' com -1 para indicar que nenhum valor foi calculado
    inicializa_memo();

    // Chama a função 'fib' e imprime o resultado
    printf("Fibonacci de %d = %d\n", n, fib(n));

    return 0;
}
