#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct heap {
  int* arr;
  int size;
} Heap;

int* creatMall(int Size) {
  int* arr;
  arr = (int*)malloc(Size * sizeof(int));
  return arr;
}
void raspred(Heap* Heaps, int i) {
  int max = i, l = 2 * i, r = 2 * i + 1, temp;
  if (l < Heaps->size && Heaps->arr[l] < Heaps->arr[max]) max = l;
  if (r < Heaps->size && Heaps->arr[r] < Heaps->arr[max]) max = r;

  if (max != i) {
    temp = Heaps->arr[i];
    Heaps->arr[i] = Heaps->arr[max];
    Heaps->arr[max] = temp;
    raspred(Heaps, max);
  }
}
void push(Heap* Heaps, int newNum) {
  int i, parent;
  i = Heaps->size;
  Heaps->arr[i] = newNum;
  parent = i / 2;
  while (parent >= 0 && i > 0) {
    if (Heaps->arr[i] < Heaps->arr[parent]) {
      int tmp = Heaps->arr[i];
      Heaps->arr[i] = Heaps->arr[parent];
      Heaps->arr[parent] = tmp;
    }
    i = parent;
    parent = i / 2;
  }
  Heaps->size++;
}
int pop(Heap* Heaps) {
  int tmp;
  tmp = Heaps->arr[0];
  Heaps->arr[0] = Heaps->arr[Heaps->size - 1];
  Heaps->arr[Heaps->size - 1] = tmp;
  Heaps->size -= 1;
  raspred(Heaps, 0);

  return tmp;
}
void print(Heap Heaps) {
  for (int i = 0; i < Heaps.size; i++) printf("%d ", Heaps.arr[i]);
  printf("\n");
}
int main() {
  freopen("input.txt", "r", stdin);
  int N, numb, Size;
  char text[5];
  scanf("%d", &N);
  Heap Heaps;
  Heaps.arr = creatMall(N);
  Heaps.size = 0;
  for (int i = 0; i < N; i++) {
    scanf("%s", text);
    if (strcmp(text, "push") == 0) {
      scanf("%d", &numb);
      push(&Heaps, numb);
    } else if (strcmp(text, "pop ")) {
      if (Heaps.size == 0) {
        printf("Heap is empty\n");
        continue;
      } else {
        printf("%d\n", pop(&Heaps));
      }
    }
  }
}