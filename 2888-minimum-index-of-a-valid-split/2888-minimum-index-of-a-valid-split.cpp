class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int ans=-1;
        int maxvalue = 0;
        int maxelement=0;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto pair: mp){
            if(maxvalue<pair.second){
                maxvalue = pair.second;
                maxelement = pair.first;
            }
        }
        int count = 0;
        int n = nums.size();
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==maxelement){
                count++;
            }
            if(count>((i+1)/2) && (maxvalue-count)>((n-i-1)/2)){
                ans = i;
                break;
            }
        }

        return ans;
        
    }
};