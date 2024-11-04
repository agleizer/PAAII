// complexidade O(n^3)

#include <stdio.h>
#include <limits.h>

#define MAX_MATRIZES 100 // Define o tamanho máximo para as matrizes

int custoMinimo[MAX_MATRIZES][MAX_MATRIZES];  // Armazena os custos mínimos de multiplicação
int pontoDivisao[MAX_MATRIZES][MAX_MATRIZES]; // Armazena os pontos de divisão para parentização ótima

// Função para calcular a ordem ótima de multiplicação de matrizes
void calcular_ordem_multiplicacao_matriz(int dimensoes[], int numMatrizes)
{
    // Passo 1: Inicializa os custos para multiplicação de uma única matriz como zero
    for (int i = 1; i <= numMatrizes; i++)
    {
        custoMinimo[i][i] = 0;
    }

    // Passo 2: Calcula os custos para cadeias de matrizes de tamanho crescente
    for (int comprimentoCadeia = 2; comprimentoCadeia <= numMatrizes; comprimentoCadeia++)
    {
        for (int inicio = 1; inicio <= numMatrizes - comprimentoCadeia + 1; inicio++)
        {
            int fim = inicio + comprimentoCadeia - 1;
            custoMinimo[inicio][fim] = INT_MAX;

            // Passo 3: Determina o ponto de divisão k que minimiza o custo
            for (int ponto = inicio; ponto < fim; ponto++)
            {
                int custoAtual = custoMinimo[inicio][ponto] + custoMinimo[ponto + 1][fim] +
                                 dimensoes[inicio - 1] * dimensoes[ponto] * dimensoes[fim];
                if (custoAtual < custoMinimo[inicio][fim])
                {
                    custoMinimo[inicio][fim] = custoAtual;
                    pontoDivisao[inicio][fim] = ponto;
                }
            }
        }
    }
}

// Função para imprimir a parentização ótima
void imprimir_parentizacao_otima(int inicio, int fim)
{
    if (inicio == fim)
    {
        printf("A%d", inicio);
    }
    else
    {
        printf("(");
        imprimir_parentizacao_otima(inicio, pontoDivisao[inicio][fim]);
        imprimir_parentizacao_otima(pontoDivisao[inicio][fim] + 1, fim);
        printf(")");
    }
}

// Função principal
int main()
{
    int numMatrizes;

    printf("Digite o número de matrizes: ");
    scanf("%d", &numMatrizes);

    int dimensoes[MAX_MATRIZES];

    printf("Digite as dimensões das matrizes (vetor dimensoes):\n");
    for (int i = 0; i <= numMatrizes; i++)
    {
        scanf("%d", &dimensoes[i]);
    }

    // Calcula a ordem de multiplicação ótima
    calcular_ordem_multiplicacao_matriz(dimensoes, numMatrizes);

    printf("O número mínimo de multiplicações necessárias é: %d\n", custoMinimo[1][numMatrizes]);
    printf("A parentização ótima é: ");
    imprimir_parentizacao_otima(1, numMatrizes);
    printf("\n");

    return 0;
}
