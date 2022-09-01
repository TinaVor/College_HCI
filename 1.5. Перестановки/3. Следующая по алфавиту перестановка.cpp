#include <iostream>
using namespace std;

void next_permut(int a[], int n) {
  int num = 0;
  int w = 0;
  int p = -1;

  for (int i = n - 1; i > 0; i--) {
    if (a[i - 1] < a[i]) {
      p = i - 1;
      break;
    }
  }
  if (p != -1) {
    for (int i = p; i < n; i++) {
      if (a[p] < a[i]) {
        w = i;
      }
    }
    num = a[p];
    a[p] = a[w];
    a[w] = num;
  }
  for (int i = p + 1; i < (n + p + 1) / 2; i++) {
    int h = i, hh = n - i + p;
    num = a[h];
    a[h] = a[hh];
    a[hh] = num;
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

int main() {
  int a[1000], n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  next_permut(a, n);
}