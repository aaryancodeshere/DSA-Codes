class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(),queries.end());
        priority_queue<int> pq;
        priority_queue<int,vector<int>, greater<int>> past;

        int q = queries.size();
        int n = nums.size();
        int j=0;
        int used = 0;

        for(int i=0; i<n; i++){

            while(j<q && queries[j][0]==i){
                pq.push(queries[j][1]);
                j++;
            }
            nums[i]-=past.size();

            while(nums[i]>0 && !pq.empty() && pq.top()>=i){
                int curr = pq.top();
                past.push(curr);
                pq.pop();
                nums[i]--;
                used++;
            }
            if(nums[i]>0)return -1;

            while(!past.empty() && past.top()==i){
                past.pop();
            }

        }
        return q - used;

    }
};