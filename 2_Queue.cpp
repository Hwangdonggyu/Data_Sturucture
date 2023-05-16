#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max_queue 100

typedef int data;
typedef struct {
	int front, rear;
	data items[max_queue];

}queue;

void initqueue(queue* pqueue);
bool isfull(queue* pqueue);
bool isempty(queue* pqueue);
data peek(queue* pqueue);
void enqueue(queue* pqueue, data item);
void dequeue(queue* pqueue);

int main(){

}

void initqueue(queue* pqueue){
	pqueue->front = pqueue-> rear = 0;
}
bool isfull(queue* pqueue){
	return pqueue->front == (pqueue->rear+1)%max_queue;
}
bool isempty(queue* pqueue){
	return pqueue->front == pqueue->rear;
}
data peek(queue* pqueue){
	if(isempty(pqueue)) exit(1);
	return pqueue->items[pqueue->front];
}
void enqueue(queue* pqueue, data item){
	if(isfull(pqueue)) exit(1);
	pqueue->items[pqueue->rear]= item;
	pqueue->rear = (pqueue->rear+1) % max_queue;
}
void dequeue(queue* pqueue){
	if(isempty(pqueue)) exit(1);
	pqueue->front = (pqueue->front+1)% max_queue;
}
