class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0; i<m; i++){
            mp[nums2[i]] = i;
        }

        vector<int> ng(m,-1);

        stack<int> s;
        for(int i= m-1; i>=0; i--){
            while(!s.empty() && s.top()<nums2[i]){
                s.pop();
            }
            ng[i] = s.empty()?-1 :s.top();

            s.push(nums2[i]);
        }
        vector<int> ans(n,-1);
        for(int i=0; i<nums1.size(); i++){
            ans[i] = ng[mp[nums1[i]]];
        }

        return ans;
    }
};