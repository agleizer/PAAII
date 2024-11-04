// complexidade O(n^3)

#include <stdio.h>
#include <limits.h>
#include <locale.h>

#define MAX 100 // Define o tamanho máximo para as matrizes

int m[MAX][MAX]; // Armazena os custos mínimos de multiplicação
int s[MAX][MAX]; // Armazena os índices de divisão para parentização ótima

// Função para calcular a ordem ótima de multiplicação de matrizes
void ordem_cadeia_matriz(int p[], int n)
{
    // Passo 1: Inicializa os custos para multiplicação de uma única matriz como zero
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    // Passo 2: Calcula os custos para cadeias de tamanho crescente
    for (int l = 2; l <= n; l++)
    { // l é o comprimento da cadeia
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            // Passo 3: Determina o ponto de divisão k que minimiza o custo
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// Função para imprimir a parentização ótima
void imprime_parenteses_otimo(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        imprime_parenteses_otimo(i, s[i][j]);
        imprime_parenteses_otimo(s[i][j] + 1, j);
        printf(")");
    }
}

// Função principal
int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int n;

    printf("Digite o número de matrizes: ");
    scanf("%d", &n);

    int p[MAX];

    printf("Digite as dimensões das matrizes (vetor p):\n");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    // Calcula a ordem de multiplicação ótima
    ordem_cadeia_matriz(p, n);

    printf("O número mínimo de multiplicações necessárias é: %d\n", m[1][n]);
    printf("A parentização ótima é: ");
    imprime_parenteses_otimo(1, n);
    printf("\n");

    return 0;
}
