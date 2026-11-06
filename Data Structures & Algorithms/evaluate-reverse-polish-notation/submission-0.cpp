class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const string & token : tokens){
            if(token == "+" || token == "-" || token == "*"|| token == "/"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);
            } 
            else {
            // 如果是數字，轉成整數後壓入堆疊
            st.push(std::stoi(token));
            }
        }
        return st.top();
    }
};
