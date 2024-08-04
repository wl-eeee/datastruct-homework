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

	Lhead->next->data = 4;
	Lhead->next->next->data = 3;
	Lhead->next->next->next->data = 2;
	Lhead->next->next->next->next->data = 9;
	Lhead->next->next->next->next->next->data = 5;
	Lhead->next->next->next->next->next->next->data = 2;
    Lhead->next->next->next->next->next->next->next->data = 1;
	Lhead->next->next->next->next->next->next->next->next->data = 8;
	Lhead->next->next->next->next->next->next->next->next->next->data = 7;

}

Lnode * dizeng(Lnode* Lhead)
{
	Lnode* Qhead = (Lnode*)malloc(sizeof(Lnode));
	Qhead -> data = -1;
	Qhead -> next = NULL;

	Lnode* Q = (Lnode*)malloc(sizeof(Lnode));
	Q->data = 0;
	Q->next = NULL;
	Qhead->next = Q;//Q 遍历用 Qin 插入用

	Lnode *L = Lhead->next;
	Q->data = L->data;
	//printf("%d\n", Q->data);
	L = L->next;
	Q = Qhead->next;

	while (L != NULL)//还是按逻辑顺序来写
	{
		if (L->data < Qhead->next->data)//左边界 如果小于头节点的值 直接用头指针进行运算
		{
			//插入
			Lnode* Qin = (Lnode*)malloc(sizeof(Lnode));
			Qin->data = L->data;
			Qin->next = Qhead->next;
			Qhead->next = Qin;
			//printf("%d %d\n", Qhead->next->data, Qhead->next->next->data);
			//重置
			L = L->next;
			Q = Qhead->next;
			
		}
		else
		{
			if (Q->next != NULL)//先判定这个 注意到自己的序列是递增的 所以不需要反复写条件
			{
				if(L->data>Q->data && L->data >Q->next->data)//大于当前且大于下一个
					Q = Q->next;
				else//插入
				{
					Lnode *Qin = (Lnode*)malloc(sizeof(Lnode));
					Qin->data = L->data;
					Qin->next = Q->next;
					Q->next = Qin;

					L = L->next;
					Q = Qhead->next;
				}
			}
			else//右边界 为什么呢 因为 Q->next = NULL 且已经判定过了一定大于当前的Q
			{
				Lnode* Qin = (Lnode*)malloc(sizeof(Lnode));
				Qin->data = L->data;
				Qin->next = NULL;
				Q->next = Qin;

				L = L->next;
				Q = Qhead->next;
			}
		}
		

		

	}


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



	L = dizeng(Lhead);
	L = L->next;
	puts("output sequence");
	while (L != NULL)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	


	return 0;
}
