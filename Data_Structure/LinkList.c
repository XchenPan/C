#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<unistd.h> 
typedef int T;

typedef struct LinkNode
{
    T data;
    struct LinkNode *next;
}LinkNode;

typedef struct LinkList
{
    LinkNode header;
    int length;
}LinkList_Head;

//创建一个链接存储的线性表，初始为空表，返回 llist 指针
LinkList_Head *LL_Create()
{
    LinkList_Head *llist = (LinkList_Head*)malloc(sizeof(LinkList_Head));
    llist->header.next = NULL;
    llist->length = 0;
    return llist;
}

//释放链表的结点，然后释放 llist 所指向的结构
void LL_Free(LinkList_Head *llist)
{
    LinkNode *p = llist->header.next;
    while (p->next) 
    { //释放结点
        llist->header.next = p->next;
        free(p);
        p = llist->header.next;
    }
    free(llist); //释放链表
}

//将当前链表变为一个空表，因此需要释放所有结点
void LL_MakeEmpty(LinkList_Head *llist)
{
    LinkNode *p = llist->header.next;

    while (p->next) {        //释放结点
        llist->header.next = p->next;
        free(p);
        p = llist->header.next;
    }
    llist->length = 0;
}

//返回 index 位置的元素
LinkNode *LL_GetIndex(LinkList_Head *llist, int index)
{
    LinkNode *p = llist->header.next;

    while (p != NULL && index > 0) {
        p = p->next;
        index--;
    }

    return p;
}

//修改链表中 index 位置元素值为 v
void LL_Set(LinkList_Head *llist, int index, T v)
{
    if (index > llist->length || index < 1) {
		printf("此结点不存在！\n");
		return;
	}
    LinkNode *NewNode = NULL;
    NewNode = llist->header.next;
    while (--index)
        NewNode = NewNode->next;
    NewNode->data = v;
}

//在链表头部插入元素 x 到链表中
void LL_Insert(LinkList_Head *llist, T x)
{
    LinkNode *NewNode = (LinkNode*)malloc(sizeof(LinkNode));
    if (NewNode == NULL) return;
    NewNode->data = x;
    NewNode->next = llist->header.next;
    llist->header.next = NewNode;
    llist->length++;
}

//在链表结点 p 后插入元素 x
void LL_InsertAfter(LinkList_Head *llist, LinkNode *p, T x)
{
    LinkNode *q = llist->header.next;
    while (q != p)
        q = q->next;
    LinkNode *NewNode = (LinkNode*)malloc(sizeof(LinkNode));
    NewNode->data = x;
    NewNode->next = q->next;
    q->next = NewNode;
    llist->length++;
}

//删除链表当中 p 结点之后的元素
void LL_DeleteAfter(LinkList_Head *llist, LinkNode *p)
{
    int index = 0;
    LinkNode *q = llist->header.next;
    LinkNode *t;
    while (q != p) {
        q = q->next;
        index++;
    }
    t = q->next;
    q->next = NULL;
    free(t);
    llist->length = index+1;
}

//删除链表表头元素
void LL_DeleteHead(LinkList_Head *llist)
{
    LinkNode *p = llist->header.next;
    llist->header.next = p->next;
    free(p);
    llist->length--;
}

//删除链表 llist 中的元素 v
void LL_DeleteValue(LinkList_Head *llist, T v)
{
    LinkNode *p = llist->header.next;
    if (p == NULL) return; //空链表不能删除
    if (p->data == v) {
        LL_DeleteHead(llist);
    }
    while (p) {
        if (p->next->data == v) {
        LL_DeleteAfter(llist, p);
        return;
        }
        p = p->next;
    }
}

//查找元素为 x 的结点并返回
LinkNode *LL_Search(LinkList_Head *llist,T x)
{
    LinkNode *p = llist->header.next;

    while (p) {
        if (p->data == x) {
            break;
        }
        p = p->next;
    }
    return p;
}

//打印链表元素
void LL_Output(LinkList_Head *llist)
{
    LinkNode *p = llist->header.next;
    printf("header->");
    while (p) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
}

//生成 100 个随机整数并放入一个链表中,
//要求链表中的元素按从小到大顺序排列,然后
//输出该链表。
void random_input_1(LinkList_Head *llist)
{
    srand((int)time(NULL));
    for(int i =0; i < 100; i++)
        LL_Insert(llist, rand() % 100 + 1);
}
void random_input_2(LinkList_Head *llist_1, LinkList_Head *llist_2)
{
    srand((int)time(NULL));
    for(int i =0; i < 100; i++) {
        LL_Insert(llist_1, rand() % 100 + 1);
        LL_Insert(llist_2, rand() % 100 + 1);
    }
}

//链表的冒泡排序
void LL_Sort(LinkList_Head *llist)
{
    int temp = 0, count = 0;
    LinkNode *t = llist->header.next;
    LinkNode *p;
    while (t)
    {
        count++;
        t = t->next;
    }
    for (int i = 0; i < count - 1; i++)
    {
        t = llist->header.next;
        p = t->next;
        for (int j = 0; j < count - i - 1; j++)
        {
            if (t->data > p->data)
            {
                temp = t->data;
                t->data = p->data;
                p->data = temp;
            }
            p = p->next;
            t = t->next;
        }
    }
}

//将两个从小到大排列的链表合并为一个新链表(仍然有序排列),若遇到相同的元素,
//则在合并时去掉重复元素。输出合并前的两个链表,输出合并后的链表,检查合并是否成功。
void two2one(LinkList_Head *llist_1, LinkList_Head *llist_2, LinkList_Head *llist_total)
{
    LinkNode *a = llist_1->header.next;
    LinkNode *b = llist_2->header.next;
    while (a != NULL && b != NULL)
    {
        LL_Insert(llist_total, a->data);
        LL_Insert(llist_total, b->data);
        a = a->next;
        b = b->next;
    }
    LL_Sort(llist_total);
    LinkNode *p,*q;
    p = llist_total->header.next;
    while(p != NULL){
        while(p->next != NULL && p->data == p->next->data){
            q = p->next;
            p->next = q->next;
            free(q);
        }
        p = p->next;
    }
}
int main()
{
    LinkList_Head *llist_1 = LL_Create();
    LinkList_Head *llist_2 = LL_Create();
    LinkList_Head *llist_total = LL_Create();
    random_input_2(llist_1, llist_2);
    LL_Sort(llist_1);
    LL_Sort(llist_2);
    two2one(llist_1, llist_2, llist_total);
    LL_Output(llist_1);
    LL_Output(llist_2);
    LL_Output(llist_total);
    return 0;
}