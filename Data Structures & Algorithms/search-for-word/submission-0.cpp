class Solution {
public:
    int m;
    int n;
    vector<vector<char>> board;
    string word;
    vector<vector<bool>> visited;
    


    bool dfs(int r, int c,int index){   
        //base case
        if (index == word.size()){
            return true;
        }

        if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != word[index] || visited[r][c]){
            return false;
        }

        //choose
        visited[r][c] = true;
        //explore
        bool found = dfs(r - 1, c, index + 1) ||
            dfs(r + 1, c, index + 1) ||
            dfs(r, c - 1, index + 1) ||
            dfs(r, c + 1, index + 1);
        //undo
        visited[r][c] = false;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;    

        m = board.size();
        n = board[0].size();
        visited.assign(m, vector<bool>(n, false));

        for (int r = 0; r < m;++r){
            for (int c = 0; c < n;++c){
                if (board[r][c] == word[0]){
                    if(dfs(r,c, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
