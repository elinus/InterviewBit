#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

int getLength(ListNode *head) {
  int len = 0;
  while (head) {
    head = head->next;
    len++;
  }
  return len;
}

ListNode *helper(ListNode *A, ListNode *B, int diff) {
  while (diff--) {
    A = A->next;
  }
  while (A && B) {
    if (A == B) return A;
    A = A->next;
    B = B->next;
  }
  return nullptr;
}

ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
  if (!A || !B) return nullptr;
  int lenA = getLength(A);
  int lenB = getLength(B);
  int diff = lenA - lenB;
  if (diff > 0) {
    return helper(A, B, diff);
  }
  return helper(B, A, -diff);
}