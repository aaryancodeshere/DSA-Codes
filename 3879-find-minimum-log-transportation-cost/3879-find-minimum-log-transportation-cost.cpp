class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        int maxi = max(n,m);
        int mini = min(n,m);

        if(maxi<=k)return 0;

        long long cost = 0;
        long long diff1 = maxi -  k;
        cost+=diff1*k;

        long long diff2 = mini - k;
        if(diff2>0){
            cost+=diff2*k;
        }
        return cost;
    }
};