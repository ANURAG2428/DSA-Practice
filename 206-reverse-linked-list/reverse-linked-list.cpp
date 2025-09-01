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
    ListNode* reverseList(ListNode* head) {
        // edge case 1: if only 1 node or 0 node present in the SLL return 
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head; // mene ek temp pointer bna liya , so that head mai change na ho
        ListNode* curr = NULL;
        ListNode* front = NULL; // ye pointer (temp->next) store karega , taaki hm LL mai aage bd paye (aur initially is pointer ko NULL hi lenge taki garbage value store na ho)
        while(temp!=NULL){ 
            front = temp->next; // (temp->next) ko store kara diya taaki chain break na ho
            temp->next = curr; // yaha mai temp->next = NULL bna rha hu 
            curr = temp;
            temp = front;  // yaha mai temp ko temp->next bna rha hu jo ki NULL h
            // head = curr;  ye likhne ki jarurat nhi 
        }
        return curr; // curr ab head hi bn jayega aur LL reverse mai print ho jayegi 

    }
};