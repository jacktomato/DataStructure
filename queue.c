#include "queue.h"
#include "dlist.h"
#include "stack.h"
#include <assert.h>
static Dnode_t *Push(Queue_t*queue,Dnode_t *node)
{
	Dlist_t dlist = {0};
	assert(queue||node);
	Dlist_init(&dlist);
	dlist.Add_tail(queue->head,node->data);
	Dlist_deinit(&dlist);
	return node;
}

static Dnode_t *Pop(Queue_t*queue)
{
	Dnode_t *save = NULL;
	assert(queue);
	if(!queue->head->next)
	{
		printf("[%s][%d]this is a empty queue\n",__FILE__,__LINE__);
		return NULL;
	}
	save = queue->head->next;
	queue->head->next = save->next;
	save->next->prev = queue->head;
	return save;
}

static int GetElemNum(Queue_t*queue)
{
	int cnt = 0;
	Dnode_t *cur = NULL;
	if(!queue)
	{
		printf("the param is not correct!\n");
		return -1;
	}
	if(!queue->head)
	{
		printf("[%s][%d]the stack has not been inited yet!\n",__FILE__,__LINE__);
		return -1;
	}
	if(queue->head->next == queue->head)
		return 0;
	cur = queue->head->next;
	while(cur != queue->head)
	{
		cnt++;
		//printf("[%s][%d]now the cnt is %d\n",__FILE__,__LINE__,cnt);
		cur = cur->next;
	}
	return cnt;

}

static int Isempty(Queue_t*queue)
{
	assert(queue||queue->head);
	return (queue->head->next == queue->head?1:0);
}

static int Destroy(Queue_t*queue)
{
	Dnode_t *tmp = NULL;
	while(!Isempty(queue))
	{
		tmp = Pop(queue);
		if(tmp)
			free(tmp);
	}
	return 0;
}

static void List_for_each(Queue_t*queue)
{
	Dnode_t *cur = NULL;
	cur = queue->head->next;
	while(cur != queue->head)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

static Dnode_t *TwoQ2oneStack(Queue_t*queue1,Queue_t*queue2)
{
	Dnode_t *cur = queue1->head->next;
	Dnode_t *tmp,*save = NULL;
	assert(queue1||queue2||queue1->head->next);
#if 1
	while(cur->next != queue1->head)//判断条件总是容易写错！！！！！！
	{
		tmp = queue1->Pop(queue1);
		//printf("[%s][%d] the queue1 pop data is %d \n",__FILE__,__LINE__,tmp->data);
		queue2->Push(queue2,tmp);
		cur = cur->next;
	}
	printf("\n");
	save = cur;

	cur->prev->next = queue1->head;
	queue1->head->prev = cur->prev;//这个地方第一次又写错了
#endif

#if 0
	do{
			tmp = queue1->Pop(queue1);
			//printf("[%s][%d] the queue1 pop data is %d \n",__FILE__,__LINE__,tmp->data);
			if(tmp->next != queue1->head)
			{
				queue2->Push(queue2,tmp);
				cur = cur->next;
			}
			else
				save = tmp;
	}while(cur->next != queue1->head);
#endif
	cur = queue2->head->next;
	while(cur != queue2->head)//此处同上！！！！！！！！！
	{
		tmp = queue2->Pop(queue2);
		//printf("[%s][%d] the queue2 pop data is %d \n",__FILE__,__LINE__,tmp->data);
		queue2->Push(queue1,tmp);
		cur = cur->next;
	}
	printf("\n");
	return save;
}

int Queue_init(Queue_t*queue)
{
	if(!queue)
	{
		printf("[%s][%d]param is not correct \n",__FILE__,__LINE__);
		return -1;
	}
#if 0
	if(queue->head)
	{
		printf("[%s][%d]the queue has been inited already\n",__FILE__,__LINE__);
		return -1;
	}
#endif
	queue->head = (Dnode_t*)malloc(sizeof(Dnode_t));
	if(!queue->head)
	{
		printf("[%s][%d]out of memory\n",__FILE__,__LINE__);
		return -1;
	}
	queue->head->prev = queue->head;
	queue->head->next = queue->head;
	queue->Push = Push;
	queue->Pop = Pop;
	queue->Isempty = Isempty;
	queue->GetElemNum = GetElemNum;
	queue->List_for_each = List_for_each;
	queue->TwoQ2oneStack = TwoQ2oneStack;
	queue->Destroy = Destroy;
	return 0;
}

int Queue_deinit(Queue_t*queue)
{
	if(!queue)
	{
		printf("[%s][%d]param is not correct \n",__FILE__,__LINE__);
		return -1;
	}
	if(queue->head)
	{	
		free(queue->head);
		queue->head = NULL;
	}
	queue->Push = NULL;
	queue->Pop = NULL;
	queue->Isempty = NULL;
	queue->GetElemNum = NULL;
	queue->List_for_each = NULL;
	queue->TwoQ2oneStack = NULL;
	queue->Destroy = NULL;
	return 0;
}