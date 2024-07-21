#include "head.h"
//线性表基本操作

#define max1 20

typedef struct linklist {
	int data[max1];
	int length;
}linklist;

typedef struct linklist2 {
	int data[50];
	int length;
}linklist2;


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
	puts("input sequence:");
	for (n = 0; n < max1; n++)
		printf("%d ", L->data[n]);
	printf("\n");
}

linklist2 merge(linklist *L1, linklist *L2);

int main()
{
	linklist L1;
	init(&L1);
	insert(&L1);
	linklist L2;
	init(&L2);
	insert(&L2);

	merge(&L1, &L2);
	

	return 0;
}

linklist2 merge(linklist *L1, linklist *L2)
{
	linklist2 L3;
	int n;
	for (n = 0; n < max1; n++)
		L3.data[n] = L1->data[n];

	for (n = max1; n < max1 + max1; n++)
		L3.data[n] = L2->data[n - max1];
	for (; n < 50; n++)
		L3.data[n] = 0;

	puts("output sequence:");
	for (n = 0; n < 50; n++)
		printf("%d ", L3.data[n]);
	printf("\n");

	return L3;

}
