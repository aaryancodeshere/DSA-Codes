class Solution {
public:
    void change(string &s, char c, int idx, char to){
        for(int i=idx; i<s.size(); i++){
            if(s[i]==c){
                s[i]=to;
            }
        }
    }

    int minMaxDifference(int num) {
        string s1 = to_string(num);
        string s2 = to_string(num);

        int n = s1.size();
        for(int i=0; i<n; i++){
            if(s1[i]!='9'){
                change(s1,s1[i],i,'9');
                break;
            }
        }

        for(int i=0; i<n; i++){
            if(s2[i]!='0'){
                change(s2,s2[i],i,'0');
                break;
            }
        }


        int ans = stoi(s1) - stoi(s2);

        return ans;

    }
};