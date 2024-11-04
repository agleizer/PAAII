// complexidade O(m*n)

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 100 // Define o tamanho máximo para as sequências

int comprimentoLCS[MAX][MAX]; // Matriz para armazenar o comprimento da LCS
char direcaoLCS[MAX][MAX];    // Matriz para armazenar as direções da LCS

// Função para calcular a Subsequência Comum Mais Longa (LCS) entre duas sequências X e Y
void calcular_LCS(char X[], char Y[], int m, int n)
{
    // Inicializa a primeira linha e a primeira coluna da matriz comprimentoLCS com 0
    for (int i = 0; i <= m; i++)
    {
        comprimentoLCS[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        comprimentoLCS[0][j] = 0;
    }

    // Preenche as matrizes comprimentoLCS e direcaoLCS com base nas comparações entre elementos de X e Y
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            { // Comparação entre elementos de X e Y
                comprimentoLCS[i][j] = comprimentoLCS[i - 1][j - 1] + 1;
                direcaoLCS[i][j] = 'D'; // Direção diagonal (match)
            }
            else if (comprimentoLCS[i][j - 1] > comprimentoLCS[i - 1][j])
            {
                comprimentoLCS[i][j] = comprimentoLCS[i][j - 1];
                direcaoLCS[i][j] = 'L'; // Direção para a esquerda
            }
            else
            {
                comprimentoLCS[i][j] = comprimentoLCS[i - 1][j];
                direcaoLCS[i][j] = 'U'; // Direção para cima
            }
        }
    }
}

// Função para imprimir a Subsequência Comum Mais Longa (LCS) usando a matriz de direções direcaoLCS
void recuperar_LCS(char direcaoLCS[MAX][MAX], char X[], int i, int j)
{
    if (i == 0 || j == 0)
    { // Caso base: fim da matriz
        return;
    }
    if (direcaoLCS[i][j] == 'D')
    { // Movimento diagonal indica correspondência
        recuperar_LCS(direcaoLCS, X, i - 1, j - 1);
        printf("%c", X[i - 1]); // Imprime o caractere correspondente na LCS
    }
    else if (direcaoLCS[i][j] == 'U')
    { // Movimento para cima
        recuperar_LCS(direcaoLCS, X, i - 1, j);
    }
    else
    { // Movimento para a esquerda
        recuperar_LCS(direcaoLCS, X, i, j - 1);
    }
}

// Função principal
int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    char X[MAX], Y[MAX];
    int m, n;

    printf("Digite a primeira sequência: ");
    scanf("%s", X);
    printf("Digite a segunda sequência: ");
    scanf("%s", Y);

    m = strlen(X);
    n = strlen(Y);

    // Calcula a Subsequência Comum Mais Longa
    calcular_LCS(X, Y, m, n);

    printf("O comprimento da Subsequência Comum Mais Longa é: %d\n", comprimentoLCS[m][n]);
    printf("A Subsequência Comum Mais Longa é: ");
    recuperar_LCS(direcaoLCS, X, m, n);
    printf("\n");

    return 0;
}
