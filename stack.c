#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

#if 0//�����ú���ôд��
#define PARAM_CHECK if(!stack)\
	{
		printf("the param is not correct!\n");
		return NULL;
	}
#endif

static int Isempty(struct stack_t*stack)
{
	if(!stack)
	{
		printf("the param is not correct!\n");
		return -1;
	}
	if(!stack->head)
	{
		printf("[%s][%d]the stack has not been inited yet!\n",__FILE__,__LINE__);
		return -1;
	}
	return (stack->head->next == stack->head?1:0);
}

static Dnode_t *push(struct stack_t*stack,int data)
{
	Dnode_t *node = NULL;
	if(!stack)
	{
		printf("the param is not correct!\n");
		return NULL;
	}
	if(!stack->head)
	{
		printf("[%s][%d]the stack has not been inited yet!\n",__FILE__,__LINE__);
		return NULL;
	}
	node = (Dnode_t*)malloc(sizeof(Dnode_t));
	if(!node)
	{
		printf("out of memory ,malloc failed\n");
		return NULL;
	}
	node->data = data;
	node->next = stack->head->next;
	node->prev = stack->head;
	stack->head->next = node;
	node->next->prev = node;
	return node;
}

static Dnode_t *pop(struct stack_t*stack)
{
	Dnode_t *save = NULL;
	if(!stack)
	{
		printf("the param is not correct!\n");
		return NULL;
	}
#if 1
	if(!stack->head)
	{
		printf("[%s][%d]the stack has not been inited yet!\n",__FILE__,__LINE__);
		return NULL;
	}
#endif
	if(Isempty(stack))//��ջ
		return NULL;
	save = stack->head->next;
	stack->head->next = save->next;
	save->next->prev = stack->head;
	save->next = save;
	save->prev = save;
	return save;
}

static int GetElemNum(struct stack_t*stack)
{
	int cnt = 0;
	Dnode_t *cur = NULL;
	if(!stack)
	{
		printf("the param is not correct!\n");
		return -1;
	}
	if(!stack->head)
	{
		printf("[%s][%d]the stack has not been inited yet!\n",__FILE__,__LINE__);
		return -1;
	}
	if(stack->head->next == stack->head)//��������ط��ˣ�������������
		return 0;
	cur = stack->head->next;
	while(cur != stack->head)
	{
		cnt++;
		//printf("[%s][%d]now the cnt is %d\n",__FILE__,__LINE__,cnt);
		cur = cur->next;
	}
	return cnt;
}
static Dnode_t *top(struct stack_t*stack)
{
	if(stack)
		return stack->head->next;
}

static Dnode_t *TwoStack2oneQ(struct stack_t*stack1,struct stack_t*stack2)
{
	Dnode_t *tmp,*cur = NULL;
	if(!stack1||!stack2)
	{
		printf("[%s][%d]the param is not correct!\n",__FILE__,__LINE__);
		return NULL;
	}
	while(!Isempty(stack1))
	{
		tmp = pop(stack1);
		push(stack2,tmp->data);//fixme:�˴�������ʵ�ֲ�̫�ã�Ч�ʵ�
		if(tmp)
			free(tmp);
	}
	tmp = pop(stack2);
	while(!Isempty(stack2))//��stack2��ջ��Ԫ�ص���֮��ʣ��Ļ�Ҫѹ��stack1,���ܸı�ԭ��ջ�Ľṹ
	{
		cur = pop(stack2);
		push(stack1,cur->data);//fixme:�˴�������ʵ�ֲ�̫�ã�Ч�ʵ�
		if(cur)
			free(cur);
	}

	return tmp;
}

static void list_for_each(struct stack_t*stack)
{
	Dnode_t *cur = NULL;
	cur = stack->head->next;
	while(cur != stack->head)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");

}
static int Destroy(struct stack_t*stack)
{
	Dnode_t *tmp = NULL;
	while(!Isempty(stack))
	{
		tmp = pop(stack);
		if(tmp)
			free(tmp);
	}
	return 0;
}

int Stack_init(Stack_t *stack)
{
	if(!stack)
	{
		printf("[%s][%d]the param is not correct!\n",__FILE__,__LINE__);
		return -1;
	}
	stack->head = (Dnode_t*)malloc(sizeof(Stack_t));
	if(!stack->head)
	{
		printf("out of memory ,malloc failed\n");
		return -1;
	}
	stack->head->prev = stack->head;
	stack->head->next = stack->head;
	stack->head->data = 0;
	stack->Push = push;
	stack->Pop = pop;
	stack->Top = top;
	stack->Isempty = Isempty;
	stack->Destroy = Destroy;
	stack->GetElemNum = GetElemNum;
	stack->TwoStack2oneQ = TwoStack2oneQ;
	stack->List_for_each = list_for_each;
	return 0;

}


int Stack_deinit(Stack_t*stack)
{
	if(!stack)
	{
		printf("the param is not correct!\n");
		return -1;
	}
	if(stack->head)
	{
		free(stack->head);
		stack->head = NULL;
	}
	stack->Push = NULL;
	stack->Pop = NULL;
	stack->Top = NULL;
	stack->Isempty = NULL;
	stack->Destroy = NULL;
	stack->GetElemNum = NULL;
	stack->TwoStack2oneQ = NULL;
	stack->List_for_each = NULL;
	return 0;
}