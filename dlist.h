#pragma once

typedef struct Dnode_t{
	int data;
	struct Dnode_t *prev;
	struct Dnode_t *next;
}Dnode_t;

typedef struct Dlist_t{
	Dnode_t *head;
	Dnode_t *(*Add_head)(Dnode_t*head,int data);
	Dnode_t *(*Add_tail)(Dnode_t*head,int data);
	Dnode_t *(*Search)(Dnode_t*head,int data);
	int (*Delete)(Dnode_t*head,int data);
	void (*List_for_each)(Dnode_t*head);
	int (*Destroy)(Dnode_t*head);
}Dlist_t;

int Dlist_init(Dlist_t *Dlist);

int Dlist_deinit(Dlist_t *Dlist);