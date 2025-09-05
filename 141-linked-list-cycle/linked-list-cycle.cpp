/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 

Brute Force Approch : 
t.c = O(n) // kyoki hme puri LL traverse krke to dekhni pd hi rhi hai
s.c = o(n) // kyoki hmne unordered_Set create kara hai aur usme unique address ke node store karaynge 
 */




class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>set; // store unique addresses (key = addresses)
        ListNode* temp = head; //hmne ek temp bna diya jo ki same head ko point karega , taaki jo bhi change's ho temp mai ho na ki head mai
        while(temp!=NULL){
            // means agr mera iteratior end() ko point nhi kr rha means's there is a cycle in the linked list
            if(set.find(temp)!=set.end()){
                return true;
            }
            // aur agr temp ka iterator == end ke baad position tk pahunch gya means , its a unique node , mtlb is node ko kisi ka next wapis point nhi kr rha , so ise store kara lo
            set.insert(temp); // store this node in unordered_set
            temp = temp->next; // temp ko aage bda lo
            
        }
        return false;       
    }
};
