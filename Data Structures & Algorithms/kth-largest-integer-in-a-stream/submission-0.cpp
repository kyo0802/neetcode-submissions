class KthLargest {
private:
    int K;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (auto num : nums) {
            minHeap.push(num);
            if (minHeap.size() > K) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        
        minHeap.push(val);
        if (minHeap.size() > K) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
