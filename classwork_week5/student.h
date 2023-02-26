#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

struct student {
    int id;
    string name;
    int final;
    int midterm;
    vector<int> hw_grades;
};

void get_input(student &s);

double average_score(student &s);

#endif