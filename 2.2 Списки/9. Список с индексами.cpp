#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

struct List {
  int value;
  List* next;
  List* next_big;
  int distan;
};

void out_list(List* hd) {
  List* list = hd;
  while (list != nullptr) {
    cout << list->value << ":" << list->distan << " ";
    list = list->next;
  }
  cout << endl;
}

List* create_list(int data) {
  List* t = (List*)malloc(sizeof(List));
  t->value = data;
  t->next = nullptr;
  t->distan = 0;
  t->next_big = nullptr;
  return t;
}

void add_element(List** hd, int index, int data);

void print_list(List* head, int index);

void clear_list(List* hd) {
  List* temp;
  List* list = hd;
  while (list != nullptr) {
    temp = list;
    list = list->next;
    free(temp);
  }
}

int main() {
  srand((unsigned)time(NULL));
  int n;
  cin >> n;
  int tip = 0, indx = 0, num = 0;
  cin >> tip >> indx >> num;
  List* head = create_list(num);
  for (int i = 1; i < n; i++) {
    cin >> tip;
    switch (tip) {
      case 0:
        cin >> indx >> num;
        add_element(&head, indx, num);
        break;
      case 1:
        cin >> indx;
        print_list(head, indx);
        break;
    }
  }
  return 0;
}

void add_element(List** hd, int index, int data) {
  List* p = (List*)malloc(sizeof(List));
  p->value = data;
  p->next = nullptr;
  bool is_big = (rand() % 100 == 99) ? true : false;
  if (index == 0) {
    if (is_big) {
      p->next_big = *hd;
      p->distan = 1;
    } else {
      p->next_big = (*hd)->next_big;
      p->distan = (*hd)->distan + 1;
      (*hd)->distan = -1;
    }
    p->next = (*hd);
    (*hd) = p;
    return;
  }
  int c_ind = 0;
  List* list = (*hd);
  List* p_big = (*hd);
  while (c_ind + list->distan <= index && list->next_big != nullptr) {
    c_ind += list->distan;
    p_big = list;
    list = list->next_big;
  }
  List* cur_big = list;
  c_ind = index - c_ind;
  for (int j = 1; j < c_ind; ++j) {
    list = list->next;
  }
  if (c_ind == 0) {
    list = p_big;
    for (int j = 1; j < p_big->distan; ++j) {
      list = list->next;
    }
    if (is_big) {
      p->distan = 1;
      p->next_big = cur_big;
      p_big->next_big = p;
    } else {
      p_big->distan++;
      p->distan = -1;
    }
    p->next = cur_big;
    list->next = p;
    return;
  }

  if (is_big) {
    if (cur_big->next_big != nullptr) {
      p->next_big = cur_big->next_big;
      p->distan = cur_big->distan - c_ind + 1;
    } else {
      p->distan = 0;
      p->next_big = nullptr;
    }
    cur_big->next_big = p;
    cur_big->distan = c_ind;
  } else {
    p->distan = -1;
    cur_big->distan++;
  }
  p->next = list->next;
  list->next = p;
}

void print_list(List* hd, int index) {
  int cur_ind = 0;
  List* list = hd;
  while (cur_ind + list->distan <= index && list->next_big != nullptr) {
    cur_ind += list->distan;
    list = list->next_big;
  }
  cur_ind = index - cur_ind;
  for (int j = 0; j < cur_ind; j++) {
    list = list->next;
  }
  cout << list->value << endl;
}