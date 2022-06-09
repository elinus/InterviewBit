#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// TODO: try to swap nodes instead of just values
ListNode *insertionSortList(ListNode *A) {
  if (!A || !A->next)
    return A;
  for (ListNode *tmp = A; tmp != nullptr; tmp = tmp->next) {
    for (ListNode *curr = A; curr != tmp; curr = curr->next) {
      if (curr->val > tmp->val) {
        int ans = curr->val;
        curr->val = tmp->val;
        tmp->val = ans;
      }
    }
  }
  return A;
}