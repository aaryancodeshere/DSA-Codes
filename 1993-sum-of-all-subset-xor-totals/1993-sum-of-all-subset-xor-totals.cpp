class Solution {
public:
    
    int subsetXORSum(vector<int>& nums) {
       int n=nums.size();
       int sum=0;
       for(auto num:nums){
        sum|=num;

       }

       return sum<<(n-1);
    }
};