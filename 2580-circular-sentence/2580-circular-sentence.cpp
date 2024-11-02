class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        string token;
        stringstream ss(sentence);
        vector<string> words;

        while(ss>>token){
            words.push_back(token);
        }
        

        for(int i=0; i<words.size()-1; i++){
            string first = words[i];
            string second = words[i+1];
            if(first[first.size()-1]!=second[0]){
                return false;
            }
        }
        string s1 = words[0];
        string s2 = words[words.size()-1];
        if(s1[0]!= s2[s2.size()-1]){
            return false;
        }
        return true;
    }
};