class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder), end(folder));
        
        vector<string> ans;

        ans.push_back(folder[0]);

        for(int i=1; i<folder.size(); i++){
            string last = ans.back();
            int len = last.size();

            if(folder[i].substr(0, len) == last && 
               (folder[i].length() == len || folder[i][len] == '/')) {
                continue; 
            }

            else{
                ans.push_back(folder[i]);
            }
        }

        return ans;

    }
};