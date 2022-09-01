#include <iostream>
using namespace std;
int main() {
  int n, s = 0;
  cin >> n;
  for (int i = 31; i >= 0; i--) cout << ((n & (1 << i)) != 0);
  cout << endl;

  for (int i = 0; i < 32; i++) {
    if ((n & (1 << i)) != 0) {
      s = (s | (1 << (31 - i)));
    }
  }
  cout << s << endl;
  for (int i = 31; i >= 0; i--) cout << ((s & (1 << i)) != 0);
  cout << endl;
  return 0;
}