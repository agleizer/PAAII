/*
2. (SUBSEQUÊ NCIA COMUM MÁ XIMA) Dadas duas sequê ncias X e Y determinar a
maior subsequê ncia comum de X e Y.
Exemplo:
X = ATCTGAT e Y = TGCATTA.
tamanho da maior subsequência comum: 4 SCM(X, Y) = TCTA
Faça:
a. Execute o LCS (preencha a tabela S[i,j]) para as seguintes sequências X e Y
X[1..m]={G, A, C, C, T, G } Y[1..n]={A, G, T, A, A, C, G, C, T, A}. Qual é a maior
subsequência comum entre X e Y?
b. Implemente, na linguagem C, o algoritmo que resolve o problema da LCS usando força-
bruta.
c. Implemente, na linguagem C, o algoritmo LCS (programação dinâmica), que constrói
a tabela S[i,j] (top-down ou bottom-up).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para verificar se uma subsequência está contida em uma sequência
int verificarSubsequencia(char *seq, char *subseq, int seqLen, int subLen)
{
    int j = 0;
    for (int i = 0; i < seqLen && j < subLen; i++)
    {
        if (seq[i] == subseq[j])
        {
            j++;
        }
    }
    return j == subLen;
}

// Função principal para encontrar a LCS por força bruta
int lcsForcaBruta(char *X, char *Y)
{
    int maxLen = 0;
    int xLen = strlen(X), yLen = strlen(Y);

    // Array temporário para armazenar subsequências de X
    char subseq[xLen + 1];

    // Gera todas as subsequências de X
    for (int len = 1; len <= xLen; len++)
    { // Tamanho da subsequência
        for (int start = 0; start <= xLen - len; start++)
        { // Posição inicial
            // Copia o trecho de X para subseq
            strncpy(subseq, &X[start], len);
            subseq[len] = '\0'; // Finaliza a string

            // Verifica se subseq é subsequência de Y
            if (verificarSubsequencia(Y, subseq, yLen, len) && len > maxLen)
            {
                maxLen = len; // Atualiza o comprimento máximo
            }
        }
    }

    return maxLen;
}

// Função para calcular a LCS usando programação dinâmica
int lcsDP(char *X, char *Y)
{
    int m = strlen(X);
    int n = strlen(Y);
    int S[m + 1][n + 1];

    // Inicializa a matriz S
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                S[i][j] = 0; // Caso base
            }
            else if (X[i - 1] == Y[j - 1])
            {
                // Se os caracteres são iguais, incrementa o valor da célula anterior
                S[i][j] = S[i - 1][j - 1] + 1;
            }
            else
            {
                // Caso contrário, toma o valor máximo das células adjacentes
                S[i][j] = (S[i - 1][j] > S[i][j - 1]) ? S[i - 1][j] : S[i][j - 1];
            }
        }
    }

    return S[m][n]; // Retorna o comprimento da LCS
}

int main()
{
    char X[] = "GACCTG";
    char Y[] = "AGTAACGCTA";

    int resultadoFB = lcsForcaBruta(X, Y);
    printf("Comprimento da maior subsequência comum (Força Bruta): %d\n", resultadoFB);

    int resultadoPD = lcsDP(X, Y);
    printf("Comprimento da maior subsequência comum (Programação Dinâmica): %d\n", resultadoPD);

    return 0;
}
