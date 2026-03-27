#include<iostream>

 struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Check if k nodes are available
        ListNode* curr = head;
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        if (count < k) return head;

        // Reverse k nodes
        ListNode* prev = nullptr;
        curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // Recurse for remaining list and attach
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};