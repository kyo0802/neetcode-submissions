class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();   
        int n = matrix[0].size();   
        int up = m*n -1 ;
        int low = 0;
        while (low <= up) {
            int mid = low + (up - low) / 2;
            int value = matrix[mid / n][mid % n];
            if (value == target) {
                return true;
            } 
            else if (value < target) {
                low = mid + 1;
            } 
            else {
                up = mid - 1;
            }
        }
        return false;
    }
};
