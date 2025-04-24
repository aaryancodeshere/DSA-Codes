class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &num:nums){
            st.insert(num);
        }
        int distinct = st.size();
        unordered_map<int,int> mp;
        int i=0,j=0;
        int ans = 0;
        int n = nums.size();
        while(j<n){
            mp[nums[j]]++;
            while(i<=j && mp.size()==distinct){
                ans+=(n-j);
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }

            j++;
        }
        return ans;

    }
};