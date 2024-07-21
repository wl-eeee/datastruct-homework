#include "head.h"

//x = 15
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

	L->data[5] = 15;

}
void deletex(linklist* L,int x);

int main()
{
	linklist L;
	init(&L);
	insert(&L);
	deletex(&L, 15);


	return 0;
}

void deletex(linklist* L,int x)//x = 15 the vlaue to be deleted
{
	int n = 0;
	int t = 0;//辅助中间值
	for (n = 0; n < max1; n++)
	{
		if (L->data[n] == x)
		{
			t = n;
			for (; t < max1-1; t++)
				L->data[t] = L->data[t + 1];
			L->length--;
		}
	}

	for (n = 0; n < max1; n++)
		printf("%d\n", L->data[n]);
	printf("l.length%d\n", L->length);
}
