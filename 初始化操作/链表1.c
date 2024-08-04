#include "head.h"
//链表基本操作

typedef struct node {
	int data;
	struct node* next;
}Lnode;

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

	Lnode* Qhead = (Lnode*)malloc(sizeof(Lnode));
	Qhead->data = -1;
	Qhead->next = NULL;

	Lnode* Q = (Lnode*)malloc(sizeof(Lnode));
	Q->data = 0;
	Q->next = NULL;
	Qhead->next = Q;//Q 遍历用    Qin 插入用



	return Qhead;
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



	

	L = function(Lhead);
	L = L->next;
	puts("output sequence");
	while (L != NULL)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	

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
