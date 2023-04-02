#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STACK 100

typedef int data;
typedef struct {
	data items[MAX_STACK];
	int top;

}stack;


void initstack(stack* pstack);
bool isfull(stack* pstack);
bool isempty(stack* pstack);
data peek(stack* pstack);
void push(stack* pstack, data item);
void pop(stack* pstack);
int comp(char op1, char op2);
int getcomp(char op1);

void reverseprint(char* s, int n) {
	stack pstack;
	char ch;
	initstack(&pstack);
	for (int i = 0; i < n; i++) {
		push(&pstack, s[i]);
	}
	while (!isempty(&pstack)) {
		ch = peek(&pstack);
		printf("%c\n", ch);
		pop(&pstack);
	}
}

bool isparanbalanced(char* s, int n) {
	stack pstack;
	initstack(&pstack);
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			push(&pstack, s[i]);
		}
		else {
			if (isempty(&pstack)) {
				return false;
			}
			pop(&pstack);
		}
	}
	if (isempty(&pstack)) {
		return true;
	}
	else {
		return false;
	}
}
int evalpostfix(char* exp, int len) {
	stack pstack;
	int op1, op2;
	initstack(&pstack);
	for (int i = 0; i < len; i++) {
		if (isdigit(exp[i])) {
			push(&pstack, exp[i]-'0'); // 문자열에서 숫자로 바꿔주는 기능 -'0'
		}
		else {
			op2 = peek(&pstack), pop(&pstack);
			op1 = peek(&pstack), pop(&pstack);
			if (exp[i] == '+') {
				push(&pstack, op1 + op2);
			}
			else if (exp[i] == '-') {
				push(&pstack, op1 - op2);
			}
			else if (exp[i] == '*') {
				push(&pstack, op1 * op2);
			}
			else if (exp[i] == '/') {
				push(&pstack, op1 / op2);
			}

		}
	}
	return peek(&pstack);
}

void convinfixtopostfix(char* exp, char* conv, int len) {
	stack pstack;
	int idx = 0;
	initstack(&pstack);
	for (int i = 0; i < len; i++) {
		if (isdigit(exp[i])) {
			conv[idx++] = exp[i];
		}
		else {
			while (!isempty(&pstack) && comp(peek(&pstack), exp[i])) {
				conv[idx++] = peek(&pstack);
				pop(&pstack);
			}
			push(&pstack, exp[i]);
		}
	}
	
}

int main() {
	char a[100] = { "(4+3)*3" };
	char b[100];
	convinfixtopostfix(a, b, 8);
	for (int i = 0; i < 7; i++) {
		if (b[i] == '(' || b[i] == ')') {
			continue;
		}
		printf("%c", b[i]);
	}
}

void initstack(stack* pstack) {
	pstack->top = -1;
}
bool isfull(stack* pstack) {
	return pstack->top == MAX_STACK - 1;
}
bool isempty(stack* pstack) {
	return pstack->top == -1;
}
data peek(stack* pstack) {
	if (isempty(pstack)) {
		exit(1);
	}
	return pstack->items[pstack->top];
}
void push(stack* pstack, data item) {
	if (isfull(pstack)) {
		exit(1);
	}
	pstack->items[++(pstack->top)] = item;
}
void pop(stack* pstack) {
	if (isempty(pstack)) {
		exit(1);
	}
	--(pstack->top);
}

int comp(char op1, char op2) {
	if (getcomp(op1) >= getcomp(op2)) return true;
	else if (getcomp(op2) > getcomp(op1)) return false;


}

int getcomp(char op1) {
	switch (op1) {
	case '(': return 1;
	case ')': return 5;
	case '*':
	case '/': return 4;
	case '+':
	case '-': return 3;
	}
}
