#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "linked_list.h"

const int LIST_LENGTH_0 = 0;
struct node *linked_list_0 = build_linked_list(LIST_LENGTH_0);

const int LIST_LENGTH_1 = 1;
struct node *linked_list_1 = build_linked_list(LIST_LENGTH_1);

const int LIST_LENGTH_2 = 2;
struct node *linked_list_2 = build_linked_list(LIST_LENGTH_2);


const int LIST_LENGTH_10 = 10;
struct node *linked_list_10 = build_linked_list(LIST_LENGTH_10);


const int LIST_LENGTH_7 = 7;
struct node *linked_list_7 = build_linked_list(LIST_LENGTH_7);

const int LIST_LENGTH_8 = 8;
struct node *linked_list_8 = build_linked_list(LIST_LENGTH_8);

const int LIST_LENGTH_3 = 3;
struct node *linked_list_3 = build_linked_list(LIST_LENGTH_3);

struct node *array_of_elts = array_ptrs_to_each_element_in_linked_list(linked_list_3, LIST_LENGTH_3);
struct node *t_list = linked_list_3;

struct node * my_copy = array_ptrs_to_each_element_in_linked_list(linked_list_3, 3);

//print_jumper_next_node(my_copy, 3);

int * x = f0(4);

int a = g(x);

TEST_CASE("Testing pointer_jumped_linked_list") {
  struct node * end = pointer_jumper_linked_list(linked_list_0, LIST_LENGTH_0);
  CHECK(end->next == end); // the last node points to itslf
  // if there are zero nodes, the anchor made points to itslf
  
  end = pointer_jumper_linked_list(linked_list_1, LIST_LENGTH_1);
  CHECK(end->next->next == end ); // the last node points to itslf
  
  }


TEST_CASE("Testing build linked list") {
  std::cout << "size of struct node: " << sizeof(node) << std::endl;
  print_linked_list(linked_list_0, LIST_LENGTH_0);
  print_linked_list(linked_list_1, LIST_LENGTH_1);
  print_linked_list(linked_list_2, LIST_LENGTH_2);
  print_linked_list(linked_list_10, LIST_LENGTH_10);
  print_linked_list(linked_list_7, LIST_LENGTH_7);
  print_linked_list(linked_list_8, LIST_LENGTH_8);
  
  
  
  CHECK(delete_linked_list(linked_list_0, LIST_LENGTH_0) == LIST_LENGTH_0);
  CHECK(delete_linked_list(linked_list_1, LIST_LENGTH_1) == LIST_LENGTH_1);
  CHECK(delete_linked_list(linked_list_2, LIST_LENGTH_2) == LIST_LENGTH_2);
  CHECK(delete_linked_list(linked_list_10, LIST_LENGTH_10) == LIST_LENGTH_10);
  CHECK(delete_linked_list(linked_list_7, LIST_LENGTH_7) == LIST_LENGTH_7);
  CHECK(delete_linked_list(linked_list_8, LIST_LENGTH_8) == LIST_LENGTH_8);
  }
