#include <stdio.h>
#include <stdbool.h>

/*
Dada uma sequência de números inteiros com n elementos, faça uma função na linguagem
C para determinar o comprimento de um segmento crescente de tamanho máximo.
Exemplos:
Na sequência 5 10 3 2 4 7 9 8 5 o comprimento do segmento crescente máximo é 4 (2, 4, 7, 9).
Na sequência 10 8 7 5 2 o comprimento do segmento crescente máximo é 1.*/

int tamSegmentoCresc(int v[], int tam) {
    int tamanhoMax = 1;
    int tamanhoIteracao = 1;
    for (int i = 1; i < tam; i++) {
        if (v[i] > v[i -1]) {
            tamanhoIteracao++;
            if (tamanhoIteracao > tamanhoMax) {
                tamanhoMax = tamanhoIteracao;
            }
        } else {
            tamanhoIteracao = 1;
        }

    }
    return tamanhoMax;
}

int main() {
    int tamA;
    printf("Informe o tamanho da sequencia a: ");
    scanf("%d", &tamA);
    int a[tamA];
    for (int i = 0; i < tamA; i++) {
        printf("Informe o valor de a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("O tamanho do maior segmento crescente é %d\n", tamSegmentoCresc(a, tamA));
    return 0;
}