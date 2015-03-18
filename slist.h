#include <stdio.h>
#include <string.h>

#pragma once

typedef struct Node_t{
    int data;
    struct Node_t *next;
}Node_t;

typedef void (*todo)(Node_t *node);
Node_t *add_head(Node_t *head,int data);

Node_t *add_tail(Node_t *head,int data);

int delete_node(Node_t *head,int data);

int list_for_each(Node_t *head,todo);

Node_t *Search(Node_t *head,int data);

Node_t *reverse(Node_t *head);

int Destroy(Node_t *head);


