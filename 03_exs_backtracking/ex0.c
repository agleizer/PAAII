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
    if (i == tam) printArray(s, tam);
    else {
        for (int j = 0; j < tam; j++) {
            printf("j = %d\n", j);
            s[i] = v[j];
            mostraSeq(v, i+1, s, tam);
        }
    }
}

int main() {
    int v[] = {1,2,3};
    int s[3];
    mostraSeq(v, 0, s, 3);
}