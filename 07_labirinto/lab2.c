#include <stdio.h>
#include <stdbool.h>

void imprimirLabirinto(int labirinto[][8], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", labirinto[i][j]);
        }
        printf("\n");
    }
}

bool jogadaValida(int labirinto[][8], int tamanho, int paraX, int paraY) {
    if (paraX < 0 || paraX >= tamanho || paraY < 0 || paraY >= tamanho) return false; // Check bounds
    if (labirinto[paraX][paraY] == 1) return false; // Check for walls
    return true;
}

bool resolverLabirinto(int labirinto[][8], int tamanho, int posX, int posY) {
    // vetores de movimentos válidos
    int jogadasX[] = {1,-1,0,0};
    int jogadasY[] = {0,0,1,-1};
    // caso base
    if (posX == tamanho-1 && posY == tamanho-1) { // Changed from OR to AND
        labirinto[posX][posY] = 2; // Mark end position
        imprimirLabirinto(labirinto, tamanho);
        return true;
    }
    int jogadasMax = sizeof(jogadasX)/sizeof(int);
    for (int i = 0; i < jogadasMax; i++) {
        int newX = posX + jogadasX[i];
        int newY = posY + jogadasY[i];
        if (jogadaValida(labirinto, tamanho, newX, newY)) {
            labirinto[posX][posY] = 2; // Mark current position
            if (resolverLabirinto(labirinto, tamanho, newX, newY)) return true;
            labirinto[posX][posY] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    // 0 = livre, 1 = parede
    int tabuleiro[8][8] = {     {1,1,1,1,1,1,1,1},
                                {1,1,0,0,0,0,0,1},
                                {1,1,0,1,1,1,0,0},
                                {0,0,0,1,1,1,1,1},
                                {1,1,1,1,1,1,1,1},
                                {1,1,1,1,1,1,1,1},
                                {1,1,1,1,1,1,1,1},
                                {1,1,1,1,1,1,1,1}};

    resolverLabirinto(tabuleiro, 8, 1, 1); // Start position changed to (1, 1)

    return 0;
}
