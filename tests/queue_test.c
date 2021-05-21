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

Test(queue_operations_test, dequeue_test)
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
	cr_assert(queue_size(queue) == 0, "Queue must be empty");
}

Test(queue_operations_test, front_test)
{
	int* dataPtr = NULL;
	for(int i = 1; i <= 5; i++)
	{
		dataPtr = (int*) malloc(sizeof(i));
		*dataPtr = i;
		enqueue(queue, dataPtr);
	}

	dataPtr = (int*) front(queue);	
	cr_assert(*dataPtr == 1, "Queue front must be 1");
}

Test(queue_operations_test, rear_test)
{
	int* dataPtr = NULL;
	for(int i = 1; i <= 5; i++)
	{
		dataPtr = (int*) malloc(sizeof(i));
		*dataPtr = i;
		enqueue(queue, dataPtr);
	}

	dataPtr = (int*) rear(queue);	
	cr_assert(*dataPtr == 5, "Queue rear must be 5");
}

Test(queue_operations_test, queue_size_test)
{
	int* dataPtr = NULL;
	for(int i = 1; i <= 5; i++)
	{
		dataPtr = (int*) malloc(sizeof(i));
		*dataPtr = i;
		enqueue(queue, dataPtr);
	}
	cr_assert(queue_size(queue) == 5, "Queue size must be 5");
}