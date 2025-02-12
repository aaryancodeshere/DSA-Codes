class Solution {
public:
    int sum(int num){
        int ans=0;
        while(num){
            ans+=num%10;
            num/=10;
        }
        return ans;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=-1;
        for(int i=0; i<nums.size(); i++){
            int currsum = sum(nums[i]);
            if(mp.count(currsum)){
                ans = max(ans,mp[currsum]+nums[i]);
            }
            mp[currsum]=max(mp[currsum],nums[i]);
        }

        return ans;
    }
};