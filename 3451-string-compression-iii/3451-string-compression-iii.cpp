class Solution {
public:
    string compressedString(string word) {
        string ans ="";
        int i=0;
        while(i<word.size()){
            int count=0;
            char c = word[i];
            while(word[i]==c && count<9){
                count++;
                i++;
            }
            ans+=to_string(count);
            ans+=c;
        }
        return ans;
    }
};