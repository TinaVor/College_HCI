#include <stdio.h>

double bcd(int n, int k) {
  if (k > n / 2) k = n - k;
  if (k == 1) return n;
  if (k == 0) return 1;
  double r = 1;
  for (int i = 1; i <= k; ++i) {
    r *= n - k + i;
    r /= i;
  }
  return r;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int h;
  int x, x2;
  scanf("%d", &h);
  for (int i = 0; i < h; i++) {
    scanf("%d %d", &x, &x2);
    printf("%0.10g\n", bcd(x, x2));
  }
}