class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        vector<bool> aa(n+1,false);
        vector<bool> bb(n+1,false);

        for(int i=0; i<n; i++){
            aa[A[i]]=true;
            bb[B[i]]=true;
            int count=0;
            for(int j=0; j<=n; j++){
                if(aa[j]==true && bb[j]==true)count++;
            }
            ans[i]=count;
        }
        return ans;
    }
};