#include <queue>

#ifndef _QUEUEP1_H_
#define _QUEUEP1_H_
using namespace std;

queue<struct T> q_file_input(const char* filename);
struct T queue_pop(queue<struct T> my_queue);
int queue_add(queue<struct T> my_queue);

#endif
