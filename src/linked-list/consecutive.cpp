/**
 * @file consecutive.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
#include <iostream>

#include <string>

class Consecutive {
 private:
  int *_arr;
  int _n;

 public:
  Consecutive(int *arr, int n): _arr(arr), _n(n) {}

  int getMin() {
    int min;
    for (int i=0; i < this->_n; ++i) {
      if (this->_arr[i] < min) {
          min = this->_arr[i];
      }
    }
    return min;
  }

  /*
  a^a = 0, a^b = b^a  => XOR all array elements with [min, min+1, ..., min-1+n] => 0 if elements are consecutive
  */
  int checkConsecutive(){
    int minVal = this->getMin();
    int num = 0;
    for (int i=0; i < this->_n; ++i) {
        num ^= minVal^this->_arr[i];
        std::cout << num << " " << minVal << " " << std::to_string(this->_arr[i])
                  << " " << std::to_string(minVal^this->_arr[i]) << std::endl;
        minVal +=1;
    }
    if (num == 0) {
        return 1;
    }
    return 0;
  }
};

int main() {
  int arr[] = {15, 14, 16, 11, 12, 13};
  Consecutive cons(arr, 6);
  std::cout << cons.checkConsecutive() << std::endl;

  return 0;
}
