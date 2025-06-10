class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxodd = 0;
        int mineven = INT_MAX;

        for (int f : freq) {
            if (f == 0) continue;
            if (f % 2 == 1) {
                maxodd = max(maxodd, f);
            } else {
                mineven = min(mineven, f);
            }
        }

        if (maxodd == 0 || mineven == INT_MAX) return -1;  
        return maxodd - mineven;
    }
};