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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (a != NULL && b != NULL) {
            if (a->val <= b->val) {
                curr->next = a;
                a = a->next;
            } else {
                curr->next = b;
                b = b->next;
            }
            curr = curr->next; // curr ko bhi to aage badaoge
        }

        // Now if while condition true nhi beth rhi means , dono mai se koi ek
        // LL NULL pai reach kr gyi hai , so jo NOT-NULL LL hai uske directly
        // curr se attack krdo
        if (a != NULL) {
            curr->next = a;
        } else {
            curr->next = b;
        }

        return dummy->next;
    }
};