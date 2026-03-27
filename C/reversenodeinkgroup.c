#include<stdio.h>

 struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k == 1) return head;

    // Count remaining nodes from current position
    struct ListNode* curr = head;
    int count = 0;
    while (curr && count < k) {
        curr = curr->next;
        count++;
    }
    if (count < k) return head; // not enough nodes

    // Reverse k nodes
    struct ListNode* prev = NULL;
    curr = head;
    for (int i = 0; i < k; i++) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // head is now the tail of this reversed group
    // curr points to the (k+1)th node — recurse on the rest
    head->next = reverseKGroup(curr, k);

    return prev; // new head of this group
}