#ifndef _STACKP1_H_
#define _STACKP1_H_
#include <stack>

using namespace std;

stack<struct T> s_file_input(const char* filename);
int stack_add(stack<struct T> my_stack);
struct T stack_pop(stack<struct T> my_stack);


#endif
