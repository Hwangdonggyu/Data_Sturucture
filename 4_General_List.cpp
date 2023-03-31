#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxlist 100

typedef int data;
typedef struct {
	data items[maxlist];
	int len;
}arraylist;

void initlist(arraylist* plist);
bool isempty(arraylist* plist);
bool isfull(arraylist* plist);
void insertmiddle(arraylist* plist,int pos, data item);
void removemiddle(arraylist* plist, int pos);
data readitem(arraylist* plist, int pos);
void printlist(arraylist* plist);

int main() {
	arraylist a;
	initlist(&a);
	for (int i = 0; i < 10; i++) {
		insertmiddle(&a, i, i);
	}
	removemiddle(&a, 3);
	printlist(&a);

}

void initlist(arraylist* plist) {
	plist->len = 0;
}
bool isempty(arraylist* plist) {
	return plist->len == 0;
}
bool isfull(arraylist* plist) {
	return plist->len == maxlist;
}
void insertmiddle(arraylist* plist, int pos, data item) {
	if (isfull(plist) || pos < 0 || pos > plist->len) exit(1);
	for (int i = plist->len - 1; i >= pos; i--) {
		plist->items[i + 1] = plist->items[i];
	}
	plist->items[pos] = item;
	plist->len++;
}
void removemiddle(arraylist* plist, int pos) {
	if (isempty(plist) || pos<0 || pos>=plist->len) exit(1);
	for (int i = pos; i < plist->len - 1; i++) {
		plist->items[i] = plist->items[i + 1];
	}
	plist->len--;
}
data readitem(arraylist* plist, int pos) {
	if (isempty(plist) || pos < 0 || pos >= plist->len) exit(1);
	return plist->items[pos];
}
void printlist(arraylist* plist) {
	for (int i = 0; i < plist->len; i++) {
		printf("%d\n", plist->items[i]);
	}
}
