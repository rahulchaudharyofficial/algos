#ifndef _QUEUE_H_
#define _QUEUE_H_
    #include<stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    #include<assert.h>

    typedef struct Node qnode_t;
    typedef struct Queue queue_t;

    queue_t* create_queue();
    qnode_t* create_qnode();
    void destroy_queue(queue_t*);
    bool enqueue(queue_t*, void*);
    void* dequeue(queue_t*);
    void* front(queue_t*);
    void* rear(queue_t*);
    int queue_size(queue_t*);
#endif