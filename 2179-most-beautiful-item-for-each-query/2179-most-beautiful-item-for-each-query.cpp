class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n = items.size();
        int m = queries.size();
        
        vector<int> ans(m);
        int maxi = items[0][1];

        for(int i =1; i<n; i++){
            maxi=max(items[i][1],maxi);
            items[i][1]=maxi;
        }

        for(int i=0; i<m; i++){
            int l = 0,r=n-1;
            int curr = 0;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(queries[i]>=items[mid][0]){
                    curr = max(curr,items[mid][1]);
                    l = mid+1;
                }
                else {
                    r=mid-1;
                }
                
            }
            ans[i]=curr;
            
        }

        return ans;
        
    }
};