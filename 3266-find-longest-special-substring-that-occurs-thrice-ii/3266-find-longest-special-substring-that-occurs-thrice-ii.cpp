class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> ch(26,vector<int>(n+1,0));
        char prev = s[0];
        int l =0;
        for(int i=0; i<n; i++){
            char curr = s[i];
            if(curr == prev){
                l++;
                ch[curr-'a'][l]++;
                
            }
            else{
                l=1;
                ch[curr-'a'][l]++;
                prev = curr;
            }
        }
        int ans =-1;
        for(int i=0; i<26; i++){
            int csum=0;
            for(int j = n; j>=1; j--){
                csum+=ch[i][j];
                if(csum>=3){
                    ans = max(ans,j);
                    break;
                }
            }
        }
        return ans;
    }
};