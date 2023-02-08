#include <iostream>
#include "prefix_sum.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>


using namespace std;

int prefix_sum(int array[], int last) { /* last must be less than length of the array */
  int sum = 0;
  for (int i=0; i < last; i++) {
    sum += array[i];
  }
  return sum;
}


bool non_negative_prefix_sum(int array[], int length) {
  bool is_non_negative = true;
  for (int i = 0; i < length; i++) {
    int sum = prefix_sum(array,i);
    if (sum >= 1) {
      is_non_negative = false;
      break;
    }
  }
  return is_non_negative;
}

bool status_seq(vector<int> &spc) {
    int add_ = 0;
    int a;
    for (a = 0; a < spc.size(); a++) {
        add_ = add_ + spc[a];
        if (0 > add_) {
            return false;
        }
    }
    return true;
}

int main() {
    int input_;
    cout << "Enter an n value:";
    cin >> input_;
    int rf = 2*input_;
    vector<int> spc(rf);
    int j;
    for (j = 0; j < input_; j++) {
        spc[j] = 1;
    }
    int k;
    for (k = input_; k < rf; k++) {
        spc[k] = -1;
    }

    random_device gn;
    mt19937 g(gn());
    int num_ = 0;
    int all_ = 0;
    do {
        shuffle(spc.begin(), spc.end(), g);
        all_++;
        if (status_seq(spc)) {
            num_++;
        }
    } 
    
    while (next_permutation(spc.begin(), spc.end()));

    cout << "Total = " << all_ << endl;
    cout << "Correct = " << num_ << endl;
    return 0;
}
