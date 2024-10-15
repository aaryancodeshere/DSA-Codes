class Solution {
public:
    typedef long long ll;
    long long minimumSteps(string s) {
        ll n = s.size();
        if(n==1)return 0;

        ll countone=0,ans=0;
        for(ll i=0; i<n; i++){
            if(s[i]=='0'){
                ans+=countone;
            }
            else{
                countone++;
            }
        }

        return ans;

    }
};