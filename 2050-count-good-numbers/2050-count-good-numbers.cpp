class Solution {
public:
    const int MOD = 1000000007;
    long long power(long long a, long long b){
        if(b==0)return 1;

        long long half = power(a,b/2);
        long long result = (half*half)%MOD;

        if(b%2){
            result = (result*a)%MOD;
        }

        return result;
    }
    int countGoodNumbers(long long n) {
        
        long long evenpos = (n+1)/2;
        long long oddpos = n - evenpos;
        long long ans = power(5,evenpos)*(power(4,oddpos))%MOD;
        

        return ans;
        
    }
};