
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct Tree {
  int Data;
  Tree* Right;
  Tree* Left;
};
void InfixPrint(Tree* tree, FILE* fileW) {
  if (tree != NULL) {
    InfixPrint(tree->Left, fileW);
    fwrite(&tree->Data, sizeof(int), 1, fileW);
    InfixPrint(tree->Right, fileW);
  }
}
void DeleteTree(Tree* tree) {
  if (tree != NULL) {
    DeleteTree(tree->Left);
    DeleteTree(tree->Right);
    free(tree);
  }
}
Tree* AddTree(Tree* tree, int x) {
  if (tree == NULL) {
    tree = (Tree*)malloc(sizeof(Tree));
    tree->Data = x;
    tree->Left = NULL;
    tree->Right = NULL;
  } else if (x < tree->Data)
    tree->Left = AddTree(tree->Left, x);
  else
    tree->Right = AddTree(tree->Right, x);
  return tree;
}

void torg(int& i1, int& i2) {
  int tmp = i1;
  i1 = i2;
  i2 = tmp;
}
void fun(int* Arr, int i, int n) {
  int r;
  while (2 * i <= n) {
    r = 2 * i;
    if (r + 1 <= n && Arr[r] < Arr[r + 1]) r++;
    if (Arr[i] < Arr[r]) {
      torg(Arr[i], Arr[r]);
      i = r;
    } else
      return;
  }
}
void MeBpoDu(int* Arr, int N) {
  for (int i = N / 2; i >= 0; i--) {
    fun(Arr, i, N - 1);
  }
  for (int i = N - 1; i >= 1; i--) {
    torg(Arr[0], Arr[i]);
    fun(Arr, 0, i - 1);
  }
}
int main() {
  int N, number;
  FILE* fileR = NULL;
  FILE* fileW = NULL;
  fileR = fopen("input.bin", "rb");
  fileW = fopen("output.bin", "wb");
  fread(&N, sizeof(int), 1, fileR);
  Tree* tree = NULL;
  int* Arr = (int*)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    fread(&Arr[i], sizeof(int), 1, fileR);
  }
  MeBpoDu(Arr, N);
  for (int i = 0; i < N; i++) {
    fwrite(&Arr[i], sizeof(int), 1, fileW);
  }
  return 0;
}
