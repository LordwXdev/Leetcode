#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        
        // Push first node of each list
        for (auto node : lists) {
            if (node) {
                pq.push(node);
            }
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            
            tail->next = smallest;
            tail = tail->next;
            
            if (smallest->next) {
                pq.push(smallest->next);
            }
        }
        
        return dummy.next;
    }
};