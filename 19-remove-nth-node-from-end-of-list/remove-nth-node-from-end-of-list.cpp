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
        // first Calculate the length of LL
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        // loop end -> means hame length of LL pta chal gyi hogi

        
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        int cnt = 0;
        int backcount = len-n;
        // If we need to remove the head (backcount == 0) (len-n = 2-2(2nd position from the last of LL))
        if(backcount == 0) {
            ListNode* newHead = head->next;
            delete head; // Optional: free memory
            return newHead;
        }
        
        while(cnt!=backcount){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        // loop end hote hi , curr will be at the node jo delete krna hai and prev will at (node-1)
        prev->next = curr->next; // jaha mera curr pehle , point kr rha tha waha ab prev point karega
        curr->next = NULL; // curr ke next ko NULL kar diya
        delete curr;

        return head;

    }
    
    
};