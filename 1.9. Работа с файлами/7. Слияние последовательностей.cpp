#include <stdio.h>
#include <math.h>
void merge(const int* a, int ak, const int* b, int bk, int* res) {
  int i = 0, j = 0, k = 0, x;
  while ((i < ak) || (j < bk)) {
    if (i == ak)
      x = b[j++];
    else if (j == bk)
      x = a[i++];
    else if (a[i] < b[j])
      x = a[i++];
    else
      x = b[j++];
    res[k++] = x;
  }
}
int main() {
  long signed N = 0, M = 0;
  FILE* fileR = NULL;
  FILE* fileW = NULL;
  fileR = fopen("input.bin", "rb");
  fileW = fopen("output.bin", "wb");
  fread(&N, sizeof(int), 1, fileR);
  fread(&M, sizeof(int), 1, fileR);
  int* array = new int[N]();
  int* brray = new int[M]();
  int* res = new int[N + M]();
  for (int i = 0; i < N; i++) fread(&array[i], sizeof(int), 1, fileR);
  for (int i = 0; i < M; i++) fread(&brray[i], sizeof(int), 1, fileR);
  merge(array, N, brray, M, res);
  for (int i = 0; i < N + M; i++) {
    fwrite(&res[i], sizeof(int), 1, fileW);
  }
  return 0;
}