class Solution {
public:
    int count(vector<int>&mat){
        int c=0,maxi=0;
        for(int i=0; i<mat.size(); i++){
            if(mat[i]==0){
                c=0;
            }
            else{
                c++;
                maxi+=c;
            }
        }
        return maxi;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;

        for(int i=0; i<n; i++){
            vector<int> vec(m,1);
            for(int j = i; j<n; j++){
                for(int col = 0; col<m; col++){
                    vec[col] = vec[col]&mat[j][col];
                }
                ans+=count(vec);
            }
        }

        return ans;
    }
};