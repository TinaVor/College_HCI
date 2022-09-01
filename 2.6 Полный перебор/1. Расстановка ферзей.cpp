
#include <stdio.h>
#include <malloc.h>
#include <math.h>

    void
    ferz(int** mass, int x, int y, int N, int M) {
  mass[x][y] = -5;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (mass[i][j] == -1) {
        if (i == x) mass[i][j] = x;
        if (j == y) mass[i][j] = x;
        if (abs(i - x) == abs(j - y)) mass[i][j] = x;
      }
    }
  }
}
void del(int** mass, int x, int y, int N, int M) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (mass[i][j] == x) {
        if (i == x) mass[i][j] = -1;
        if (j == y) mass[i][j] = -1;
        if (abs(i - x) == abs(j - y)) mass[i][j] = -1;
      }
    }
  }
  mass[x][y] = -1;
}
void text(int** mass, int N, int M) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (mass[i][j] == -5)
        printf("X");
      else
        printf(".");
    }
    printf("\n");
  }
}
bool Try(int**mass, int i, int N, int M, bool& prov) {
  for (int k = 0; k < M; k++) {
    if (i < N && mass[i][k] == -1) {
      ferz(mass, i, k, N, M);
      Try(mass, i + 1, N, M, prov);
      if (prov == true) return 1;
      del(mass, i, k, N, M);
    } else if (i >= N) {
      prov = true;
      return 1;
    }
  }
  return 0;
}
int main() {
  freopen("input.txt", "r", stdin);
  int N, M;
  char str;
  bool prov = false;
  scanf("%d %d", &N, &M);
  int** Str = (int**)malloc(N * sizeof(int*));
  for (int i = 0; i < N; i++) Str[i] = (int*)malloc(M * sizeof(int));
  scanf("%c", &str);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%c", &str);
      if (str == '?')
        Str[i][j] = -1;
      else
        Str[i][j] = -2;
    }
    scanf("%c", &str);
  }

  Try(Str, 0, N, M, prov);
  if (prov) {
    printf("YES\n");
    text(Str, N, M);
  } else {
    printf("NO\n");
  }
  for (int i = 0; i < N; i++) free(Str[i]);
  return 0;
}
