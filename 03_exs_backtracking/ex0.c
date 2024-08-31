#include <stdio.h>

void printArray(int array[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ",array[i]);
    }
    printf("]\n");
}

int mostraSeq(int v[], int i, int s[], int tam) {
    printf("chamada de mostraSeq com i = %d\n", i);
    if (i == tam) {
        printf("---> print de retorno: ");
        printArray(s, tam);
    }
    else {
        for (int j = 0; j < tam; j++) {
            printf("no for loop. j = %d, i = %d\n", j, i);
            s[i] = v[j];
            printf("status: ");
            printArray(s, tam);
            mostraSeq(v, i+1, s, tam);
        }
    }
}

int main() {
    int v[] = {1,2,3};
    int s[] = {99,99,99}; // 99 só p ter ctz que o codespaces estava limpando a memoria
    mostraSeq(v, 0, s, 3);
}