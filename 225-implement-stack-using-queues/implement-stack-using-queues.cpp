#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
    
public:
    MyStack() {
        // Constructor - kuch initialize karne ki need nahi
    }
    
    void push(int x) {
        // Naya element ko q2 mein daalo
        q2.push(x);
        
        // Q1 ke saare elements ko q2 mein move karo
        while(!q1.empty()) {
            q2.push(q1.front());  // Q1 ka front element q2 mein daalo
            q1.pop();             // Q1 se remove karo
        }
        
        // Swap karo q1 aur q2 ko
        swap(q1, q2);
    }
    
    int pop() {
        // Stack ka top element return karo aur remove karo
        if(q1.empty()) return -1;  // Stack empty hai
        
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }
    
    int top() {
        // Stack ka top element return karo (without remove)
        if(q1.empty()) return -1;
        return q1.front();
    }
    
    bool empty() {
        // Check karo stack empty hai ya nahi
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */