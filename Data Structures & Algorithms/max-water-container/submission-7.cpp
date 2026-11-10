class Solution {
public:
    int maxArea(vector<int>& heights) {
        /*brute
        int most = 0;
        for (int i = 0; i < heights.size(); ++i){
            for (int j = i + 1; j < heights.size(); ++j){
                most = max(most, min(heights[i], heights[j]) * (j - i));
            }
        }
        return most;
        */
        int left = 0;
        int right = heights.size() - 1;
        int most = 0;
        while (left < right){
            int gap = right - left;
            int area = min(heights[left], heights[right]) * gap;
            most = max(most, area);
            if (heights[left] <= heights[right]) {
                ++left;
            } 
            else {
                --right;
            }
        }
        return most;
    }
};
