class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans = "";
        vector<int> count(26,0);
        for(auto a:s){
            count[a-'a']++;
        }

        int i = 25;
        while(i>=0){
            if(count[i]==0){
                i--;
                continue;
            }
            int freq = min(repeatLimit,count[i]);
            int ch = 'a' + i;
            ans.append(freq,ch);
            count[i]-=freq;
            if(count[i]>0){
                int j =i-1;
                while(j>=0 && count[j]==0){
                    j--;
                }
                if(j<0){
                    break;
                }
                char cc = 'a' + j;
                ans.append(1,cc);
                count[j]--;
            }
        }

        return ans;

    }
};