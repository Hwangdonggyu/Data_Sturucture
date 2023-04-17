#include<stdio.h>
#include<stdlib.h>

typedef int data;

typedef struct _bt {
	data item;
	struct _bt* left_child;
	struct _bt* right_child;
}bt;

bt* createnode(data item);
void destroynode(bt* node);
void createleftsubtree(bt* root, bt* left);
void createrightsubtree(bt* root, bt* right);
int nodes(bt* node);
int height(bt* node);
int max(int a, int b);

int main() {
	bt* n1 = createnode(1);
	bt* n2 = createnode(2);
	bt* n3 = createnode(3);
	bt* n4 = createnode(4);
	bt* n5 = createnode(5);
	bt* n6 = createnode(6);
	createleftsubtree(n1, n2);
	createrightsubtree(n1, n3);
	createleftsubtree(n2, n4);
	createrightsubtree(n2, n5);
	createleftsubtree(n3, n6);
	printf("%d %d", nodes(n1), height(n1));

}

bt* createnode(data item) {
	bt* newnode = (bt*)malloc(sizeof(bt));
	newnode->item = item;
	newnode->left_child = NULL;
	newnode->right_child = NULL;
	return newnode;

}
void destroynode(bt* node) {
	free(node);
}
void createleftsubtree(bt* root, bt* left) {
	if (root->left_child != NULL) exit(1);
	root->left_child = left;
}
void createrightsubtree(bt* root, bt* right) {
	if (root->right_child != NULL) exit(1);
	root->right_child = right;
}
int nodes(bt* node) {
	int r = 0, l = 0;
	if (node->right_child != NULL) r = nodes(node->right_child);
	if (node->left_child != NULL) l = nodes(node->left_child);
	return 1 + r + l;
}
int height(bt* node) {
	int r = 0, l = 0;
	if (node->right_child != NULL) {
		r = height(node->right_child);
	}
	if (node->left_child != NULL) {
		l = height(node->left_child);
	}
	return max(r, l)+ 1;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
