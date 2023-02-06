#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include "doctest.h"
#include "prefix_sums.h"

int nums_0[] = {};
int nums_1[] = {-5};
int nums_2[] = {35};
int nums_3[] = {2,-3,3,2};
int nums_4[] = {1,1,-1,1};
int nums_5[] = {-1,-1,-1,-1,1,1};

int positive_test[] = {12, 14, 16,342};
int negative_test[] = {-64, -2, 1, -8};

TEST_CASE("WEEK 2 CLASSWORK UNIT TEST CASES") {
  SUBCASE("POSITIVE PREFIX SUMS") {
    CHECK(non_negative_prefix_sum(nums_4, 4) == false);
    CHECK(non_negative_prefix_sum(positive_test, 4) == false);
  };
  SUBCASE("NEGATIVE PREFIX SUMS") {
    CHECK(non_negative_prefix_sum(nums_5, 5) == true);
    CHECK(non_negative_prefix_sum(negative_test, 4) == true);
  };
}
