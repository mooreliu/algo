#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef int BOOL;

#define TRUE 0;
#define FALSE 1;


typedef struct SingleLinkListNode {
    void* data;
    struct SingleLinkListNode* next; 
} SingleLinkListNode;

typedef struct SingleLinkList {
    SingleLinkListNode* head;
    SingleLinkListNode* tail;
    size_t size;
}SingleLinkList;

BOOL init();

BOOL add(void* data);

BOOL del(int pos);

BOOL insert(void* data, int pos);

#endif