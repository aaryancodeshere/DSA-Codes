class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int curr = nums[0];
        int start = 0, end = 0, tempStart = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (curr + nums[i] < nums[i]) {
                curr = nums[i];
                tempStart = i;  
            } else {
                curr += nums[i];
            }

            if (curr > maxi) {
                maxi = curr;
                start = tempStart;
                end = i;
            }
        }

        cout << "Maximum subarray is from index " << start << " to " << end << endl;

        return maxi;
    }
};