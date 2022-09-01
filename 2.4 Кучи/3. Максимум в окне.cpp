#include <iostream>
#include <string>
using namespace std;
int main() {
  int l =0, r = 0, n;
  string strok;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  cin >> strok;
  int max = _I32_MIN;
  for (int i = 0; i < n * 2 - 1; i++) {
    if (strok[i] == 'R') {
      r++;
      if (arr[r - 1] > max) max = arr[r - 1];
    } else if (strok[i] == 'L') {
      if (arr[l] == max) {
        l++;
        max = _I32_MIN;
        for (int j = l; j < r; j++) {
          if (arr[j] > max) max = arr[j];
        }
      } else
        l++;
    }
    cout << max << '\n';
  }
}