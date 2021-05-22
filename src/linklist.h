#ifndef _LINKLIST_H_
#define _LINKLIST_H_
    #include<stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    #include<assert.h>

    typedef struct LinkListNode llnode_t;
    typedef struct LinkListHead llhead_t;

    llhead_t* create_list(int (*compare)(void* arg1, void* arg2));
    llhead_t* destroy_list(llhead_t*);
    bool add_node(llhead_t*, void*);
    bool remove_node(llhead_t*, void*);
    bool search(llhead_t*, void*);
    llnode_t* retrieve(llhead_t*, void*);
    void traverse(llhead_t*);

    int list_size(llhead_t*);
    bool is_empty_list(llhead_t*);
    bool is_full_list(llhead_t*);

#endif