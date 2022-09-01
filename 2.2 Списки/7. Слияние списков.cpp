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
void add_List(List** list, int Data) {
  List *temp, *p;
  temp = (List*)malloc(sizeof(List));
  p = (*list)->next;  // сохранение указателя на следующий узел
  (*list)->next = temp;  // предыдущий узел указывает на создаваемый
  temp->data = Data;  // сохранение поля данных добавляемого узла
  temp->next = p;  // созданный узел указывает на следующий элемент
}
void next_List(List** list, int Data) {
  List* p = create_List(Data);
  p->next = *list;
  *list = p;
}
void back_List(List** list, int Data) {
  List* p = create_List(Data);
  List* tmp = *list;
  while (tmp->next != NULL) tmp = tmp->next;
  tmp->next = p;
}
void print(List* lst) {
  List* p = lst;
  do {
    printf("%d ", p->data);
    p = p->next;
  } while (p != NULL);
  printf("\n");
}
void delete_Node(List* list) {
  while (list != NULL) {
    List* Del = list;
    list = list->next;
    free(Del);
  }
}
int maxi(List* list) {
  List* max = list;
  while (max->next != NULL) max = max->next;
  return max->data;
}
List* sort(List* list1, List* list2) {
  List *p = list1, *temp = list2, *h;
  int max = p->data, min = maxi(p);
  while (temp != NULL) {
    if (temp->data >= max) {
      max = temp->data;
      next_List(&p, temp->data);
    } else if (temp->data <= min) {
      min = temp->data;
      back_List(&p, temp->data);
    } else {
      h = p;
      while (h->next->data > temp->data) {
        h = h->next;
      }
      add_List(&h, temp->data);
    }

    temp = temp->next;
  }
  return p;
}
int main() {
  freopen("input.txt", "r", stdin);
  int size_A, size_B, N;
  scanf("%d", &size_A);
  scanf("%d", &size_B);
  scanf("%d", &N);
  List* Node_A = create_List(N);
  for (int i = 1; i < size_A; i++) {
    scanf("%d", &N);
    next_List(&Node_A, N);
  }
  scanf("%d", &N);
  List* Node_B = create_List(N);
  for (int i = 1; i < size_B; i++) {
    scanf("%d", &N);
    next_List(&Node_B, N);
  }
  if (size_A > size_B) {
    Node_A = sort(Node_A, Node_B);
    print(Node_A);
  } else {
    Node_B = sort(Node_B, Node_A);
    print(Node_B);
  }
  delete_Node(Node_A);
  delete_Node(Node_B);
  return 0;
}