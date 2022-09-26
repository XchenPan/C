#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct 
{
    int* data;
    int length;
    int capacity;
}SepList;
//创建顺序表
SepList* SL_create(int capacitylength)
{
    SepList* slist = (SepList*)malloc(sizeof(SepList));
    slist->data = (int*)malloc(sizeof(int)*capacitylength);
    slist->capacity = capacitylength;
    slist->length = 0;
    return slist;
}
//删除顺序表
void SL_Free(SepList* slist)
{
    free(slist->data);
    free(slist);
}
//初始化顺序表
void SL_MakeEmpty(SepList* slist)
{
    slist->length = 0;
}
//获取长度
int SL_Length(SepList* slist)
{
    return slist->length; 
}
//输入元素
void SL_Make(SepList* slist, int n)
{
    int i, j;
 	for(i = 0; i < n; i++)
 	{
 		scanf("%d",&j);
 		slist->data[i]=j;
	 }
	 slist->length=n;
}
int DeleteMin(SepList* slist)
{
    int i, j, temp, min;
    min = slist->data[0];
    for(i = 0; i < slist->length; i++)
    {
        if(slist->data[i] <= min)
        {
            min = slist->data[i];
            temp = i;
        }   
    }
    for(j=temp; j <= slist->length; ++j)
	{
		slist->data[j] = slist->data[j+1];
	}	
	slist->length--;
    return min;
}
//逆置
void ReverseList(SepList* slist)
{
    int temp;
    for(int i = 0; i < slist->length / 2; i++)
    {
        temp = slist->data[i];
        slist->data[i] = slist->data[slist->length - 1 - i];
        slist->data[slist->length - 1 - i] = temp;
    }
}
//打印顺序表
void printlist(SepList* slist)
{
	int i=0;
	while(i < slist->length )
	{
		printf("%d ",slist->data[i]);
		++i;
	}
}
void main()
{
    SepList* slist = SL_create(MAX);
    int n, m;
	printf("请输入数据元素的个数：\n");
	scanf("%d",&n);
	printf("请向顺序表中输入元素：\n");
    SL_Make(slist, n);
    // printlist(slist);
    // printf("\n");
    // m = DeleteMin(slist);
    // printlist(slist);
    printf("\n");
    // printf("min is %d\n",m);
    ReverseList(slist);
    printlist(slist);
}