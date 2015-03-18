#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "slist.h"
/*
*this is the list with head,noloop;by Jack @2015.03.04
*/
#define NOLOOP


Node_t *add_head(Node_t *head,int data)
{
    //assert(head != NULL);
    Node_t *node = (Node_t *)malloc(sizeof(Node_t));
    //assert(node != NULL);
	Node_t *pnode = head->next;
    node->data = data;
    node->next = NULL;//��ѭ��

    if(!pnode)
    {
        head->next = node;
#ifndef NOLOOP   
        node->next = head;//��Ϊѭ��
#endif
        
    }
    else
    {
        node->next = head->next;
        head->next = node;
    }
    return node;
}

Node_t *add_tail(Node_t *head,int data)
{
    //assert(head != NULL);
    Node_t *node = (Node_t *)malloc(sizeof(Node_t));
    //assert(node != NULL);
	Node_t *pnode = head->next;
    node->data = data;
    node->next = NULL;//��ѭ��
	if(!pnode)
	{
		head->next = node;
		return node;
	}
	while(pnode->next)
    {
        pnode = pnode->next;
    }
    pnode->next = node;
#ifndef NOLOOP
    node->next = head;//ѭ��
#endif
    return node;
}

int delete_node(Node_t *head,int data)
{
    //assert(head != NULL);
    Node_t *pnode = head->next;
    Node_t *pre = head;
#ifdef NOLOOP
    while(pnode)
#else
    while(pnode->next != head)
#endif
    {
        if(pnode->data == data)
        {
            pre->next = pnode->next;
            free(pnode);
            return 0;//�ҵ��ýڵ㲢�ɹ�ɾ���ýڵ�
            
        }
        pre = pnode;
        pnode = pnode->next;
    }
    return 1;//δ�ҵ��ýڵ�
}
#if 1
int list_for_each(Node_t *head,void (*todo)(Node_t *node))
{
    //assert(head != NULL);
    Node_t *pnode = head;
#ifdef NOLOOP
    for(;pnode->next;pnode = pnode->next)
#else
    for(;pnode->next != head;pnode = pnode->next)
#endif
    {
        todo(pnode);
    }
}
#endif
Node_t *Search(Node_t *head,int data)
{
    //assert(head != NULL);
    Node_t *pnode = head->next;
#ifdef NOLOOP
    while(pnode)
#else
    while(pnode->next != head)
#endif
    {
        if(pnode->data == data)
        {
            return pnode;//�ҵ��ýڵ�
        }
        pnode = pnode->next;
    }
    return NULL;//δ�ҵ��ýڵ�
}

//������ķ�ת(����)
Node_t *reverse(Node_t *head)
{
    //assert(head != NULL);
    Node_t *p1 = head;
    Node_t *p2 = head->next;
    Node_t *p3 = NULL;
	Node_t *tmp = NULL;
    while(p2->next)
    {
        p3 = p2->next;
        tmp = p3;
        p2->next = p3->next;
        p3->next = head->next;
        p1->next = tmp;
    }
    return head;
}

int Destroy(Node_t *head)
{
    //assert(head != NULL);
    Node_t *pnode = head->next;
#ifdef NOLOOP
	while(pnode)
    {
       head->next = pnode->next;
       free(pnode);
	   //head->next = pnode->next;
	   pnode = head->next;
    }
	free(head->next);
	head->next = NULL;
        return 0;

#else
    while(pnode != head)
    {
        head->next = pnode->next;
        free(pnode);
        pnode = pnode->next;        
    }
        return 0;
#endif
}
