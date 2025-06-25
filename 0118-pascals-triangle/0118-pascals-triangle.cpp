class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});

        if(numRows==1)return ans;
        numRows--;

        while(numRows--){
            vector<int> temp;
            vector<int> prev = ans.back();
            int n = prev.size();

            for(int i=0; i<=n; i++){
                int a = (i-1)>=0 ? prev[i-1] : 0;
                int b = i<n ? prev[i] : 0;

                temp.push_back(a+b);
            }

            ans.push_back(temp);
        }

        return ans;

    }
};