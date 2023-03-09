#include "perfect_integer_lambda.h"

using namespace std;

vector<int> find_perfect_numbers(const vector<int> input_list) {
    // empty vector
    vector<int> perfect_numbers;
    
    for_each(input_list.begin(), input_list.end(), [&](const int &num) {
    
        int sum_of_divisors = 0; //sum of all divisors of the current integer
        
        for (int i = 1; i < num; i++) { // for each integer between 1 and current integer, check if it is a divisor of current integer.
        
            if ((num % i) == 0) { // if "i" is a divisor, add it to the sum of divisors
            
                sum_of_divisors += i;
                
            }
            
        }
        
        if (sum_of_divisors == num) { // if the sum equals to the current integer, it is a perfect number
        
            perfect_numbers.push_back(num);
            
          }
          
      }
      
  );
  
    return perfect_numbers;
}

