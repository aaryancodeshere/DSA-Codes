class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        if(n%2)return false;

        unordered_map<int,int> mp;

        for(auto m: nums){
            mp[m]++;
        }

        for(auto n: mp){
            if(n.second % 2)return false;
        }

        return true;
    }
};