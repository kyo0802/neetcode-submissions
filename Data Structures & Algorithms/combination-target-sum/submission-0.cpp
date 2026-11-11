class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<int>& nums, int index, int sum, int target) {

    // 1. Base Cases
    if (sum == target){
        ans.push_back(path);
        return;
    }

    if (sum > target){
        return;
    }
    if (index >= nums.size()){
        return;
    }

    // 2. 選目前的數字
    path.push_back(nums[index]);
    dfs(nums, index, sum + nums[index], target);

    // 3. 撤銷
    path.pop_back();

    // 4. 不選目前的數字
    dfs(nums, index + 1, sum, target);
}

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums, 0,0, target);
        return ans;
    }
};
