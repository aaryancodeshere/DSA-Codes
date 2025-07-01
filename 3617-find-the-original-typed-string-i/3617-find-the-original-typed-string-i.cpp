class Solution {
public:
    int possibleStringCount(string word) {
       int i=0;
       int n = word.size();
        int ans=0;
       while(i<n){
            char c = word[i];
            while(i<n && word[i]==c){
                ans++;
                i++;
            }
            ans--;
       }
       return ans+1;
    }
};