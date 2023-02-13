#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "stackp1.h"
#include "queuep1.h"
#include "doctest.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "tests.h"

using namespace std;

struct T newstrct(int number, int id) {
  T result;
  result.number = number;
  result.id = id;
  return result;
}


TEST_CASE("QUEUE TESTS") {
  queue<T> qt = q_file_input("test_file.txt");
  queue<T> non_positive_queue = q_file_input("test_file2.txt");
  CHECK(non_positive_queue.front().id == 0);
  CHECK_THROWS_WITH(queue_add(non_positive_queue), "neg sum");
  CHECK(qt.front().id == 0);
  T s = queue_pop(qt);
  CHECK(s.id == 0);
  int sum = queue_add(qt);
  CHECK(sum > 0);

}


TEST_CASE("STACK TESTS") {
  stack<T> st = s_file_input("test_file.txt");
  stack<T> non_positive_stack = s_file_input("test_file2.txt");
  CHECK(non_positive_stack.top().id > 0);
  CHECK_THROWS_WITH(stack_add(non_positive_stack), "neg sum");
  CHECK(st.top().id > 0);
  T s = stack_pop(st);
  CHECK(s.id > 0);
  int sum = stack_add(st);
  CHECK(sum > 0);
}
