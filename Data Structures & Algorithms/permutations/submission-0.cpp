class Solution {
public:
    vector<vector<int>> ans;
    /*
    vector<int> path;
    vector<bool> used;
    void dfs(vector<int>& nums){
        //base case
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        
        for (int i = 0;i < nums.size();++i){
            if (used[i]) continue;

            used[i] = true;

            path.push_back(nums[i]);

            dfs(nums);

            path.pop_back();

            used[i] = false;
        }
    }*/
    void dfs(vector<int>& nums, int index) {

        // TODO 1: Base Case
        if (index == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        // TODO 2: for 迴圈
        for (int i = index;i < nums.size();i++){
            
        // TODO 3: Swap
            swap(nums[i], nums[index]);
        // TODO 4: DFS
            dfs(nums, index+1);

        // TODO 5: Undo Swap
            swap(nums[i], nums[index]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        /*
        used.resize(nums.size(), false);
        dfs(nums);
        */
        dfs(nums, 0);
        return ans;
    }
};
