#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *midpoint(ListNode *head) {
  if (!head || !head->next)
    return head;

  ListNode *slow = head, *fast = head->next;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

ListNode *mergeSortedLists(ListNode *A, ListNode *B) {
  if (!A)
    return B;
  if (!B)
    return A;

  ListNode *temp;
  if (A->val <= B->val) {
    temp = A;
    temp->next = mergeSortedLists(A->next, B);
  } else {
    temp = B;
    temp->next = mergeSortedLists(A, B->next);
  }

  return temp;
}

ListNode *sortList(ListNode *A) {
  if (!A || !A->next) {
    return A;
  }

  ListNode *mid = midpoint(A);
  ListNode *a = A;
  ListNode *b = mid->next;

  mid->next = NULL;

  a = sortList(a);
  b = sortList(b);

  ListNode *temp = mergeSortedLists(a, b);
  return temp;
}