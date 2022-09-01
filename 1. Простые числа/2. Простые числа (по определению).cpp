#include<stdio.h>
#include <math.h>
int main() {
  int n, f = 0, i, j;
  scanf("%d", &n);
  if ((n >= 2) && (n <= 1000000)) {
    for (j = 2; j <= n; j++) {
      for (i = 2; i <= sqrt(j); i++) {
        if (j % i == 0) {
          f = 1;
          break;
        } else
          f = 0;
      }
      if (f == 0) {
        printf("%d ", j);
      }
    }
  }
}