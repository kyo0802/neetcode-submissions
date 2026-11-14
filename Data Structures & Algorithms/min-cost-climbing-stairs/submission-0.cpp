class Solution {
public :
    vector<int> dp;
    int dfs(vector<int>& cost, int i){
        if (i <= 1) return 0;
        if (dp[i] != -1) {
            return dp[i];
        }

        int dp1 = dfs(cost, i - 1);
        int dp2 = dfs(cost, i - 2);
        
        dp[i] = min(dp1 + cost[i - 1], dp2 + cost[i - 2]);

        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n + 1 , -1);
        return dfs(cost, n);
    }
};
