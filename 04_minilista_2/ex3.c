/*
3. (PERCURSO DO CAVALO) Dado um tabuleiro com n × n posições, o cavalo
movimenta-se segundo as regras do xadrez. A partir de uma posição inicial (x0, y0), o
problema consiste em fazer o cavalo “visitar” todas as casas do tabuleiro, sem
repetições.
Figura 1: Percurso do cavalo no tabuleiro de xadrez
Escreva um programa que selecione uma determinada posição do tabuleiro e verifique se é
possível realizar o percurso do cavalo no tabuleiro de xadrez.
*/

#include <stdio.h>

// imprime matriz
// ideal seria aprimorar para int** matriz....
void mostra_matriz(int array[8][8], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("| ");
        for (int j = 0; j < cols; j++) {
            printf("%2d ", array[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

// verifica se a posição existe no tabuleiro e se o cavalo já passou pela posição anteriormente
int posicaoValida(int tabuleiro[8][8], int linha, int coluna) {
    return (linha >= 0 && linha < 8 && coluna >= 0 && coluna < 8 && tabuleiro[linha][coluna] == -1);
}

int percursoCavalo(int tabuleiro[8][8], int linha, int coluna, int numJogada, int jogadasLin[], int jogadasCol[]) {
    if (numJogada == 64) {
        mostra_matriz(tabuleiro, 8, 8); // se todas as casas visitadas, imprimir
        return 1; // retornar! existem mais de 30 trilhões de soluções......
    }
    
    else {
        // testar todas as 8 jogadas possíveis
        for (int i = 0; i < 8; i++) {
            int proxLinha = linha + jogadasLin[i];
            int proxCol = coluna + jogadasCol[i];
            if (posicaoValida(tabuleiro, proxLinha, proxCol)) {
                // se a posição for válida, preencher com o numero da jogada
                tabuleiro[proxLinha][proxCol] = numJogada;
                // chamada recursiva partindo da proxPosição, com numJogada++
                if (percursoCavalo(tabuleiro, proxLinha, proxCol, numJogada+1, jogadasLin, jogadasCol)) return 1; // retornar! existem mais de 30 trilhões de soluções......
                tabuleiro[proxLinha][proxCol] = -1; // backtrack
            }
        }
    }

    return 0; // nenhuma solução encontrada
}

int main() {

    // matriz tabuleiro
    int tabuleiro[8][8] = {
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1}
    };

    // juntos, os dois vetores correspondem a uma jogada possivelmente válida do cavalo.
    // se o cavalo está na posição (x,y), temos 8 jogadas possivelmente válidas, de forma que:
    // op1 = (x,y)' = (x+jogadaLin[1] , y+jogadaCol[1]
    // opk = (x,y)' = (x+jogadaLin[k] , y+jogadaCol[k]
    int jogadasLin[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int jogadasCol[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    tabuleiro[0][0] = 0; // cavalo inicia em 0,0

    percursoCavalo(tabuleiro, 0, 0, 1, jogadasLin, jogadasCol);
}