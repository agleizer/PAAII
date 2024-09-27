#include <stdbool.h>
#include <stdio.h>


void printArray(int array[], int size) {
  printf("[ ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("]\n");
}

void ordenarBack(int s[], int v[], bool used[], int tam, int i) {
  if (i == tam) {
    printArray(s, tam);
    return;
  } else {
    for (int j = 0; j < tam; j++) {
      if (!used[j] && (i == 0 || v[j] > s[i - 1])) {
        s[i] = v[j];
        used[j] = true;
        ordenarBack(s, v, used, tam, i + 1);
        used[j] = false; // backtrack
        s[i] = 0;        // optional: reset the element (for clarity)
      }
    }
  }
}

int main() {
  int v[] = {6, 4, 2, 1};
  int s[4];
  bool used[4] = {false}; // initially, no elements are used
  ordenarBack(s, v, used, 4, 0);
}
