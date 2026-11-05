class Solution {
public:
    bool isValid(string s) {
        stack<char> cs;
        for (char c : s){
            // 1. Opening bracket: push
            if (c == '[' || c == '(' || c == '{' ) 
                cs.push(c);
            else{
                if (cs.empty()) {
                    return false;
                }
                if (c == ']' && cs.top() != '[') {
                    return false;
                }
                if (c == ')' && cs.top() != '(') {
                    return false;
                }
                if (c == '}' && cs.top() != '{') {
                    return false;
                }

                cs.pop();
            }
        }
        return cs.empty();
    }
};
