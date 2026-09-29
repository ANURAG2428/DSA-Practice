class KthLargest {
private:  
// made them private member of class because ye parameterized constructor mai local variable hai , constructor khtm hote hi ye khtm ho jayeneg , isley inhe class memeber bna diya 
    int k;
    priority_queue<int , vector<int>, greater<int>>pq; // Min-heap

public:
    KthLargest(int k, vector<int>& nums) {  // Constructor
    this->k = k; // intialize integer
        
        // step 1 : sbse pehle to priority queue(min heap) mai k element store kara le , where top will be the smallest element in priority queue
        
        for(int i = 0 ;i< nums.size() ; i++){
            if(pq.size() < k){
                pq.push(nums[i]);
            }
            else{
                if(nums[i]>pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        // if pq ka size hi km hai k se
        if(pq.size() < k){
            pq.push(val);
        }

        // If the smallest element is less than the element to be added
        else if(val > pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();  // Return the kth largest element
         
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */