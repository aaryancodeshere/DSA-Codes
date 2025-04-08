class Solution {
public:
    bool check(vector<int>& nums, int idx) {
        unordered_set<int> seen;
        for (int i = idx; i < nums.size(); i++) {
            if (seen.count(nums[i])) return false;
            seen.insert(nums[i]);
        }
        return true;
    }

    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (check(nums, i)) break;
            count++;
        }
        return ceil(count / 3.0); // FIXED: must divide by 3.0 (double)
    }
};