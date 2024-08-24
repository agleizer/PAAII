#include <stdio.h>

int coefBinomial(int n, int m) {
  if (n == m || m == 0) {
    return 1;
  }
  return coefBinomial(n-1, m) + coefBinomial(n-1, m-1);
}

int main(void) {
  int n,m;
  printf("Informe o valor de n: ");
  scanf("%d", &n);
  printf("Informe o valor de m: ");
  scanf("%d", &m);
  int coef = coefBinomial(n, m);
  printf("Coeficiente binomial(%d %d) = %d\n", n, m, coef);
}