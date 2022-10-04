#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<memory.h>
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
void SL_resize(SepList* slist, int size)
{
    slist->capacity = size;
    int* newdata = (int*)malloc(sizeof(int)* slist->capacity);
    if(slist->data != NULL)
    {
        memcpy(newdata, slist->data, slist->length*sizeof(int));
        SL_Free(slist);
    }
    slist->data = newdata;
}

//置为空表
void SL_MakeEmpty(SepList* slist)
{
    slist->length = 0;
}

//获取长度
int SL_Length(SepList* slist)
{
    return slist->length; 
}

//判断顺序表是否空
bool SL_IsEMpty(SepList* slist)
{
    return 0 == slist->length;
}

//判断顺序表是否满
bool SL_IsFull(SepList* slist)
{
    return slist->length == slist->capacity;
}

//获取顺序表slist的第i个节点数据
//返回第i个结点的值
int SL_GetAt(SepList* slist, int i)
{
    if(i < 0 || i >= slist->length){
        printf("SL_GetAt(): location error when reading elements of the slist!\n");
        SL_Free(slist);
        exit(0);
    }
    else
        return slist->data[i];
}

//设置第i个结点的值（对第i个结点的数据进行写）
void SL_SetAt(SepList* slist, int i, int x)
{
    if(i < 0 || i >= slist->length){
        printf("SL_GetAt(): location error when reading elements of the slist!\n");
        SL_Free(slist);
        exit(0);
    }
    else
        slist->data[i] = x;
}

//追加元素在顺序表表尾
void SL_Append(SepList* slist, int x)
{
    if(slist->length == slist->capacity)
        SL_resize(slist, slist->capacity + slist->capacity*0.1);
    //xxxx

}

//在顺序表的位置i插入结点x,插入d[i]之前
//i的有效范围[0,slist->length]
void SL_InsertAt(SepList* slist, int i, int x)
{
    //xxxx
}

//删除顺序表slist的第i号结点
//i的有效范围[0,slist->length]内，否则会产生异常或错误
//返回被删除的数据元素的值
int SL_DeleteAt(SepList* slist, int i)
{
    int j, t;
    t = slist->data[i];
    if(i < 0 || i >=slist->length)
        return 0;
    else
        for(j =i; j <= slist->length; j++)
            slist->data[j] = slist->data[j+1];
    --slist->length;
    return t;
}

//在顺序表中查找第一个值为x的结点，返回结点的编号
//返回值大于等于0时表示找到值为x的结点的编号，-1表示没有找到
int SL_FindValue(SepList* slist, int x)
{
    /////
}

//删除第一个值为x的结点，
//存在值为x的结点则返回结点编号，为找到返回-1
int SL_DeleteValue(SepList* slist, int x)
{

}

//打印整个顺序表
void SL_output(SepList* slist)
{
    if(slist->length == 0){
        printf("The slist is empty.\n");
        return;
    }
	int i=0;
	while(i < slist->length)
	{
		printf("%d ",slist->data[i]);
		++i;
	}
    printf("\n");
}

void main()
{
    SepList* slist = SL_create(MAX);
    int n, m;
	printf("请输入数据元素的个数：\n");
	scanf("%d",&n);
	printf("请向顺序表中输入元素：\n");
    SL_Input(slist, n);
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
//输入元素
void SL_Input(SepList* slist, int n)
{
    int i, j;
 	for(i = 0; i < n; i++)
 	{
 		scanf("%d",&j);
 		slist->data[i]=j;
	 }
	 slist->length = n;
}
