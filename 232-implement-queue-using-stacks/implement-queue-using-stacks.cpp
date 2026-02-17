// Approch 1 : ye mai tb implement kar rha hu , jb push operations km hai , kyoki mere push ke code mai 2 while loop honge which makes its T.C = O(2N) and it is a costly operation and will reduce my code effeciency and perfomance

class MyQueue {
    private:
    stack<int>st1;  // stack 1 
    stack<int>st2;  // stack 2
public:
    MyQueue() {
        // It is default constructor that is called when object is created of the above class , 
    }
    
    void push(int x) {  // T.C = O(2n) , this code of push is only applicable if push operations are way less as compare to pop() and top() , else we prefer to follow Approch 2 , where large no of push operation are handeled with effective T.C


        // step 1 : st1 ke sare element st2 mai daal do 
        while(st1.size()){
            st2.push(st1.top());
            st1.pop();
        }

        // Step 2 : ab st1 mai new element x daal do
        st1.push(x);

        // step 3 : st2 ke sare element st1 mai wapis daal do
        while(st2.size()){
            st1.push(st2.top());
            st2.pop();
        }

        // here push operation is handeled fully 
    }
    
    int pop() {
        int n = st1.top();
        st1.pop();
        return n;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */