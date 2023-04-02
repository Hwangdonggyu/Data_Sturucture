#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data;
typedef struct _node{
	data item;
	struct _node* next;
}node;
typedef struct {
	node* head;
	int len;
}linkedlist;

void initlist(linkedlist* plist);
bool isempty(linkedlist* plist);
void insertmiddle(linkedlist* plist, int pos, data item);
void removemiddle(linkedlist* plist, int pos);
data readitem(linkedlist* plist, int pos);
void printlist(linkedlist* plist);
void clearlist(linkedlist* plist);
void insertfirst(linkedlist* plist, data item);
void removefirst(linkedlist* plist);

int main() {
	linkedlist list;
	initlist(&list);
	for (int i = 0; i < 10; i++) {
		insertfirst(&list, i);
	}
	printlist(&list);
	removemiddle(&list, 4);
	printlist(&list);
	clearlist(&list);


}

void initlist(linkedlist* plist) {
	plist->head = (node*)malloc(sizeof(node));
	plist->head->next = NULL;
	plist->len = 0;
}
bool isempty(linkedlist* plist) {
	return plist->len == 0;
}
void insertmiddle(linkedlist* plist, int pos, data item) {
	node* cur, *newnode;
	if (pos<0 || pos > plist->len) exit(1);
	newnode = (node*)malloc(sizeof(node));
	newnode->item = item;
	newnode->next = NULL;
	cur = plist->head;
	for (int i = 0; i < pos; i++) {
		cur = cur->next;
	}
	newnode->next = cur->next;
	cur->next = newnode;
	plist->len++;
}
void removemiddle(linkedlist* plist, int pos) {
	node* cur,*temp;
	if (pos<0 || pos>plist->len) exit(1);
	cur = plist->head;
	for (int i = 0; i < pos; i++) {
		cur = cur->next;
	}
	temp = cur->next;
	cur->next = cur->next->next;
	plist->len--;
	free(temp);
	
}
data readitem(linkedlist* plist, int pos) {
	node* cur;
	if (pos<0 || pos > plist->len) exit(1);
	cur = plist->head->next;
	for (int i = 0; i < pos; i++) {
		cur = cur->next;
	}
	return cur->item;
}
void printlist(linkedlist* plist) {
	for (node* cur = plist->head->next; cur != NULL; cur = cur->next) {
		printf("%d ", cur->item);
	}
}
void clearlist(linkedlist* plist) {
	while (plist->head->next != NULL) {
		removefirst(plist);
	}
	free(plist->head);
}

void insertfirst(linkedlist* plist, data item) {
	node* newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->item = item;
	newnode->next = plist->head->next;
	plist->head->next = newnode;
	plist->len++;
}
void removefirst(linkedlist* plist) {
	node* temp;
	if (isempty(plist)) exit(1);
	temp = plist->head->next;
	plist->head->next = temp->next;
	free(temp);
	plist->len--;
}
