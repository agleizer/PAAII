#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Dada a sequência a[1..n] de números inteiros, escreva um programa na linguagem C que
verifica se existem dois segmentos consecutivos iguais na sequência, isto é, se existem i e m
tais que:
a[i] a[i+1] ... a[i+m-1] = a[i+m] a[i+m+1] ... a[i+2m-1]
Imprima, caso existam, os valores de i e m.
Exemplo: Na sequência 7 9 5 4 5 4 8 6 existem i=3 e m=2.
*/

bool segmentosIguais(int v[], int i1, int f1, int i2, int f2) {
    int tam1 = f1 - i1;
    int tam2 = f2 - i2;
    if (tam1 != tam2) {
        return false;
    }
    for (int j = 0; j < tam1; j++) {
        if (v[i1 + j] != v[i2 + j]) {
            return false;
        }
    }
    return true;
}

bool segmentosConsecutivos (int v[], int tam, int* i, int* m) {
    for (int tamSeq = tam / 2; tamSeq > 0; tamSeq--) {
        for (int buscaI = 0; buscaI + 2 * tamSeq <= tam; buscaI++) {
            if (segmentosIguais(v, buscaI, buscaI+tamSeq - 1, buscaI+tamSeq, buscaI+2*tamSeq-1)) {
                *i = buscaI;
                *m = tamSeq;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int i = 0;
    int m = 0;
    int tam;
    printf("Informe o tamanho da sequencia: ");
    scanf("%d", &tam);
    int v[tam];
    for (int j = 0; j < tam; j++) {
        printf("Informe o valor de v[%d]", j);
        scanf("%d", &v[j]);
    }
    segmentosConsecutivos(v, tam, &i, &m);
    printf("i = %d e m = %d\n", i, m);
}