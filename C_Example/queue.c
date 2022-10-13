#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
struct Queue
{
    int *Data;
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
void InputQueue(struct Queue *q)
{
		  for (int i = 0; i < 10 ; i++) {
				q->Data[i] = i;
				q->tail = (q->tail + 1) % q->capacity;
		  }
		  printf("\n");
}
void PrintQueue(struct Queue *q)
{
		  for (int i = q->head; i != q->tail;) {
				printf("%d ", q->Data[i]);
				i = (i + 1) % q->capacity;
		  }
		  printf("\n");
}
int main()
{
    struct Queue *q = InitQueue(MaxSize);
    InputQueue(q);
    PrintQueue(q);
    printf("hello world\n");
    return 0;
}