class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long ans = 0;
        int n = nums.size();
        
        long long l = 0,r=0;

        for(int i=0; i<n; i++){
            r = target[i] - nums[i];
            
            if(l*r < 0){
                ans+=abs(r);
            }
            else if(abs(r)>abs(l)){
                ans+=abs(r-l);
            }

            l = r;
        }

        return ans;
    }
};