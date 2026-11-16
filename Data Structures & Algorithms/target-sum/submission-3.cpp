class Solution {
public:
    vector<vector<int>> memo;
    int n, offset;

    int dfs(int index, int cur, vector<int>& nums, int target){
        //base case
        if (index == nums.size()){
            if(cur == target){
                return 1;
            }
            else{
                return 0;
            }
        }

        int col = cur + offset;
        //caching
        if (memo[index][col] != -1) {
            return memo[index][col];
        }

        //recursive
        int plus = dfs(index + 1,
                       cur + nums[index],
                       nums, target);

        int minus = dfs(index + 1,
                        cur - nums[index],
                        nums, target);

        
        //store
        return memo[index][col] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        offset = accumulate(nums.begin(), nums.end(), 0);
        
        if (abs(target) > offset) {
            return 0;
        }
        memo.assign(n, vector<int>(2 * offset + 1, -1));

        return dfs(0,0,nums,target);
    }   
};
