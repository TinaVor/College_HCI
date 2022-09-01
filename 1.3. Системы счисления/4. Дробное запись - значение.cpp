#include <string>
#include <iostream>
#include <cmath>
using namespace std;
int syst(string n2);
int main() {
  string n, n2;
  int b;
  int j = 0;
  double P = 0;
  cin >> b >> n;
  if (n == "0") {
    cout << 0;
    return 0;
  }
  for (int i = 2; i < n.length(); i++) {
    j=j+1;
    n2 = n[i];
    P += syst(n2) * pow(b, -j);
  }
  cout.precision(5);
  cout << fixed << P;
  return 0;
}
int syst(string n2) {
  int n;
  if (n2 == "a") {
    n = 10;
  } else if (n2 == "b") {
    n = 11;
  } else if (n2 == "c") {
    n = 12;
  } else if (n2 == "d") {
    n = 13;
  } else if (n2 == "e") {
    n = 14;
  } else if (n2 == "f") {
    n = 15;
  } else {
    n = stoi(n2);
  }
  return n;
}