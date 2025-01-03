class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false; // checks for negative or ends in zero

        int result = 0; 
        while(x > result){
            int cur = x % 10; //extract last digit
            x /= 10; // remove last digit
            result = result * 10 + cur;
        }

        return x == result || x == result / 10; // checks for palindrome

    }
};