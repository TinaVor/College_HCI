#include <malloc.h>
#include <stdio.h>

typedef struct list {
  int data;
  struct list* next;
} List;

List* create_List(int Data) {
  List* p = (List*)malloc(sizeof(List));
  p->data = Data;
  p->next = NULL;
  return p;
}
void next_List(List** list, int Data) {
  List* p = create_List(Data);
  p->next = *list;
  *list = p;
}

int main() {
  freopen("input.txt", "r", stdin);
  int n, count = 0;
  scanf("%d", &n);
  List* Node = create_List(n);
  while (scanf("%d", &n) != EOF) next_List(&Node, n);

  while (Node != NULL) {
    if (Node->data % 7 == 0 && Node->data < 0) count++;
    Node = Node->next;
  }
  printf("%d", count);
  while (Node != NULL) {
    List* Del = Node;
    Node = Node->next;
    free(Del);
  }
  return 0;
}