#ifndef SRC_LINKED_LIST_LINKEDLIST_H_
#define SRC_LINKED_LIST_LINKEDLIST_H_

#include <iostream>
#include <vector>
#include<algorithm>


template <typename T>
class LinkedList {
 public:
  T data;
  LinkedList *next;

  LinkedList() : data(0), next(nullptr) {}
  LinkedList(int x, LinkedList *_next) : data(x), next(_next) {}
};


template <typename T>
void pushNode(LinkedList<T> **L, T x);
extern template void pushNode<int>(LinkedList<int> **L, int x);


template <typename T>
void insertNode(LinkedList<T> **L, T x);
extern template void insertNode<int>(LinkedList<int> **L, int x);


template <typename T>
void displayLinkedList(LinkedList<T> *L);
extern template void displayLinkedList<int>(LinkedList<int> *L);


template <typename T>
int getLength(LinkedList<T> *head);
extern template int getLength(LinkedList<int> *head);


template <typename T>
LinkedList<T> *removeNthFromStart(LinkedList<T> *L, T n);
extern template LinkedList<int> *removeNthFromStart<int>(LinkedList<int> *L, int n);


template <typename T>
LinkedList<T> *removeNthFromEnd(LinkedList<T> *L, T n);
extern template LinkedList<int> *removeNthFromEnd<int>(LinkedList<int> *L, int n);


template <typename T>
LinkedList<T> *deleteMiddle(LinkedList<T> *head);
extern template LinkedList<int> *deleteMiddle(LinkedList<int> *head);


template <typename T>
LinkedList<T> *swapPairs(LinkedList<T> *head);
extern template LinkedList<int> *swapPairs(LinkedList<int> *head);


template <typename T>
LinkedList<T> *rotateRight(LinkedList<T> *head, int k);
extern template LinkedList<int> *rotateRight(LinkedList<int> *head, int k);

template <typename T>
LinkedList<T> *reverseList(LinkedList<T> *head);
extern template LinkedList<int> *reverseList(LinkedList<int> *head);


template <typename T>
LinkedList<T> *reverseBetween(LinkedList<T> *head, int left, int right);
extern template LinkedList<int> *reverseBetween(LinkedList<int> *head, int left, int right);


template <typename T>
LinkedList<T> *insertionSort(LinkedList<T> *head);
extern template LinkedList<int> *insertionSort(LinkedList<int> *head);


template <typename T>
LinkedList<T> *sortedMerge(LinkedList<T> *L1, LinkedList<T> *L2);
extern template LinkedList<int> *sortedMerge(LinkedList<int> *L1, LinkedList<int> *L2);


template <typename T>
void FrontBackSplit(LinkedList<T> *head, LinkedList<T> **front, LinkedList<T> **back);
extern template void FrontBackSplit(LinkedList<int> *head, LinkedList<int> **front, LinkedList<int> **back);


template <typename T>
LinkedList<T> *mergeSort(LinkedList<T> *head);
extern template LinkedList<int> *mergeSort(LinkedList<int> *head);


template <typename T>
LinkedList<T> *mergeKLists(std::vector<LinkedList<T>*>& lists);
extern template LinkedList<int> *mergeKLists(std::vector<LinkedList<int>*>& lists);

#endif  // SRC_LINKED_LIST_LINKEDLIST_H_
