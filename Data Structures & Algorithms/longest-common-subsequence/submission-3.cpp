class Solution {
    string s1, s2;
    int m, n;
    vector<vector<int>> memo;

public:
    int dfs(int i, int j) {
        // 終止條件：任一字串走到底（注意 i 對應 m，j 對應 n）
        if (i == m || j == n)
            return 0;

        // 若已經計算過，直接回傳快取結果
        if (memo[i][j] != -1)
            return memo[i][j];

        // 字元相同：長度 +1，兩個指標一起往後移
        if (s1[i] == s2[j])
            return memo[i][j] = 1 + dfs(i + 1, j + 1);

        // 字元不同：分別嘗試跳過 s1[i] 或 s2[j]，取較大值並記錄
        return memo[i][j] = max(
            dfs(i + 1, j),
            dfs(i, j + 1)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1;
        s2 = text2;
        m = text1.size();
        n = text2.size();
        
        // 初始化 memo 陣列為 -1，代表尚未計算
        memo.assign(m, vector<int>(n, -1));
        
        // 從兩個字串的開頭 (0, 0) 開始遞迴
        return dfs(0, 0);
    }
};