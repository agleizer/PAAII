#include <stdio.h>

int mdcRusso(int x, int y) {
  if (y == 0 || x == 0) {
    return -1;
  }
  if (x == y) {
    return x;
  }
  if (x % 2 == 0) {
    if (y % 2 == 0) {
      return 2 * mdcRusso(x / 2, y / 2);
    } else {
      return mdcRusso(x / 2, y);
    }
  } else { // se x não for par
    if (y % 2 == 0) {
      return mdcRusso(x, y / 2);
    } else {
      if (x > y) {
        return mdcRusso((x - y) / 2, y);
      } else {
        return mdcRusso(x, (y - x) / 2);
      }
    }
  }
}

int main(void) {
  int x, y;
  printf("Informe o valor de x: ");
  scanf("%d", &x);
  printf("Informe o valor de y: ");
  scanf("%d", &y);
  int mdc = mdcRusso(x, y);
  printf("MDC(%d, %d) = %d\n", x, y, mdc);
}