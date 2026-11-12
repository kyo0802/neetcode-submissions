class Solution {
public:
    vector<string> res;
    string path;
    void dfs(int open, int close, int n){
        //base case
        if (open == n && close == n){
            res.push_back(path);
            return;
        }

        if (open < n) {
            path.push_back('(');
            dfs(open + 1, close, n);
            path.pop_back();
        }

        if (close < open) {
            path.push_back(')');
            dfs(open, close + 1, n);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(0,0,n);
        return res;
    }
};
