class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<int>& nums, int index, int sum, int target) {

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

    path.push_back(nums[index]);
    dfs(nums, index, sum + nums[index], target);

    path.pop_back();

    dfs(nums, index + 1, sum, target);
}

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums, 0,0, target);
        return ans;
    }
};
