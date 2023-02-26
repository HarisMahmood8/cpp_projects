#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

struct student;

void get_input(student &s);

double average_score(student &s);

#endif