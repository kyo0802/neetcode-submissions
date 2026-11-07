class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0;
        int res = 0;

        for (int right = 0; right < s.size(); right++) {

            // 如果 s[right] 已經在 seen 裡
            if (seen.count(s[right])){
                while (seen.count(s[right])){
                    seen.erase(s[left]);
                    left++;
                }
            }
            // 將 s[right] 加入 seen
            seen.insert(s[right]);
            // 更新 res
            res = max(res, right - left + 1);
        }

        return res;
    }
};
