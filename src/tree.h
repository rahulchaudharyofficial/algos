#ifndef _TREE_H_
#define _TREE_H_
    #include<stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    #include<assert.h>
    typedef struct TreeNode tnode_t;
    tnode_t* create_node(void* value);
    void print_tree(tnode_t*);
    void pre_order_traversal(tnode_t*);
#endif