#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <mu.h>


struct entry {
    struct entry *next;
    size_t        hash;
    void         *data;
    size_t        data_size;
    int           data_type;
    unsigned char name[];
};

typedef struct {
    size_t         size;
    size_t         used;  /* Number of entries, total */
    struct entry **slot;  /* Array of entry pointers */
    size_t       (*hash)(const unsigned char *, size_t);
} hashmap;

int hashmap_new(hashmap *hmap, const size_t size,
                size_t (*hash)(const unsigned char *, size_t))
{
    if (!hmap)
        return -1; /* No hashmap specified */

    hmap->size = 0;
    hmap->used = 0;
    hmap->slot = NULL;
    hmap->hash = NULL;

    if (size < 1)
        return -1; /* Invalid size */
    if (!hash)
        return -1; /* No hash function specified. */

    // hmap->slot = calloc(size, sizeof hmap->slot[0]);
	hmap->slot = (struct entry**)malloc(size*sizeof(hmap->slot[0]));
    if (!(hmap->slot)) {
        return -1; /* Not enough memory */
    }
	memset(hmap->slot, 0, sizeof(hmap->slot[0])*size);
    hmap->size = size;
    hmap->hash = hash;

    return 0;
}

void hashmap_free(hashmap *hmap)
{
    if (hmap) {
        size_t  i = hmap->size;
        while (i-->0) {
            struct entry *next = hmap->slot[i];
            struct entry *curr;

            while (next) {
                curr = next;
                next = next->next;

                free(curr->data);

                /* Poison the entry, to help detect use-after-free bugs. */
                curr->next = NULL;
                curr->data = NULL;
                curr->hash = 0;
                curr->data_size = 0;
                curr->data_type = 0;
                curr->name[0] = '\0';

                free(curr);
            }
        }
    }

    free(hmap->slot);
    hmap->size = 0;
    hmap->used = 0;
    hmap->slot = NULL;
    hmap->hash = NULL;
}

int hashmap_add(hashmap *hmap, const unsigned char *name,
                const void *data, const size_t data_size,
                const int data_type)
{
    const size_t  namelen = (name) ? strlen((const char*)name) : 0;
    struct entry *curr;
    size_t        i;

    if (!hmap)
        return -1; /* No hashmap specified. */

    if (namelen < 1)
        return -1; /* NULL or empty name. */

    /* Allocate memory for the hashmap entry,
       including enough room for the name, and end of string '\0'. */
    curr = (struct entry*)malloc(sizeof(struct entry) + namelen + 1);
    if (!curr)
        return -1; /* Out of memory. */

    /* Copy data, if any. */
    if (data_size > 0) {
        curr->data = malloc(data_size);
        if (!curr->data) {
            free(curr);
            return -1; /* Out of memory. */
        }
        memcpy(curr->data, data, data_size);
    } else {
        curr->data      = NULL;
        curr->data_size = 0;
    }

    curr->data_type = data_type;

    /* Calculate the hash of the name. */
    curr->hash = hmap->hash(name, namelen);

    /* Copy name, including the trailing '\0'. */
    memcpy(curr->name, name, namelen + 1);

    /* Slot to prepend to. */
    i = curr->hash % hmap->size;

    curr->next = hmap->slot[i];
    hmap->slot[i] = curr;

    /* An additional node added. */
    hmap->used++;

    return 0;
}


/* Returns 0 if found. */
int hashmap_find(hashmap *hmap, const unsigned char *name,
                 const int data_type,
                 void **dataptr_to, size_t *size_to)
{
    struct entry  *curr;
    size_t         hash;

    if (size_to)
        *size_to = 0;
    if (dataptr_to)
        *dataptr_to = NULL;

    if (!hmap)
        return -1; /* No hashmap specified. */
    if (!name || !*name)
        return -1; /* NULL or empty name. */

    hash = hmap->hash(name, strlen((const char*)name));
    curr = hmap->slot[hash % hmap->size];

    for (curr = hmap->slot[hash % hmap->size]; curr != NULL; curr = curr->next) {
        if (curr->data_type == data_type && curr->hash == hash &&
            !strcmp((const char*)curr->name, (const char*)name)) {
            /* Data type an name matches. Save size if requested. */
            if (size_to)
                *size_to = curr->data_size;
            if (dataptr_to)
                *dataptr_to = curr->data;
            return 0; /* Found. */
        }
    }

    return -1; /* Not found. */
}

void cls() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
