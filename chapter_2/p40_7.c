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
	//先判断头结点 为了简单 直接采用Lhead->next
	if (Lhead->next ->data >= 2 && Lhead->next->data <= 10)
	{
		Lnode* Lout = Lhead->next;
		Lhead->next = Lhead->next->next;
		free(Lout);
	}

	Lnode *L = Lhead->next;
	while (L->next != NULL)//还是这个条件 不要用其它的判定条件 上一个已经判定过了满足要求 每轮判定的都是L的下一个 
	{
		if (L->next->data >= 2 && L->next->data <= 10)
		{
			Lnode *Lout = L->next;
			L->next = L->next->next;
			free(Lout);
		}
		else
			L = L->next;
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

