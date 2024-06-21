class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();
        int curr = 0;

        int maxi = curr;
        int i=0,j=0;
        while(j<n){
            curr+=customers[j]*grumpy[j];
            
            if(j-i+1>minutes){
                curr-=customers[i]*grumpy[i];
                
                i++;
            }
            maxi=max(maxi,curr);
            j++;

        }
        

        for(int i=0; i<n; i++){
            maxi+=customers[i]*(1-grumpy[i]);
        }
        return maxi;

        

    }
};