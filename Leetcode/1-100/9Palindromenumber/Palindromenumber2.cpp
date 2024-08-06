#include <iostream>
#include <string>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x)
    {
        std::string num = std::to_string(x);
        return num == std::string (num.rbegin(), num.rend());
    }
};