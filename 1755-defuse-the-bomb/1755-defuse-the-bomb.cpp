class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans;

        if(k<0){
            for(int i=0; i<n; i++){
                int sum = 0;
                for(int j=0; j<abs(k); j++){
                    sum+=code[((i-1-j)%n + n)%n];
                }
                ans.push_back(sum);
            }
        }
        if(k>0){
            for(int i=0; i<n; i++){
                int sum = 0;
                for(int j=0; j<abs(k); j++){
                    sum+=code[((i+1+j)%n + n)%n];
                }
                ans.push_back(sum);
            }
        }
        if(k==0){
            for(int i=0; i<n; i++){
                ans.push_back(0);
            }
        }
        return ans;
    }
};