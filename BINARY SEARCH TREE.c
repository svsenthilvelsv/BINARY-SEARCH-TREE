#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int data;
struct node *left;
struct node *right;
struct node *parent;
}node;

typedef struct binary_search_tree {
node *root;
}binary_search_tree;

node* new_node(int data) {
node *n = malloc(sizeof(node));
n->data = data;
n->left = NULL;
n->right = NULL;
n->parent = NULL;

return n;
}
binary_search_tree* new_binary_search_tree() {
binary_search_tree *t = malloc(sizeof(binary_search_tree));
t->root = NULL;

return t;
}
void insert(binary_search_tree *t, node *n) {
node *y = NULL;
node *temp = t->root;
while(temp != NULL) {
  y = temp;
  if(n->data < temp->data)
    temp = temp->left;
  else
    temp = temp->right;
}
n->parent = y;

if(y == NULL) //newly added node is root
  t->root = n;
else if(n->data < y->data)
  y->left = n;
else
  y->right = n;
}

