#include "head.h"
//线性表基本操作

#define max1 20

typedef struct linklist {
	int data[max1];
	int length;
}linklist;

void init(linklist* L)
{
	int n;
	for (n = 0; n < max1; n++)
		L->data[n] = 0;
	L->length = 0;

}

void insert(linklist* L)//插入元素
{
	int n = 0;
	for (n = 0; n < max1; n++)
	{
		L->data[n] = n;
		L->length++;
	}

}

void turn1(linklist* L);

int main()
{
	linklist L;
	init(&L);
	insert(&L);
	turn1(&L);



	return 0;
}

void turn1(linklist* L)
{
	int n = max1 - 1;
	int x;//middle value
	for (; n > (max1 / 2 - 1); n--)
	{
		x = L->data[n];
		L->data[n] = L->data[max1 - 1 - n];
		L->data[max1 - 1 - n] = x;
	}


	for (n = 0; n < max1; n++)
		printf("%d\n", L->data[n]);


}
