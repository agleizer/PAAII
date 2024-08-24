#include <stdio.h>
#include <stdbool.h>

/*
Escreva uma função booleana na linguagem C que receba duas sequências e decida se a sequência s[i..k] é um segmento da sequência a[1..n].
*/

bool ehSegmento(int a[], int s[], int tamA, int tamS) {
    bool validacao = false;
    int i = 0;
    int j = 0;
    if (tamS > tamA) {
        return false;
    }
    while (i < tamA && j < tamS) {
        if (a[i] != s[j]) {
            validacao = false;
            j = 0;
            i++;
        } else {
            validacao = true;
            i++;
            j++;
        }
    }
    return validacao;
}

int main() {
    int tamA, tamS;
    printf("Informe o tamanho da sequencia a: ");
    scanf("%d", &tamA);
    printf("Informe o tamanho do segmento s: ");
    scanf("%d", &tamS);
    int a[tamA], s[tamS];
    for (int i = 0; i < tamA; i++) {
        printf("Informe o valor de a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < tamS; i++) {
        printf("Informe o valor de s[%d]: ", i);
        scanf("%d", &s[i]);
    }
    if (ehSegmento(a,s,tamA,tamS)) {
        printf("Verdadeiro!\n");
    } else {
        printf("Falso...\n");
    }
    return 0;
}

/*
int main() {
    int a[] = {9,7,8,2,1,4};
    int s[] = {7,8, 9};
    int tamA = sizeof(a)/sizeof(int);
    int tamS = sizeof(s)/sizeof(int);
    if (ehSegmento(a,s,tamA,tamS)) {
        printf("Verdadeiro!\n");
    } else {
        printf("Falso...\n");
    }
    return 0;
}
*/