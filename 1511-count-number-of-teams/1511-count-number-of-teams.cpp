class Solution {
public:
    int ans = 0;
    int dp1[1001][1001][4]; // for increasing sequence
    int dp2[1001][1001][4]; // for decreasing sequence

    int solve(vector<int>& rating, int curr, int prev, int count) {
        if (count == 3) return 1;
        if (curr == rating.size()) return 0;

        if (dp1[curr][prev + 1][count] != -1) return dp1[curr][prev + 1][count];

        int take = 0;
        if (prev == -1 || rating[curr] > rating[prev]) {
            take = solve(rating, curr + 1, curr, count + 1);
        }
        int skip = solve(rating, curr + 1, prev, count);

        return dp1[curr][prev + 1][count] = take + skip;
    }

    int solve2(vector<int>& rating, int curr, int prev, int count) {
        if (count == 3) return 1;
        if (curr == rating.size()) return 0;

        if (dp2[curr][prev + 1][count] != -1) return dp2[curr][prev + 1][count];

        int take = 0;
        if (prev == -1 || rating[curr] < rating[prev]) {
            take = solve2(rating, curr + 1, curr, count + 1);
        }
        int skip = solve2(rating, curr + 1, prev, count);

        return dp2[curr][prev + 1][count] = take + skip;
    }

    int numTeams(vector<int>& rating) {
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        return solve(rating, 0, -1, 0) + solve2(rating, 0, -1, 0);
    }
};