/*
Escreva uma função na linguagem C que receba duas sequências e retorna:
1  se uma sequência r[1..j] é lexicograficamente menor que uma sequência s[1..k].
0  se uma sequência r[1..j] é lexicograficamente igual que uma sequência s[1..k].
-1 se uma sequência r[1..j] é lexicograficamente maior que uma sequência s[1..k].
*/

#include <stdio.h>

// retorna 1 se v1 > v2, -1 se v2 > v1, 0 se iguais
int comparacaoLexicografica (int v1[], int v2[], int tam1, int tam2) {
    int tamMenor = (tam1 < tam2) ? tam1 : tam2;

    for (int i = 0; i < tamMenor; i++) {
        if (v1[i] > v2[i]) return 1;
        if (v1[i] < v2[i]) return -1;
    }

    if (tam1 > tam2) return 1;
    else if (tam2 > tam1) return -1;
    else return 0;
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
    int comp = comparacaoLexicografica(v1, v2, tam1, tam2);
    if ( comp == 1) {
        printf("v1 > v2\n");
    } else if (comp == -1) {
        printf("v2 > v1\n");
    } else {
        printf("v2 = v1\n");
    }

    return 0;
}