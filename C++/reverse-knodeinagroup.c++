#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        int count = 0;
        ListNode* curr = head;
        while (curr) { count++; curr = curr->next; }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (count >= k) {
            curr = groupPrev->next;
            ListNode* nxt = curr->next;

            for (int i = 1; i < k; i++) {
                curr->next = nxt->next;
                nxt->next = groupPrev->next;
                groupPrev->next = nxt;
                nxt = curr->next;
            }

            groupPrev = curr;
            count -= k;
        }

        return dummy.next;
    }
};