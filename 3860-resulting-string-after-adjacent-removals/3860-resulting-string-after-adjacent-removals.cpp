class Solution {
public:
    string resultingString(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(!st.empty()){
                int top = st.top();
                int diff = abs(top - s[i]);
                if(diff == 1 || diff == 25){
                    st.pop();
                    continue;
                }
                st.push(s[i]);
            }
            else{
                st.push(s[i]);
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        

        return ans;
    }
};