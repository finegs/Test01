#ifndef __M_LINKEDLIST_H
#define __M_LINKEDLIST_H

#include <stdlib.h>

typedef struct ListElmt_ {
	void*	data;
	struct ListElmt_ *next;
} ListElmt;

typedef struct List_ {
	size_t size;
	int		(*match)(const void* key1, const void* key2);
	void	(*destroy)(void* data);

	ListElmt	*head;
	ListElmt	*tail;
} List;



void list_init(List *list, void (*desctroy)(void* data));
void list_desctroy(List* list);
int list_ins_next(List* list, ListElmt *element, const void *data);
int list_rem_next(List* list, ListElmt* element, void** data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 :0)
#define list_is_tail(list, element) ((element)->next == NULL ? 1 :0)
#define list_data(list) ((list)->data)
#define list_next(list) ((list)->next)

//int list_size(const List* list);
//ListElmt* list_head(const List* list);
//ListElmt* list_tail(const List* list);
//int list_is_head(const ListElmt* element);
//int list_is_tail(const ListElmt* element);
//void *list_data(const ListElmt* element);
//ListElmt* list_next(const ListElmt* element);

#endif
