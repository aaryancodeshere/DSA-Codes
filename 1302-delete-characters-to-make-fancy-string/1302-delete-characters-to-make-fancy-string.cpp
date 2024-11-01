class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        unordered_set<int> idx;
        if(n<3)return s;
        int i=0,j=1,k=2;
        while(k<s.size()){
            if(s[i]==s[j] && s[j]==s[k]){
                idx.insert(i);
            }
            
                i++;
                j++;
                k++;
            
        }
        string a = "";
        for(int i =0; i<n; i++){
            if(!idx.contains(i)){
                a+=s[i];
            }
        }
        return a;
    }
};