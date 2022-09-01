
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
void getListCoint(Tree* tree, int yrov, int& t, int max_yrov) {
  if (tree != NULL) {
    if (yrov == max_yrov) t++;
    yrov++;
    getListCoint(tree->Left, yrov, t, max_yrov);
    getListCoint(tree->Right, yrov, t, max_yrov);
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  int n, t = 0, yrov;
  Tree* tree = NULL;
  scanf("%d", &yrov);
  while (scanf("%d", &n) != EOF) tree = AddTree(tree, n);
  getListCoint(tree, 0, t, yrov);
  printf("%d", t);
  return 0;
}