#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max_queue 100

#ifndef __cplusplus
typedef enum { false, true }bool;
#endif
typedef int data;
typedef struct {
	int fornt, rear;
	data items[max_queue];

}queue;