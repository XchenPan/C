#include<stdio.h>
#include<stdlib.h>

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

//TODO:在链表结点 p 后插入元素 x
void LL_InsertAfter(LinkList_Head *llist, LinkNode *p, T x)
{
    int index = 0;
    LinkNode *NewNode = (LinkNode*)malloc(sizeof(LinkNode));
    LinkNode *q = llist->header.next;
    while (p->data != x)
    {
        p = p->next;
        ++index;
    }
    
    llist->length++;
}

//TODO:删除链表当中 p 结点之后的元素
void LL_DeleteAfter(LinkList_Head *llist, LinkNode *p)
{

}

//TODO:删除链表表头元素
void LL_DeleteHead(LinkList_Head *llist)
{

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

int main()
{
    LinkList_Head *llist = LL_Create();
    for(int i = 0; i < 10; i++)
        LL_Insert(llist, i);
    LL_Output(llist);
    LinkNode *p = llist->header.next;
    for (int i = 0; i < 3; i++) {
        p = p->next;
    }
    LL_InsertAfter(llist, p, 99999);
    LL_Output(llist);

    return 0;
}