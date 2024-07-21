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
		L->data = 10 - n;
		L->next = head->next;
		head->next = L;
	}
	Lnode* L = (Lnode*)malloc(sizeof(Lnode));
	L->data = 5;
	L->next = head->next;
	head->next = L;
}

void delete1(Lnode* head,int x)
{
	Lnode* p = head;

	while (p->next != NULL)
	{
		
		if (p->next->data == x)
		{
			Lnode* q = p->next;// !!!!!用的时候重新定义 不用就不要定义
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else
		{
			p = p->next;
		}
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


	delete1(head, 5);


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
