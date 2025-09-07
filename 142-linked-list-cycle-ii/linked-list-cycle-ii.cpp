/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 
NOTE-  here i have to return the entire node not the index

Approch : whi tortoise - Hare method hi effective maani jayeg */


class Solution {
public:
    ListNode *detectCycle(ListNode *head) { // here we can see our function is of listNode type
        ListNode* slow = head;
        ListNode* fast = head;
        int pos = 0;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow ->next;
            fast = fast ->next->next;
            if(slow == fast){ // mai is condition ko bina dono ko move karaye nhi likh skta vrna initially dono hamesha head node pai hi hote hai to condition always true ho jayegi
                
                // inside the if slow and fast pointer collide ho gye hai and ab hm further approch likhenege to get the node from where the cycle has begin
                slow = head; // slow ko hmne head pai point kra diya
                // fast is till at the position of collision
                while(slow!=fast){
                    // now move both of them by 1 step and where they meet will be the starting node of the cycle
                    slow = slow -> next;
                    fast = fast -> next;
                }
                // loop se bahr aagye means (slow == fast)
                return slow ; // return Node (this will be the starting node of cycle)

            }
            

        }
        return NULL;
        
    }
};