class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            // 1. Skip invalid characters
            while(left < right &&!isalnum(s[left])){
                left++;
            }
            while(left < right &&!isalnum(s[right])){
                right--;
            }
            // 2. Compare valid characters
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            // 3. Move pointers
            left++;
            right--;
        }
        return true;
        // Return result
    }
};
