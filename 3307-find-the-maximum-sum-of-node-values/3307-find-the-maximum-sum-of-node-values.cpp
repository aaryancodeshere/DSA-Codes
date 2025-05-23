class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum=0;
        int count=0;
        int mini=INT_MAX;

        for(long long num:nums){
            if((num^k)>num){
                sum+=(num^k);
                count++;
            }
            else{
                sum+=num;
            }
            mini=min((long long)mini,abs(num-(num^k)));
        }

        return count%2==0?sum:sum-mini;

    }
};