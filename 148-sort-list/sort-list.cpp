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
T.C = O(N) + O(N logN) + O(N) = O(N logN)
S.C = O(N)
 */

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // EDGE CASE
        if(head==NULL || head->next ==NULL){
            
            return head;
        }

        vector<int>arr;
        
        ListNode* temp = head;
        while(temp!=NULL){                    // T.C = O(N)
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size(); // syntax to get size of vector
        // after the end of this loop , arr will contain val of LL in unsorted order

        // Now we will sort the element in the array (using either Quick/Merge Sort)
        sort(arr.begin(),arr.end());                       // T.C = O(n logn)

        // now element inside the arr are sorted
        temp = head;
        for(int i = 0; i<n ; i++){            // T.C = O(N)
            temp->val = arr[i];
            temp = temp -> next;
        }
        return head;
    }
};