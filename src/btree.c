#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t
  struct tree_node *T = malloc(sizeof(struct tree_node)); // Creates new node
    T->item = x;
    T->left = NULL;
    T->right = NULL;
  
  if (Empty(t)) // if tree is empty, the created node will be the first node.
    return T;
  
  if (x <= t->item)                 //
    t->left = Insert(x, t->left);   // Recurses through the tree, until it finds the right spot for the node.
  else                              //
    t->right = Insert(x, t->right); //

  return t;
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t
  //assert(Contains(x, t));
  if (!Contains(x, t))
    return t;

  struct tree_node *beforet = t;
  struct tree_node *T = t;

  while (x != T->item)  // Finds the node being removed and the node before
  {                     //
    beforet = T;        //
    if (x <= T->item)   //
      T = T->left;      //
    else                //
      T = T->right;     //
  }

  if (Empty(T->right))    // Makes the left child of T replace it, if the right child is empty
    T->right = T->left;   //
  else                                      //
  {                                         //
    struct tree_node *lastleft = T->right;  // If that isn't the case, put the left child of T, on the grandest
    while (lastleft->left != NULL)          // of grand childs of the node replacing T.
      lastleft = lastleft->left;            //
    lastleft->left = T->left;               //
  }

  if (beforet->right != NULL && beforet->right->item == x)     //
    beforet->right = T->right;                                 // replaces the node being deleted with its right child.
  else if (beforet->left != NULL && beforet->left->item == x)  //
    beforet->left = T->right;                                  //
  else              //
    t=T->right;     // case for trying to remove the root

  free(T);

  return t;
}

int Contains(int x, struct tree_node *t) {
  // Return true if the tree t contains item x. Return false otherwise.
  if (t->item == x)  // Recurses through the tree until it finds the node we are looking for, if it doesn't, return 0.
    return 1;
  if (x <= t->item && t->left != NULL)
    return Contains(x, t->left);
  if (x > t->item && t->right != NULL)
    return Contains(x, t->right);

  return 0;
}

struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree
  t = NULL; // If the tree is a NULL pointer, the tree is empty, we now have a tree

  return t;
}

int Empty(struct tree_node *t) {
  // Test if empty
  if (t == NULL) // If the tree is a NULL pointer, the tree is empty
    return 1;
  return 0;
}

int Full(struct tree_node *t) {
  // Test if full
  return 0;
}
