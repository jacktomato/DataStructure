#include <stdio.h>
#include <string.h>
#include "slist.h"
#include <windows.h>
#include "yhtriangle.h"
#include "dlist.h"
#include "stack.h"


//#define SLIST_TEST			//单链表
//#define YHTRIANGLE_TEST	//杨辉三角
//#define DLIST_TEST			//双向链表
#define STACK_TEST				//栈



static void mylist_for_each(Node_t *node)
{
	printf("%d ",node->data);
	return;
}
int main(int argc, char **argv)
{
	/*================================slist start===================================*/
#ifdef SLIST_TEST

	int i = 0;int ret = 0;
	Node_t head;
	Node_t *pnode,*tmp = NULL;
	head.data = 1000;
	head.next = NULL;
	for(;i < 20;i++)
	{
		add_head(&head,i);
		//add_tail(&head,i);
	}
	tmp = Search(&head,5);
	if(tmp)
		printf("find the node\n");
	else 
		printf("not find the node\n");
	delete_node(&head,5);
	printf("after delete node:\n");
	tmp = Search(&head,5);
	if(tmp)
		printf("find the node\n");
	else 
		printf("not find the node\n");
	pnode = head.next;
	printf("before reverse the data is :\n");
#if 0
	while(pnode)
	{
		printf("%d ",pnode->data);
		pnode = pnode->next;
	}
#endif
	list_for_each(&head,mylist_for_each);
	printf("\n");
	reverse(&head);
	pnode = head.next;
	printf("after reverse the data is :\n");
	while(pnode)
	{
		printf("%d ",pnode->data);
		pnode = pnode->next;
	}
	printf("\n");
	Destroy(&head);
	pnode = head.next;
	printf("after Destroy the data is :\n");
	while(pnode)
	{
		printf("%d ",pnode->data);
		pnode = pnode->next;
	}

#endif
	/*==================================list end=================================*/




	/*=================================yhtriangle start====================================*/
#ifdef YHTRIANGLE_TEST
	int dimension = 0;
	int value,i,j,blankcnt;
	printf("now begin the yhtriangle test!\nplease enter a num as the dimension:\n");
	scanf("%d",&dimension);
	printf("the num you enter as the dimension is %d\n",dimension);

	for(i = 1;i <= dimension;i++)
	{
		for(blankcnt = 0;blankcnt<dimension-i;blankcnt++)
			printf(" ");
		for(j = 1;j <= i;j++)
		{
			printf(" %d",Getvalue(i,j));
		}
		printf("\n");
	}
	//printf("the value is %d\n",value);


#endif
	/*=================================yhtriangle end======================================*/


	/*=====================================dlist start=====================================*/
#ifdef DLIST_TEST

	Dlist_t Dlist = {0};
	Dnode_t *cur = NULL;
	Dnode_t *tmp = NULL;
	int i;
	Dlist_init(&Dlist);
	for(i = 0;i < 10;i++)
	{
		//Dlist.Add_head(Dlist.head,i);
		Dlist.Add_tail(Dlist.head,i);
		if(i == 4)
			Dlist.Add_tail(Dlist.head,i);;
	}

	printf("after add_head,the data is:\n");
	for(cur = Dlist.head->next;cur != Dlist.head;cur = cur->next)
	{
		Dlist.List_for_each(cur);
	}
	printf("\n");

	tmp = Dlist.Search(Dlist.head,7);
	if(tmp)
		printf("find the node\n");
	else
		printf("not find the node\n");

	Dlist.Delete(Dlist.head,4);
	printf("after delete:\n");
	for(cur = Dlist.head->next;cur != Dlist.head;cur = cur->next)
	{
		Dlist.List_for_each(cur);
	}
	printf("\n");

	Dlist.Destroy(Dlist.head);
	printf("after Destroy,the data is:\n");
	for(cur = Dlist.head->next;cur != Dlist.head;cur = cur->next)
	{
		Dlist.List_for_each(cur);
	}

	Dlist_deinit(&Dlist);
#endif
	/*======================================dlist end======================================*/



	/*=======================================stack start=======================================*/
#ifdef STACK_TEST

	Stack_t *stack = (Stack_t*)malloc(sizeof(Stack_t));
	Dnode_t *cur,*tmp = NULL;
	int i,j,count;
	if(stack)
	{
		Stack_init(stack);
		for(i = 0;i < 10;i++)
		{
			stack->Push(stack,i);
		}
#if 1
		tmp = stack->head->next;
		while(tmp != stack->head)
			{
				printf("%d ",tmp->data);
				tmp = tmp->next;
			}
		printf("\n");
#endif
#if 1
		count = stack->GetElemNum(stack);
		printf("[%d]the stack count is %d\n",__LINE__,count);
		for(i = 0;i < count-3;i++)
		{
			cur = stack->Pop(stack);
			if(cur)
			{
				printf("[%d]now the %d is poped\n",__LINE__,cur->data);
				free(cur);
			}
			printf("after pop the stack data is :\n");
			tmp = stack->head->next;
			while(tmp != stack->head)
			{
				printf("%d ",tmp->data);
				tmp = tmp->next;
			}
			printf("\n");
		}
#endif
		stack->Destroy(stack);
		Stack_deinit(stack);
	}
	else
		printf("[%d]out of memory\n",__LINE__);

#endif
	/*=====================================stack end============================================*/

    while(1)
	{
		Sleep(5000);
		break;
	}
	return 0;
}
