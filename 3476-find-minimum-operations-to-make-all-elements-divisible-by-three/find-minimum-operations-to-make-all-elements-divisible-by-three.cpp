class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0; 
        for(auto num : nums ){
            if((num - 1) % 3 == 0) cnt++;
            else if ((num + 1) % 3 == 0) cnt++;

        }
        if(cnt == 0) return 0;
        return cnt;
    }
};