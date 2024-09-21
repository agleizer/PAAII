#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 8  // Define o tamanho do tabuleiro como 8x8

// Função para exibir o tabuleiro de forma visual
void mostra_matriz(char array[][N], int linhas, int cols) {
    // Percorre as linhas
    for (int i = 0; i < linhas; i++) {
        printf("| ");
        // Percorre as colunas e exibe cada elemento da linha
        for (int j = 0; j < cols; j++) {
            printf("%c ", array[i][j]);  // Imprime o caractere atual da célula
        }
        printf("|\n");  // Pula para a próxima linha após imprimir todas as colunas
    }
    printf("\n");  // Nova linha após a impressão do tabuleiro completo
}

// Função que verifica se é seguro colocar uma rainha na posição (linha, coluna)
bool esta_salva(char tabuleiro[][N], int linha, int coluna) {
    int i, j;
    
    // Verifica se já existe uma rainha na mesma linha à esquerda
    for (i = 0; i < coluna; i++) 
        if (tabuleiro[linha][i] == 'Q') return false;

    // Verifica a diagonal superior à esquerda
    for (i = linha, j = coluna; i >= 0 && j >= 0; i--, j--)
        if (tabuleiro[i][j] == 'Q') return false;

    // Verifica a diagonal inferior à esquerda
    for (i = linha, j = coluna; i < N && j >= 0; i++, j--)
        if (tabuleiro[i][j] == 'Q') return false;

    return true;  // Retorna true se a posição for segura para colocar a rainha
}

// Função recursiva para posicionar as rainhas no tabuleiro
void posiciona_rainha(char tabuleiro[][N], int coluna) {
    // Caso base: se todas as rainhas foram colocadas, exibe o tabuleiro
    if (coluna == N) 
        mostra_matriz(tabuleiro, N, N);
    else {
        // Percorre todas as linhas para tentar colocar a rainha na coluna atual
        for (int i = 0; i < N; i++) {
            // Verifica se é seguro colocar a rainha na posição (i, coluna)
            if (esta_salva(tabuleiro, i, coluna)) {
                tabuleiro[i][coluna] = 'Q';  // Coloca a rainha na posição
                posiciona_rainha(tabuleiro, coluna + 1);  // Recursão para a próxima coluna
                tabuleiro[i][coluna] = '-';  // Remove a rainha para tentar outra solução
            }
        }
    }
}

int main(int argc, char *argv[]) {
    char tabuleiro[N][N];
    
    // Inicializa o tabuleiro com '-' em todas as posições
    memset(tabuleiro, '-', sizeof(tabuleiro));

    // Inicia o posicionamento das rainhas a partir da coluna 0
    posiciona_rainha(tabuleiro, 0);

    return 0;
}
