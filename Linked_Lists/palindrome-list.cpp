#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseList(ListNode *A) {
  ListNode *prev = nullptr, *curr = A, *next = nullptr;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

bool checkEqual(ListNode *A, ListNode *B) {
  if (!A && !B) return true;
  while (A && B) {
    if (A->val != B->val) return false;
    A = A->next;
    B = B->next;
  }
  return true;
}

int lPalin(ListNode *A) {
  if (!A || !A->next) return true;
  ListNode *slow = A, *fast = A;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode *revList = reverseList(slow->next);
  return checkEqual(A, revList);
}