class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        int i=0;
        int n = nums.size();
        while(i+2<n){
            if(nums[i+2]-nums[i]<=k){
                vector<int> temp;
                for(int j = i; j<i+3; j++){
                    temp.push_back(nums[j]);
                }
                ans.push_back(temp);
            }
            else{
                return {};
            }
            i= i+3;
        }

        return ans;
    }
};