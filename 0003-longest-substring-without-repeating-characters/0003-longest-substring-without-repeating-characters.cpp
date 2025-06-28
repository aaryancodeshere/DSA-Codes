class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size()<=1)return s.size();

        int i=0,j=0,ans=0;
        unordered_set<char> m;
        while(j<s.size()){
            if(m.count(s[j])){
                while(i<j && s[i]!=s[j]){
                    m.erase(s[i]);
                    i++;
                }  
                m.erase(s[i]);
                i++;
            }
            else{
                m.insert(s[j]);
                ans=max(ans,j-i+1);
                j++;
            }
        
        
        
        
        
        
        }

        return ans;
        
    }
};