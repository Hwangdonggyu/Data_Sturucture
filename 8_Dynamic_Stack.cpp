#include <stdio.h>
#include <stdlib.h>

typedef int data;
typedef struct _node {
	data item;
	struct _node* next;
}node;
typedef struct {
	node* top;
}dstack;

void initstack(dstack* pstack);
bool isempty(dstack* pstack);
data peek(dstack* pstack);
void push(dstack* pstack, int item);
void pop(dstack* pstack);

int main() {
	dstack a;
	initstack(&a);
	for (int i = 0; i < 10; i++) {
		push(&a, i);
	}
	while (!(isempty(&a))) {
		printf("%d ",peek(&a));
		pop(&a);
	}

}

void initstack(dstack* pstack) {
	pstack->top = NULL;
}
bool isempty(dstack* pstack) {
	return pstack->top == NULL;
}
data peek(dstack* pstack) {
	if (isempty(pstack)) exit(1);
	return pstack->top->item;
}
void push(dstack* pstack, int item) {
	node* newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->item = item;
	newnode->next = pstack->top;
	pstack->top = newnode;
}
void pop(dstack* pstack) {
	if (isempty(pstack)) exit(1);
	node* temp;
	temp = pstack->top;
	pstack->top = temp->next;
	free(temp);
}