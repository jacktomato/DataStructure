#include <stdio.h>
#include <string.h>
#include "slist.h"
//#include "stack.h"
#include <windows.h>

int main(int argc, char **argv)
{
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
	while(pnode)
	{
		printf("%d ",pnode->data);
		pnode = pnode->next;
	}
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
    while(1)
	{
		Sleep(10000);
		break;
	}
	return 0;
}
