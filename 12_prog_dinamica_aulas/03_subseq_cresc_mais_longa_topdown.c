// complexidade O(n^2)

#include <stdio.h>
#include <locale.h>

// Define um valor para indicar que um índice ainda não foi calculado
#define NAO_CALCULADO -1

// Declara o array para memoização e o array dos números
int L[1000];   // Array para armazenar o comprimento da LIS para cada posição
int num[1000]; // Array para armazenar a sequência de entrada

// Função auxiliar para retornar o valor máximo entre dois números
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Função recursiva para calcular a LIS até o índice i
int LIS(int i)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    // Passo 1: Verifica se L[i] já foi calculado
    if (L[i] != NAO_CALCULADO)
    {
        return L[i]; // Retorna o valor memoizado
    }

    // Passo 2: Caso base - se i for 0, a LIS até essa posição é 1
    if (i == 0)
    {
        return L[i] = 1;
    }

    // Passo 3: Inicializa o comprimento máximo da LIS até i com valor 1
    int maior = 1;

    // Passo 4: Itera de 0 até i - 1 para verificar todas as subsequências anteriores
    for (int j = 0; j < i; j++)
    {
        // Passo 5: Verifica se num[j] é menor que num[i] para manter a sequência crescente
        if (num[j] < num[i])
        {
            // Passo 6: Atualiza 'maior' com o valor máximo entre 'maior' atual e LIS(j) + 1
            maior = max(maior, LIS(j) + 1);
        }
    }

    // Passo 7: Armazena o resultado no array L e retorna
    return L[i] = maior;
}

// Função principal para encontrar a subsequência crescente mais longa em um array
int subsequencia_crescente_mais_longa(int n)
{
    int maior = 1; // Variável para armazenar o comprimento da LIS máxima

    // Inicializa o array L com NAO_CALCULADO para indicar que os valores não foram computados
    for (int i = 0; i < n; i++)
    {
        L[i] = NAO_CALCULADO;
    }

    // Passo 1: Calcula a LIS para cada índice e atualiza o maior comprimento
    for (int i = 0; i < n; i++)
    {
        maior = max(maior, LIS(i));
    }

    // Passo 2: Retorna o comprimento da maior subsequência crescente
    return maior;
}

int main()
{
    int n;

    printf("Digite o tamanho da sequência: ");
    scanf("%d", &n);

    printf("Digite a sequência de %d números: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    // Calcula e imprime o comprimento da subsequência crescente mais longa
    printf("Comprimento da subsequência crescente mais longa: %d\n", subsequencia_crescente_mais_longa(n));

    return 0;
}
