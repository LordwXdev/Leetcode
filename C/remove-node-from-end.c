#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode* first = &dummy;
    struct ListNode* second = &dummy;
    
    // move first n+1 steps
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }
    
    // move both pointers
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    
    struct ListNode* toDelete = second->next;
    second->next = second->next->next;
    
    free(toDelete);
    
    return dummy.next;
}