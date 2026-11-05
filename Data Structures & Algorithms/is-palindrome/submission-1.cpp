class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;
        while (left < right) {
            // 1. Skip invalid characters
            while(left < right &&!isalnum(static_cast<unsigned char>(s[left]))){
                left++;
            }
            while(left < right &&!isalnum(static_cast<unsigned char>(s[right]))){
                right--;
            }
            // 2. Compare valid characters
            if(tolower(static_cast<unsigned char>(s[left])) != tolower(static_cast<unsigned char>(s[right]))){
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
