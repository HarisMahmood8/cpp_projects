
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "fractions.h"
#include "doctest.h"

using namespace std;


TEST_CASE("Testing big fraction struct creation and matrix operations.") {
  bigint num_big_int("600000000000000000000000000000000000000000000000000000000000000000");
  bigint den_big_int("100000000000000000000000000000000000000000000000000000000000000000");
  bigint div_big_int = num_big_int / den_big_int;
  CHECK(div_big_int == to_bigint(6));
  division my_fraction(num_big_int,den_big_int);
  my_fraction.print();
  CHECK(my_fraction.cur.first == num_big_int);
  CHECK(my_fraction.cur.second == den_big_int);
  division mult_res = my_fraction * my_fraction;
  CHECK(mult_res.cur.first == (num_big_int * num_big_int));
  CHECK(mult_res.cur.second == (den_big_int * den_big_int));

  division addi_res = my_fraction + my_fraction;

  addi_res.print();
  
  CHECK(addi_res.cur.first == (num_big_int + num_big_int));
  CHECK(addi_res.cur.second == den_big_int);

  division a(to_bigint(1),to_bigint(4));
  division b(to_bigint(2),to_bigint(3));
  division c(to_bigint(2),to_bigint(5));
  division d(to_bigint(3),to_bigint(4));
  
  vector<vector<division>> first_fraction_vector = { {a,b},
							{c,d} };
  Matrices_division first_fraction_matrix(first_fraction_vector);
}


TEST_CASE("Testing big fraction struct creation and matrix operations.") {
  bigint num_big_int("9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210");
  bigint den_big_int("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
  bigint div_big_int = num_big_int / den_big_int;
  CHECK(div_big_int == to_bigint("80"));
  division my_fraction(num_big_int, den_big_int);
  my_fraction.print();
  CHECK(my_fraction.cur.first == num_big_int);
  CHECK(my_fraction.cur.second == den_big_int);
  division mult_res = my_fraction * my_fraction;
  CHECK(mult_res.cur.first == (num_big_int * num_big_int));
  CHECK(mult_res.cur.second == (den_big_int * den_big_int));

  division addi_res = my_fraction + my_fraction;
  addi_res.print();
  CHECK(addi_res.cur.first == (num_big_int + num_big_int));
  CHECK(addi_res.cur.second == den_big_int);

  division a(to_bigint("9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210"), to_bigint("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789"));
  division b(to_bigint("555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555"), to_bigint("666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666"));
  division c(to_bigint("444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444"), to_bigint("777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777"));
  division d(to_bigint("222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222"), to_bigint("888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888"));
  
  vector<vector<division>> first_fraction_vector = { {a,b},
                                                      {c,d} };
  Matrices_division first_fraction_matrix(first_fraction_vector);
}
