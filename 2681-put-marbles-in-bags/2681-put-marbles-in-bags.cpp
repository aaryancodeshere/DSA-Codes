class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        int m = n -1;

        vector<int> pairs(m,0);

        for(int i =0 ;i<m; i++){
            pairs[i] = weights[i]+weights[i+1];
        }

        sort(pairs.begin(), pairs.end());

        long long mini = 0;
        long long maxi = 0;

        for(int i=0; i<k-1; i++){
            mini += pairs[i];
            maxi += pairs[m - i -1];
        }

        return maxi - mini;
    }
};