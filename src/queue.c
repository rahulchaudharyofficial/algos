#include "queue.h"

struct Node
{
    void *data;
    struct Node *link;
};

struct Queue
{
    int size;
    struct Node *front;
    struct Node *rear;
};

bool is_queue_empty(queue_t* queue)
{
	return (queue->size == 0 && queue->front == NULL && queue->rear == NULL)? true : false;
}

bool is_queue_full()
{
	bool result = true;
	qnode_t* node = (qnode_t*) malloc(sizeof(qnode_t));
	if(node)
	{
		result = false;
		free(node);
	}
	return result;
}

queue_t *create_queue()
{
	queue_t* queue = (queue_t*) malloc(sizeof(queue_t));
	assert(queue != NULL); // "StackOveflowError: Queue must not be null"
	queue -> size = 0;
	queue -> front = NULL;
	queue -> rear = NULL;
	return queue;
}

qnode_t* create_qnode()
{
	qnode_t* node = NULL;
	if(!is_queue_full())
	{
		node = (qnode_t*) malloc(sizeof(qnode_t));
		if(node)
		{
			node -> data = NULL;
			node -> link = NULL;
		}
	}
	return node;
}

void destroy_queue(queue_t* queue)
{
	assert(queue != NULL);
	qnode_t* node = NULL;
	while(queue->front != NULL)
	{
		free(queue->front->data);
		node = queue->front;
		queue->front = queue->front->link;
		free(node);
	}
	free(queue);
}

bool enqueue(queue_t* queue, void* data)
{
	/*
	 * Sanity Test
	*/
	assert(queue !=NULL);
	assert(data !=NULL);

	bool result = false;
	qnode_t* node = create_qnode();
	if(node)
	{
		node->data = data;
		if(is_queue_empty(queue)) //First node
		{
			queue->front = node;
		}
		else {
			queue->rear->link = node;
		}
		queue->rear = node;
		(queue->size)++;
		result = true;
	}
	return result;
}

void* dequeue(queue_t* queue)
{
	assert(queue != NULL);

	void* result = NULL;
	if(!is_queue_empty(queue))
	{
		qnode_t* front_node = queue->front;
		result = front_node->data;

		if(queue->size == 1)
		{
			queue->front = queue->rear = NULL;
		}
		else
		{
			queue->front = front_node->link;
		}
		(queue->size)--;
		free(front_node);
	}
	return result;
}

void* front(queue_t* queue)
{
	assert(queue != NULL);
	return !is_queue_empty(queue)? queue->front->data : NULL;
}

void* rear(queue_t* queue)
{
;	return !is_queue_empty(queue)? queue->rear->data : NULL;
}

int queue_size(queue_t* queue)
{
	assert(queue != NULL);
	return queue->size;
}