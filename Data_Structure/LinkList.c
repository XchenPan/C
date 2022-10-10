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
}LinkList;

//创建一个链接存储的线性表，初始为空表，返回 llist 指针
LinkList *LL_Create()
{
    LinkList *llist = (LinkList*)malloc(sizeof(LinkList));
    llist->header.next = NULL;
    llist->length = 0;
    return llist;
}

//释放链表的结点，然后释放 llist 所指向的结构
void LL_Free(LinkList *llist)
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
void LL_MakeEmpty(LinkList *llist)
{
    LinkNode *p = llist->header.next;

    while (p->next){        //释放结点
        llist->header.next = p->next;
        free(p);
        p = llist->header.next;
    }
    llist->length = 0;
}

//返回 index 位置的元素
LinkNode *LL_GetIndex(LinkList *llist, int index)
{
    LinkNode *p = llist->header.next;

    while(p != NULL && index > 0){
        p = p->next;
        index--;
    }

    return p;
}

//TODO：修改链表中 index 位置元素值为 v
void LL_Set(LinkList *llist, int index, T v)
{
    
}

//在链表头部插入元素 x 到
void LL_Insert(LinkList *llist, T x)
{
    LinkNode *newNode = (LinkNode*)malloc(sizeof(LinkNode));
    if(newNode == NULL) return;
    newNode->data = x;
    newNode->next = llist->header.next;
    llist->header.next = newNode;
    llist->length++;
}

//TODO:在链表结点 p 后插入元素 x
void LL_InsertAfter(LinkList *llist, LinkNode *p, T x)
{

}

//TODO:删除链表当中 p 结点之后的元素
void LL_DeleteAfter(LinkList *llist, LinkNode *p)
{

}

//TODO:删除链表表头元素
void LL_DeleteHead(LinkList *llist)
{

}

//删除链表 llist 中的元素 v
void LL_DeleteValue(LinkList *llist, T v)
{
    LinkNode *p = llist->header.next;
    if(p == NULL) return; //空链表不能删除
    if(p->data == v) {
        LL_DeleteHead(llist);
    }
    while (p) {
        if(p->next->data == v) {
        LL_DeleteAfter(llist, p);
        return;
        }
        p = p->next;
    }
}

//查找元素为 x 的结点并返回
LinkNode *LL_Search(LinkList *llist,T x)
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
void LL_Output(LinkList *llist)
{
    LinkNode *p = llist->header.next;
    printf("header->");
    while (p) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
}

// 头插法创建链表
LinkNode *createHead()
{
	//定义了三个指针类型的lnode head是头指针
    LinkNode *head, *p, *q;
    head = p = (LinkNode*)malloc(sizeof(LinkNode));
    p->next = NULL;
    for (int i = 0; i < 10; i++) {
        q = (LinkNode*)malloc(sizeof(LinkNode));
        q->data = i;
        q->next = p->next;
        p->next = q;
    }
    return head;
}

int main()
{
    LinkList *llist = LL_Create();
    llist = createHead();
    LL_Output(llist);
    return 0;
}