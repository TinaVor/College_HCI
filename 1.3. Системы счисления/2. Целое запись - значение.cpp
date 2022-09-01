#include <iostream>
using namespace std;
int Pered(const char* n, int f) {
  return static_cast<const int>(strtol(n, NULL, f));
}
int main() {
  char n[20];
  int f;
  cin >> f >> n;
  if (f < 2 || f > 16 || n < 0) {
    return 0;
  }

  cout << Pered(n, f);
}