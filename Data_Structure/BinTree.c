#include<stdio.h>
#include<stdlib.h>

static int i = 0;
static int sum = 0;
static char Max = 0;

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
struct BinTree *createByPre(char *p)
{
    char ch = p[i++];
    if (ch == '#') return NULL;
    struct BinTree *bt = create(ch);
    bt->lchild = createByPre(p);
    bt->rchild = createByPre(p);

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
static struct BinTree *rebuildByPreIn(char *pre, char *in, int len)
{   //根据先序遍历和中序遍历重构二叉树
    if(len == 0) return NULL;
    char root = pre[0];
    struct BinTree *bt = create(root);
    int pos = 0;
    while (pos < len) {
        if (in[pos] == root) break;
        pos++;
    }
    bt->lchild = rebuildByPreIn(pre + 1, in, pos);
    pos++;
    bt->rchild = rebuildByPreIn(pre + pos, in + pos, len - pos);

    return bt;
}
static struct BinTree *rebuildByInPost(char *in, char *post, int len)
{   //根据中序遍历和后序遍历重构二叉树
    if(len == 0) return NULL;
    char root = post[len - 1];
    struct BinTree *bt = create(root);
    int pos = 0;
    while (in[pos] != root) pos++; 
    bt->lchild = rebuildByInPost(in, post, pos);
    bt->rchild = rebuildByInPost(in + pos + 1, post + pos, len - pos -1);

    return bt;
}
int count(struct BinTree *T)
{
    if (T)
    {
        count(T->lchild);
        count(T->rchild);
        sum++;
    }
    return sum;
}
char FindMax(struct BinTree *T)
{
    if (T)
    {
        if (T->data >= Max)
            Max = T->data;
        FindMax(T->lchild);
        FindMax(T->rchild);
    }
    return Max;
}
void SetIndex()
{
    i = 0;
}
void SetSum()
{
    sum = 0;
}
void SetMax()
{
    Max = 0;
}
int main()
{
    struct BinTree *tree;
    char *p = "AB##CDF###E##";
    tree = createByPre(p);
    printf("二叉树的先序/中序/后序遍历为：\n");
    preOrder(tree);
    printf("\n");
    inOrder(tree);
    printf("\n");
    postOrder(tree);
    printf("\n");
    SetIndex();
    char *pre = "abdgcefh";
    char *in = "dgbaechf";
    char *post = "gdbehfca";
    struct BinTree *T1 = rebuildByPreIn(pre, in, 8);
    printf("根据先序遍历和中序遍历重构二叉树的后序遍历为：\n");
    postOrder(T1);
    printf("\n");
    struct BinTree *T2 = rebuildByInPost(in, post, 8);
    printf("根据中序遍历和后序遍历重构二叉树的先序遍历为：\n");
    preOrder(T2);
    printf("\n");
    printf("结点总个数为：%d\n",count(T1));
    SetSum();
    printf("结点最大值为：%c\n", FindMax(tree));
    SetMax();

    return 0;
}
