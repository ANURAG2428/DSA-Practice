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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         // Step 1: Create a dummy node that points to the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2: Set two pointers - slow and fast - both starting from dummy
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Step 3: Move the fast pointer n steps ahead
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        // Step 4: Move both pointers until fast reaches the end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 5: Now, slow is just before the node we want to delete
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;

        // Step 6: Free the memory of the deleted node
        delete nodeToDelete;

        // Step 7: Return the new head
        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node
        return newHead;
    }
};