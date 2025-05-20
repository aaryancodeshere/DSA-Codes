class Solution {
public:
    int binarysearch(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) return mid;

            // Check which half is sorted
            if (nums[l] <= nums[mid]) {
                // Left half is sorted
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // Right half is sorted
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binarysearch(nums, target, 0, nums.size() - 1);
    }
};