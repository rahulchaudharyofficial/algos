#include<criterion/criterion.h>
#include "../src/queue.h"

queue_t* queue;

void setup()
{
	queue = create_queue();
}

void teardown()
{
	if(queue)
	{
		destroy_queue(queue);
	}
}

TestSuite(queue_operations_test,.init = setup, .fini = teardown);

Test(queue_operations_test, create_queue_test)
{
	cr_assert(queue != NULL, "Queue must not be NULL");
}

void print_queue()
{
	/*
	int* data = NULL;
	if(queue_size(queue)>0)
	{
		data = (int*) dequeue(queue);
		printf("data = %d\n", *data);
		while(data != NULL)
		{
			printf("data = %d\n", *data);
			data = (int*) dequeue(queue);
		}
		printf("\n");
	}
	*/
}

Test(queue_operations_test, enqueue_test)
{
	int* dataPtr = NULL;
	for(int i = 1; i <= 10; i++)
	{
		dataPtr = (int*) malloc(sizeof(i));
		*dataPtr = i;
		enqueue(queue, dataPtr);
	}

	cr_assert(queue_size(queue) == 10, "Must be equals");
	for(int i = 1; i <= 10; i++)
	{
		int* data = (int*) dequeue(queue);
		cr_assert(*data == i, "Must be equal");
	}
	
	
}