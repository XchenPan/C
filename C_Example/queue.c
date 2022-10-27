#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef int T;

struct Queue
{
    T *Data;
    int head; //队头
    int tail; //队尾
    int capacity; //队列最大容量
};
struct Queue *InitQueue(int size)
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->Data = (int*)malloc(sizeof(int)*size);
    q->head = q->tail;
    q->capacity = size;
    return q;
}
int IsEmpty(struct Queue *q)
{   //判空, 空返回1,非空返回0;
    if (q->head == q->tail)
        return 1;
    else
        return 0;
}
void enQueue(struct Queue *q, T v)
{   //入队
	q->Data[q->tail] = v;
	q->tail = (q->tail + 1) % q->capacity;
}
void deQueue(struct Queue *q)
{
    //出队
    int t;
    t = q->Data[q->head];
    q->head = (q->head + 1) % q->capacity;
}
void OutputQueue(struct Queue *q)
{   //输出打印全部元素
	for (int i = q->head; i != q->tail;) {
		printf("%d ", q->Data[i]);
		i = (i + 1) % q->capacity;
	}
	printf("\n");
}
int main()
{
    struct Queue *q = InitQueue(MaxSize);
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    enQueue(q,4);
    OutputQueue(q);
    deQueue(q);
    OutputQueue(q);
    return 0;
}