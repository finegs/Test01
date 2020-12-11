#include <stdlib.h>
#include <string.h>

#include "M_Linkedlist.h"


void list_init(List* list,  void (*destroy)(void *(data))) {
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
}

void list_destroy(List *list) {
	void* data;
	while(list_size(list)>0) {
		if(list_rem_next(list, NULL, (void*)&data) == 0 && list->destroy != NULL) {
			list->destroy(data);
		}
	}

	memset(list, 0, sizeof(List));
}

int list_ins_next(List* list, ListElmt* element, const void* data) {
	ListElmt* newElmt;

	if((newElmt = (ListElmt*)malloc(sizeof(ListElmt))) == NULL) {
		return -1;
	}

	newElmt->data = (void*)data;
	if(element == NULL) {
		if(list_size(list) == 0)
			list->tail = newElmt;

		newElmt->next = list->head;
		list->head = newElmt;
	}
	else {
		if(element->next == NULL)
			list->tail = newElmt;

		newElmt->next = element->next;
		element->next = newElmt;
	}
	list->size++;

	return 0;
}

int list_rem_next(List* list, ListElmt* element, void **data) {
	ListElmt *oldElmt;

	if(list_size(list) == 0) return -1;

	if(element == NULL) {
		*data = list->head->data;
		oldElmt = list->head;
		list->head = list->head->next;

		if(list_size(list) == 1) 
			list->tail = NULL;
		
	} else {
		if(element->next = NULL) 
			return -1;
		*data  = element->next->data;
		oldElmt = element->next;
		element->next = element->next->next;
		if(element->next = NULL)
			list->tail = element;

	}
	free(oldElmt);
	list->size--;
	return 0;
}



