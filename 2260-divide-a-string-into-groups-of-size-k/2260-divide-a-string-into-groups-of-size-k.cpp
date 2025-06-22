class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int n = s.size();
        for(int i=0; i<n; i+=k){
            string temp = (n - i)>=k ? s.substr(i,k): s.substr(i,n-i);
            ans.push_back(temp);
        }
        
        string last = ans.back();
        int m = last.size();
        if(m<k){
            for(int i=0; i<k-m; i++){
                last.push_back(fill);
            }
            ans.pop_back();
            ans.push_back(last);
        }

        return ans;
    }
};