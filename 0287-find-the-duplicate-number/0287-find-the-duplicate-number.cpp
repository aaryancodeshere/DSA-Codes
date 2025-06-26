class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];

        int n = nums.size();

        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];

            if(fast==slow)break;
        }

        fast = nums[0];

        while(fast!=slow){
            fast = nums[fast];
            slow = nums[slow];
        }

        return slow;
    }
};