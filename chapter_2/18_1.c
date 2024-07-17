#include "head.h"

#define max1 20


typedef struct linklist {
	int data[max1];
	int length;
}linklist;

void init(linklist *L)
{
	int n;
	for (n = 0; n < max1; n++)
		L->data[n] = 0;
	L->length = 0;

}

void insert(linklist *L)//插入元素
{
	int n = 0;
	for (n = 0; n < max1; n++)
	{
		L->data[n] = n+10;
		L->length++;
	}
	L->data[10] = 2;

	for (n = 0; n < max1; n++)
		printf("%d ", L->data[n]);
	printf("\n");

}
int delete1(linklist *L);
int main()
{
	linklist L;
	init(&L);
	insert(&L);
	
	int n = delete1(&L);
	printf("%d\n", n);


	return 0;
}
int delete1(linklist *L)
{
	
	if (L->length == 0)
	{
		printf("error\n");
		exit(-1);
	}

	int n = 1;//count
	int smi = 0;//small data index
	int smv = L->data[0];//small data value
	for (n = 1; n < max1; n++)
	{
		if (L->data[n] < smv) {
			smv = L->data[n];
			smi = n;
			printf("%d\n", smi);
		}
	}
	L->data[smi] = L->data[max1 - 1];
	L->data[max1 - 1] = 0;
	L->length--;

	for (n = 0; n < max1; n++)
		printf("%d ", L->data[n]);
	printf("\n");
	return smv;
}
