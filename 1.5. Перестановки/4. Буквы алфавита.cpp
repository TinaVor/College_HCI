#include <iostream>
using namespace std;
void alf(char a[], int n) {
  int m = 0, r = 0, d = -1;
  for (int i = n - 1; i > 0; i--) {
    if (a[i - 1] < a[i]) {
      d = i - 1;
      break;
    }
  }
  if (d != -1) {
    for (int i = d; i < n; i++) {
      if (a[d] < a[i]) {
        r = i;
      }
    }
    m = a[d];
    a[d] = a[r];
    a[r] = m;
  }
  for (int i = d + 1; i < (n + d + 1) / 2; i++) {
    int h = i, hh = n - i + d;
    m = a[h];
    a[h] = a[hh];
    a[hh] = m;
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
int main() {
  char a[1000];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  alf(a, n);
}