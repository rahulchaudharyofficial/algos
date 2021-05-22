#include "linklist.h"

struct LinkListNode
{
    void *data;
    struct LinkListNode *link;
};

struct LinkListHead
{
    int count;
    struct LinkListNode *position;
    struct LinkListNode *head;
    struct LinkListNode *rear;
    int (*compare)(void *, void *);
};

bool is_empty_list(llhead_t *list)
{
    return (list != NULL && list->count == 0) ? true : false;
}

bool is_full_list(llhead_t *list)
{
    bool result = true;
    llnode_t *node = (llnode_t *)malloc(sizeof(llnode_t));
    if (node)
    {
        result = false;
        free(node);
    }
    return result;
}

llhead_t *create_list(int (*compare)(void *arg1, void *arg2))
{
    llhead_t *list = (llhead_t *)malloc(sizeof(llhead_t));
    assert(list != NULL);
    list->count = 0;
    list->head = NULL;
    list->position = NULL;
    list->rear = NULL;
    list->compare = compare;
    return list;
}

llhead_t *destroy_list(llhead_t *list)
{
    assert(list != NULL);
    free(list);
}

bool add_node(llhead_t *list, void *data)
{
    assert(list != NULL);
    bool result = false;
    llnode_t *node = (llnode_t *)malloc(sizeof(llnode_t));
    if (node)
    {
        node->data = data;
        node->link = NULL;
        if (is_empty_list(list))
        {
            list->head = node;
            list->rear = node;
            list->position = node;
        }
        else
        {
            list->rear->link = node;
            list->rear = node;
        }
        (list->count)++;
        result = true;
    }

    return result;
}

bool remove_node(llhead_t *list, void *data)
{
    assert(list != NULL);
    assert(data != NULL);
    return false;
}

bool search(llhead_t *list, void *data)
{
    assert(list != NULL);
    assert(data != NULL);
    return false;
}

llnode_t *retrieve(llhead_t *list, void *data)
{
    return NULL;
}

void traverse(llhead_t *list)
{
}

int list_size(llhead_t *list)
{
    return -1;
}