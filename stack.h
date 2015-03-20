#pragma once
#include "dlist.h"

typedef struct stack_t{
	Dnode_t *head;
	Dnode_t *(*Push)(struct stack_t*,int data);
	Dnode_t *(*Pop)(struct stack_t*);
	Dnode_t *(*Top)(struct stack_t*);
	int (*GetElemNum)(struct stack_t*stack);
	int (*Isempty)(struct stack_t*);
	int (*Destroy)(struct stack_t*);

}Stack_t;

int Stack_init(Stack_t*);
int Stack_deinit(Stack_t*);