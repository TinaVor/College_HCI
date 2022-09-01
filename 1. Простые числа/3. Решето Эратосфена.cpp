#include<stdio.h>
#include <math.h>
int main() {
  int x, y;
  scanf("%d", &x);
  for (int j = 2; j <= x; j++) {
    y = 0;
    for (int i = 2; i * i <= j; i++) {
      if (j % i == 0) {
        y = y + 1;
        break;
      }
    }
    if (y == 0 && j != 1) {
      printf("%d ", j);
    }
  }
}