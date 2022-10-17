#include<stdio.h>
#include<stdlib.h>

#define MaxSize 5

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
    sstack->capacity = size;
    return sstack;
}
void Push(struct SepStack *sstack, T v) {
    //将数据v存入栈顶位置；
    if (sstack->top == sstack->capacity) {
        printf("栈空间已满，不能PUSH\n");
        return;
    }
    sstack->data[sstack->top] = v;
    sstack->top++;
}
T Pop(struct SepStack *sstack) {
    //删除并返回当前栈顶元素；
    int t = sstack->data[sstack->top - 1];
    sstack->top--;
    return t;
}
T Peek(struct SepStack *sstack) {
    //读取当前栈顶元素；
    int t = sstack->data[sstack->top - 1];
    return t;
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