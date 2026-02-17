// Approch 2 : here mere pass bht sare push() operation hai in input as compare to pop() and top() , so i will choose this approch, as 

// koi hard & fast rule nhi hai ki sirf st1 ko use krke hi result return krna hai , hm dono mai se kisi bhi stack ko us krke us particular operation ka result return kara skte hai

class MyQueue {
    // similarly we will make 2 stack
    private: 
    stack<int>st1;
    stack<int>st2;
public:
    MyQueue() {
        // Default Constructor
    }
    
    void push(int x) {
        st1.push(x); // is approch hm st1 mai sare push operation ke element store karate reh jayenge
    }
    
    int pop() {
        if(st2.size()){ // means i have element in st2
            int n = st2.top();
            st2.pop();
            return n;
        }
        else{ // means no element in st2 , aur yhi stack shi top dega
            while(st1.size()!=0){
                st2.push(st1.top());
                st1.pop();
            }
            // loop se bahr aagya means sare element st2 stack mai aagye , now
            int m = st2.top();
            st2.pop();
            return m;
        }
    }
    
    int peek() {
        if(st2.size()){ // means element are present in st2 stack
            return st2.top();
        }
        else{ // means no element present in st2
            while(st1.size()!=0){
                st2.push(st1.top());
                st1.pop();
            }
            // loop se bahr aagya means sare element st2 mai aagye
            return st2.top();

        }
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
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