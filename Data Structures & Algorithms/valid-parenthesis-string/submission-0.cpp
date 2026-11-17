class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> star;
        
        for(int i = 0; i < s.size();++i){
            if (s[i] == '('){
                left.push(i);
            }
            if (s[i] == '*'){
                star.push(i);
            }
            if (s[i] == ')'){
                if (!left.empty()) {
                    left.pop();
                }
                else if (!star.empty()) {
                    star.pop();
                }
                else {
                    return false;
                }
            }
        }
        while (!left.empty() && !star.empty()){
            if (left.top() < star.top()){
                left.pop();
                star.pop();
            }
            else {
                return false;
            }
        }
        return left.empty();
    }
};
