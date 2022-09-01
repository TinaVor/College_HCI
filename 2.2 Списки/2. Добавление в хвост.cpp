#include <stdio.h>
#include <malloc.h>

typedef struct list {
  int data;
  struct list* next;
} List;

List* create_list(int Data) {
  List* p = (List*)malloc(sizeof(List));
  p->data = Data;
  p->next = NULL;
  return p;
}

void last_List(List** list, int Data) {
  List* p = create_list(Data);
  List* temp = *list;
  while (temp->next != NULL) temp = temp->next;
  temp->next = p;
}

int main() {
  freopen("input.txt", "r", stdin);
  int n, count = 0, i = 0;
  scanf("%d", &n);
  List* N = create_list(n);
  while (scanf("%d", &n) != EOF) last_List(&N, n);

  while (N != NULL) {
    count += N->data;
    i++;
    N = N->next;
  }
  printf("%d", count / i);
  while (N != NULL) {
    List* Del = N;
    N = N->next;
    free(Del);
  }
  return 0;
}