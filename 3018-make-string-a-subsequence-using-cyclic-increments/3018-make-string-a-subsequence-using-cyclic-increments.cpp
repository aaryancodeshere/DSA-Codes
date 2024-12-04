class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0, j=0;
        if(str1.length()<str2.length())return false;

        int m = str1.size();
        int n = str2.size();
        while(i<m && j<n){
            if((str1[i]==str2[j]) || (str1[i] - str2[j] == -1) || (str1[i] - str2[j] == 25)){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return j==n;
    }
};