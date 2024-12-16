class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        int n = nums.size();
        for(int i=0; i<n; i++){
            pq.push({nums[i],i});
        }

        while(k--){
            int mini = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            int newval = mini*multiplier;

            pq.push({newval,idx});
        }

        for(int i=0; i<n; i++){
            int val = pq.top().first;
            int idx = pq.top().second;

            nums[idx]= val;
            pq.pop();
        }
        return nums;
    }
};