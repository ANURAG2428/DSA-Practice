/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    class cmp {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap
            // for max-heap use (<)
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // create a pq (min-heap) of ListNode* type , where we compare not on the
        // basis of address , but on the basis of value (with the help of custom
        // comprator)
        int n1 = lists.size();

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // step 1 : sare head of all k linked list add kr initially in pq
        for (int i = 0; i < n1; i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        // now ab dummy ListNode bna and using curr min ListNode ko curr se attack krke
        // min ko pop kra from pq and then if min->next !=null , then add in pq
        // , and in the end  curr =curr->next
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        // jb tk pq empty nhi ho jta do above step
        while (!pq.empty()) {
            ListNode* minNode = pq.top();
            pq.pop();
            curr->next = minNode;
            curr = curr->next;

            if (minNode->next != NULL) {
                pq.push(minNode->next);
            }
        }
        return dummy->next; // return head
    }
};