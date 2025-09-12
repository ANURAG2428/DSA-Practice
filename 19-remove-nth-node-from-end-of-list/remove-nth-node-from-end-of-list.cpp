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
Optimized Approch : 1) here use two pointer slow and fast (both pointing to head initially)
                    2) ab fast pointer ko n(given in que) tk traverse kara using for loop
                    3) jese hi fast n pai pahunch jaye ab slow aur fast ko by 1 step traverse kara jb tk fast->next!=NULL
                    4) ab jese hi loop end hoga mera slow pointer will be just before the node jo delete krna hai , then i will simply create a pointer that will point to the node that need's to be deleted 
                    5) mai slow ke next ko waha point kara dunga jaha deleted node ka next point kr rha hai 
                    6) then i will delete the deleted node using delete keyword and return the head

NOTE-  this code won't work for deleting head node, so we have to write EDGE CASE for it   
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        // ListNode* temp = head;
        // STEP 1: traverse fast pointer till n (kyoki mujhe jo node delete krna hai us se just pehle wale node tk reach krna hai)
        for(int i = 0; i<n ;i++){ // if i<=n , to fast aage nikal jayega
            fast = fast -> next;
        }
        // now my fast will be just before the n = 2 from the end position

        // STEP 2 : ab slow and fast ko by 1 step simultenously move kra jb tk fast -> next != NULL
        if(fast == NULL){ // EDGE CASE
            
            return head->next; // mean's head ke just aage wale node se list print kara do
        }
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }

        // STEP 3: jo node delete krna hai use kisi pointer mai store kara de
        ListNode* deleteNode = slow->next;
        slow->next = deleteNode->next;
        delete deleteNode;

        return head;

    }
};