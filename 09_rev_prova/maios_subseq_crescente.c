/*
Encontrar o tamanho da maior subsequencia crescente
*/

#include <stdio.h>

int maiorSubseqCresc(int v[], int tam) {
  int maiorAtual = 0;
  int maiorGeral = 0;
  for (int i = 0; i < tam; i++) {
    if (i == 0)
      maiorAtual++;
    else if (v[i] > v[i - 1])
      maiorAtual++;
    else
      maiorAtual = 1;
    if (maiorAtual > maiorGeral)
      maiorGeral = maiorAtual;
  }
  return maiorGeral;
}

int main() {
  int v[] = {3, 5, 2, 3, 4, 5, 3, 2, 8, 9, 23, 44, 55};
  int tam = sizeof(v) / sizeof(int);
  printf("%d", maiorSubseqCresc(v, tam));
  return 0;
}