class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans=100,curr=0;
        int i=0,j=0;
        while(j<n){
            if(blocks[j]=='W'){
                curr++;
            }
            if((j-i+1)==k){
                ans = min(ans,curr);
                if(blocks[i]=='W'){
                    curr--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};