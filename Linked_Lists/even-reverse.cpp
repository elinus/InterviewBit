#include <iostream>

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

ListNode *solve(ListNode *A) {
  if (!A || !A->next)
    return A;
  ListNode oddList(INT_MIN), evenList(INT_MIN);
  ListNode *pOdd = &oddList, *pEven = &evenList, *curr = A;
  int n = 1;
  while (curr) {
    if (n % 2) {
      pOdd->next = curr;
      pOdd = pOdd->next;
    } else {
      pEven->next = curr;
      pEven = pEven->next;
    }
    curr = curr->next;
    n++;
  }
  pEven->next = nullptr;
  pOdd->next = nullptr;
  pOdd = oddList.next;
  pEven = reverseList(evenList.next);
  n = 1;
  ListNode dummy(INT_MIN);
  ListNode *dp = &dummy;
  while (pOdd && pEven) {
    if (n % 2) {
      dp->next = pOdd;
      pOdd = pOdd->next;
    } else {
      dp->next = pEven;
      pEven = pEven->next;
    }
    dp = dp->next;
    n++;
  }
  if (pOdd) {
    dp->next = pOdd;
  }
  if (pEven) {
    dp->next = pEven;
  }
  return dummy.next;
}