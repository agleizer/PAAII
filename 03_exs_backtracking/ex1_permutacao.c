/*
Dado uma vetor v, escreva um programa que imprima todas as
permutações. Se v tem n elementos, então o programa deve
imprimir n! permutações.
entrada: v = {1, 2, 3}
saída: {1, 2, 3}, {1, 3, 2}, {2, 1, 3},
{2, 3, 1}, {3, 1, 2}, {3, 2, 1}.
*/

#include <stdio.h>

void printArray(int array[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

// função para gerar permutações
// inclusão de um vetor adicional para armazenar de determinado valor já foi utilizado
// o indice é o valor, usado[indice] = 0 se usado, 1 se não usado
void mostraSeqPermuta(int v[], int i, int s[], int tam, int usado[]) {
    if (i == tam) {
        printf("---> print de retorno: ");
        printArray(s, tam);
    } else {
        for (int j = 0; j < tam; j++) {
            if (!usado[j]) { // checar se elemento foi usado
                s[i] = v[j];
                usado[j] = 1; // marcar como usado
                mostraSeqPermuta(v, i + 1, s, tam, usado);
                usado[j] = 0; // desmarcar como usado para a próxima iteração / permutação
            }
        }
    }
}

int main() {
    int v[] = {1, 2, 3};
    int s[] = {99, 99, 99};
    int used[] = {0, 0, 0}; // vetor de usados começa com tudo não usado
    mostraSeqPermuta(v, 0, s, 3, used);
}