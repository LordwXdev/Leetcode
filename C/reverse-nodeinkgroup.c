#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k == 1) return head;

    // Count total nodes
    int count = 0;
    struct ListNode* curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }

    // Dummy node before head
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* groupPrev = &dummy;

    while (count >= k) {
        curr = groupPrev->next;
        struct ListNode* nxt = curr->next;

        // Reverse k nodes: perform k-1 swaps
        for (int i = 1; i < k; i++) {
            curr->next = nxt->next;
            nxt->next = groupPrev->next;
            groupPrev->next = nxt;
            nxt = curr->next;
        }

        groupPrev = curr;  // curr is now the tail of the reversed group
        count -= k;
    }

    return dummy.next;
}