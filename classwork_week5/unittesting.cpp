#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "student.h"

#include "doctest.h"
#include <iostream>
#include "student.h"
using namespace std;


TEST_CASE("CHECKING TEST") {
    int x = 1;
    CHECK(x == 1);
}

TEST_CASE("Testing the average_score function") {
    student s1;
    s1.id = 1;
    s1.name = "John";
    s1.final = 80;
    s1.midterm = 75;
    s1.hw_grades = {90, 85, 95};

    double expected_avg = 85.5;
    double actual_avg = average_score(s1);

    CHECK(actual_avg == doctest::Approx(expected_avg).epsilon(0.01));
}