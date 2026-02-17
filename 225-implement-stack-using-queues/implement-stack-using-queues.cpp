class MyStack {
    private:
    queue<int>q; // idhr mene queue create kr li 
public:
    MyStack() {
    // constuctor will be called during object creation , but yaha koi parameter to hai nhi pass krne ke liye so it is a default constructor jo ki call hoga        
    }
    
    void push(int x) {
        // sbse pehle current queue ka size store kara le in variable
        int s = q.size(); // push krne se pehle maine size store kara liya for ease 
        q.push(x); // ab mene ye x element ko queue mai rear mai store kara liya
        // Now ab mera main task hai isko front position pai lana because queue ese hi kaam karta hai
        for(int i = 0; i<s ; i++ ){ // less than s because indexing 0 se shuru ho rhi hai
            q.push(q.front());
            q.pop();// ab piche mene shift kara liya hai , ab isko aage se remove kara diya
        }
    }
    
    int pop() {
        // mene  front element ko int variable mai store kara liya because this func is of int type so isko int return krna hai which is front , so to store it i have used n
        int n = q.front();    
        q.pop();
        return n;
    }
    
    int top() {
        return q.front(); // simply return the top element which is the front elemnt in the queue
        
    }
    
    bool empty() {
        return q.empty();
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