class Solution {
public:
    int search(vector<int>& nums, int target) {
        int up = nums.size()-1;
        int low = 0;
        while (low <= up) {
            int mid = low + (up - low) / 2;

            if (nums[mid] == target) {
                return mid;
            } 
            else if (nums[mid] < target) {
                low = mid + 1;
            } 
            else {
                up = mid - 1;
            }
        }

        return -1;
    }
};
