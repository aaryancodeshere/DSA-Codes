class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(int i=0;i<n; i++){
            mp[nums[i]]++;
        }
        
        int ans = 0;

        for(int i=0; i<n; i++){
            int next = nums[i] + 1;
            if(mp.contains(next)){
                int count = mp[nums[i]] + mp[next] ;
                ans = max(ans,count);
            }
        }

        return ans;
    }
};