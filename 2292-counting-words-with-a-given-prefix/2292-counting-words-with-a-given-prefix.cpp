class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int m = pref.size();
        int count=0;

        for(int i=0; i<n; i++){
            if(words[i].substr(0,m)==pref)count++;
        }
        return count;
    }
};