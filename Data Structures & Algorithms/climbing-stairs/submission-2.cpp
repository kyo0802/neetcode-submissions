class Solution {
public:
    /*topdown
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
    */
    //bottom up
    int climbStairs(int n) {
        if (n <= 2) return n;
        int dp1 = 1;
        int dp2 = 2;

        for (int i = 3; i <= n;++i){
            int cur = dp1 + dp2;
            dp1 = dp2;
            dp2 = cur;
        }
        return dp2;
    }
};
