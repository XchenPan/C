#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef int T;

struct SepStack
{
    T *data;
    int top;
    int capacity;
};

struct SepStack *SS_Create(int size) {
    //创建容量大小为size的栈空间，初始化栈顶指针；
    struct SepStack *sstack = (struct SepStack*)malloc(sizeof(struct SepStack));
    sstack->data = (T*)malloc(size*sizeof(T));
    sstack->top = 0;
    return sstack;
}
void Push(struct SepStack *sstack, T v) {
    //将数据v存入栈顶位置；
}
T Pop(struct SepStack *sstack) {
    //删除并返回当前栈顶元素；
}
T Peek(struct SepStack *sstack) {
    //读取当前栈顶元素；
}
void Output(struct SepStack *sstack) {
    //按照栈底到栈顶顺序打印输出栈空间中当前元素；
    int i = 0;
    printf("栈底到栈顶的元素依次为：\n");
    while (i < sstack->top) {
        printf("%d ", sstack->data[i]);
        i++;
    }
    printf("\n");
}
void main()
{
    struct SepStack *sstack = SS_Create(MaxSize);
}
