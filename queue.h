#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

typedef struct queue_t{
	Dnode_t *head;
	Dnode_t *(*Push)(struct queue_t*,Dnode_t *);
	Dnode_t *(*Pop)(struct queue_t*);
	int (*GetElemNum)(struct queue_t*queue);//���������Ԫ�ظ���
	int (*Isempty)(struct queue_t*);//�ж϶����Ƿ�Ϊ��
	int (*Destroy)(struct queue_t*);//����һ������
	void (*List_for_each)(struct queue_t*);//����
	Dnode_t *(*TwoQ2oneStack)(struct queue_t*queue1,struct queue_t*queue2);//��������ʵ��һ��ջ
}Queue_t;

int Queue_init(Queue_t*);
int Queue_deinit(Queue_t*);