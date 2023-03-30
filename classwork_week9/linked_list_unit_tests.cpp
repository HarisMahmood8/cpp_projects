#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "unique_ptr_linked_list.h"

TEST_CASE("push ll") {
    List list;
    list.push(1);
    list.push(2);
    list.push(3);
    CHECK(list.head->data == 3);
    CHECK(list.head->next->data == 2);
    CHECK(list.head->next->next->data == 1);
}

TEST_CASE("destructor") {
    List list;
    list.push(1);
    list.push(2);
    list.push(3);
    {
        List otherList;
        otherList.push(4);
        otherList.push(5);
        otherList.head->next->next = std::move(list.head);
        CHECK(list.head == nullptr);
    }
    CHECK(list.head == nullptr);
}

// More tests can be added here
