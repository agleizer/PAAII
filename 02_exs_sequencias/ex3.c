/*
Escreva uma função booleana na linguagem C que receba duas sequências e
decida se a sequência s[1..k] é uma subsequência da sequência a[1..n].
*/

#include <stdio.h>
#include <stdbool.h>

// retorna true se v2 eh subsequencia de v1
bool verificaSubsequencia (int v1[], int v2[], int tam1, int tam2) {
    if (tam2 > tam1) return false;

    int i = 0;
    int j = 0;

    while (i < tam1 && j < tam2) {
        if (v1[i] == v2[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }

    if (j == tam2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int tam1, tam2;
    printf("Informe o tamanho da sequencia 1: ");
    scanf("%d", &tam1);
    printf("Informe o tamanho da sequencia 2: ");
    scanf("%d", &tam2);
    int v1[tam1], v2[tam2];
    for (int i = 0; i < tam1; i++) {
        printf("Informe o valor de v1[%d]: ", i);
        scanf("%d", &v1[i]);
    }
    for (int i = 0; i < tam2; i++) {
        printf("Informe o valor de v2[%d]: ", i);
        scanf("%d", &v2[i]);
    }

    // testes
    if (verificaSubsequencia(v1, v2, tam1, tam2)) {
        printf("v2 eh subsequencia de v1\n");
    } else {
        printf("v2 NAO eh subsequencia de v1\n");
    }
}