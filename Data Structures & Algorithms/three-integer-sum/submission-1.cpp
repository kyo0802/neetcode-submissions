class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size() - 2;++i){
            int left = i+1;
            int right = nums.size()-1;
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    res.push_back({nums[i],nums[left],nums[right]});
                    // 跳過左邊重複的數字
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // 跳過右邊重複的數字
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    // 繼續往中間收縮
                    left++;
                    right--;
                }
               else if (sum < 0) {
                    left++; // 和太小，左指標右移
                } 
                else {
                    right--; // 和太大，右指標左移
                }
            }
        }
        return res;
    }
};
