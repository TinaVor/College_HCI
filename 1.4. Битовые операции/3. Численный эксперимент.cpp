#include <iostream>
using namespace std;

int main() {
  int c;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> c;
    int t = 0;
    for (int j = 0; j < 32; j++) {
      if ((c & (1 << j)) == 0)
        t=t+1;
      else
        break;
    }
    cout << (1 << t) << endl;
  }
  return 0;
}