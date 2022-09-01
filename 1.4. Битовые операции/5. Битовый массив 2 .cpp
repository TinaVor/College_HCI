#include <iostream>
using namespace std;
typedef int bitword;
bitword a[312501];
void bitsetZero(bitword* arr, int num);
int bitsetGet(const bitword* arr, int idx);
void bitsetSet(bitword* arr, int idx, int newval);
int bitsetAny(const bitword* arr, int left, int right);

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
  int left_int = left / 32;
  int right_int = right / 32;

  if (left_int != right_int) {
    for (int i = (left % 32); i < 32; i++) {
      if ((arr[left_int] & (1 << i)) != 0) return 1;
    }
    for (int i = left_int + 1; i < right_int; i++) {
      if (arr[i] != 0) return 1;
    }
    for (int i = 0; i < (right % 32); i++) {
      if ((arr[right_int] & (1 << i)) != 0) return 1;
    }
  } else {
    for (int i = (left % 32); i < (right % 32); i++) {
      if ((arr[left_int] & (1 << i)) != 0) return 1;
    }
  }
}

int main() {
  int n, t;
  cin >> n >> t;
  bitsetZero(a, n * 32);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int bt, c;
  for (int i = 0; i < t; i++) {
    cin >> bt >> c;
    c = (((c / 32) + 1) * 32 - 1) - (c - 32 * (c / 32));
    bitsetSet(a, c, bt);
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}