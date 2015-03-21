#pragma once
#include "dlist.h"

typedef struct stack_t{
	Dnode_t *head;
	Dnode_t *(*Push)(struct stack_t*,int data);
	Dnode_t *(*Pop)(struct stack_t*);
	Dnode_t *(*Top)(struct stack_t*);//获取栈顶元素
	int (*GetElemNum)(struct stack_t*stack);//计算栈中元素个数
	int (*Isempty)(struct stack_t*);//判断栈是否为空
	int (*Destroy)(struct stack_t*);//销毁一个栈
	void (*List_for_each)(struct stack_t*);//遍历
	Dnode_t *(*TwoStack2oneQ)(struct stack_t*stack1,struct stack_t*stack2);//两个栈实现一个队列
}Stack_t;

int Stack_init(Stack_t*);
int Stack_deinit(Stack_t*);