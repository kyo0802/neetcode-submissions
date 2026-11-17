
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int total = 0;
        int tank = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];

            // 更新 total 和 tank
            total += diff;
            tank += diff;

            if (tank < 0){
                start = i + 1;
                tank = 0;
            }
        }

        // 判斷整圈是否有解
        return total >= 0 ? start : -1;
    }
};
