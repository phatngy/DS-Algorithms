#include "LinkedList.h"

#include <limits.h>

#include <iostream>
#include <limits>
#include <chrono>
#include <thread>


template <typename T>
void pushNode(LinkedList<T> **L, T x) {
  LinkedList<T> *p_newNode;
  p_newNode->data = x;
  p_newNode->next = *L;
  *L = p_newNode;
}
template void pushNode<int>(LinkedList<int> **L, int x);

template <typename T>
void displayLinkedList(LinkedList<T> *L) {
  while (L) {
    std::cout << L->data << "---->";
    L = L->next;
  }
  std::cout << "\n";
}
template void displayLinkedList<int>(LinkedList<int> *L);

template <typename T>
void insertNode(LinkedList<T> **L, T x) {
  LinkedList<T> *p_newNode = new LinkedList<T>;
  p_newNode->data = x;
  p_newNode->next = nullptr;
  LinkedList<T> *ptr;

  if (*L == nullptr) {
    *L = p_newNode;
  } else {
    ptr = *L;
    while (ptr->next)
      ptr = ptr->next;
    ptr->next = p_newNode;
  }
}
template void insertNode<int>(LinkedList<int> **L, int x);

template <typename T>
int getLength(LinkedList<T> *head) {
  LinkedList<T> *ptr = head;
  int count = 1;
  while (ptr->next) {
    ptr = ptr->next;
    count++;
  }
  return count;
}
template int getLength(LinkedList<int> *head);

template <typename T>
LinkedList<T> *removeNthFromStart(LinkedList<T> *head, T n) {
  LinkedList<T> *ptr = head;
  while (ptr->next) {
    if (n == 1) {
      LinkedList<T> *pTemp = ptr->next;
      ptr->next = pTemp->next;
      break;
    }
    n--;
    ptr = ptr->next;
  }
  return head;
}
template LinkedList<int> *removeNthFromStart(LinkedList<int> *L, int n);

template <typename T>
LinkedList<T> *removeNthFromEnd(LinkedList<T> *head, T n) {
  LinkedList<T> *pLength = head;
  int count = 1;
  while (pLength->next) {
    pLength = pLength->next;
    count++;
  }
  LinkedList<T> *ptr = head;
  int k = count - n;
  if (count == 1) {
    return nullptr;
  }
  while (ptr->next) {
    displayLinkedList(ptr);
    if (k == 0) {
      return ptr->next;
    }
    if (k == 1) {
      LinkedList<T> *pTemp = ptr->next;
      ptr->next = pTemp->next;
      break;
    }
    k--;
    ptr = ptr->next;
  }
  return head;
}
template LinkedList<int> *removeNthFromEnd(LinkedList<int> *L, int n);

template <typename T>
LinkedList<T> *deleteMiddle(LinkedList<T> *head) {
  if (head->next == nullptr) {
    return nullptr;
  }
  /* My solution
  LinkedList<T>* pLength = head;
  int count = 1;
  while (pLength->next){
      count++;
      pLength = pLength->next;
  }

  int middle_idx = count / 2;
  LinkedList<T>* ptr = head;
  while (ptr->next){
      if (middle_idx == 1){
          LinkedList<T>* ptemp = new LinkedList<T>;
          ptemp = ptr->next;
          ptr->next = ptemp->next;
          break;
      }
      ptr = ptr->next;
      middle_idx--;
  }
  return head;
  */
  LinkedList<T> *slow = head;
  LinkedList<T> *fast = head;

  if (!head->next)
    return nullptr;

  while (fast && fast->next)  {
    if (fast != head)
      slow = slow->next;
    std::cout << "Slow: " << slow->data << "\t";
    fast = fast->next->next;
    std::cout << "Fast: " << fast->data << "\n";
  }

  std::cout << "Slow: " << slow->data << "\t";
  slow->next = slow->next->next;
  // std::cout << "Fast: " << fast->data << "\n";
  return head;
}
template LinkedList<int> *deleteMiddle(LinkedList<int> *head);

template <typename T>
LinkedList<T> *swapPairs(LinkedList<T> *head) {
  // /* My solution
  if (!head->next)
    return head;

  LinkedList<T> *dummy = new LinkedList<T>(0, head);
  LinkedList<T> *prev = dummy;

  int count = 0;
  while (prev->next) {
    // swap 1st vs 2nd
    LinkedList<T> *first = prev->next;  // store curr node
    if (!first || !first->next)
      break;
    prev->next = first->next;  // swapping
    first->next = prev->next->next;
    prev->next->next = first;

    prev = first;  // update
  }
  head = dummy->next;
  delete dummy;
  return head;
}
template LinkedList<int> *swapPairs(LinkedList<int> *head);

