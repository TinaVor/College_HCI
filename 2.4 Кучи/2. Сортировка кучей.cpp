#include <stdio.h>
#include <string.h>
#include <malloc.h>


typedef struct heap {
  int* arr;
  int size;
} Heap;

void obmen(int& i1, int& i2) {
  int temp = i1;
  i1 = i2;
  i2 = temp;
}

void por(int* a, int i, int n) {
  int r;
  while (2 * i <= n) {
    r = 2 * i;
    if (r + 1 <= n && a[r] < a[r + 1]) r++;
    if (a[i] < a[r]) {
      obmen(a[i], a[r]);
      i = r;
    } else
      return;
  }
}
void sort(Heap* Heaps) {
  for (int i = Heaps->size / 2; i >= 0; i--) {
    por(Heaps->arr, i, Heaps->size - 1);
  }
  for (int i = Heaps->size - 1; i >= 1; i--) {
    obmen(Heaps->arr[0], Heaps->arr[i]);
    por(Heaps->arr, 0, i - 1);
  }
}
int* creatMall(int Size) {
  int* arr;
  arr = (int*)malloc(Size * sizeof(int));
  return arr;
}

int main() {
  int N;
  Heap Heaps;
  FILE *fileR = NULL, *fileW = NULL;
  fileR = fopen("input.bin", "rb");
  fileW = fopen("output.bin", "wb");
  fread(&N, sizeof(int), 1, fileR);
  Heaps.arr = creatMall(N);
  Heaps.size = N;
  for (int i = 0; i < N; i++) {
    fread(&Heaps.arr[i], sizeof(int), 1, fileR);
  }
  sort(&Heaps);

  for (int i = 0; i < N; i++) {
    printf("%d\n", Heaps.arr[i]);
    fwrite(&Heaps.arr[i], sizeof(int), 1, fileW);
  }
  free(Heaps.arr);
}