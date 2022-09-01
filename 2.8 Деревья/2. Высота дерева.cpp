
#include <stdio.h>
#include <malloc.h>

typedef struct Tree {
  int Data;
  Tree* Right;
  Tree* Left;
};

void NextTreePrint(Tree* tree) {
  if (tree != NULL) {
    printf("%d ", tree->Data);
    NextTreePrint(tree->Left);
    NextTreePrint(tree->Right);
  }
}
void BackTreePrint(Tree* tree) {
  if (tree != NULL) {
    BackTreePrint(tree->Left);
    BackTreePrint(tree->Right);
    printf("%d ", tree->Data);
  }
}
Tree* AddTree(Tree* tree, int temp, int& max, int& m) {
  if (tree == NULL) {
    tree = (Tree*)malloc(sizeof(Tree));
    tree->Data = temp;
    tree->Left = NULL;
    tree->Right = NULL;
  } else if (temp < tree->Data && temp != tree->Data) {
    m++;
    tree->Left = AddTree(tree->Left, temp, max, m);
  } else if (temp > tree->Data && temp != tree->Data) {
    m++;
    tree->Right = AddTree(tree->Right, temp, max, m);
  }
  if (max < m) max = m;
  m = 0;
  return (tree);
}
int main() {
  freopen("input.txt", "r", stdin);
  int N, max = 0, m = 0;
  Tree* tree = NULL;
  while (scanf("%d", &N) != EOF) tree = AddTree(tree, N, max, m);
  printf("%d", max);
  return 0;
}
