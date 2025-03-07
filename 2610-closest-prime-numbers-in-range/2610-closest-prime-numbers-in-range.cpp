class Solution {
public:

    bool isprime(int x){
        if(x==1)return false;
        for(int i=2; i*i<=x; i++){
            if(x%i==0)return false;
        }

        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        for(int i=left; i<=right; i++){
            if(isprime(i)){
                if(!primes.empty() && i-primes.back()<=2){
                    return {primes.back(),i};
                }
                primes.push_back(i);
            }
        }

        vector<int>ans(2,-1);
        int maxi = INT_MAX;

        for(int i=1; i<primes.size(); i++){
            if((primes[i]-primes[i-1])<maxi){
                ans[0]=primes[i-1];
                ans[1]=primes[i];
                maxi = primes[i]-primes[i-1];
            }
        }

        return ans;
    }
};