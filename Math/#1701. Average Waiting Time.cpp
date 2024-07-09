class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int timeelapsed= customers[0][0];
        double wait =0;

        for(int i=0; i<n; i++){
            int arrival = customers[i][0];
            int timetocook = customers[i][1];
             if(timeelapsed<arrival){
                timeelapsed=arrival;
             }

            
            wait+=timeelapsed+timetocook - arrival;
            timeelapsed+=timetocook;
        }

        double ans = wait/n;
        return ans;

    }
};