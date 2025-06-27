class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int len = 0;

        for(int i=0; i<nums.size(); i++){
            if(len==0){
                len=1;
                ele = nums[i];
            }
            else if(ele == nums[i]){
                len++;
            }
            else{
                len--;
            }
        }
        int count=0,n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]==ele)count++;
        }

        if(count>(n/2))return ele;

        return -1;
    }
};