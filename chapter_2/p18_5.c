#include "head.h"

// 第四题和第五题一样 不需要用有序检测

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

	for (n = 0; n < max1; n++)
		printf("%d ", L->data[n]);
	printf("\n");

}
void deletex(linklist* L, int s, int t);

int main()
{
	linklist L;
	init(&L);
	insert(&L);
	deletex(&L, 12,18);


	return 0;
}

void deletex(linklist* L, int s,int t)//s = 12 t = 15 the vlaue to be deleted
{

	if (!(s < t))
	{
		printf("error");
		exit(-1);
	}
	int n = 0;
	int q = 0;//辅助中间值
	for (n = 0; n < max1; n++)
	{
		if (L->data[n] >= s && L->data[n] <= t)
		{
			q = n;
			for (; q < max1 - 1; q++)
				L->data[q] = L->data[q + 1];
			L->length--;
			n--;//！！！因为前移了 需要重复检测一个地方 直到这个地方满足要求
		}
		
	}

	for (n = 0; n < max1; n++)
		printf("%d ", L->data[n]);
	printf("\n");
	printf("l.length%d\n", L->length);
}
