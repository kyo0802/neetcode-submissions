class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        for (char c : s){
            if (c == '(' || c == '[' || c == '{'){
                res.push(c);
            }
            else{
                if (res.empty()){
                    return false;
                }
                if (c == ')' && res.top() != '('){
                    return false;
                }
                if (c == ']' && res.top() != '['){
                    return false;
                }
                if (c == '}' && res.top() != '{'){
                    return false;
                }
                res.pop();
            }
        }
        return res.empty();
    }
};
