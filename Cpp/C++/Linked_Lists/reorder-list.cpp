#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
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

ListNode *reorderList(ListNode *A) {
  if (!A || !A->next) return A;
  ListNode *slow = A, *fast = A;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode *tmp = reverseList(slow->next);
  slow->next = nullptr;
  int flag = 1;
  ListNode *curr = A;
  ListNode dummy(0);
  ListNode *tail = &dummy;
  while (curr && tmp) {
    if (flag) {
      tail->next = curr;
      curr = curr->next;
    } else {
      tail->next = tmp;
      tmp = tmp->next;
    }
    tail = tail->next;
    flag = 1 - flag;
  }
  if (curr) {
    tail->next = curr;
  }
  if (tmp) {
    tail->next = tmp;
  }
  return dummy.next;
}
