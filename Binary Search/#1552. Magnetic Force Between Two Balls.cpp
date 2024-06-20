class Solution {
public:

    bool possible(vector<int>& position, int m, int force){
        int prev = position[0];
        int count=1;
        for(int i=1; i<position.size(); i++){
            int curr = position[i];
            if(curr-prev>=force){
                count++;
                prev=curr;
            }
            if(count==m){
                return true;
            }
        }
        return false;

    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n=position.size();
        int l=1,r=position[n-1]-position[0];
        int result=0;
        while(l<=r){
            int mid= l+ (r-l)/2;
            if(possible(position,m,mid)){
                result=mid;
                l=mid+1;
            }

            else{
                r=mid-1;
            }

        }

        return result;   
    }
};