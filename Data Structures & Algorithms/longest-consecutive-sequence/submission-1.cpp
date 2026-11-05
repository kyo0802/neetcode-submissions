class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (int num : s) {
        // Q1: 如何判斷 num 是序列起點？
            if (s.find(num - 1) == s.end()) {

            int current = num;
            int length = 1;

            // Q2: 如何檢查下一個整數存在？
            while (s.find(num + 1) != s.end()) {

                // Q3: 更新 current 和 length
                length++;
                num++;
            }

            ans = max(ans, length);
            }
        }
        return ans;
    }
};
