class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        int el = nums[0];
        cnt = 1;
        for(int i = 1; i<n ; i++){
            if(nums[i] == el){
                cnt++;
            }
            else{
                cnt--;
                }
            if(cnt == 0){
                el = nums[i];
                cnt = 1;
            }
        }

        // Now loop se check kr el element mai present element  > n/2 present hai
        int newcnt = 0;
        for(int i = 0; i<n ; i++){
            if(nums[i] == el){
                newcnt++;
            }
            if(newcnt > n/2){
                return el;
            }
        } 

        return -1;
    }
};