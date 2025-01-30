class Solution {
public:
    

    string countAndSay(int n) {
        string ans = "1";
        
        while(--n){
                string temp = "";
                int i=0;
                while(i<ans.size()){
                    int count =0;
                    char c = ans[i];
                    while(i< ans.size() && ans[i]==c){
                        i++;
                        count++;
                    }
                    temp += to_string(count) + c;   
                
            }
            ans= temp;
        }
        return ans;
    }
};