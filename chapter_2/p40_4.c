#include "head.h"
//链表基本操作

typedef struct node {
	int data;
	struct node* next;
}Lnode;

Lnode* init()
{
	Lnode* head = (Lnode*)malloc(sizeof(Lnode));
	head->data = -1;
	head->next = NULL;


	return head;
}

void insertbefore(Lnode* head)
{
	int n = 0;
	for (; n < 10; n++)
	{
		Lnode* L = (Lnode*)malloc(sizeof(Lnode));
		L->data = 10 - n+10;
		L->next = head->next;
		head->next = L;
		
	}
	head->next->next->next->next->next->data = 5;
}

void deletesmall(Lnode* head)
{
	int small = head->next->data;
	Lnode* L = head->next;
	while (L->next != NULL)
	{
		if ((L->data) < small)
			small = L->data;
		
		L = L->next;
		
	}
	if ((L->data) < small)
		small = L->data;//!!!这是最后一个的检测 不然会少一个
	printf("%d\n", small);

	
	L = head;
	while (L->next->data != small)
		L = L->next;

	Lnode* Q = L->next;//not need use malloc
	L->next =Q->next;
	free(Q);
}



int main()
{
	Lnode* head = init();
	insertbefore(head);

	int n = 0;
	Lnode* L = head->next;
	puts("input sequence");
	while (L->next != NULL)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	printf("%d ", L->data);
	puts("\n");


	deletesmall(head);


	L = head->next;
	puts("output sequence");
	while (L->next != NULL)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	printf("%d ", L->data);


	return 0;
}
