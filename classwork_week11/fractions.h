
#include <vector>
#include "bigint/Big Integer Library in Single file/bigint.h"
#include <utility>
#include <iostream>

#ifndef __FRACTION_H_
#define __FRACTION_H_

using namespace std;


struct division {
  pair<bigint,bigint> cur;

  division() : cur(make_pair(to_bigint(1), to_bigint(1))) {};
  division(bigint tp, bigint btm) : cur(make_pair(tp, btm)) {};
  
  void print() {
    cout << cur.first << "/" << cur.second << endl;
  }

  division operator+(division other) {
    bigint dvs = big_gcd(cur.second, other.cur.second);

    bigint btm = (cur.second * other.cur.second) / dvs;
    bigint tp = (cur.first * (btm / cur.second)) + (other.cur.first * (btm / other.cur.second));
    
    division result(tp, btm);
    return result;
  }
  
  division operator*(division other) {
    division result((cur.first * other.cur.first),(cur.second * other.cur.second));
    return result;
  }
};

struct Matrices_division {
  vector<vector<struct division>> mtrx;

  void print() {
    for(auto i = mtrx.begin(); i <= mtrx.end(); i++) {
      
    }
  }

  Matrices_division(vector<vector<struct division>> mtrx) : mtrx(mtrx) {};

  Matrices_division operator*(struct Matrices_division other) {
    vector<vector<struct division>> result;
    for (int i = 0; i < mtrx.size(); i++) {
      vector<struct division> sub_result;
      for (int x = 0; x < mtrx[i].size(); x++) {
        division div;
        for (int j = 0; j < other.mtrx.size(); j++) {
          div = div + (mtrx[i][x] * other.mtrx[j][x]);
        }
        sub_result.push_back(div);
      }
      result.push_back(sub_result);
    }
    return Matrices_division(result);
  }
};

#endif
