#include "unique_ptr_linked_list.h"


List::~List() {
    while (head) {
        head = std::move(head->next);
    }
}

void List::push(int data) {
    std::unique_ptr<Node> newNode = std::make_unique<Node>(data);
    newNode->next = std::move(head);
    head = std::move(newNode);
}
