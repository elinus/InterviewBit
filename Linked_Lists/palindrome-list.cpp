#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverse(ListNode *head) {
  ListNode *curr = head, *prev = head, *next = nullptr;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

int lPalin(ListNode *A) {
  if (!A || !A->next)
    return 1;
  ListNode *slow = A, *fast = A, *prev = nullptr;
  while (fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev->next = nullptr;
  fast = A;
  slow = reverse(slow);
  while (slow && fast) {
    if (slow->val != fast->val)
      return 0;
    slow = slow->next;
    fast = fast->next;
  }
  return 1;
}