template <typename T>
LinkedList<T> *rotateRight(LinkedList<T> *head, int k) {
  if (!head || !head->next) {
    return head;
  }
  LinkedList<T> *pLength = head;
  int count = 1;
  while (pLength->next) {
    pLength = pLength->next;
    count++;
  }
  k = k % count;
  while (k--) {
    LinkedList<T> *pTemp = new LinkedList<T>();
    pTemp->next = head;
    LinkedList<T> *ptr = pTemp;

    while (ptr->next->next) {
      ptr = ptr->next;
    }
    pTemp->data = ptr->next->data;
    ptr->next = nullptr;
    head = pTemp;
  }
  return head;
}
template LinkedList<int> *rotateRight(LinkedList<int> *head, int k);

template <typename T>
LinkedList<T> *reverseList(LinkedList<T> *head) {
  LinkedList<T> *prev = nullptr;
  LinkedList<T> *curr = head;
  LinkedList<T> *pTemp = nullptr;
  while (curr) {
    pTemp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = pTemp;
  }
  head = prev;
  return head;
}
template LinkedList<int> *reverseList(LinkedList<int> *head);

template <typename T>
LinkedList<T> *reverseBetween(LinkedList<T> *head, int left, int right) {
  if (!head || !head->next || (right - left) < 1)
    return head;

  int count = 1;
  LinkedList<T> *prev = nullptr;
  LinkedList<T> *curr = head;
  LinkedList<T> *pTemp = nullptr;
  LinkedList<T> *l = nullptr;
  LinkedList<T> *r = nullptr;

  while (curr) {
    if (count == left - 1) {
      l = curr;
    }
    if (count == right + 1) {
      r = curr;
    }
    if (count >= left && count <= right) {
      pTemp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = pTemp;
    } else  {
      curr = curr->next;
    }
    count++;
  }
  LinkedList<T> *pPrev = head;
  while (pPrev->next) {
    pPrev = pPrev->next;
  }

  pPrev->next = r;

  if (left == 1) {
    return prev;
  }
  l->next = prev;

  return head;
}
template LinkedList<int> *reverseBetween(LinkedList<int> *head, int left, int right);

template <typename T>
LinkedList<T> *insertionSort(LinkedList<T> *head) {
  if (!head || !head->next)
    return head;
  int inf = std::numeric_limits<int>::min();
  LinkedList<T> *newList = new LinkedList<T>(inf, nullptr);
  LinkedList<T> *ptr = head;

  while (ptr) {
    LinkedList<T> *tail = newList;
    while (tail->next && tail->next->data < ptr->data) {
      tail = tail->next;
    }
    LinkedList<T> *newNode = new LinkedList<T>(ptr->data, tail->next);
    tail->next = newNode;

    ptr = ptr->next;
  }
  return newList->next;
}
template LinkedList<int> *insertionSort(LinkedList<int> *head);

// Merge 2 sorted LinkedList
template <typename T>
LinkedList<T> *sortedMerge(LinkedList<T> *L1, LinkedList<T> *L2) {
  if (!L1)
    return L2;
  if (!L2)
    return L1;
  LinkedList<T> *dummy = new LinkedList<T>(0, L1);
  LinkedList<T> *ptr1 = dummy;
  LinkedList<T> *ptr2 = L2;
  int count = 1;
  while (ptr1->next && ptr2) {
    if (ptr1->next->data >= ptr2->data) {
      LinkedList<T> *pTemp = ptr2;
      ptr2 = ptr2->next;
      pTemp->next = ptr1->next;
      ptr1->next = pTemp;
      ptr1 = pTemp;
    } else {
      ptr1 = ptr1->next;
    }
    // std::cout << "Round: " << count << " ptr1: \t";
    // displayLinkedList(ptr1);
    // std::cout << "       " << "  ptr2: \t";
    // displayLinkedList(ptr2);
    // std::cout << "       " << "  L1: \t";
    // displayLinkedList(L1);
    // count++;
  }
  if (ptr2) {
    ptr1->next = ptr2;
  }
  return dummy->next;
}
template LinkedList<int> *sortedMerge(LinkedList<int> *L1, LinkedList<int> *L2);

