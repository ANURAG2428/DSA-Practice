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
/* 
Approch : here we want ki first half of LL should match the second half of the LL


NOTE - ye SLL hai means ye forward hi move kr skti hai backward nhi 
 */


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Step 1 : find the middle of the SLL
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        // ab yaha mera slow pointer will be at the middle of the LL

        // STEP 2 : ab middle se hm next ko reverse krte jayenge (yaha 2nd half of LL tut jayega )
        ListNode* prev = NULL;
        ListNode* curr = slow; // mean's curr will point to middle/slow pointer
        while(curr!=NULL){
            ListNode* nextNode = curr ->next ; // is pointer mai mene curr->next store kara liya
            curr->next = prev ;
            prev = curr ;
            curr = nextNode;
        }
        // is loop se bahr aate hi prev mera tail ko point karega 

        // STEP 3 : ab temp aur prev ko compare karate jayeneg
        ListNode* first = head;
        ListNode* second = prev;
        while(second!=NULL){
            if(first->val != second->val){
                return false;
            }
            first = first -> next;
            second = second -> next;
        }
        return true; // loop end's means sari value match kr rhi hai 

    }
};