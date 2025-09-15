class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

    while (left < right) {
        // Skip non-alphanumeric characters from left side
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        // Skip non-alphanumeric characters from right side
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Check if characters match (case-insensitive)
        if (tolower(s[left]) != tolower(s[right])) {
            return false;  // Not a palindrome
        }

        left++;
        right--;
    }

    return true;  // Palindrome

    }
};