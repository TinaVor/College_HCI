#include <stdio.h>
#include <malloc.h>

typedef struct list {
	int data;
	struct list* next;
	struct list* prev;
}List;

List* create_List(int Data) {
	List* p = (List*)malloc(sizeof(List));
	p->data = Data;
	p->prev = NULL;
	p->next = NULL;
	return p;
}
List* next_List(List* list, int Data)
{
	List* temp = (List*)malloc(sizeof(List));
	List* p = list->next;
	list->next = temp; 
	temp->data = Data; 
	temp->next = p; 
	temp->prev = list;
	if (p != NULL)
		p->prev = temp;
	return(temp);
}
void print(List* list){
	List* p = list;
	while (p->prev!=NULL)
		p = p->prev;
	do {
		printf("%d ", p->data); 
		p = p->next;
	} while (p != NULL); 
}

List* del_List(List* list) {
	List* p = list->prev, * n = list->next;
	if (p != NULL)
		p->next = list->next;
	if (n != NULL)
		n->prev = list->prev;
	free(list);
	return p;
}

int main() {
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	List* N = create_List(n);
	while (scanf("%d", &n) != EOF) {
		N = next_List(N, n);
	}
	while (N->prev != NULL)
		N = N->prev;
	while (N->next != NULL){
		if (N->data == N->next->data)
			N = del_List(N->next);
		else
			N = N->next;
	}
	while (N->prev != NULL)
		N = N->prev;
	print(N);
	List* Del = NULL;
	while (N->next) {
		Del = N;
		N = N->next;
	}
	return 0;
}