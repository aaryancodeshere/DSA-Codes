class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
        for(int i=0; i<32; i++){
            int count=0;
            for(int num:candidates){
                if(num &(1<<i)){
                    count++;
                }
            }
            ans=max(ans,count);
        }
        return ans;
    }
};