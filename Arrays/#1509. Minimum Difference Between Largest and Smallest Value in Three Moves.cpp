class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=3)return 0;

        sort(nums.begin(), nums.end());

        int i=3;
        int j=nums.size()-1;
        int k= nums.size()-4;
        int l= 2;
        int m= nums.size()-3;
        int n= nums.size()-2;
        int ans=INT_MAX;
        int a = min((nums[j]-nums[i]),(nums[k]-nums[0]));
        int b = min((nums[n]-nums[l]),nums[m]-nums[1]);
        ans= min(a,b);

        return ans;
    }
};