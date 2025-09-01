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
Optimized Approch : Here we will be using Tortoise-Hare Algorithm

Tortoise-Hare Algorithm - in this algo hamare pass head position pai 2 pointer honge named as slow and fast . Here slow will move with 1 step and fast will move with 2 step .

CASE 1 : in case of Odd no of LL , jese hi fast last node pai pahunchega , slow will point to the middle node of the LL.

CASE 2 : in case of Even no of LL , jese hi fast NULL pai pahunchega , slow will point to the middle node of the LL.

T.c = O(N), kyoki hm ek baar hi traverse kr rhe hai so O(N) , Constraint like  [10^6 ya 10^9] max no of node 10^9 ke liye optimistic way mai code run karega with optimistic time complexity

S.C = O(1)
 */



class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // EDGE CASE
        if(head == NULL || head->next == NULL ){
            return head;  // single node ya no node present then that will be the middle node
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){ // apne aap LL ke according slow and fast analyize kr lenege ki LL even hai ya odd hai 
        // agr fast = NULL hai to uska fast->next = NULL hi hoga
            slow = slow ->next; // move slow by 1 step
            fast = fast->next->next;  // move fast by 2 step
        }
        // loop se bahr aagye means , kisi bhi slow will point to the middle of the linked list
        return slow;
        
    }
};

/* 
|| lagane se code kabhi bhi crash kar jayega (runtime error), chahe tum odd-even case explicitly handle karo ya na karo.

Using && :

while(fast != NULL && fast->next != NULL)
# Iska matlab ye hai ki loop sirf tab tak chalega jab dono valid hain:
# fast NULL na ho
# aur fast->next bhi NULL na ho
# Matlab guaranteed hai ki tum fast->next->next safely access kar paoge.
Isiliye always AND (&&) use hota hai.

 */