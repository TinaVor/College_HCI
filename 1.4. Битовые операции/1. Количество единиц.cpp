#include <stdio.h>
int main() {
  unsigned int n;
  int i = 0;
  int maxx = 0;
  scanf_s("%d", &n);
  while (n != 0) {
    if (n % 2 == 1) {
      i++;
    } else {
      i = 0;
    }

    if (i > maxx) {
      maxx = i;
    }
    n = n / 2;
  }
  printf("%d ", maxx);
}