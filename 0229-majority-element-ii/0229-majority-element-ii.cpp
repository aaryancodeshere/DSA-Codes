class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1,ele2;
        int count1=0,count2=0;

        int n = nums.size();

        for(int i=0; i<n; i++){
            
            if(ele1 == nums[i]){
                count1++;
            }
            else if(ele2 == nums[i]){
                count2++;
            }
            else if(count1==0 ){
                ele1=nums[i];
                count1 = 1;
            }
            else if(count2==0 ){
                ele2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        cout<<count1 << " "<<count2;
        int c1=0,c2=0;

        for(int i=0; i<n; i++){
            if(nums[i]== ele1)c1++;

            if(nums[i]==ele2)c2++;
        }

        vector<int> ans;
        if(c1>n/3)ans.push_back(ele1);

        if(c2>n/3 && ele1 !=ele2)ans.push_back(ele2);

        return ans;
    }
};