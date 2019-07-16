#ifndef __T_LINKEDLIST_HPP
#define __T_LINKEDLIST_HPP


#include <cstdio>
#include <cstdlib>

typedef int ElementType;

typedef struct tagNode
{
	ElementType data;
	struct tagNode* nextNode;
} Node;

Node* sll_createNode(ElementType newData);
void* sll_destroyNode(Node* node);
void  sll_appendNode(Node** head, Node* newNode);
void  sll_insertNode(Node** current, Node* newNode);
void  sll_insertNewHead(Node** head, Node* newNode);
void  sll_removeNode(Node** head, Node* remove);
void  sll_getNodeAt(Node* head, int location);
size_t  sll_size(Node* head);
void  sll_clear(Node** head);

#endif
