#include "stackp1.h"
#include "tests.h"
#include <cstdio>
#include <iostream>
#include <stdexcept>

using namespace std;

stack<struct T> s_file_input(const char* x) {
  FILE* open_;
  open_ = fopen(x, "r");
  if(open_ == NULL) {
    exit(1);
  }
  stack<T> ret_a;
  int count = 0;
  char* new_l = (char*)malloc(sizeof(int));
   
  while(fscanf(open_, "%[^\n] ", new_l) != EOF) {
    int tot = atoi(new_l);
    T s = newstrct(tot, count);
    ret_a.push(s);
    count++;
  }

  return ret_a;
}


struct T stack_pop(stack<struct T> st) {
  T ret_a = st.top();
  st.pop();
  return ret_a
  ;
}

int stack_add(stack<struct T> st) {
  int ret_a = 0;
  while(!st.empty()) {
    T s = st.top();
    ret_a += s.number;
    st.pop();
  }

  if(ret_a < 0) {
    throw logic_error("neg sum");
  }
  
  return ret_a;
}
