class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int>& nums, int start) {
        // TODO：什麼時候把 path 放進 ans？
        ans.push_back(path);

        for (int i = start; i < nums.size(); ++i) {
            // TODO：同層去重
            if (i > start && nums[i] == nums[i-1]) continue;
            // TODO：Choose
            path.push_back(nums[i]);
            // TODO：Explore
            dfs(nums,i + 1);
            // TODO：Undo
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
};
