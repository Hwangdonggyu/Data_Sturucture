#include <stdio.h>
#include <stdlib.h>

typedef int data;
typedef struct _node {
	data item;
	struct _node* next;
}node;
typedef struct {
	node* front,*rear;
}d_queue;

void initqueue(d_queue* pqueue);
bool isempty(d_queue* pqueue);
data peek(d_queue* pqueue);
void enqueue(d_queue* pqueue, int item);
void dequeue(d_queue* pqueue);

int main() {
	d_queue a;
	initqueue(&a);
	for (int i = 0; i < 10; i++) {
		enqueue(&a, i);
	}
	while (!(isempty(&a))) {
		printf("%d ", peek(&a));
		dequeue(&a);
	}

}
void initqueue(d_queue* pqueue) {
	pqueue->front = NULL;
	pqueue->rear = NULL;
}
bool isempty(d_queue* pqueue) {
	return pqueue->front== NULL;
}
data peek(d_queue* pqueue) {
	if (isempty(pqueue)) exit(1);
	return pqueue->front->item;
}
void enqueue(d_queue* pqueue, int item) {
	node* newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->item = item;
	if (isempty(pqueue)) {
		pqueue->front = pqueue->rear = newnode;
	}
	else {
		pqueue->rear->next = newnode;
		pqueue->rear = newnode;
	}
}
void dequeue(d_queue* pqueue) {
	node* temp;
	if (isempty(pqueue)) exit(1);
	temp = pqueue->front;
	if(temp->next == NULL){
		pqueue->front = pqueue->rear = NULL;
	}
	else {
		pqueue->front = temp->next;
	}
	free(temp);
	
}