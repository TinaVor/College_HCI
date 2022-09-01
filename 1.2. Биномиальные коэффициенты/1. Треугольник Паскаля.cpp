#include <stdio.h>

void printPascal(int k) {
  unsigned long long mas[67][67];
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == j || j == 0)
        mas[i][j] = 1;
      else
        mas[i][j] = mas[i - 1][j - 1] + mas[i - 1][j];
      printf("%llu ", mas[i][j]);
    }
    printf("\n");
  }
}
int main() {
  int s;
  scanf("%d", &s);
  printPascal(s);
  return 0;
}