/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

#include "LinkedList.h"

int main() {
  LinkedList<int> *a = nullptr;
  LinkedList<int> *b = nullptr;
  LinkedList<int> *c = nullptr;

  int arr1[] = {1, 8, 10};
  int arr2[] = {3, 4, 12, 15};

  int n = sizeof(arr1) / sizeof(arr1[0]);
  int m = sizeof(arr2) / sizeof(arr2[0]);
  int *arr3 = new int[m+n];

  for (int i = 0; i < n; ++i) {
    insertNode<int>(&a, arr1[i]);
    arr3[i] = arr1[i]+1;
  }

  for (int i = 0; i < m; ++i) {
    insertNode<int>(&b, arr2[i]);
    arr3[n+i] = arr2[i]+100;
  }

  for (int i = 0; i < n+m; ++i) {
    insertNode<int>(&c, arr3[i]);
  }

  displayLinkedList(a);
  displayLinkedList(b);
  displayLinkedList(c);
  // std::cout << "\n";

  // LinkedList<int> *newHead = insertionSort<int>(a);
  // LinkedList<int> *newList = sortedMerge<int>(a, b);
  // displayLinkedList(newList);

  // LinkedList<int> *newList3 = mergeSort(c);
  // displayLinkedList(newList3);

  std::vector<LinkedList<int>*> lists{a, b, c};
  LinkedList<int> *newList4 = mergeKLists(lists);
  displayLinkedList(newList4);

  // LinkedList<int> *front = nullptr;
  // LinkedList<int> *back = nullptr;

  // FrontBackSplit(newList, &front, &back);

  // displayLinkedList(front);
  // displayLinkedList(back);
  return 0;
}
