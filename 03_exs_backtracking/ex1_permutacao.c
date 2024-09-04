/*
Dado uma vetor v, escreva um programa que imprima todas as
permutações. Se v tem n elementos, então o programa deve
imprimir n! permutações.
entrada: v = {1, 2, 3}
saída: {1, 2, 3}, {1, 3, 2}, {2, 1, 3},
{2, 3, 1}, {3, 1, 2}, {3, 2, 1}.
*/

#include <stdio.h>

void printArray(int array[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ",array[i]);
    }
    printf("]\n");
}

// apenas copiei a função de combinação por enquanto. ajustar para permutação
int mostraSeqPermuta(int v[], int i, int s[], int tam) {
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