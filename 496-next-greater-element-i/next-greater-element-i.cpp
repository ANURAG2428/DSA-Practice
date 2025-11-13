class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // stack use karenge next greater element find karne ke liye
        stack<int> st;
        unordered_map<int, int> nextGreater; // har element ka next greater store karega
        
        // nums2 ke through right se left traverse karte hain
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int curr = nums2[i];
            
            // stack se sab chhote elements hata do
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }
            
            // agar stack empty hai to koi next greater nahi
            if (st.empty()) {
                nextGreater[curr] = -1;
            } else {
                nextGreater[curr] = st.top();
            }
            
            // current element ko stack mein daal do
            st.push(curr);
        }
        
        // ab nums1 ke liye result banate hain
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        
        return result;
    }
};
