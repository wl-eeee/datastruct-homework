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

	Lhead->next->data = 2;
	Lhead->next->next->data = 3;
	Lhead->next->next->next->data = 3;
	Lhead->next->next->next->next->data = 4;
	Lhead->next->next->next->next->next->data = 5;
	Lhead->next->next->next->next->next->next->data = 6;
	Lhead->next->next->next->next->next->next->next->data = 6;
	Lhead->next->next->next->next->next->next->next->next->data = 6;
	Lhead->next->next->next->next->next->next->next->next->next->data = 7;
}

Lnode* function(Lnode* Lhead)
{

	Lnode* L = (Lnode*)malloc(sizeof(Lnode));
	L = Lhead->next;
	while (L->next != NULL)
	{
		if (L->data == L->next->data)
		{
			Lnode* Qout = (Lnode*)malloc(sizeof(Lnode));
			Qout = L->next;
			L->next = L->next->next;
			free(Qout);
			
		}
		L = L->next;//注意位置
	}




	return Lhead;
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
