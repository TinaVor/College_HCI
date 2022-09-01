#include <iostream>
using namespace std;
void permut_to_invtab(int a[], int b[], int n) {
  int k = 0, h = 0;
  for (int i = 0, f = 1; i < n; i++, f++) {
    int l = 0; h = 0;
    if (a[0] == f) {
      int l = 0;
    } else {
      while (a[h] != f) {
        if (a[h] > f) {
          l++;
        }
        h++;
      }
    }
    b[i] = l;
    cout << b[i] << " ";
  }
}
int main() {
  int a[1000], b[1000], n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  permut_to_invtab(a, b, n);
}