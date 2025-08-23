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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;  // Handle edge cases

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;  // Store the head of the even list
        
        while (even && even->next) {
            odd->next = odd->next->next;  // Link the next odd node
            even->next = even->next->next;  // Link the next even node
            
            odd = odd->next;  // Move odd pointer
            even = even->next;  // Move even pointer
        }

        odd->next = evenHead;  // Link the end of odd list to the head of even list
        return head;
    }
};