#include "queuep1.h"
#include "tests.h"
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <queue>
using namespace std;

queue<struct T> q_file_input(const char* x) {
  FILE* _open_;
  _open_ = fopen(x, "r");
  if(_open_ == NULL) {
    exit(1);
  }
  queue<T> ret_a;
  char* new_l = (char*)malloc(sizeof(int));
  int count = 0;

  while(fscanf(_open_,"%[^\n] ", new_l) != EOF) {
    int tot = atoi(new_l);
    T s = newstrct(tot, count);
    ret_a.push(s);
    count++;
  }
  
  return ret_a;
}

struct T queue_pop(queue<struct T> qt) {
  T ret_a = qt.front();
  qt.pop();
  return ret_a;
}

int queue_add(queue<struct T> qt) {
  int ret_a = 0;
  while(!qt.empty()) {
    T s = qt.front();
    ret_a += s.number;
    qt.pop();
  }

  if(ret_a < 0) {
    throw logic_error("neg sum");
  }

  return ret_a;
}
