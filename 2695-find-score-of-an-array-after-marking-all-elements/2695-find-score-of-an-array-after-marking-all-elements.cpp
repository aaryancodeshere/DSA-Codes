class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int,int>> arr;
        for(int i=0; i<nums.size(); i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());

        long long score=0;
        int n = nums.size();

        for(int i=0; i<arr.size(); i++){

            long long num = arr[i].first;
            int idx = arr[i].second;
            if(nums[idx]!=-1){
                score+=num;
                if((idx -1)>=0){
                    nums[idx-1]=-1;
                }
                if(idx+1<n){
                    nums[idx+1]=-1;
                }
                
            }
            
            
        }
        return score;
    }
};