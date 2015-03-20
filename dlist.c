#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>


static Dnode_t *Add_head(Dnode_t*head,int data)
{
	Dnode_t *Dnode = NULL;
	if(!head)
	{
		printf("the param is not correct!\n");
		return NULL;
	}
		
	Dnode = malloc(sizeof(Dnode_t));
	if(!Dnode)
	{
		printf("out of memory ,malloc failed\n");
		return NULL;
	}
	Dnode->data = data;
	Dnode->next = head->next;
	Dnode->prev = head;
	head->next = Dnode;
	Dnode->next->prev = Dnode;
	return Dnode;
}

static Dnode_t *Add_tail(Dnode_t*head,int data)
{
	Dnode_t *Dnode = NULL;
	if(!head)
	{
		printf("the param is not correct!\n");
		return NULL;
	}
		
	Dnode = malloc(sizeof(Dnode_t));
	if(!Dnode)
	{
		printf("out of memory ,malloc failed\n");
		return NULL;
	}
	Dnode->data = data;
	Dnode->prev = head->prev;
	Dnode->next = head;
	head->prev->next = Dnode;
	head->prev = Dnode;

	return Dnode;
}

static Dnode_t *Search(Dnode_t*head,int data)
{
	Dnode_t *cur = NULL;
	if(!head)
	{
		printf("the param is not correct!\n");
		return NULL;
	}
	cur = head;
	do{
		if(cur->data == data)
			return cur;
		cur = cur->next;
	}while(cur != head);//忘记分号了一开始
		
	return NULL;
}

static int Delete(Dnode_t*head,int data)
{
	Dnode_t *cur = NULL;
	Dnode_t *tmp = NULL;
	if(!head)
	{
		printf("the param is not correct!\n");
		return -1;
	}
	cur = head->next;
	while(cur->next != head)
	{
		if(cur->data == data)
		{
			cur->prev->next = cur->next;
			tmp = cur->next;
			cur->next->prev = cur->prev;
			free(cur);
			cur = tmp;
			printf("delete one specified node successful!\n");
		}
		else
			cur = cur->next;
	}
	return 0;
}

static void List_for_each(Dnode_t*Dnode)
{
	printf("%d ",Dnode->data);
	return;
}

static int Destroy(Dnode_t*head)
{
	Dnode_t *cur = NULL;
	Dnode_t *tmp = NULL;
	if(!head)
	{
		printf("the param is not correct!\n");
		return -1;
	}
	cur = head->next;
	while(cur !=head)
	{
		tmp = cur->next;
		head->next = tmp;
		free(cur);
		cur = tmp;
	}
	return 0;
}

int Dlist_init(Dlist_t *Dlist)
{
	if(!Dlist)
	{
		printf("param is not correct\n");
		return -1;
	}
	Dlist->head = malloc(sizeof(Dnode_t));
	if(!Dlist->head)
	{
		printf("out of memory ,malloc failed\n");
		return -1;
	}
	Dlist->head->prev = Dlist->head;
	Dlist->head->next = Dlist->head;
	Dlist->Add_head = Add_head;
	Dlist->Add_tail = Add_tail;
	Dlist->Search = Search;
	Dlist->List_for_each = List_for_each;
	Dlist->Delete = Delete;
	Dlist->Destroy = Destroy;
	return 0;
}

int Dlist_deinit(Dlist_t *Dlist)
{
	if(!Dlist)
	{
		printf("param is not correct!\n");
		return -1;
	}
	if(Dlist->head)
	{
		free(Dlist->head);
		Dlist->head = NULL;
	}
	Dlist->Add_head = NULL;
	Dlist->Add_tail = NULL;
	Dlist->Search = NULL;
	Dlist->List_for_each = NULL;
	Dlist->Delete = NULL;
	Dlist->Destroy = NULL;
	return 0;
}