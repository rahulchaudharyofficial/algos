#include "tree.h"

struct TreeNode
{
	void* value;
	struct TreeNode* left;
	struct TreeNode* right;
};

tnode_t* create_tree_node(void* value)
{
	tnode_t* node = (tnode_t*)malloc(sizeof(tnode_t));
	if (node)
	{
		node->value = value;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

void print_tree(tnode_t* root)
{
	if (root)
	{
		printf(" %d ", *((int*)root->value));
		if(root->left)
		{	
			printf(" ( ");
			print_tree(root->left);
		}
		if(root->right)
		{
			print_tree(root->right);
			printf(" ) ");
		}
	}
	else {
		return;
	}
}

//DFT (Deapth first traversal) examples start

//Root - Left - Right
void pre_order_traversal(tnode_t* root)
{
	if(root)
	{
		printf(" %d ", *((int*)root->value));
		if(root->left)
		{	
			printf(" ( ");
			print_tree(root->left);
		}
		if(root->right)
		{
			print_tree(root->right);
			printf(" ) ");
		}
	}
}

//Left - Root - Right
void in_order_traversal(tnode_t* root)
{
	if(root)
	{
		if(root->left)
		{
			in_order_traversal(root->left);
		}
		printf(" %d ", *((int*)root->value));
		if(root->right)
		{
			print_tree(root->right);
		}
	}
}

void post_order_traversal(tnode_t* root)
{
	if(root)
	{
		if(root->left != NULL)
		{
			print_tree(root->left);
		}
		if(root->right != NULL)
		{
			print_tree(root->right);
		}
		printf(" %d ",*((int*)root->value));
	}
}

//DFT (Deapth first traversal) examples end


//BFT (Breadth first traversal) Start
//OUTPUT = 1 4 6 2 3 7 8
void breath_first_traversal(tnode_t* root, queue_t* queue)
{
	if(root)
	{
		tnode_t* current_node = root;
		while(current_node != NULL)
		{
			printf("%d ",*((int*) current_node->value));
			if(current_node->left)
			{
				enqueue(queue, current_node->left);
			}

			if(current_node->right)
			{
				enqueue(queue,current_node->right);
			}
			if(!is_queue_empty(queue))
			{
				current_node = (tnode_t*) dequeue(queue);
			}
			else {
				current_node = NULL;
			}
		}
	}
}

/*
*								(1)
*					(4)						(6)
*				(2)		(3)				(7)		(8)
*/
/*
int main(int argc, char** argv)
{
	//Build Test Data
	int x1 = 1;
	int* xp1 = (int*)malloc(sizeof(int));
	xp1 = &x1;
	tnode_t* root = create_tree_node(xp1);

	int x2 = 2;
	int* xp2 = (int*)malloc(sizeof(int));
	xp2 = &x2;
	tnode_t* n2 = create_tree_node(xp2);

	int x3 = 3;
	int* xp3 = (int*)malloc(sizeof(int));
	xp3 = &x3;
	tnode_t* n3 = create_tree_node(xp3);

	int x4 = 4;
	int* xp4 = (int*)malloc(sizeof(int));
	xp4 = &x4;
	tnode_t* n4 = create_tree_node(xp4);

	int x5 = 5;
	int* xp5 = (int*)malloc(sizeof(int));
	xp5 = &x5;
	tnode_t* n5 = create_tree_node(xp5);

	int x6 = 6;
	int* xp6 = (int*)malloc(sizeof(int));
	xp6 = &x6;
	tnode_t* n6 = create_tree_node(xp6);

	int x7 = 7;
	int* xp7 = (int*)malloc(sizeof(int));
	xp7 = &x7;
	tnode_t* n7 = create_tree_node(xp7);

	int x8 = 8;
	int* xp8 = (int*)malloc(sizeof(int));
	xp8 = &x8;
	tnode_t* n8 = create_tree_node(xp8);

	root->left = n4;
	root->right = n6;

	n4->left = n2;
	n4->right = n3;

	n6->left = n7;
	n6->right = n8;
	

	//print_tree(root);
	printf(" -------- Pre Order ---------- \n");
	pre_order_traversal(root);
	printf("\n");


	printf(" -------- In Order ---------- \n");
	in_order_traversal(root);
	printf("\n");


	printf(" -------- Post Order ---------- \n");
	post_order_traversal(root);
	printf("\n");destroy_queue(queue);


	printf(" -------- Breath First Traversal ---------- \n");
	queue_t* queue = create_queue();
	breath_first_traversal(root,queue);
	printf("\n");

	//Clean Test Data
	destroy_queue(queue);
	free(root);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	free(n6);
	free(n7);
	free(n8);
}
*/