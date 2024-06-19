class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>m;
        unordered_map<char,int>n;
        
        if(s.size()!= t.size())return false;

        for(int i=0; i<s.size(); i++){
            if(m.count(s[i])){
                if(m[s[i]]!=t[i]) return false;
            }

            m[s[i]]=t[i];

        }for(int i=0; i<s.size(); i++){
            if(n.count(t[i])){
                if(n[t[i]]!=s[i]) return false;
            }

            n[t[i]]=s[i];

        }      

        return true;
    }
}; 