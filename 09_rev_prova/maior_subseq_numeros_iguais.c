/*
Dada uma sequência de números inteiros com n elementos, determinar quantas
subsequências de números iguais consecutivos compõem essa sequência.
Exemplos:
a) A sequência 5 2 2 3 4 4 4 4 4 1 1, é composta por 5 subsequências:
(5), (2,2), (3), (4, 4, 4, 4, 4), (1,1);
b) A sequência: 3 3 -1 -1 -1 12 12 12 3 3 é composta por 4 subsequências:
(3,3), (-1, -1, -1), (12, 12, 12), (3,3);
Escreva uma função na linguagem C que determina a quantidade de
subsequências em sequência dada.
Qual é complexidade da sua função ?
*/

#include <stdio.h>

// entendimento 1, só temos uma subsequencia váçida com mais de um numero
// igual...
int subsequenciasNumsConsecutivos(int v[], int tam) {
  int qtdSubsequencias = 0;
  int ultimoNumConsecutivo = v[0];

  for (int i = 1; i < tam; i++) {
    if (v[i] == v[i - 1]) {
      if (i == 1)
        qtdSubsequencias++;
      else {
        if (v[i] != ultimoNumConsecutivo) {
          qtdSubsequencias++;
          ultimoNumConsecutivo = v[i];
        }
      }
    }
  }

  return qtdSubsequencias;
}

int main() {
  int vetor[] = {5, 2, 2, 3, 4, 4, 4, 4, 4, 1, 1};
  int tam = sizeof(vetor) / sizeof(int);
  printf("Qtd de subsequencias de nums iguais: %d\n",
         subsequenciasNumsConsecutivos(vetor, tam));
}