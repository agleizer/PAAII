/*
Um bitonic array é um vetor de números que é organizado em duas partes.
A primeira parte que consiste de elementos na ordem crescente e a segunda parte
consiste de elementos em ordem decrescente. Mais precisamente, uma vetor A[1 . .
n] é bitonic se e somente se existe um índice i, 1 ≤ i ≤ n, tal que A[1..i] é
estritamente crescente, e A[i..n] é estritamente decrescente. Por exemplo, o
vetor {2, 5, 8, 7, 3} é bitonic, com i = 3. Faça uma função, utilizando a
técnica de divisão e conquista que encontre o máximo elemento de um bitonic
array (assuma que todos os elementos são distintos).
*/

#include <stdio.h>

int maxBitonic(int vetor[], int inicio, int fim) {
  int meio = (inicio + fim) / 2;

  // caso base
  if (vetor[meio] > vetor[meio + 1] && vetor[meio] > vetor[meio - 1]) {
    return vetor[meio];
  }

  if (vetor[meio] < vetor[meio + 1]) {
    return maxBitonic(vetor, meio + 1, fim);
  }

  if (vetor[meio] < vetor[meio - 1]) {
    return maxBitonic(vetor, inicio, meio - 1);
  }
}

int main(void) {
  int tamanho;
  printf("Informe o tamanho do vetor: ");
  scanf("%d", &tamanho);
  int vetor[tamanho];
  for (int i = 0; i < tamanho; i++) {
    printf("Informe o valor do %do elemento: ", i + 1);
    scanf("%d", &vetor[i]);
  }
  int maximo = maxBitonic(vetor, 0, tamanho - 1);
  printf("Maior elemento = %d\n", maximo);
}
