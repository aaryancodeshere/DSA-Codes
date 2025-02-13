class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int a : nums) {
            pq.push(a);
        }

        int ans = 0;
        while (pq.size() >= 2) {
            long long top = pq.top();
            if (top >= k) return ans;
            pq.pop();
            long long second = pq.top();
            pq.pop();
            long long newnum = min(top, second) * 2LL + max(top, second); 
            pq.push(newnum);
            ans++;
        }

        return ans;

    }
};