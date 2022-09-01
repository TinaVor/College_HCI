#include <iostream>
using namespace std;
typedef int bitword;
bitword Arr[312501];

void bitsetZero(bitword* arr, int num);
int bitsetGet(const bitword* arr, int idx);
void bitsetSet(bitword* arr, int idx, int newval);
int bitsetAny(const bitword* arr, int left, int right);

int main() {
  int n, c;
  int ar1, ar2;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c == 0) {
      cin >> ar1;
      bitsetZero(Arr, ar1);
    }
    if (c == 1) {
      cin >> ar1;
      cout << bitsetGet(Arr, ar1) << endl;
    }
    if (c == 2) {
      cin >> ar1 >> ar2;
      bitsetSet(Arr, ar1, ar2);
    }
    if (c == 3) {
      cin >> ar1 >> ar2;
      if (bitsetAny(Arr, ar1, ar2) == 0)
        cout << "none" << endl;
      else
        cout << "some" << endl;
    }
  }

  return 0;
}

void bitsetZero(bitword* arr, int num) {
  int i_last = num / 32;
  for (int i = 0; i <= i_last; i++) {
    arr[i] = 0;
  }
}

int bitsetGet(const bitword* arr, int idx) {
  int int_1 = idx / 32;
  int bit_2 = idx % 32;
  int res = 0;
  res = ((arr[int_1] & (1 << bit_2)) != 0);
  return res;
}

void bitsetSet(bitword* arr, int idx, int newval) {
  int int_1 = idx / 32;
  int bit_2 = idx % 32;
  if (newval)
    arr[int_1] = ((arr[int_1] | (1 << bit_2)));
  else
    arr[int_1] = ((arr[int_1] & ~(1 << bit_2)));
}

int bitsetAny(const bitword* arr, int left, int right) {
  int left1 = left / 32;
  int right1 = right / 32;

  if (left1 != right1) {
    for (int i = (left % 32); i < 32; i++) {
      if ((arr[left1] & (1 << i)) != 0) return 1;
    }
    for (int i = left1 + 1; i < right1; i++) {
      if (arr[i] != 0) return 1;
    }
    for (int i = 0; i < (right % 32); i++) {
      if ((arr[right1] & (1 << i)) != 0) return 1;
    }
  } else {
    for (int i = (left % 32); i < (right % 32); i++) {
      if ((arr[left1] & (1 << i)) != 0) return 1;
    }
  }

  return 0;
}
