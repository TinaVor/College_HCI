#include <iostream>
#include <math.h>
using namespace std;

bool pr(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
      break;
    }
  }
  return true;
}

int main() {
  int Q, N, n;
   scanf("%d %d", &N, &Q);
  do {
    scanf("%d", &n);
    if (n < N) {
      if (pr(n))
        printf("%d prime\n", n);
      else
        printf("%d not\n", n);
      Q--;
    }
  } while (Q != 0);
  return 0;
}