#pragma once
#include "dlist.h"

typedef struct stack_t{
	Dnode_t *head;
	Dnode_t *(*Push)(struct stack_t*,int data);
	Dnode_t *(*Pop)(struct stack_t*);
	Dnode_t *(*Top)(struct stack_t*);//��ȡջ��Ԫ��
	int (*GetElemNum)(struct stack_t*stack);//����ջ��Ԫ�ظ���
	int (*Isempty)(struct stack_t*);//�ж�ջ�Ƿ�Ϊ��
	int (*Destroy)(struct stack_t*);//����һ��ջ
	void (*List_for_each)(struct stack_t*);//����
	Dnode_t *(*TwoStack2oneQ)(struct stack_t*stack1,struct stack_t*stack2);//����ջʵ��һ������
}Stack_t;

int Stack_init(Stack_t*);
int Stack_deinit(Stack_t*);