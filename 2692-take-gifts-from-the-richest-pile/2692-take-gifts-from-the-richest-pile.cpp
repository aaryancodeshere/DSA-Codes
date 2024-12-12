class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int i=0; i<gifts.size(); i++){
            pq.push(gifts[i]);
        }
        for(int i=0; i<k; i++){
            long long curr = (pq.top());
            pq.pop();
            long long rem = (sqrt(curr));
            pq.push(rem);
        }
        long long ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};