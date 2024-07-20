#include "head.h"
//链表基本操作

typedef struct node {
	int data;
	struct node* next;
}Lnode;


Lnode* init()
{
	Lnode* head = (Lnode*)malloc(sizeof(Lnode));
	head -> data = 0;
	head->next = NULL;


	return head;
}

void insertbefore(Lnode* head)
{
	int n = 0;
	for (; n < 10; n++)
	{
		Lnode* L = (Lnode*)malloc(sizeof(Lnode));
		L->data = 10-n;
		L->next = head->next;
		head->next = L;
	}
}

int main()
{
    Lnode* head = init();
	insertbefore(head);

	int n = 0;
	Lnode* L = head->next;
	puts("input sequence");
	for (; n < 10; n++)
	{
		printf("%d ", L->data);
		L = L->next;
	}

	return 0;
}
