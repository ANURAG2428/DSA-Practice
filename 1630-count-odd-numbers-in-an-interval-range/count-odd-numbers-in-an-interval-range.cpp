class Solution {
public:
    int countOdds(int low, int high) {
        // high tak kitne odds hai - low se pehle kitne odds the
        return (high + 1) / 2 - (low / 2);
    }
};
