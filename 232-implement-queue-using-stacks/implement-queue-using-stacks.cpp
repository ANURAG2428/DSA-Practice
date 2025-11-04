#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2; // Do stacks use karenge

    MyQueue() {
        // Constructor - kuch initialize nahi karna
    }
    
    // Push operation - element ko queue ke end me dalna
    void push(int x) {
        // Step 1: sab kuch s1 se s2 me daal do (reverse karne ke liye)
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // Step 2: naya element s1 me daal do
        s1.push(x);
        // Step 3: wapas s2 ke elements ko s1 me daal do
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    // Pop operation - front element ko remove karna
    int pop() {
        int topElement = s1.top();
        s1.pop();
        return topElement;
    }
    
    // Peek operation - front element dekhna (remove nahi karna)
    int peek() {
        return s1.top();
    }
    
    // Empty check karna
    bool empty() {
        return s1.empty();
    }
};
