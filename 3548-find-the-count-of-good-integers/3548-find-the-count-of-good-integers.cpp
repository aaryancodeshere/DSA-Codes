class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> st;
        int d = (n+1)/2;
        int start = pow(10,d-1);
        int end = pow(10,d)-1;

        for(int i = start; i<=end; i++){
            string half = to_string(i);
            string s = "";

            if(n%2 == 0){
                string lasthalf = half;
                reverse(lasthalf.begin(),lasthalf.end());
                s = half + lasthalf;
            }
            else{
                string lasthalf  =  half.substr(0,d-1);
                reverse(lasthalf.begin(),lasthalf.end());
                s = half + lasthalf;
            }

            long long num = stoll(s);
            if(num%k)continue;

            sort(s.begin(),s.end());
            st.insert(s);
        }

        vector<long long> factorial(11,1);
        for(int i=1; i<11; i++){
            factorial[i]= i*factorial[i-1];
        }
        long long ans = 0;
        for(const string &s: st){
            vector<int> count(10,0);
            for(const char &ch: s){
                count[ch-'0']++;
            }

            int n = s.size();

            int zeros = count[0];
            int nonzero = n - zeros;

            long long totalcount = nonzero * factorial[n-1];

            for(int i=0; i<10; i++){
                totalcount /= factorial[count[i]];
            }

            ans +=totalcount;

        }
        return ans;
    }
};