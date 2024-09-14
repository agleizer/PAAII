#include <stdio.h>

void printArray(int array[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ",array[i]);
    }
    printf("]\n");
}

void ordenarBack(int s[], int v[], int tam, int i) {
    if (i == tam){
        printArray(s, tam);
        return;
    } 
    else {
        for (int j = 0; j < tam; j++) {
            if (i == 0) s[i] = v[j];
            else if (v[j] > s[i-1]) {
                s[i] = v[j];
                ordenarBack(s,v,tam,i+1);
                s[i]=0;
            }
        }
    }
}

int main() {
    int v[] = {6,4,2,1};
    int s[4];
    ordenarBack(s,v,4,0);

}