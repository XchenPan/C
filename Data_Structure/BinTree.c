#include<stdio.h>
#include<stdlib.h>

int i = 0;

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
    
}
void SetIndex()
{
    i = 0;
}
int main()
{
    struct BinTree *tree;
    char *p = "AB##CDF###E##";
    tree = createByPre(p);
    preOrder(tree);
    printf("\n");
    inOrder(tree);
    printf("\n");
    postOrder(tree);
    printf("\n");
    SetIndex();
    char *pre = "abdgcefh";
    char *in = "dgbaechf";
    struct BinTree *T = rebuildByPreIn(pre, in, 8);
    postOrder(T);
    printf("\n");
    return 0;
}
