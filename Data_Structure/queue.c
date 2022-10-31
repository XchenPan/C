#include<stdio.h>
#include<stdlib.h>
#define MaxSize 5
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
{   //判断队列的状态
    if (q->head == q->tail)
        printf("队列为空\n");
    else if ((q->tail + 1) % q->capacity == q->head)
        printf("队列已满\n");
    else
        printf("队列非空\n");
}
void enQueue(struct Queue *q, T v)
{   //入队
    if ((q->tail + 1) % q->capacity == q->head) {
        printf("队列已满，不能再入队\n");
        return;
    }
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
void main()
{
    struct Queue *q = InitQueue(MaxSize);
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    enQueue(q,4);
        printf("原始队列为（队列已满）：");
    OutputQueue(q);

    deQueue(q);
    printf("出队1次队列为：");
    OutputQueue(q);
    deQueue(q);
    printf("出队2次队列为：");
    OutputQueue(q);
    deQueue(q);
    printf("出队3次队列为：");
    OutputQueue(q);
    deQueue(q);
    printf("出队4次队列为：");
    OutputQueue(q);
    IsEmpty(q);
    deQueue(q);
    printf("出队超出队列容量后的队列为：");
    OutputQueue(q);
    IsEmpty(q);
}