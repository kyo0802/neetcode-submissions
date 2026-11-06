class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {

        while (/* Stack 非空，而且今天更熱 */!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prev = st.top();
            st.pop();

            res[prev] = i - prev;
        }
        st.push(i);
        // 將今天的 Index 放進 Stack
    }

        return res;
    }  
};