template <typename T>
void FrontBackSplit(LinkedList<T> *head, LinkedList<T> **front, LinkedList<T> **back) {
  if (!head || !head->next) {
    *front = head;
    *back = nullptr;
    return;
  }
  LinkedList<T> *fast = head;
  LinkedList<T> *slow = head;

  while (fast->next) {
    fast = fast->next;
    if (fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
  }

  *front = head;
  *back = slow->next;
  slow->next = nullptr;
}
template void FrontBackSplit(LinkedList<int> *head, LinkedList<int> **front, LinkedList<int> **back);

template <typename T>
LinkedList<T> *mergeSort(LinkedList<T> *head) {
  if (!head || !head->next) {
    return head;
  }

  LinkedList<T> *a = nullptr;
  LinkedList<T> *b = nullptr;

  FrontBackSplit(head, &a, &b);

  a = mergeSort(a);
  b = mergeSort(b);

  head = sortedMerge(a, b);
  displayLinkedList(head);
  return head;
}
template LinkedList<int> *mergeSort(LinkedList<int> *head);

template <typename T>
LinkedList<T> *quickSort(LinkedList<T> *head) {
  return nullptr;
}
template LinkedList<int> *quickSort(LinkedList<int> *head);

template <typename T>
LinkedList<T> *mergeKLists(std::vector<LinkedList<T> *> &lists) {
  /* My Solution
  int idx = 0;
  int init_flag = 0;
  int min = std::numeric_limits<int>::max();
  if (lists.size() == 1){
    return lists[0];
  }
  if (lists.size() == 0){
    return nullptr;
  }
  LinkedList<T>* newList = new LinkedList<T>(min, lists[0]);
  LinkedList<T>* newPtr = newList;
  std::vector<LinkedList<T>*> list_ptrs;
  for (auto& l: lists){
    LinkedList<T>* ptr = l;
    list_ptrs.push_back(ptr);
    idx++;
    if (l && min > l->data){
      min = l->data;
      newList->next = l;
      init_flag = 1;
    }
  }
  lists.erase(std::remove(lists.begin(), lists.end(), newList->next), lists.end());
  list_ptrs.erase(std::remove(list_ptrs.begin(), list_ptrs.end(), newList->next), list_ptrs.end());

  int count = 1;
  while(newPtr->next)
  {
    int i = 0;
    int count_ptr = 0;
    std::cout << "Round: " << count << "\n";
    for(auto& ptr: list_ptrs){
      if (!ptr){
        continue;
      }
      if (newPtr->next->data >= ptr->data)
      {
        LinkedList<T> *pTemp = ptr;
        ptr = ptr->next;
        pTemp->next = newPtr->next;
        newPtr->next = pTemp;
        i++;
      }
      std::cout << "\t ptr" << count_ptr << ": \t\t" ;
      displayLinkedList(ptr);
      count_ptr++;
    }
    if (i == 0)
      newPtr = newPtr->next;
    std::cout << "\t" << " newPtr: \t";
    displayLinkedList(newPtr);
    std::cout << "\t" << " newList: \t";
    displayLinkedList(newList->next);
    count++;
  }

  for(auto& ptr: list_ptrs){
    if (ptr){
      newPtr->next = ptr;
      // ptr = ptr->next;
      break;
    }
  }

  list_ptrs.erase(std::remove(list_ptrs.begin(), list_ptrs.end(), newPtr->next), list_ptrs.end());
  list_ptrs.push_back(newList->next);
  newList->next = mergeKLists(list_ptrs);
  return newList->next;
  */
  // time: O(kN), k is size of lists, N is the total number of elements in the final merged list
  // space: O(1)

  /*
      general idea: scan all the head of each linked list and record the minimum value and
      the corresponding index of the vector, then our final merged list will include this node
      (p->next = lists[min_idx]). Also, we need to pop out this value from the original linked list.
      If there is no minimum value can be found, means that all linked lists have been visited, we can stop there.
  */

  // edge cases check, quickly return
  int n = lists.size();
  if (n == 0)
    return nullptr;
  if (n == 1 && lists[0] == nullptr)
    return nullptr;

  LinkedList<T> *dummy = new LinkedList<T>(-1, nullptr);  // dummy head node trick
  LinkedList<T> *p = dummy;                               // a new list that would merge all the linked-lists

  bool flag = true;  // whether we can find a minimum value
  while (flag) {
    int min = INT_MAX;
    int min_idx = -1;
    // find the minimum value among all heads of each linked list and corresponding index in the vector
    for (int i = 0; i < n; ++i) {
      if (lists[i] && lists[i]->data < min) {
        min = lists[i]->data;
        min_idx = i;
      }
    }
    if (min_idx != -1) {
      // if we found a minimum, we will merge it to the final list and update vector and move to next
      p->next = lists[min_idx];
      lists[min_idx] = lists[min_idx]->next;
      p = p->next;
    } else  {
      // when we cannot find a minimum value among all the linked lists, stop while
      flag = false;
    }
  }
  return dummy->next;
}
template LinkedList<int> *mergeKLists(std::vector<LinkedList<int> *> &lists);
