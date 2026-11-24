class Solution {
public:
    //map數diff?
    int countSubstrings(string s) {
        int n = s.size();
        if (n == 0 ) return 0; 
        int count = 0;
        int left;
        int right;
        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            left = i;
            right = i;
            while (left >= 0 && right < n && s[left] == s[right]){
                count++;
                left--;
                right++;
            }

            // Even length palindrome
            left = i;
            right = i+1;
            while (left >= 0 && right < n && s[left] == s[right]){
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};
