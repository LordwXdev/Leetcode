#include<stdio.h>


struct ListNode {
      int val;
      struct ListNode *next;
 };
 
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (prev->next && prev->next->next) {
        struct ListNode* a = prev->next;
        struct ListNode* b = a->next;

        // rewire
        a->next = b->next;
        b->next = a;
        prev->next = b;

        prev = a;  // move forward (a is now second in the pair)
    }

    return dummy.next;
}