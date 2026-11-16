class Solution {
private:
    string s, t;
    vector<vector<int>> memo;
    int dfs(int i, int j) {
        // 1. Base Case: Success
        if (j == t.size()) {
            return 1;
        }
        // 2. Base Case: Failure

        if (i == s.size()) {
            return 0;
        }

        if (memo[i][j] != -1){
            return memo[i][j];
        }

        // 3. Match: Take + Skip
        if (s[i] == t[j]) {
            int cur = dfs(i + 1, j + 1);
            int next = dfs(i + 1, j);
            return memo[i][j] = cur + next;
        }

        // Mismatch：字元不同
        return memo[i+1][j] = dfs(i + 1, j);
        // 4. Mismatch: Skip
    }

public:
    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        memo.assign(s.size()+1, vector<int>(t.size()+1, -1));

        return dfs(0, 0);
    }
};
