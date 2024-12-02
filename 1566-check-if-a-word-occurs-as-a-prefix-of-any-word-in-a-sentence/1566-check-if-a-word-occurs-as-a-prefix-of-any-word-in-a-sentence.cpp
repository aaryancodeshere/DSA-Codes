class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        stringstream ss(sentence);
        string token;

        while(ss >> token){
            words.push_back(token);
        }

        for(int i=0; i<words.size(); i++){
            string curr = words[i];
            if(curr.size()<searchWord.size())continue;

            int size = searchWord.size();
            if(curr.substr(0,size)==searchWord)return i+1;
        }
        return -1;
    }
};