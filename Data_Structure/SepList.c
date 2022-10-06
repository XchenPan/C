#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<memory.h>
#include <time.h>
#include <assert.h>
#define MAX 110

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

//扩容
void SL_resize(SepList* slist)
{
    assert(slist->data != NULL);
    slist->data = (int*)realloc(slist->data , slist->capacity * 2 * sizeof(int));//(内存块泄露)
    assert(slist->data != NULL);
    slist->capacity *= 2;
}

void SL_resize_N(SepList* slist, int size)
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
    if(slist->length == slist->capacity)//元素满了，需要先扩容
        SL_resize(slist);
    slist->data[slist->length] = x;
    ++slist->length;
}

//在顺序表的位置i插入结点x,插入d[i]之前
//i的有效范围[0,slist->length]
void SL_InsertAt(SepList* slist, int i, int x)
{
    int j;
    for( j = slist->length; j >= i; j--)
        slist->data[j] = slist->data[j - 1];
    slist->data[i] = x;
    ++slist->length;
}

//删除顺序表slist的第i号结点
//i的有效范围[0,slist->length)内，否则会产生异常或错误
//返回被删除的数据元素的值
int SL_DeleteAt(SepList* slist, int i)
{
    int j, t;
    t = slist->data[i];
    if(i < 0 || i > slist->length)
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
    int i, t;
    for(i = 0; i < slist->length; i++){
        if(slist->data[i] == x){
            t = i;break;
        }
        else
            t = -1;
    }
    return t;
}

//删除第一个值为x的结点，
//存在值为x的结点则返回结点编号，未找到返回-1
int SL_DeleteValue(SepList* slist, int x)
{
    int i, j, t;
    for(i = 0; i < slist->length; i++){
        if(slist->data[i] == x){
            t = i;
            break;
        }
        else
            t = -1;
    }
    for(j = t; j <= slist->length; j++)
            slist->data[j] = slist->data[j+1];
    --slist->length;
    return t;
}

//给顺序表输入初始元素
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

//拓展-随机数存入顺序表
//
//随机生成 100 个整数存入一个顺序表,整数范围在[100,200)之间,然后去掉其
//中的重复元素(重复的仅保留第一个),最后输出表中所有元素。
void SL_Random_2(SepList* slist)
{
    srand((int)time(NULL));
    for(int i =0; i < 100; i++)
    {
        slist->data[i] = rand() % 100 + 100;
        slist->length++;
    }
    SL_output(slist);
    for(int j = 0; j < slist->length; j++)
        for(int k = j + 1,t = slist->length; k < t; k++)
            if(slist->data[j] == slist->data[k])
                SL_DeleteAt(slist, k);
    SL_output(slist);
}

//随机生成 20 个整数存入一个顺序表,整数范围在[1,200)之间,然后在第一个素
//数后插入 1 个 0,第二个素数后插入 2 个 0,以此类推,最后输出表中所有元素。
void SL_Random_3(SepList* slist)
{
    srand((int)time(NULL));
    for(int i = 0; i < 20 ; i++)
    {
        slist->data[i] = rand() % 200 + 1;
        slist->length++;
    }       
    for(int j = 0,n = 2; j < 230;  j = j + n++)                 //n+n*(n+1)/2
        for(int k = 0, l = j + 1; k < n - 1; k++,l++)
        {
            SL_InsertAt(slist, l, 0);
            if(slist->length == slist->capacity)//元素满了，需要先扩容
                SL_resize(slist);
        }
    SL_output(slist);
}

void main()
{
    SepList* slist = SL_create(MAX);
    // int a, b, c, d, e, f;
    // printf("请输入数据元素的个数：\n");
	// scanf("%d",&a);
	// printf("请向顺序表中输入元素：\n");
    // SL_Input(slist, a);
    // printf("最初的顺序表：\n");
    // SL_output(slist);
    // printf("请输入需要插入的位置和元素：\n");
    // scanf("%d %d", &b, &c);
    // SL_InsertAt(slist, b, c);
    // printf("插入元素后顺序表：\n");
    // SL_output(slist);
    // printf("请输入需要追加的元素：\n");
    // scanf("%d", &d);
    // SL_Append(slist, d);
    // printf("追加%d后的顺序表：\n", d);
    // SL_output(slist);
    // printf("请输入需要删除的元素：\n");
    // scanf("%d", &e);
    // SL_DeleteValue(slist, e);
    // printf("删除的元素后的顺序表：\n");
    // SL_output(slist);

    // SL_Random_2(slist);                 //拓展（2）
    // SL_Random_3(slist);                 //拓展（3）
}


//测试结果
// 请输入数据元素的个数：
// 4
// 请向顺序表中输入元素：
// 1 2 3 4
// 最初的顺序表：
// 1 2 3 4 
// 请输入需要插入的位置和元素：
// 0 0
// 插入元素后顺序表：
// 0 1 2 3 4 
// 请输入需要追加的元素：
// 5
// 追加5后的顺序表：
// 0 1 2 3 4 5 
// 请输入需要删除的元素：
// 0
// 删除的元素后的顺序表：
// 1 2 3 4 5 