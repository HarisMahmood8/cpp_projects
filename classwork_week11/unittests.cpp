#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "fractions.h"
#include "doctest.h"
using namespace std;


TEST_CASE("Testing matrix") {
  bigint numerator("600000000000000000000000000000000000000000000000000000000000000000");
  bigint denominator("100000000000000000000000000000000000000000000000000000000000000000");
  bigint answr = numerator / denominator;
  CHECK(answr == to_bigint(6));
  division frac_cur(numerator,denominator);
  frac_cur.outpt();
  CHECK(frac_cur.cur.first == numerator);
  CHECK(frac_cur.cur.second == denominator);
  division final_s = frac_cur * frac_cur;
  CHECK(final_s.cur.first == (numerator * numerator));
  CHECK(final_s.cur.second == (denominator * denominator));

  division adding = frac_cur + frac_cur;

  adding.outpt();
  
  CHECK(adding.cur.first == (numerator + numerator));
  CHECK(adding.cur.second == denominator);

  division first(to_bigint(1),to_bigint(4));
  division second(to_bigint(2),to_bigint(3));
  division thrd(to_bigint(2),to_bigint(5));
  division forth(to_bigint(3),to_bigint(4));
  
  vector<vector<division>> fraction_div = { {first,second},
							{thrd,forth} };
  Matrices_division matrix_frst(fraction_div);
}


TEST_CASE("Testing matrix 2") {
  bigint numerator("9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210");
  bigint denominator("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
  bigint answr = numerator / denominator;
  CHECK(answr == to_bigint("80"));
  division frac_cur(numerator, denominator);
  frac_cur.outpt();
  CHECK(frac_cur.cur.first == numerator);
  CHECK(frac_cur.cur.second == denominator);
  division final_s = frac_cur * frac_cur;
  CHECK(final_s.cur.first == (numerator * numerator));
  CHECK(final_s.cur.second == (denominator * denominator));

  division adding = frac_cur + frac_cur;
  adding.outpt();
  CHECK(adding.cur.first == (numerator + numerator));
  CHECK(adding.cur.second == denominator);

  division first(to_bigint("9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210"), to_bigint("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789"));
  division second(to_bigint("555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555"), to_bigint("666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666"));
  division thrd(to_bigint("444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444"), to_bigint("777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777"));
  division forth(to_bigint("222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222"), to_bigint("888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888"));
  
  vector<vector<division>> fraction_div = { {first,second},
                                                      {thrd,forth}};
  Matrices_division matrix_frst(fraction_div);
}




