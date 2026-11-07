class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //brutal go throught O(n^2)
        int res = 0;
        for (int i = 0; i< prices.size();++i){
            int j = i + 1;
            while (j < prices.size()){
                if (prices[j] > prices[i]){
                    res = max(prices[j] - prices[i], res);
                }
                j++;
            }
        }
        return res;
    }
};
