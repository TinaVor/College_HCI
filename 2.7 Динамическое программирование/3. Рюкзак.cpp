#include <iostream>
#include <fstream>

using namespace std;

void rucksack(int W, int* w, int* V, int N);

int max(int i, int j) {
  int m;
  if (i > j)
    m = i;
  else
    m = j;
  return m;
}

int Rever(int** arr, int I, int J) {
  while (arr[I][J] == arr[I - 1][J] && I != 0) {
    I--;
    if (I == 0) break;
  }
  return I;
}

int main() {
  ifstream inp;
  inp.open("input.txt");
  int N, W;
  inp >> N;
  inp >> W;
  int *cnt, *K;
  cnt = (int*)malloc(N * sizeof(int));
  K = (int*)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    inp >> K[i];
    inp >> cnt[i];
  }
  rucksack(W, K, cnt, N);
  return 0;
}

void rucksack(int W, int* w, int* V, int N) {
  int* total;
  total = (int*)malloc((N + 3) * sizeof(int));
  int** tbl;
  tbl = (int**)malloc((N + 1) * sizeof(int*));
  for (int i = 0; i <= N; i++) {
    tbl[i] = (int*)malloc((W + 1) * sizeof(int));
  }
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= W; j++) {
      if (i == 0 || j == 0) {
        tbl[i][j] = 0;
      } else if (w[i - 1] <= j) {
        tbl[i][j] = max(V[i - 1] + tbl[i - 1][j - w[i - 1]], tbl[i - 1][j]);
      } else {
        tbl[i][j] = tbl[i - 1][j];
      }
    }
  }
  total[1] = 0;
  total[0] = 0;
  total[2] = tbl[N][W];
  int i = N, j = W, kl = 1;
  while (i > 0) {
    i = Rever(tbl, i, j);
    j -= w[i - 1];
    if (i > 0) {
      total[1] += w[i - 1];
      total[0]++;
      total[2 + kl] = i;
      i--;
      kl++;
    }
  }
  cout << total[0] << " " << total[1] << " " << total[2] << endl;
  for (int i = 3; i < 3 + total[0]; i++) {
    if (total[i] != 0) cout << total[i] << " ";
  }
}