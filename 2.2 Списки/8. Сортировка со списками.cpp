#include <malloc.h>
#include <stdio.h>


typedef struct list {
  char str[9];
  struct list* next;
  struct list* prev;
} List;

List* create_List(char* str) {
  List* p = (List*)malloc(sizeof(List));
  sscanf(str, "%s", p->str);
  p->next = NULL;
  p->prev = NULL;
  return p;
}

List* next_List(List* list, char* str) {
  List* temp = (List*)malloc(sizeof(List));
  List* p = list->next;
  list->next = temp;
  sscanf(str, "%s", temp->str);
  temp->next = p;
  temp->prev = list;
  if (p != NULL) p->prev = temp;
  return (temp);
}
void back_List(List** list, char* str) {
  List* p = create_List(str);
  List* temp = *list;
  while (temp->next != NULL) temp = temp->next;
  temp->next = p;
}
void print_list(List* list, int i) {
  if (list->next == NULL) return;
  List* p = list->next;
  while (p->next != NULL) p = p->next;
  do {
    if (*(p->str) == '0') return;
    printf("%d %s\n", i, p->str);
    p = p->prev;
  } while (p != NULL);
}
int main() {
  freopen("input.txt", "r", stdin);
  int N, temp;
  char arr[9] = {'0'};
  List **Node = (List **)malloc(1000001 * sizeof(List *)), *p;
  for (int i = 0; i < 1000001; i++) Node[i] = create_List(arr);

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &temp);
    scanf("%s", arr);
    p = Node[temp];
    p = next_List(p, arr);
  }
  for (int i = 0; i < 1000001; i++) {
    p = Node[i];
    if (p != NULL) {
      print_list(p, i);
    }
    while (p != NULL) {
      List* Del = p;
      p = p->next;
    }
  }
  return 0;
}