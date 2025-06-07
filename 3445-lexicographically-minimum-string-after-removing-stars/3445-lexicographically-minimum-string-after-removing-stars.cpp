class Solution {
public:
 typedef pair<char, int> P;

    struct comp{
        bool operator()(P &p1, P& p2){
            if(p1.first == p2.first) {
                return p1.second < p2.second;
            }

            return p1.first > p2.first;
        }
    };

    string clearStars(string s) {
        priority_queue<P, vector<P>, comp> pq;
        int n = s.size();
        int i=0;
        while(i<n){
            if(s[i]=='*' && !pq.empty()){
                pq.pop();
            }
            else{
                pq.push({s[i],i});
            }
            i++;
        }

        string ans = "";
        vector<pair<int,char>> v;
        while(!pq.empty()){
            auto c = pq.top();
            pq.pop();
            v.push_back({c.second,c.first});
        }

        sort(v.begin(),v.end());
        for(int j=0; j<v.size(); j++){
            ans+=v[j].second;
        }
        return ans;
    }
};