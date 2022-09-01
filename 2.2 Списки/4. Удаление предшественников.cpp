
#include <malloc.h>
#include <stdio.h>


typedef struct list {
  int data;
  struct list* next;
  struct list* prev;
} List;

List* create_List(int Data) {
  List* p = (List*)malloc(sizeof(List));
  p->data = Data;
  p->prev = NULL;
  p->next = NULL;
  return p;
}
List* next_List(List* list, int Data) {
  List* temp = (List*)malloc(sizeof(List));
  List* p = list->next;
  list->next = temp;
  temp->data = Data;
  temp->next = p;
  temp->prev = list;
  if (p != NULL) p->prev = temp;
  return (temp);
}
void print(List* list) {
  List* p = list;
  while (p->next != NULL) p = p->next;
  do {
    printf("%d ", p->data);
    p = p->prev;
  } while (p != NULL);
}

List* delete_List(List* list) {
  List *p = list->prev, *n = list->next;
  if (p != NULL) p->next = list->next;
  if (n != NULL) n->prev = list->prev;
  free(list);
  return p;
}

int main() {
  freopen("input.txt", "r", stdin);
  int num, n;
  scanf("%d", &n);
  scanf("%d", &num);
  List* Node = create_List(num);
  while (scanf("%d", &num) != EOF) {
    Node = next_List(Node, num);
  }
  while (Node->next != NULL) Node = Node->next;
  while (Node->prev != NULL) {
    if (Node->prev->data == n)
      Node = delete_List(Node);
    else
      Node = Node->prev;
  }
  while (Node->prev != NULL) Node = Node->prev;
  print(Node);
  List* Del = NULL;
  while (Node->next) {
    Del = Node;
    Node = Node->next;
  }
  return 0;
}