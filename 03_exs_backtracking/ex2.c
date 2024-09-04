/*
1. Escreva uma função recursiva que apresente números binários de tamanho n.
• Exemplo: n = 3
Saída :
000
001
010
011
100
101
110
111
*/

#include <stdio.h>

void printArray(int array[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ",array[i]);
    }
    printf("]\n");
}

int mostraSeq(int v[], int i, int s[], int tamV, int tamS) {
    //printf("chamada de mostraSeq com i = %d\n", i);
    if (i == tamS) {
        //printf("---> print de retorno: ");
        printArray(s, tamS);
    }
    else {
        for (int j = 0; j < tamV; j++) {
            //printf("no for loop. j = %d, i = %d\n", j, i);
            s[i] = v[j];
            //printf("status: ");
            //printArray(s, tamS);
            mostraSeq(v, i+1, s, tamV, tamS);
        }
    }
}

int main() {
    int v[] = {0,1};
    int s[] = {99,99,99}; // 99 só p ter ctz que o codespaces estava limpando a memoria
    mostraSeq(v, 0, s, 2, 3);
}