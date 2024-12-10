class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int> mp;
        for(int i=0; i<s.size(); i++){
            string temp = "";
            int j=i;
            while(j<s.size() && s[j]==s[i]){
                temp+=s[j];
                mp[temp]++;
                j++;
            }
        }
        int ans=0;
        for(auto m: mp){
            if(m.second>=3){
                int temp = m.first.size();
                ans = max(ans,temp);
            }
        }
        return ans==0?-1:ans;
    }
};