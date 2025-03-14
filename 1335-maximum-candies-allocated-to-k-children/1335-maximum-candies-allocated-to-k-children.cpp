class Solution {
public:
    bool cangive(vector<int> candies, long long k, long long maxcandies) {
        long long count = 0;
        for (int c : candies) {
            count += c / maxcandies;
            if (count >= k)
                return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int ans = 0;
        long long sum = 0;

        for (int i = 0; i < candies.size(); i++) {
            sum += candies[i];
        }

        long long maxcandies = sum / k;
        int i = 1;
        int j = maxcandies;

        while (i <= j) {
            long long mid = i - (i - j) / 2;
            if (cangive(candies, k, mid)) {
                ans = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return ans;
    }
};