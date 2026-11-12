class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int n : nums){
            mp[n]++;
        }
    
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& pair : mp) {
            int num = pair.first;
            int freq = pair.second;
            buckets[freq].push_back(num);
        }

        for (int i = nums.size(); i >= 0 && res.size() < k; i--) {
            if (!buckets[i].empty()) {
                for (int num : buckets[i]) {
                    res.push_back(num);
                    if (res.size() == k) {
                        break; 
                    }
                }
            }
        }
        
        return res;
    }
};
