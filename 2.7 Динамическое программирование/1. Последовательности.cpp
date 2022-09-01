#include <iostream>
#include <vector>
#include <string>
using namespace std;

int kol_str(const int m);

int main() {
  int N;
  cin >> N;
  cout << kol_str(N) << endl;
  return 0;
}
int kol_str(const int n) {
  vector<int> kol(n), vek(n);

  kol[0] = vek[0] = 1;

  for (int i = 1; i < n; i++) {
    kol[i] = kol[i - 1] + vek[i - 1];
    vek[i] = kol[i - 1];
  }
  return kol[n - 1] + vek[n - 1];
}