class MinStack {
    private:
    stack<int>st1; // here i have created a stack inside MinStack class
    stack<int>st2; // this stack helps to store the minmum element 
public:
    MinStack() {
        // Default Constructor
    }
    
    
    void push(int val) {
        st1.push(val);

        // stack2 (Min stack) mai sirf tb push kro jb val current st.top() ke equal(to handle dublicate case) ya chota ho
        if(st2.empty() || val<=st2.top()){ // ya to stack 2 empty hai for initial element to get into stack 2 as min or current val equal hai ya choti hai stack2 ke top element se
            st2.push(val);
        }  
    }
    
    void pop() {
        if(st1.top() == st2.top()){
            st2.pop(); // removes the top most element which is current min
        }
        st1.pop(); // removes the top element from stack 1
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */