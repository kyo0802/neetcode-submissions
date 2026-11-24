class Solution {
public:
    bool dfs(int i, string& s, vector<string>& wordDict,
             vector<int>& memo) {

        // 1. Base Case
        if (i == s.size()) return true;

        if (memo[i] != -1){
            return memo[i];
        }

        for (const string& word : wordDict) {

            if (s.substr(i, word.size()) == word) {

                if (dfs(i + word.size(), s, wordDict, memo)) {
                    memo[i] = 1;
                    return true;
                }

            }
        }
        memo[i] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        return dfs(0, s, wordDict, memo);
    }
};
