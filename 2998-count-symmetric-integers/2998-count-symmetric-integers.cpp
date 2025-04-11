class Solution {
public:

    bool check(int num){
        string s = to_string(num);
        int n = s.size();
        int fsum =0,ssum=0;
        for(int i=0; i<n/2; i++){
            fsum+=int(s[i]);
        }
        for(int i=n/2; i<n; i++){
            ssum+=int(s[i]);
        }

        return fsum==ssum;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for(int i = low; i<= high; i++){
            string s= to_string(i);
            if(s.size()%2)continue;

            if(check(i)){
                ans++;
            }
        }

        return ans;
        
    }
};