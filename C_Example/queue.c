#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
struct queue
{
    int *data;
    int head; //队头
    int tail; //队尾
    int capacity; //队列最大容量
};
struct queue *InitQueue(int size)
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->data = (int*)malloc(sizeof(int)*size);
    q->head = q->tail;
    q->capacity = size;
    return q;
}
void InputQueue(struct queue *q)
{
		  for (int i = 0; i < 10 ; i++) {
				q->data[i] = i;
				q->tail = (q->tail + 1) % q->capacity;
		  }
		  printf("\n");
}
void PrintQueue(struct queue *q)
{
		  for (int i = q->head; i != q->tail;) {
				printf("%d ", q->data[i]);
				i = (i + 1) % q->capacity;
		  }
		  printf("\n");
}
int main()
{
    struct queue *q = InitQueue(MaxSize);
    InputQueue(q);
    PrintQueue(q);
    printf("hello world\n");
    return 0;
}