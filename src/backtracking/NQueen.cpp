/**
 * @file test.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <glog/logging.h>

#include <iostream>

void printPosition(int *arr, int rows) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      if (j == arr[i]) {
        std::cout << " x ";
      } else {
        std::cout << " . ";
      }
    }
    std::cout << std::endl;
  }
  std::cout << "================" << std::endl;
}

void backtrack(std::vector<int> *used_cols, std::vector<int> *cross_down, std::vector<int> *cross_up,
               int *res, int i, int rows) {
  for (int j = 0; j < rows; j++) {
    if (!used_cols->at(j) && !cross_down->at(i - j + rows - 1) && !cross_up->at(i + j)) {
      res[i] = j;
      used_cols->at(j) = 1;
      cross_down->at(i - j + rows - 1) = 1;
      cross_up->at(i + j) = 1;
      if (i == rows - 1) {
        printPosition(res, rows);
      } else {
        backtrack(used_cols, cross_down, cross_up, res, i + 1, rows);
      }
      used_cols->at(j) = 0;
      cross_down->at(i - j + rows - 1) = 0;
      cross_up->at(i + j) = 0;
    }
  }
}

int main(int argc, char *argv[]) {
  int N;
  std::cin >> N;
  std::vector<int> used_cols(N, 0);
  std::vector<int> cross_down(2 * N - 1, 0);
  std::vector<int> cross_up(2 * N - 1, 0);
  int res[N];

  backtrack(&used_cols, &cross_down, &cross_up, res, 0, N);
  return 0;
}
