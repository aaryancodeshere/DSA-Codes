class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freetime;
        int n = startTime.size();
        int currend=0;

        freetime.push_back(startTime[0]);
        currend = endTime[0];

        for (int i = 1; i < n; i++) {
            int temp = startTime[i] - endTime[i - 1];
            freetime.push_back(temp);  
            currend = endTime[i];
        }

        freetime.push_back(eventTime - endTime[n - 1]);

        int j = 0,i=0;
        int sum = 0;
        int maxi = 0;
        int m = freetime.size();
        while(j<m){
            if((j-i+1)>k+1){
                sum-=freetime[i];
                i++;;
            }
            else{
                sum+=freetime[j];
                maxi = max(maxi,sum);
                j++;
            }
            

        }

        return maxi;
    }
};