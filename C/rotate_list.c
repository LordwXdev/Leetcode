#include<stdio.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Find length and tail
    int n = 1;
    struct ListNode* tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
        n++;
    }

    k %= n;
    if (k == 0)
        return head;

    // Make circular list
    tail->next = head;

    // Find new tail
    int steps = n - k;
    struct ListNode* newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // New head
    struct ListNode* newHead = newTail->next;

    // Break the circle
    newTail->next = NULL;

    return newHead;
}