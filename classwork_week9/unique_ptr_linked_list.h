#ifndef UNIQUE_PTR_LINKED_LIST_H
#define UNIQUE_PTR_LINKED_LIST_H

#include <memory>
using namespace std;

struct List {
    struct Node {
        int data;
        unique_ptr<Node> next;

        Node(int data) : data(data), next(nullptr) {}
    };

    unique_ptr<Node> head;

    ~List();

    void push(int data);
};
#endif


