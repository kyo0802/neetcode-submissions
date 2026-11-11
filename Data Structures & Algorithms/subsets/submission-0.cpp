class Solution {
public:
        vector<vector<int>> ans;
        vector<int> path;

        void dfs(int index, vector<int> &nums){
            if (index == nums.size()){
                ans.push_back(path);
                return;
            }

            path.push_back(nums[index]);

            dfs(index+1, nums);

            path.pop_back();

            dfs(index+1, nums);

        }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};
