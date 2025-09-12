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
    ListNode* deleteMiddle(ListNode* head) {
              // Agar sirf ek node hai to usko delete karke NULL return karna hai
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // Slow and Fast pointer approach se middle node dhoondhenge
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr; // Ye slow ke pichle node ko track karega

        // Jab tak fast ya fast->next NULL nahi hota, tab tak loop chalayenge
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Ab slow middle node par hai, usko hata dete hain
        prev->next = slow->next;
        delete slow; // Memory free kar di

        return head;
    }
};