class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int i=0,j=0;
        int n = colors.size();
        int s = n+k-1;
        while(j<s){
            if((j-i+1)==k){
                ans++;
                i++;
            }

            if((j+1)<s && colors[(j+1)%n]!=colors[j%n]){
                j++;
            }
            else{
                i = j+1;
                j = i;
            }
        }
        return ans;
    }
};