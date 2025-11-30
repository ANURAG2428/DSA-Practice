class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // Step 1: Calculate total sum of elements in the array
    long long totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    // Step 2: Check if the total sum is already divisible by p
    if (totalSum % p == 0) {
        return 0;  // No need to remove any element
    }

    // Step 3: Calculate the remainder of total sum when divided by p
    long long remainder = totalSum % p;
    
    // Step 4: Map to store the last seen index of a particular remainder
    unordered_map<long long, int> remainderIndex;
    remainderIndex[0] = -1;  // To handle the case when subarray starts from index 0

    // Step 5: Iterate through the array to find the minimum subarray to remove
    long long currentSum = 0;
    int result = nums.size();  // Start with the worst case (removing all elements)
    for (int i = 0; i < nums.size(); i++) {
        currentSum += nums[i];
        long long mod = currentSum % p;

        // Check if we have seen a remainder that helps to make the sum divisible by p
        long long target = (mod - remainder + p) % p;

        if (remainderIndex.find(target) != remainderIndex.end()) {
            result = min(result, i - remainderIndex[target]);
        }
        
        // Store the current remainder with its index
        remainderIndex[mod] = i;
    }

    // If no valid subarray found, return -1
    return result == nums.size() ? -1 : result;
    }
};