#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "student.h"

#include "doctest.h"
#include <iostream>
#include "student.h"
using namespace std;


TEST_CASE("CHECKING TEST") {
}

TEST_CASE("Testing 1") {
    student s1;
    s1.id = 1;
    s1.name = "Walter";
    s1.final = 80;
    s1.midterm = 75;
    s1.hw_grades = {90, 85, 95};

    double correct_val = 82.5;
    double our_val = average_score(s1);
   CHECK(our_val == correct_val);
}


TEST_CASE("Testing 2"){
    student s;
    s.name = "Jen";
    s.final = 100;
    s.midterm = 100;
    s.hw_grades = {100,100,100,100,100,100};
    double total_s = average_score(s);
    CHECK(total_s == 100);
}

TEST_CASE("Testing 3"){
    student s2;
    s2.name = "Nichole";
    s2.final = 87;
    s2.midterm = 78;
    s2.hw_grades = {89,97,87,100,99,100,98,79};
    double total_s = average_score(s2);
    CHECK(total_s == 86.95);
}

TEST_CASE("Testing 4") {
    student s4;
    s4.id = 1432;
    s4.name = "Tim";
    s4.final = 0;
    s4.midterm = 0;
    s4.hw_grades = {0, 0, 0};
    
    double our_val = average_score(s4);
    CHECK(our_val == 0);
    double hw_checker = 0;
    for(auto e : s4.hw_grades) {
      hw_checker += e;
      CHECK(hw_checker == 0);
      }
}


