#define _CRT_SECURE_NO_WARNINGS
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
Tree* AddTree(Tree* tree, int x) {
  if (tree == NULL) {
    tree = (Tree*)malloc(sizeof(Tree));
    tree->Data = x;
    tree->Left = NULL;
    tree->Right = NULL;
  } else if (x < tree->Data && x != tree->Data)
    tree->Left = AddTree(tree->Left, x);
  else if (x > tree->Data && x != tree->Data)
    tree->Right = AddTree(tree->Right, x);
  return (tree);
}
int main() {
  freopen("input.txt", "r", stdin);
  int n;
  Tree* tree = NULL;
  while (scanf("%d", &n) != EOF) tree = AddTree(tree, n);
  NextTreePrint(tree);
  printf("\n");
  BackTreePrint(tree);
  return 0;
}
