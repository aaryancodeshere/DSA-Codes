class Solution {
public:
    int n,m;

    string shortestCommonSupersequence(string str1, string str2) {
        n = str1.size();
        m = str2.size();

        vector<vector<int>>t(n+1,vector<int>(m+1,0));
        for(int i=0; i<n+1; i++){
            for(int j = 0; j<m+1; j++){
                if(i==0 || j==0){
                    t[i][j]= i+j;
                }
                else{
                    if(str1[i-1]==str2[j-1]){
                        t[i][j] = 1 + t[i-1][j-1];
                    }
                    else{
                        t[i][j]=  1 + min(t[i-1][j],t[i][j-1]);
                    }
                }
            }
        }

        string ans = "";
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;j--;
            }
            else{
                if(t[i-1][j]>t[i][j-1]){
                    ans+=str2[j-1];
                    j--;
                }else{
                    ans+=str1[i-1];
                    i--;
                }
            }
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};