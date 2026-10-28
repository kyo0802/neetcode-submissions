// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> res;
        int n = pairs.size();

        // edge condition
        if (n == 0) {
            return res;
        }
        // iteration
        for (int i = 0;i < n;i++){
            Pair temp = pairs[i];
            int j = i - 1;
            //move backard element.key > tmp.key
            while(j >= 0 && pairs[j].key > temp.key){
                pairs[j + 1] = pairs[j];
                j--;
            }
            pairs[j + 1] = temp;
            res.push_back(pairs);
        }
        return res;
    }
};
