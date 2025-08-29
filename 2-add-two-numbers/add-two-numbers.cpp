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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node taaki result list banate waqt easy rahe
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        // Jab tak l1, l2 ya carry mein kuch hai tab tak loop chalega
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = 0;

            // Agar l1 valid hai to uska value sum mein add karo
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Agar l2 valid hai to uska value sum mein add karo
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Carry bhi add karo
            sum += carry;

            // Naya digit aur carry calculate karo
            carry = sum / 10;
            int digit = sum % 10;

            // Nayi node banao result list mein
            current->next = new ListNode(digit);
            current = current->next;
        }

        // Dummy ka next return karo kyunki dummy pehle node thi
        return dummy->next;
    }
};