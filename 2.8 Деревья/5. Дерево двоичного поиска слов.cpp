#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Tree {
  char Data[101];
  Tree* Right;
  Tree* Left;
};
void InfixPrint(Tree* tree) {
  if (tree != NULL) {
    InfixPrint(tree->Left);
    printf("%s\n", tree->Data);
    InfixPrint(tree->Right);
  }
}
void NextTreePrint(Tree* tree) {
  if (tree != NULL) {
    printf("%s ", tree->Data);
    NextTreePrint(tree->Left);
    NextTreePrint(tree->Right);
  }
}
void BackTreePrint(Tree* tree) {
  if (tree != NULL) {
    BackTreePrint(tree->Left);
    BackTreePrint(tree->Right);
    printf("%s ", tree->Data);
  }
}
void LeavesPrint(Tree* tree, int& yroven) {
  if (tree->Left != NULL && tree->Right != NULL) {
    LeavesPrint(tree->Left, yroven);
    LeavesPrint(tree->Right, yroven);
  } else
    yroven++;
}
void DeleteTree(Tree* tree) {
  if (tree != NULL) {
    DeleteTree(tree->Left);
    DeleteTree(tree->Right);
    free(tree);
  }
}
Tree* AddTree(Tree* tree, char* temp) {
  if (tree == NULL) {
    tree = (Tree*)malloc(sizeof(Tree));
    strcpy(tree->Data, temp);
    tree->Left = NULL;
    tree->Right = NULL;
  } else if (strcmp(temp, tree->Data) < 0 && strcmp(temp, tree->Data) != 0)
    tree->Left = AddTree(tree->Left, temp);
  else if (strcmp(temp, tree->Data) > 0 && strcmp(temp, tree->Data) != 0)
    tree->Right = AddTree(tree->Right, temp);
  return tree;
}
int main() {
  freopen("input.txt", "r", stdin);
  char N[101];
  Tree* tree = NULL;
  while (scanf("%s", &N) != EOF) tree = AddTree(tree, N);
  InfixPrint(tree);
  DeleteTree(tree);
  return 0;
}