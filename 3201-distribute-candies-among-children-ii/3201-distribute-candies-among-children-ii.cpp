class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long mini = max(0,n-2*limit);
        long long maxi = min(n,limit);
        long long ways=0;

        for(int i=mini; i<=maxi; i++){
            int N = n - i;
            long long mini2 = max(0,N-limit);
            long long maxi2 = min(N,limit);
            ways+= maxi2 - mini2 + 1;
        }
        return ways;
    }
};