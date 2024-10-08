/*
9) Dados dois números naturais m e n e duas sequências ordenadas sem números
repetidos com m e n números inteiros, obter uma única sequência ordenada
contendo todos os elementos das sequências originais.
Qual é complexidade da sua função ?
*/

#include <stdio.h>

void printArray(int array[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ",array[i]);
    }
    printf("]\n");
}

void sequenciaOrdenada(int v1[], int v2[], int n1, int n2, int v3[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2) {
        if (v1[i] < v2[j]) {
            v3[k++] = v1[i++];
        } else {
            v3[k++] = v2[j++];
        }
    }

    // último elemento
    if (i < n1) v3[k] = v1[i]; 
    if (j < n2) v3[k] = v2[j]; 

}

int main() {
    int v1[] = {1,3,5,7,9};
    int v2[] = {2,4,6,8};
    int n1 = sizeof(v1)/sizeof(int);
    int n2 = sizeof(v2)/sizeof(int);
    int v3[n1+n2];

    sequenciaOrdenada(v1, v2, n1, n2, v3);

    printArray(v1, n1);
    printArray(v2, n2);
    printArray(v3, n1+n2);

}