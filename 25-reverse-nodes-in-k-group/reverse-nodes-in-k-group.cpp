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
    ListNode* reverseKGroup(ListNode* head, int k) {
         if (!head || k == 1) return head; // agar empty list ya k=1 ho toh seedha return

        // Dummy node banaya easy handling ke liye
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy, *nex = dummy, *prev = dummy;

        // pehle count kar lenge kitne nodes total hai
        int count = 0;
        while (curr->next) {
            curr = curr->next;
            count++;
        }

        // ab groups mai reverse karenge
        while (count >= k) {
            curr = prev->next;
            nex = curr->next;
            for (int i = 1; i < k; i++) {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
            count -= k;
        }
        return dummy->next;
    }
};