#include "head.h"
//顺序表基本操作

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
		L->data[n] = n ;
		L->length++;
	}
	
	puts("input sequence:");
	for (n = 0; n < max1; n++)
		printf("%d ", L->data[n]);
	printf("\n");
	printf("input length %d\n", L->length);


}



int main()
{
	linklist L;
	init(&L);
	insert(&L);


	int n;
	puts("output sequence:");
	for (n = 0; n < max1; n++)
		printf("%d ", L.data[n]);
	printf("\n");
	printf("output length %d\n", L.length);

	return 0;
}

