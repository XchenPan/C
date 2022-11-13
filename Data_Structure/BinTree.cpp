#include<stdio.h>
#include<stdlib.h>

typedef char T;

struct BinTree
{
    T data;
    struct BinTree *lchild;
    struct BinTree *rchild;
};

struct BinTree *create(T ch)
{
    struct BinTree *node = (struct BinTree*)malloc(sizeof(struct BinTree));
    node->data = ch;
    node->lchild = node->rchild = NULL;

    return node;
}
struct BinTree *createByPre(char *str, int &index)
{
    char ch = str[index];
    index++;
    if(ch == '#') return NULL;
    struct BinTree *bt = create(ch);
    bt->lchild = createByPre(str, index);
    bt->rchild = createByPre(str, index);
    return bt;
}
void preOrder(struct BinTree *T)
{
    if (T)
    {
        printf("%c->", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}
void inOrder(struct BinTree *T)
{
    if (T)
    {
        inOrder(T->lchild);
        printf("%c->", T->data);
        inOrder(T->rchild);
    }
}
void postOrder(struct BinTree *T)
{
    if (T)
    {
        postOrder(T->lchild);
        postOrder(T->rchild);
        printf("%c->", T->data);
    }
}
int main()
{
    struct BinTree *tree;
    char str[] = "AB##CDF###E##";
    int index = 0;
    tree = createByPre(str, index);
    postOrder(tree);

    return 0;
}
