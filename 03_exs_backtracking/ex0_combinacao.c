/*
Gerar todas as sequências possíveis de 3 dígitos com os dígitos
1,2 e 3 armazenados no vetor v[0 · · n − 1], onde n = 3
Solução: 111, 112, 113, 121, 122, 123, 131, 132, 133, 211,
212, 213, 221, 222, 223, 231, 232, 233, 311, 312, 313, 321,
322, 323, 331, 332, 333
A quantidade é de 3
3 = 27 sequências.
*/

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