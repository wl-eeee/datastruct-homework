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
		L->data[n] = n+10;
		L->length++;
	}
	L->data[5] = 5;
	L->data[10] = 0;
	puts("input sequence:");
	for (n = 0; n < max1; n++)
		printf("%d ", L->data[n]);
	printf("\n");
	printf("input length %d\n", L->length);


}

void deletemin(linklist* L);

int main()
{
	linklist L;
	init(&L);
	insert(&L);

	deletemin(&L);

	int n;
	puts("output sequence:");
	for (n = 0; n < max1; n++)
		printf("%d ", L.data[n]);
	printf("\n");
	printf("output length %d\n", L.length);

	return 0;
}

void deletemin(linklist* L)
{
	int n;//count
	int x = 0;//the min index
	int e = L->data[0];//the min value

	for (n = 1; n < max1; n++)
	{
		if (L->data[n] < e)
		{
			e = L->data[n];
			x = n;
			printf("%d\n", x);
		}
	}

	L->data[x] = L->data[max1 - 1];
	L->length--;

}
