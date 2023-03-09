#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "perfect_integer_lambda.h"

using namespace std;

TEST_CASE("Testing with input") {
    vector<int> input_list = {6, 10, 28, 30, 496, 8128};
    vector<int> expected_output = {6, 28, 496, 8128};
    
    vector<int> result = find_perfect_numbers(input_list);
    
    CHECK(result == expected_output);
}



TEST_CASE("Testing Empty Input") {
    vector<int> input_list = {};
    vector<int> expected_output = {};
    
    vector<int> result = find_perfect_numbers(input_list);
    
    CHECK(result == expected_output);
}


TEST_CASE("Testing no perfect number") {
    vector<int> input_list = {1, 2, 4, 8, 16, 32};
    vector<int> expected_output = {};
    
    vector<int> result = find_perfect_numbers(input_list);
    
    CHECK(result == expected_output);
}



TEST_CASE("Testing empty vector") {
    vector<int> input_list = {};
    vector<int> expected_output = {};
    CHECK(find_perfect_numbers(input_list) == expected_output);
}



TEST_CASE("Testing Vector 1") {
    vector<int> input_list = {6};
    vector<int> expected_output = {6};
    CHECK(find_perfect_numbers(input_list) == expected_output);
}



TEST_CASE("Testing Vector 5") {
    vector<int> input_list = {10, 15, 28, 30, 33};
    vector<int> expected_output = {28};
    CHECK(find_perfect_numbers(input_list) == expected_output);
}
