class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> arr=nums;
        int n = nums.size();
        sort(arr.begin(),arr.end());
        for(int i=0; i<arr.size(); i++){
            int count=0;
            for(int j = 0; j<arr.size(); j++){
                if(nums[(i+j)%n]==arr[j])count++;
            }
            if(count==n)return true;

        }
        return false;
    }
};