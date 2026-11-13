class Solution {
public:
    vector<int> dp;
    int dfs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] = dfs(n - 1) + dfs(n - 2);

        return dp[n];
    }

    int climbStairs(int n) {
        dp.assign(n + 1, -1);
        return dfs(n);
    }
};
