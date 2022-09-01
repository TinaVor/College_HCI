#include <string>
#include <iostream>
#include <cmath>
using namespace std;
string choise(int n);
int main() {
  string s2, s;
  int c, N, k, h;
  int ct = 0, l = 0;
  double n;
  string Nn;
  cin >> c >> k;
  cin >> n;
  if (n == 0) {
    cout << 0;
  } else {
    N = int(n);
    if (N != 0) {
      while (N != 0) {
        s += choise(N % c);
        N /= c;
      }
      for (int i = s.length() - 1; i > -1; i--) {
        cout << s[i];
      }
    } else {
      cout << 0;
    }
    if (int(n) != n) {
      cout << ".";
    }
  }
  Nn = to_string(n);
  l = Nn.length() - 1;
  bool gal = true;
  int ii = 0;
  while (gal) {
    s2 = Nn[l];
    if (s2 != "0") {
      gal = false;
    }
    l--;
  }
  while (int(n) != n && ct != k) {
    n -= int(n);
    n *= c;
    h = pow(10, l);
    n = int(n * h + 0.5) / double(h);
    cout << choise(int(n));
    ct++;
  }
  return 0;
}
string choise(int n) {
  string b;
  if (n == 10) {
    b = "a";
  } else if (n == 11) {
    b = "b";
    ;
  } else if (n == 12) {
    b = "c";
  } else if (n == 13) {
    b = "d";
  } else if (n == 14) {
    b = "e";
  } else if (n == 15) {
    b = "f";
  } else {
    b = to_string(n);
  }
  return b;
}