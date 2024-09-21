#include <stdio.h>
#include <stdbool.h>

/*
Escreva uma função booleana na linguagem C que receba duas sequências e decida se a sequência s[i..k] é um segmento da sequência a[1..n].
*/

bool ehSegmento(int a[], int s[], int tamA, int tamS) {
    if (tamS > tamA) {
        return false;  // If the segment is larger than the array, it can't be a segment
    }

    for (int i = 0; i <= tamA - tamS; i++) {
        int j = 0;

        // Check if the segment matches starting from index i
        while (j < tamS && a[i + j] == s[j]) {
            j++;
        }

        // If we've matched the whole segment, return true
        if (j == tamS) {
            return true;
        }
    }

    // If no match was found, return false
    return false;
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