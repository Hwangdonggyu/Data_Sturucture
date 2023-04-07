#include <stdio.h>
#include <stdlib.h>
#define max_list 100

typedef int data;
typedef struct _node {
	data item;
	struct _node* next;
}node;
typedef struct {
	node* tail;
	int len;
}circularlist;

bool isempty(circularlist* plist);
void insertinititem(circularlist* plist, data item);
void insertfirst(circularlist* plist, data item);
void insertlast(circularlist* plist, data item);
void insertmiddle(circularlist* plist, int pos, data item);
void removeinititem(circularlist* plist);
void removefirst(circularlist* plist);
void removelast(circularlist* plist);
void removemiddle(circularlist* plist, int pos);
void printlist(circularlist* plist, int len);

int main() {
	circularlist a;
	insertinititem(&a, 1);
	insertfirst(&a, 2);
	insertlast(&a, 3);
	insertmiddle(&a, 2, 4);
	printlist(&a, 4);
}
bool isempty(circularlist* plist) {
	return (plist->len == 0);
}

void insertinititem(circularlist* plist, data item) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->item = item;
	newnode->next = newnode;
	plist->tail = newnode;
	plist->len++;
}
void insertfirst(circularlist* plist, data item) {
	if (plist->len == 0) {
		insertinititem(plist, item);
	}
	else {
		node* newnode = (node*)malloc(sizeof(node));
		newnode->item = item;
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
		plist->len++;
	}
}
void insertlast(circularlist* plist, data item) {
	if (plist->len == 0) {
		insertinititem(plist, item);
	}
	else {
		node* newnode = (node*)malloc(sizeof(node));
		newnode->item = item;
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
		plist->tail = newnode;
		plist->len++;

	}

}
void insertmiddle(circularlist* plist, int pos, data item) {
	if (plist->len == 0) {
		insertinititem(plist, item);
	}
	else {
		node* cur, *newnode;
		cur = plist->tail;
		for (int i = 0; i < pos; i++) {
			cur = cur->next;
		}
		newnode = (node*)malloc(sizeof(node));
		newnode->item = item;
		newnode->next = cur->next;
		cur->next = newnode;
		plist->len++;
	}

}
void removeinititem(circularlist* plist) {
	if (isempty(plist)) exit(1);
	if (plist->len == 1) {
		free(plist->tail);
		plist->len--;
		plist->tail = NULL;
	}
}
void removefirst(circularlist* plist) {
	if (isempty(plist)) exit(1);
	else if (plist->len == 1) {
		removeinititem(plist);
	}
	else {
		node* tmp = plist->tail->next;
		plist->tail->next = tmp->next;
		free(tmp);
		plist->len--;
	}
}
void removelast(circularlist* plist) {
	if (isempty(plist)) exit(1);
	else if (plist->len == 1) {
		removeinititem(plist);
	}
	else {
		node* cur,*tmp;
		cur = plist->tail;
		for (int i = 0; i < plist->len - 1; i++){
			cur = cur->next;
		}
		tmp = cur->next;
		cur->next = tmp->next;
		free(tmp);
		plist->tail = cur;
		plist->len--;

	}
}
void removemiddle(circularlist* plist, int pos) {
	if (isempty(plist)) exit(1);
	else if (plist->len == 1) {
		removeinititem(plist);
	}
	else {
		node* cur, * tmp;
		cur = plist->tail;
		for (int i = 0; i < pos; i++) {
			cur = cur->next;
		}
		tmp = cur->next;
		cur->next = tmp->next;
		free(tmp);
		plist->len--;
	}
}
void printlist(circularlist* plist, int len) {
	node* cur = plist->tail;
	for (int i = 0; i < len; i++) {
		printf("%d ", cur->item);
		cur = cur->next;
	}
}