/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        
        ListNode *a = headA;
        ListNode *b = headB;
        
        // Jab tak dono equal na ho jaye
        while (a != b) {
            // Agar a list khatam ho gayi, to dusri list ke head pe jao
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }
        
        return a; // ya to intersection point, ya NULL
    }
};