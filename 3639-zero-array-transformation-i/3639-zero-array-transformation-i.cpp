class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> change(n,0);

        for(int i=0; i<queries.size(); i++){
            int id = queries[i][0];
            int nid = queries[i][1];

            change[id]+=1;
            if(nid+1<n){
                change[nid+1]-=1;
            }
        }

        for(int i=1; i<n; i++){
            change[i]+=change[i-1];
        }
        

        for(int i=0; i<n; i++){
            if(nums[i]>change[i])return false;
        }
        return true;
    }
};