class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> res;
        for (int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int >> freq_heap;
        for (auto it = mp.begin(); it != mp.end(); ++it ){
            freq_heap.push({it->second, it->first});
        }
        for (int j = 0; j < k ; j++){
            pair<int, int> ans = freq_heap.top();
            freq_heap.pop();
            res.push_back(ans.second);
        }
    return res;
    }
};
