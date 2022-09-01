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
Tree* AddTree(Tree* tree, int temp) {
  if (tree == NULL) {
    tree = (Tree*)malloc(sizeof(Tree));
    tree->Data = temp;
    tree->Left = NULL;
    tree->Right = NULL;
  } else if (temp < tree->Data) {
    tree->Left = AddTree(tree->Left, temp);
  } else if (temp > tree->Data) {
    tree->Right = AddTree(tree->Right, temp);
  }
  return (tree);
}
void LeavesPrint(Tree* tree, int& t) {
  if (tree != NULL) {
    if (tree->Left == NULL && tree->Right == NULL) t++;
    LeavesPrint(tree->Left, t);
    LeavesPrint(tree->Right, t);
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  int N, t = 0;
  Tree* tree = NULL;
  while (scanf("%d", &N) != EOF) tree = AddTree(tree, N);
  LeavesPrint(tree, t);
  printf("%d", t);
  return 0;
}