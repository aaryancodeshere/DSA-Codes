class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        long long mini=INT_MAX;
        int nums=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]<0){
                    nums++;
                }
                mini=min(mini,(long long)abs(matrix[i][j]));
                ans+=(long long)abs(matrix[i][j]);
            }
        }
        if(nums%2){
            return ans-2*mini;
        }
        else{
            return ans;
        }
    }
};