#if 1

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
		while(NULL != tail && tail->next != NULL) tail = tail->next;

		tail->next = newNode;
	}

}

void sll_insertNode(Node** current, Node* newNode) {
	if(*current == null) return;
	current->next = newNode;
}

void sll_insertNewHead(Node** head, Node* newNode) {
	if(null == head) return;
	newNode->next = head;
	*head = newNode;
}

void sll_removeNode(Node** head, Node* deleteNode) {
	if(*head == nullptr || deleteNode == nullptr) return;
	if(*head == deleteNode) {
		Node* node = *head;
		*head = *head->next;
		free(node);
	}
	else {
		Node* prev = node = *head;
		while(node != NULL && node != deleteNode) {
			prev = node;
			node = node->next;
		}
		if(node) {
			prev->next = node->next;
			free(node);
		}
	}
}

void sll_clear(Node** head) {
	Node* t = node = *head;
	while(node != nullptr) {
		t = node;
		node = node->next;
		delete t;
	}

	*head = t = node = nullptr;
}

size_t sll_size(Node* head) {
	Node* n = head;
	size_t size = 0;
	

	while(n != nullptr) {
		n = n->next;
		size++;
	}
	return size;
}

Node* sll_getNodeAt(Node** head, int location) {
	Node* node = *head;
	while(node && location-->0) {
		node = node->next;
	}
	return node;
}
#endif
