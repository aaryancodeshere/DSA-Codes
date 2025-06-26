class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();

        int length = 0;
        int factor = 1;

        for(int i=n-1; i>=0; i--){
            if(s[i]=='0'){
                length++;
                factor <<= 1;
            }
            else if(factor<=k){
                length++;
                k-=factor;
                factor <<= 1;
            }
        }

        return length;
    }
};