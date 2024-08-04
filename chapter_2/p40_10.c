#include "head.h"
//链表基本操作

typedef struct node {
	int data;
	struct node* next;
}Lnode;

typedef struct {
	Lnode* Qhead1;
	Lnode* Qhead2;
}back;

Lnode* init()
{
	Lnode* Lhead = (Lnode*)malloc(sizeof(Lnode));
	Lhead->data = -1;
	Lhead->next = NULL;


	return Lhead;
}

void insertbefore(Lnode* Lhead)
{
	int n = 0;
	for (; n < 10; n++)
	{
		Lnode* L = (Lnode*)malloc(sizeof(Lnode));
		L->data = 10 - n;
		L->next = Lhead->next;
		Lhead->next = L;
	}
}

Lnode* function(Lnode* Lhead)
{
	back* Q = (Lnode*)malloc(sizeof(back) * 2);
	Q->Qhead1 = (Lnode*)malloc(sizeof(Lnode));
	Q->Qhead1->data = -1;
	Q->Qhead1->next = NULL;

	Q->Qhead2 = (Lnode*)malloc(sizeof(Lnode));
	Q->Qhead2->data = -1;
	Q->Qhead2->next = NULL;


	Lnode *L = Lhead->next;

	Lnode* Q1 = (Lnode*)malloc(sizeof(Lnode));
	Q1->data = L->data;
	Q1->next = NULL;
	Q->Qhead1->next = Q1;
	L = L->next;

	Lnode* Q2 = (Lnode*)malloc(sizeof(Lnode));
	Q2->data = L->data;
	Q2->next = NULL;
	Q->Qhead2->next = Q2;
	L = L->next;

	int n = 1;//count
	while (L != NULL)
	{
		if (n % 2 != 0)
		{
			Lnode* Q1in = (Lnode*)malloc(sizeof(Lnode));
			Q1in->data = L->data;
			Q1in->next = NULL;
			Q1->next = Q1in;
			Q1 = Q1->next;

			L = L->next;
			n++;
		}
		else
		{
            Lnode* Q2in = (Lnode*)malloc(sizeof(Lnode));
			Q2in->data = L->data;
            Q2in->next = NULL;
            Q2->next = Q2in;
            Q2 = Q2->next;

			L = L->next;
			n++;

		}
	}




	return Q;
}




int main()
{
	Lnode* Lhead = init();
	insertbefore(Lhead);

	int n = 0;
	Lnode* L = Lhead->next;
	puts("input sequence");
	while (L->next != NULL)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	printf("%d ", L->data);
	puts("\n");



	back* Q = function(Lhead);
	L= Q->Qhead1->next;
	puts("output sequence1");
	while (L != NULL)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	puts("");
	L = Q->Qhead2->next;
	puts("output sequence2");
	while (L != NULL)
	{
		printf("%d ", L->data);
		L = L->next;
	}

	puts("");
	return 0;
}

//如果需要链表是乱序 使用这个插入
/*
Lhead->next->data = 4;
	Lhead->next->next->data = 3;
	Lhead->next->next->next->data = 2;
	Lhead->next->next->next->next->data = 9;
	Lhead->next->next->next->next->next->data = 5;
	Lhead->next->next->next->next->next->next->data = 2;
	Lhead->next->next->next->next->next->next->next->data = 1;
	Lhead->next->next->next->next->next->next->next->next->data = 8;
	Lhead->next->next->next->next->next->next->next->next->next->data = 7;*/
