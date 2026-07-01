class Solution {
public:
    // Largest index where arr[mid] <= target
    int floorIndex(vector<int>& arr, int target) {
        int s = 0, e = arr.size() - 1;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] <= target) {
                ans = mid;
                s = mid + 1;   // right side for larger <= target
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }

    // Smallest index where arr[mid] >= target
    int ceilIndex(vector<int>& arr, int target) {
        int s = 0, e = arr.size() - 1;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] >= target) {
                ans = mid;
                e = mid - 1;   // left side for smaller >= target
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = ceilIndex(nums, target);
        int last  = floorIndex(nums, target);

        // Agar target exist nahi karta
        if (first == -1 || last == -1 || nums[first] != target || nums[last] != target) {
            return {-1, -1};
        }
        return {first, last};
    }
};