class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int m = nums.size();
        
        vector<int> ng(m,-1);

        stack<int> s;
        for(int i= 2*m-1; i>=0; i--){
            while(!s.empty() && s.top()<=nums[i%m]){
                s.pop();
            }
            if (i < m) {
                ng[i] = s.empty() ? -1 : s.top();
            }


            s.push(nums[i%m]);
        }
        return ng;
    }
};