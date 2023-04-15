#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

#define max_serv_time 10
#define	max_queue 100

int waited_time = 0;
int served_customers = 0;
int num_customers = 0;

typedef struct {
	int id;
	int arrival_time;
	int service_time;
}customer;

typedef struct {
	int front, rear;
	customer* data[max_queue];
}queue;

void initqueue(queue* pqueue) {
	pqueue->front = pqueue->rear = 0;
}
bool isfull(queue* pqueue) {
	return (pqueue->front == (pqueue->rear + 1) % max_queue);
}
bool isempty(queue* pqueue) {
	return pqueue->front == pqueue->rear;
}
customer* peek(queue* pqueue) {
	if (isempty(pqueue)) {
		exit(1);
	}
	return pqueue->data[pqueue->front];
}
void enqueue(queue* pqueue, customer* item) {
	if (isfull(pqueue)) {
		exit(1);
	}
	pqueue->data[pqueue->rear] = item;
	pqueue->rear = (pqueue->rear + 1) % max_queue;
}
void dequeue(queue* pqueue) {
	if (isempty(pqueue)) {
		exit(1);
	}
	pqueue->front = (pqueue->front + 1) % max_queue;
}

void insertcustomer(queue* pqueue, int id, int clock);
int removecustomer(queue* pqueue, int clock);
bool iscustomerarrived();
void printstat();

int main() {
	int service_time = 0, duration = 10;
	int clock = 0, id = 1;
	queue queue;
	initqueue(&queue);
	while (clock < duration) {
		clock++;
		printf("Time = %d\n", clock);
		if (iscustomerarrived()) {
			insertcustomer(&queue, id++, clock);
		}
		if (service_time > 0) service_time--;
		else service_time = removecustomer(&queue, clock);
	}
	printstat();
	return 0;
}

void insertcustomer(queue* pqueue, int id, int clock) {
	customer c;
	int service_time = (int)(rand() % max_serv_time) + 1;
	if (isfull(pqueue)) return;
	c.id = id;
	c.arrival_time = clock;
	c.service_time = service_time;
	enqueue(pqueue, &c);
	printf("Cuttomer %2d enters. service time: %d mins\n", id, service_time);
	num_customers++;
}

int removecustomer(queue* pqueue, int clock) {
	customer* c;
	int service_time = 0;
	if (isempty(pqueue)) return 0;
	c = peek(pqueue);
	dequeue(pqueue);
	service_time = c->service_time;
	printf("Customer %2d: %2d mins service starts. waiting time: %2d mins\n", c->id, service_time, clock - c->arrival_time);

	served_customers++;
	waited_time += clock - c->arrival_time;
	return service_time;
}

bool iscustomerarrived() {
	double prob = rand() / (double)RAND_MAX;
	if (prob >= 0.5) return true;
	else return false;
}

void printstat() {
	printf("\nTotal waiting time = %d mins\n", waited_time);
	printf("Average waiting time per customer = %.2f mins\n", (double)waited_time / served_customers);
	printf("Number of served customer = %d\n", served_customers);
	printf("Number of waiting customers = %d\n", num_customers - served_customers);
}
