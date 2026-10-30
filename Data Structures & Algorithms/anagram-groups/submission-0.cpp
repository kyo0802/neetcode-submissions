class Solution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (int i = 0; i < strs.size(); i++){
            vector<int> v(26,0);
            for(int j = 0; j < strs[i].size(); j++){
                v[(strs[i][j] - 'a')]++;
            }
            string key = hash(v);
            groups[key].push_back(strs[i]);
        }

        vector<vector<string>> ans = {};
        for (auto it = groups.begin(); it != groups.end(); it++){
            ans.push_back(it -> second);
        }

        return ans;
    }
    string hash(const vector<int>& v){
        string key="";
        for (int i = 0; i < v.size(); i++){
            key += to_string(v[i]);
            key += '#';
        }
        return key;
    }
};