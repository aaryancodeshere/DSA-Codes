class Solution {
public:

    bool hamming(string s1, string s2){
        int ans=0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                ans++;
            }
            if(ans>1)return false;
        }
        return true;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<int> dp(n,1);
        vector<int> parent(n,-1);
        int maxi=1,maxiidx = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<=i-1; j++){
                if(groups[i]!=groups[j] && words[i].length() == words[j].length() && hamming(words[i],words[j])){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        parent[i]=j;
                        if(dp[i]>maxi){
                            maxi = dp[i];
                            maxiidx = i;
                        }
                    }
                }
            }
        }
        vector<string> ans;

        while(maxiidx!=-1){
            ans.push_back(words[maxiidx]);
            maxiidx = parent[maxiidx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};