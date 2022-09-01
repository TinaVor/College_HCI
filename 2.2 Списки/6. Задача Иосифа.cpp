#include <malloc.h>
#include <stdio.h>


typedef struct list {
  int data;
  struct list* next;
  struct list* prev;
} List;

typedef struct s_Dlist {
  int size;
  List* head;
  List* tail;
} DList;

List* create_List(int Data) {
  List* p = (List*)malloc(sizeof(List));
  p->data = Data;
  p->prev = NULL;
  p->next = NULL;
  return p;
}
List* next_List(List* list, DList* Dnode, int Data) {
  List* temp = (List*)malloc(sizeof(List));
  List* p = list->next;
  list->next = temp;
  Dnode->tail = temp;
  Dnode->size++;
  temp->data = Data;
  temp->next = p;
  temp->prev = list;
  if (p != NULL) p->prev = temp;
  return (temp);
}

void print(List* list, DList Dlist) {
  List* p = list;
  while (p->data != 1) p = p->next;
  for (int i = 0; i < Dlist.size; i++) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}
void cycle_list(List* list, DList Dlist, bool pr) {
  List *N = Dlist.head, *K = Dlist.tail;
  if (pr == false) {
    N->prev = K;
    K->next = N;
  } else {
    N->prev = NULL;
    K->next = NULL;
  }
}
List* delete_List(List* list) {
  List *p = list->prev, *n = list->next;
  if (p != NULL) p->next = list->next;
  if (n != NULL) n->prev = list->prev;
  free(list);
  return p;
}
void Joseph(List* list, DList* Dlist, int K) {
  int res = 0;
  for (int i = 2; i <= Dlist->size; i++) {
    res = (res + K) % i;
  }
  printf("%d", res + 1);
}
int main() {
  freopen("input.txt", "r", stdin);
  int N, K, i = 1;
  scanf("%d", &N);
  scanf("%d", &K);
  DList DNode;
  List* Node = create_List(1);
  DNode.size = 1;
  DNode.head = Node;
  DNode.tail = Node;
  for (int j = 2; j <= N; j++) {
    Node = next_List(Node, &DNode, j);
  }
  cycle_list(Node, DNode, false);
  Joseph(Node, &DNode, K);
  cycle_list(Node, DNode, true);
  free(Node);
  return 0;
}