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
    if (labirinto[paraX][paraY] == 1) return false;
    return true;
}

bool resolverLabirinto(int labirinto[][8], int tamanho, int posX, int posY, int saidaX, int saidaY) {
    // vetores de movimentos válidos
    int jogadasX[] = {1,-1,0,0};
    int jogadasY[] = {0,0,1,-1};
    imprimirLabirinto(labirinto, tamanho);
    // caso base
    if (posX == saidaX && posY == saidaY) {
        imprimirLabirinto(labirinto, tamanho);
        return true;
    }
    int jogadasMax = sizeof(jogadasX)/sizeof(int);
    for (int i = 0; i < jogadasMax; i++) {
        if (posX+jogadasX[i] < tamanho && posY+jogadasY[i] < tamanho && posX+jogadasX[i] > -1 && posY+jogadasY[i] > -1) {
            if (jogadaValida(labirinto, tamanho, posX+jogadasX[i], posY+jogadasY[i])) {
                labirinto[posX][posY] = 2;
                if (resolverLabirinto(labirinto, tamanho, posX+jogadasX[i], posY+jogadasY[i], saidaX, saidaY)) return true;
                else labirinto[posX][posY] = 0;
            }
        }
    }
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