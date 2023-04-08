#include <stdio.h>
#include <stdlib.h>

typedef int data;
typedef struct _node {
	data item;
	struct _node* prev;
	struct _node* next;
}node;
typedef struct {
	node* head;
	int len;
}doublelinkedlist;

void initlist(doublelinkedlist* plist);
bool isempty(doublelinkedlist* plist);
void insertmiddle(doublelinkedlist* plist, int pos, int item);
void removemiddle(doublelinkedlist* plist, int pos);
void printlist(doublelinkedlist* plist, int len);

int main(){
	doublelinkedlist a;
	initlist(&a);
	for (int i = 0; i < 10; i++) {
		insertmiddle(&a, i, i);
	}
	printlist(&a, 10);
}

void initlist(doublelinkedlist* plist) {
	node* dummy1, * dummy2;
	dummy1 = (node*)malloc(sizeof(node));
	dummy2 = (node*)malloc(sizeof(node));
	dummy1->prev = NULL;
	dummy1->next = dummy2;
	dummy2->prev = dummy1;
	dummy2->next = NULL;

	plist->head = dummy1;
	plist->len = 0;
}
bool isempty(doublelinkedlist* plist) {
	return plist->len == 0;
}

void insertmiddle(doublelinkedlist* plist, int pos, int item) {
	node* cur, * newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->item = item;
	newnode->prev = NULL;
	newnode->next = NULL;
	cur = plist->head;
	for (int i = 0; i < pos; i++) {
		cur = cur->next;
		}
	newnode->prev = cur;
	newnode->next = cur->next;
	cur->next->prev = newnode;
	cur->next = newnode;
	plist->len++;
}
void removemiddle(doublelinkedlist* plist, int pos) {
	node* cur, *temp;
	if (isempty(plist) || pos < 0 || pos >= plist->len) exit(1);
	cur = plist->head;
	for (int i = 0; i < pos; i++) {
		cur = cur->next;
	}
	temp = cur->next;
	cur->next->prev = cur;
	cur->next = temp->next;
	plist->len--;
	free(temp);
}
void printlist(doublelinkedlist* plist, int len) {
	node* cur;
	cur = plist->head->next;
	for(int i = 0;i<=len;i++){
		printf("%d ", cur->item);
		cur = cur->next;
	}
}