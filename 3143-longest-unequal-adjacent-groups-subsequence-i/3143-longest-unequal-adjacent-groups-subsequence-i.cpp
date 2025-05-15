class Solution {
public:
    int n;
    vector<string> ans;
    void solve(vector<string>& words, vector<int>& groups, int i, int curr){
        if(i>=n)return;

        if(groups[i]!=curr){
            ans.push_back(words[i]);
            solve(words,groups,i+1,groups[i]);
        }

        else{
            solve(words,groups,i+1,curr);
        }


    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        n = words.size();
        ans.push_back(words[0]);
        solve(words,groups,1,groups[0]);
        return ans;
    }
};