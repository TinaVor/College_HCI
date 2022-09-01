#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <iostream>

using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  int N, K, t1, t2;
  cin >> N >> K;
  int** arr1 = (int**)malloc((N + 1) * sizeof(int*));
  int* arr2 = (int*)malloc(N * sizeof(int));
  for (int i = 0; i <= N; i++) arr1[i] = (int*)malloc(K * sizeof(int));
  for (int i = 0; i < N; i++) cin >> arr2[i];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      arr1[i][j] = 0;
    }
  }

  for (int j = 0; j < K; j++) {
    if (abs(arr2[0] % K) == j) arr1[0][j] = 1;
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < K; j++) {
      if (arr1[i - 1][j] == 1) {
        t1 = arr2[i];
        t2 = arr2[i];
        t1 = j + (t1 % K);
        t2 = j - (t2 % K);
        if (t1 > (K - 1))
          t1 -= K;
        else if (t1 < 0)
          t1 += K;
        if (t2 < 0)
          t2 += K;
        else if (t2 > (K - 1))
          t2 -= K;
        arr1[i][t1] = 1;
        arr1[i][t2] = 1;
      }
    }
  }
  if (arr1[N - 1][0] == 1)
    cout << "Divisible";
  else
    cout << "Not divisible";
  for (int i = 0; i <= N; i++) free(arr1[i]);
  return 0;
}
