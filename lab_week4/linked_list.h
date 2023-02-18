#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_


using namespace std;

enum {
      NUMBER = 10
};

struct node {
  int number;
  struct node * next;
  struct node * jumper;
};

struct node* build_linked_list(const int elements);

int print_array_list(struct node * list, const int elements);

struct node * pointer_jumper_linked_list(struct node * linked_list, const int elements);

int print_linked_list(struct node * list, const int elements);
int delete_linked_list(struct node * list, const int elements); 


int sum_values_in_linked_list(struct node * list, const int elements);

struct node * array_ptrs_to_each_element_in_linked_list(struct node * origional_list, const int element);

int print_jumper_next_node(struct node * array_ptrs, const int elements);

int * f0(int x);

int g(int * x);

#endif
