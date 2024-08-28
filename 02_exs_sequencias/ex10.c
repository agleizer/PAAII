/*
Suponha o seguinte problema:
Enumerar todas as sequências possíveis de 3 dígitos, por exemplo se tivermos
os dígitos 1, 2 e 3 teríamos como resultado:
1 1 1, 1 1 2, 1 1 3, 1 2 1, 1 2 2, 1 2 3, 1 3 1, 1 3 2, 1 3 3,
2 1 1, 2 1 2, 2 1 3, 2 2 1, 2 2 2, 2 2 3, 2 3 1, 2 3 2, 2 3 3,
3 1 1, 3 1 2, 3 1 3, 3 2 1, 3 2 2, 3 2 3, 3 3 1, 3 3 2, 3 3 3
Nesse caso teremos 27 (3^3) sequências.
Uma dica é resolver o problema usando uma função recursiva, armazenar os
dígitos no vetor a[1..n] e as sequências geradas no vetor s[1..n], onde n=3.
*/

void printArray(int array[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ",array[i]);
    }
    printf("]\n");
}

void enumerarSequencias(int qtdDigitos, int unidadeMax) {
    int vetor[qtdDigitos];

    for (int i = 0; i < qtdDigitos; i++) {
        for(int j = 1; j <= unidadeMax; j++) {

        }
    }
}

int main () {

    return 0;
}