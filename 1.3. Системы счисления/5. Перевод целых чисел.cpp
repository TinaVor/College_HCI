#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main() {
  int f;
  int cs;
  char k[65] = {0};
  cin >> f >> cs >> k;
  if (f < 2 || cs > 36) return 0;
  unsigned long long m = 0;
  char* c;
  for (c = k; *c; ++c) m = m * f + *c - (*c > '9' ? 'a' - 10 : '0');
  for (c = k + 64; m; m /= cs )
    if ((*--c = m % cs + 'a' - 10) < 'a') *c += '0' - 'a' + 10;

  cout << c;
}