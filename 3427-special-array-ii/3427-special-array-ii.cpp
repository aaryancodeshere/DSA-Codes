class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<bool> ans(m,true);
        vector<int> csum(n,0);
        if(n==1){
            return ans;
        }

        for(int i=1; i<n; i++){
            if((nums[i]%2==0 && nums[i-1]%2==0) || (nums[i]%2==1 && nums[i-1]%2==1)){
                csum[i]= 1+csum[i-1];
            }
            else{
                csum[i]=csum[i-1];
            }
        }
        for(int i=0; i<queries.size(); i++){
            int start = queries[i][0];
            int end = queries[i][1];

            if(csum[start]!=csum[end]){
                ans[i]=false;
            }
        }
        return ans;
    }
};