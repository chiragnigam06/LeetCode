class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n; ++m) {

                if (i + 2 * m >= n) {
                    dp[i][m] = suffix[i];
                    continue;
                }

                int best = 0;

                for (int x = 1; x <= 2 * m && i + x <= n; ++x) {
                 
                    int taken = suffix[i] - suffix[i + x];


                    int opponent = dp[i + x][max(m, x)];

                    int current = taken + suffix[i + x] - opponent;

                    best = max(best, current);
                }

                dp[i][m] = best;
            }
        }

        return dp[0][1];
    }
};