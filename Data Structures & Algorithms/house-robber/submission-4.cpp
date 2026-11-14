class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int dp1 = nums[0];
        int dp2 = max(nums[0], nums[1]);

        for (int i = 2; i < n;++i){
            int cur = max(dp2, dp1 + nums[i]);

            dp1 = dp2;
            dp2 = cur;
        }
        return dp2;
    }
};
