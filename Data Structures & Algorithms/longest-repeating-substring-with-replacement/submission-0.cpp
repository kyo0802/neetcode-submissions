class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {};
        int left = 0;
        int best = 0;
        int n = s.size();

        for (int right = 0; right < n; ++right) {
            ++freq[s[right] - 'A'];

            while (right - left + 1 - *max_element(freq, freq + 26) > k) {
               --freq[s[left]-'A'];
               ++left;
            }

            best = max(best, right - left + 1);
        }

    return best;
        
    }
};
