class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& triangle) {
        if (i == n - 1)
            return triangle[i][j];

        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        return dp[i][j] = triangle[i][j] +
               min(solve(i + 1, j, triangle),
                   solve(i + 1, j + 1, triangle));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        dp.assign(n, vector<int>(n, INT_MAX));

        return solve(0, 0, triangle);
    }
};