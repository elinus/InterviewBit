#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *A, ListNode *B) {
  if (!A)
    return B;
  if (!B)
    return A;
  ListNode dummy(0);
  ListNode *tail = &dummy;
  while (A && B) {
    if (A->val <= B->val) {
      tail->next = A;
      A = A->next;
    } else {
      tail->next = B;
      B = B->next;
    }
    tail = tail->next;
  }
  while (A) {
    tail->next = A;
    A = A->next;
    tail = tail->next;
  }
  while (B) {
    tail->next = B;
    B = B->next;
    tail = tail->next;
  }

  return dummy.next;
}
