class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long hours = 0;

            for (int pile : piles) {
                // TODO:
                // 計算這堆香蕉以 mid 速度吃完
                // 需要幾個小時，累加到 hours
                hours += (pile + mid - 1) / mid;
            }

            if (hours <= h) {
                // TODO: 可以完成，嘗試更慢
                right = mid - 1;
            } else {
                // TODO: 無法完成，必須更快
                left = mid + 1;
            }
        }

        return left;
    }
};
