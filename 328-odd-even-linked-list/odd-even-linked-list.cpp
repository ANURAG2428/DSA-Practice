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
        if (head == nullptr || head->next == nullptr) {
            return head;  // Agar linked list empty ho ya ek hi element ho toh direct return kar dena
        }

        // Initializing two pointers for odd and even
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Even head ko store kar rahe hain taaki end mein use kar sakein

        while (even != nullptr && even->next != nullptr) {
            odd->next = odd->next->next;  // Odd node ka next odd node set karna
            even->next = even->next->next; // Even node ka next even node set karna

            odd = odd->next; // Odd pointer ko next odd node pe move karna
            even = even->next; // Even pointer ko next even node pe move karna
        }

        odd->next = evenHead; // Last mein odd list ka next even list ka head ho

        return head; // Finally head ko return karna
    }
};