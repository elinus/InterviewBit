#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *addTwoNumbers(ListNode *A, ListNode *B) {
  if (!A)
    return B;
  if (!B)
    return A;
  ListNode dummy(INT_MIN);
  ListNode *last = &dummy;
  int carry = 0;
  while (A && B) {
    int sum = A->val + B->val + carry;
    carry = sum / 10;
    sum %= 10;
    last->next = new ListNode(sum);
    A = A->next;
    B = B->next;
    last = last->next;
  }
  while (A) {
    int sum = A->val + carry;
    carry = sum / 10;
    sum %= 10;
    last->next = new ListNode(sum);
    A = A->next;
    last = last->next;
  }
  while (B) {
    int sum = B->val + carry;
    carry = sum / 10;
    sum %= 10;
    last->next = new ListNode(sum);
    B = B->next;
    last = last->next;
  }
  if (carry) {
    last->next = new ListNode(carry);
  }
  return dummy.next;
}
