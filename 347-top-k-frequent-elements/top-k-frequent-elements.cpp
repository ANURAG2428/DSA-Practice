class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        // step 1 : create a unordered_map , which will store {key,value} pair
        // for each {element , freq}
        unordered_map<int, int> mpp;
        for (auto x : nums) {
            mpp[x]++;
        }

        // step 2 : ab ek min-heap priority_queue bna (of pair type) which ,
        // works on the basis of freq {which is the value } in map . MIN HEAP OF
        // TYPE (FREQ , ELEMENT)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        // step 3 : put starting k elements in pq firstly
        int cnt = 0;          // will use cnt
        for (auto& p : mpp) { // iterate over map using range-based loop insted
                              // of iterating via iterator
            // jb tk cnt km hai k se usko mpp {key,val} ko pq mai as {val,key}
            // push krte jao
            if (cnt <
                k) { // as indexing is starting form 0 , so will move to only <k
                pq.push({p.second, p.first});
                cnt++;
            }
            // now ab cnt>=k , now ab mai pq mai sirf max-freq {val,key} rakhna
            // chahta hu , so mai pq.top().first ko p.second se compare karunga
            // , agr pq.top().first chota hai to will pop pq.top() and push
            // pq.push({p.second ,p.first})
            else {
                if (p.second > pq.top().first) {
                    pq.pop();
                    pq.push({p.second, p.first});
                }
            }
        }

        // step 4 :  now push all k elements of key which are in  pq in ans
        // vector
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};