class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>&temp, vector<vector<int>>&ans, int n){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        
        solve(nums,i+1,temp,ans,n);
        temp.pop_back();
        while(i<n-1 && nums[i+1] == nums[i])i++;
        solve(nums,i+1,temp,ans,n);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        solve(nums,0,temp,ans,n);
        return ans;
    }
};