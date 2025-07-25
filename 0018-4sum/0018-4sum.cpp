class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0; i<n; i++){
            if(i!=0 && nums[i]==nums[i-1])continue;
            for(int j=i+1; j<n; j++){
                if(j!= i+1 and nums[j] == nums[j-1])continue;

                long long sum = nums[i] + nums[j];
                long long com = target - sum;
                int k = j+1,l = n-1;
                while(k<l){
                    

                    if(nums[k] + nums[l] == com){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1])k++;
                        while(k<l && nums[l] == nums[l+1])l--;

                    }else if(nums[k] + nums[l] > com){
                        l--;

                    }else{
                        k++;
                    }
                }
            }
        }

        return ans;
    }
};