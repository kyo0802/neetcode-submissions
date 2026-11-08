class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();
        if (k > n) return false;

        array<int, 26> need{};
        array<int, 26> window{};

        for (char c : s1) {
            ++need[c - 'a'];
        }

        for (int right = 0; right < n; ++right) {
            ++window[s2[right] - 'a'];

            // 加入新字元後，如果超過 k，就移出最左邊的字元。
            if (right >= k) {
                --window[s2[right - k] - 'a'];
            }

            // 視窗湊滿 k 個字元後，才比較頻率。
            if (right >= k - 1 && window == need) {
                return true;
            }
        }

        return false;
    }
};
