#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "btree.h"

// File for sandboxing and trying out code
int main(int argc, char **argv) {
  // Add your code
  node *list = make_node(1, make_node(2, make_node(3, make_node(4, make_node(5, NULL)))));

  print_list(list);

  printf("\n\n");

  node *ns = NULL;

  printf("%d", sum_squares(ns));

  printf("\n\n");

  print_list(map(list, square));



  printf("\n\n\n BTREE: \n\n");

  struct tree_node* root = NULL;

	root = Initialize(root);
	root = Insert(20, root);
	root = Insert(5, root);
	root = Insert(1, root);
	root = Insert(15, root);
	root = Insert(9, root);
	root = Insert(7, root);
	root = Insert(12, root);
	root = Insert(30, root);
	root = Insert(25, root);
	root = Insert(40, root);
	root = Insert(45, root);
	root = Insert(42, root);
  

  int check = Contains(7, root);

  printf("%d \n", check);

  root = Remove(7, root);

  check = Contains(7, root);

  printf("%d \n", check);

  root = Insert(-1, root);
  root = Insert(-1, root);

  root = Remove(-1, root);

  check = Contains(-1, root);

  printf("%d \n", check);
  return 0;
}