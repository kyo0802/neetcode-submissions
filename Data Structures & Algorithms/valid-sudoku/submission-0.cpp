class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};
        //check row
        for (int i = 0 ; i < 9 ; ++i){
            for (int j = 0; j < 9; ++j){
                if (board[i][j] == '.') continue;

                // 將字元 '1'~'9' 轉為 0~8 的索引
                int num = board[i][j] - '1';
                int box_idx = (i / 3) * 3 + (j / 3);

                // 檢查是否重複
                if (rows[i][num] || cols[j][num] || boxes[box_idx][num]) {
                    return false;
                }

                // 標記該數字已出現過
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box_idx][num] = true;
            }

        }
        //check col
        return true;
    }
};
