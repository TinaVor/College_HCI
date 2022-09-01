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
    List* temp, * p;
    temp = (List*)malloc(sizeof(List));
    p = (*list)->next;  
    (*list)->next = temp; 
    temp->data = Data;  
    temp->next = p;  
}
void next_List(List** list, int Data) {
    List* p = create_List(Data);
    p->next = *list;
    *list = p;
}
void back_List(List** list, int Data) {
    List* p = create_List(Data);
    List* temp = *list;
    while (temp->next != NULL) temp = temp->next;
    temp->next = p;
}
void print(List* lst) {
    List* p = lst;

    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != NULL);
}
int main() {
    freopen("input.txt", "r", stdin);
    int num;
    scanf("%d", &num);
    List* Node = create_List(num), * p;
    int max = num, min = num;
    while (scanf("%d", &num) != EOF) {
        if (num >= max) {
            if (num == max) continue;
            max = num;
            back_List(&Node, num);
       
        }
        else if (num <= min) {
            if (num == min) continue;
            min = num;
            next_List(&Node, num);
            
        }
        else {
            p = Node;
         
            while (p->next->data < num) {
                p = p->next;
                if (p->next->data == num) continue;
               
            }
            if (p->next->data == num) continue;
            add_List(&p, num);
        }
    }

    print(Node);
    while (Node != NULL) {
        List* Del = Node;
        Node = Node->next;
     
    }
    return 0;
}