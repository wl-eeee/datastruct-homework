#include "head.h"//3和5一样
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
		L->data = 10 - n;
		L->next = head->next;
		head->next = L;
	}
}

void turncopy(Lnode* head)
{
	
	Lnode* Qhead = (Lnode*)malloc(sizeof(Lnode));
	Qhead->data = -1;
	Qhead->next = NULL;
	
	
	Lnode* L = head->next;//L for head Q for down
	while (L != NULL)
	{
		Lnode* Q = (Lnode*)malloc(sizeof(Lnode));
		Q->data = L->data;
		Q->next = Qhead->next;
		Qhead->next = Q;
		L = L->next;
	}
	
	

	Lnode* T = Qhead->next; 
	while (T != NULL)//!!!这个好极了 不要Q->next
	{
		printf("%d\n", T->data);
		T = T->next;
	}
	

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


	turncopy(head);

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
