#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

typedef struct queue_t{
	Dnode_t *head;
	Dnode_t *(*Push)(struct queue_t*,Dnode_t *);
	Dnode_t *(*Pop)(struct queue_t*);
	int (*GetElemNum)(struct queue_t*queue);//计算队列中元素个数
	int (*Isempty)(struct queue_t*);//判断队列是否为空
	int (*Destroy)(struct queue_t*);//销毁一个队列
	void (*List_for_each)(struct queue_t*);//遍历
	Dnode_t *(*TwoQ2oneStack)(struct queue_t*queue1,struct queue_t*queue2);//两个队列实现一个栈
}Queue_t;

int Queue_init(Queue_t*);
int Queue_deinit(Queue_t*);