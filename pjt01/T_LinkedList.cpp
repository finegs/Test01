#include "T_LinkedList.hpp"


Node* sll_createNode(ElementType newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = newData;
	newNode->nextNode = NULL;

	return newNode;
}

void* sll_destroyNode(Node* node) {
	free(node);
}

void sll_appendNode(Node** head, Node* newNode) {
	if(*(head) == NULL) {
		*head = newNode;
	}
	else {
		Node* tail = *(head);
		while(NULL != tail && tail->


