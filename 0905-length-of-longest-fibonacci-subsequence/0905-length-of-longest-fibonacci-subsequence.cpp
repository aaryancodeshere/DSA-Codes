class Solution {
public:
    int n;
    int solve(vector<int>& arr, int i,int j, unordered_map<int,int>&mp){
        int target = arr[i] + arr[j];
        if(mp.count(target)){
            int idx = mp[target];
            return 1 + solve(arr,j,idx,mp);
        }
        return 2;

    }
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>mp;
        n = arr.size();
        for(int i=0; i<n; i++){
            mp[arr[i]]=i;
        }
        int ans =0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int maxi = solve(arr,i,j,mp);
                if(maxi>2){
                    ans = max(ans,maxi);
                }
            }
        }
        
        return ans;
    }
};