
#include <stdio.h>
#include <malloc.h>
#include <string.h>

  typedef struct Tree {
  char Data;
  Tree* Right;
  Tree* Left;
};
void InfixPrint(Tree* tree) {
  if (tree != NULL) {
    InfixPrint(tree->Left);
    printf("%c", tree->Data);
    InfixPrint(tree->Right);
  }
}
void NextTreePrint(Tree* tree) {
  if (tree != NULL) {
    printf("%c", tree->Data);
    NextTreePrint(tree->Left);
    NextTreePrint(tree->Right);
  }
}
void BackTreePrint(Tree* tree) {
  if (tree != NULL) {
    BackTreePrint(tree->Left);
    BackTreePrint(tree->Right);
    printf("%c", tree->Data);
  }
}
void LeavesPrint(Tree* tree, int& Leaves) {
  if (tree->Left != NULL && tree->Right != NULL) {
    LeavesPrint(tree->Left, Leaves);
    LeavesPrint(tree->Right, Leaves);
  } else
    Leaves++;
}
void DeleteTree(Tree* tree) {
  if (tree != NULL) {
    DeleteTree(tree->Left);
    DeleteTree(tree->Right);
    free(tree);
  }
}
Tree* AddTree(Tree* tree, char x) {
  if (tree == NULL) {
    tree = (Tree*)malloc(sizeof(Tree));
    tree->Data = x;
    tree->Left = NULL;
    tree->Right = NULL;
  } else if (x < tree->Data)
    tree->Left = AddTree(tree->Left, x);
  else if (x > tree->Data)
    tree->Right = AddTree(tree->Right, x);
  return tree;
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  char n[100];
  int i = 0;
  Tree* tree = NULL;
  while (scanf("%c", &n[i]) != EOF && i < 100) {
    i++;
  }
  for (int j = i; j >= 0; j--)
    if (n[j] >= 65) tree = AddTree(tree, n[j]);
  NextTreePrint(tree);
  DeleteTree(tree);
  return 0;
}