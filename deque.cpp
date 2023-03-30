#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_dequeue 100


typedef int data;
typedef struct {
	int front, rear;
	data items[max_dequeue];

}dequeue;

void initdequeue(dequeue* pdequeue);
bool isfull(dequeue* pdequeue);
bool isempty(dequeue* pdequeue);
void addfront(dequeue* pdequeue, data item);
void addrear(dequeue* pdequeue, data item);
void removefront(dequeue* pdequeue);
void removerear(dequeue* pdequeue);
int peekfront(dequeue* pdequeue);
int peekrear(dequeue* pdequeue);
bool checkpalindrome(char* str, int len);

int main() {
	int n;
	scanf("%d", &n);
	char* check = (char*)malloc(sizeof(char) * n);
	scanf("%s", check);
	if (checkpalindrome(check, strlen(check))) {
		printf("true");
	}
	else {
		printf("false");
	}
	free(check);

}
void initdequeue(dequeue* pdequeue) {
	pdequeue->front = pdequeue->rear = 0;
}
bool isfull(dequeue* pdequeue) {
	return pdequeue->front == (pdequeue->rear + 1) % max_dequeue;
}
bool isempty(dequeue* pdequeue) {
	return pdequeue->front == pdequeue->rear;
}
void addfront(dequeue* pdequeue, data item) {
	if (isfull(pdequeue)) {
		exit(1);
	}
	pdequeue->items[pdequeue->front] = item;
	pdequeue->front = (pdequeue->front - 1+max_dequeue) % max_dequeue;
}
void addrear(dequeue* pdequeue, data item) {
	if (isfull(pdequeue)) {
		exit(1);
	}
	pdequeue->items[pdequeue->rear] = item;
	pdequeue->rear = (pdequeue->rear + 1) % max_dequeue;
 }
void removefront(dequeue* pdequeue) {
	if (isempty(pdequeue)) {
		exit(1);
	}
	pdequeue->front = (pdequeue->front + 1) % max_dequeue;
}
void removerear(dequeue* pdequeue) {
	if (isempty(pdequeue)) {
		exit(1);
	}
	pdequeue->rear = (pdequeue->rear - 1 + max_dequeue) % max_dequeue;
}
int peekfront(dequeue* pdequeue) {
	if (isempty(pdequeue)) {
		exit(1);
	}
	return pdequeue->items[pdequeue->front];
}
int peekrear(dequeue* pdequeue) {
	if (isempty(pdequeue)) {
		exit(1);
	}
	return pdequeue->items[pdequeue->rear-1];
}
bool checkpalindrome(char* str, int len) {
	dequeue pdequeue;
	initdequeue(&pdequeue);
	for (int i = 0; i < len; i++) {
		addrear(&pdequeue, str[i]);
	}
	while (len > 1) {
		if (peekfront(&pdequeue) == peekrear(&pdequeue)) {
			removefront(&pdequeue), removerear(&pdequeue);
			len -= 2;
		}
		else return false;
	}
	return true;
}