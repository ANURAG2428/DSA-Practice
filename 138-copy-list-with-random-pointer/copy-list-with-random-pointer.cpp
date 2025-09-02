/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         if (!head) return nullptr;

        // Step 1: Create new nodes and insert them after original nodes
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Set random pointers of the newly created nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the original and the copied list
        Node* dummy = new Node(0);
        Node* copy = dummy;
        curr = head;
        while (curr) {
            copy->next = curr->next;
            curr->next = curr->next->next;

            curr = curr->next;
            copy = copy->next;
        }

        return dummy->next;
    }
};