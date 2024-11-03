class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp = s;
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<s.size()-1; j++){
                swap(temp[j],temp[j+1]);
            }
            if(temp==goal){
                cout<<temp;
                return true;
            }
        }
        return false;
    }
};