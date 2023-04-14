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
  
 

  division operator+(division sec) {
    bigint dvs = big_gcd(cur.second, sec.cur.second);

    bigint btm = (cur.second * sec.cur.second) / dvs;
    bigint tp = (cur.first * (btm / cur.second)) + (sec.cur.first * (btm / sec.cur.second));
    
    division ret(tp, btm);
    return ret;
  }

   void outpt() {
    cout << cur.first << "/" << cur.second << endl;
  }
  
  division operator*(division sec) {
    division ret((cur.first * sec.cur.first), (cur.second * sec.cur.second));
    return ret;
  }
};

struct Matrices_division {
  vector<vector<struct division>> mtrx;

  void outpt() {
    for(auto i = mtrx.begin(); i <= mtrx.end(); i++) {
      
    }
  }

  Matrices_division(vector<vector<struct division>> mtrx) : mtrx(mtrx) {};

  Matrices_division operator*(struct Matrices_division sec) {
    vector<vector<struct division>> ret;
    for (int i = 0; i < mtrx.size(); i++) {
      vector<struct division> cur_rsl;
      for (int x = 0; x < mtrx[i].size(); x++) {
        division div;
        for (int j = 0; j < sec.mtrx.size(); j++) {
          div = div + (mtrx[i][x] * sec.mtrx[j][x]);
        }
        cur_rsl.push_back(div);
      }
      ret.push_back(cur_rsl);
    }
    return Matrices_division(ret);
  }
};

#endif

