#include <stdio.h>
#include <stdbool.h>

void imprimirLabirinto(int labirinto[][8], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", labirinto[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool jogadaValida(int labirinto[][8], int tamanho, int paraX, int paraY) {
    if (labirinto[paraX][paraY] == 1 || labirinto[paraX][paraY] == 2) return false; // Added check for revisited cells
    return true;
}

bool resolverLabirinto(int labirinto[][8], int tamanho, int posX, int posY, int saidaX, int saidaY) {
    // vetores de movimentos válidos
    int jogadasX[] = {1,-1,0,0};
    int jogadasY[] = {0,0,1,-1};
    // caso base
    if (posX == saidaX && posY == saidaY) {
        labirinto[posX][posY] = 2;  // Mark exit point as part of the path
        imprimirLabirinto(labirinto, tamanho);
        return true;
    }
    // Mark current position as part of the path
    labirinto[posX][posY] = 2;
    imprimirLabirinto(labirinto, tamanho);

    int jogadasMax = sizeof(jogadasX) / sizeof(int);
    for (int i = 0; i < jogadasMax; i++) {
        int novoX = posX + jogadasX[i];
        int novoY = posY + jogadasY[i];
        
        // Check bounds and validity of the move
        if (novoX >= 0 && novoX < tamanho && novoY >= 0 && novoY < tamanho) {
            if (jogadaValida(labirinto, tamanho, novoX, novoY)) {
                // Recursively attempt to solve the maze
                if (resolverLabirinto(labirinto, tamanho, novoX, novoY, saidaX, saidaY)) {
                    return true;
                }
            }
        }
    }
    
    // Backtrack: Unmark the position if no valid moves lead to a solution
    labirinto[posX][posY] = 0;
    return false;
}

int main() {
    //int tam = 8;
    // 0 = livre, 1 = parede
    int tabuleiro[8][8] = {     {1,1,1,1,1,1,1,1},
                                {1,1,0,0,0,0,0,1},
                                {1,1,0,1,1,1,0,0},
                                {0,0,0,1,1,1,1,1},
                                {1,1,1,1,1,1,1,1},
                                {1,1,1,1,1,1,1,1},
                                {1,1,1,1,1,1,1,1},
                                {1,1,1,1,1,1,1,1}};

    resolverLabirinto(tabuleiro, 8, 3, 0, 7, 2);

    return 1;
}
