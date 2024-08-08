#include <string>
#include <vector>

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        std::vector<char> raw = {};
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'a' || s[i] == 'A')
            {
                raw.push_back('a');
            }
            else if (s[i] == 'b' || s[i] == 'B')
            {
                raw.push_back('b');
            }
            else if (s[i] == 'c' || s[i] == 'C')
            {
                raw.push_back('c');
            }
            else if (s[i] == 'd' || s[i] == 'D')
            {
                raw.push_back('d');
            }
            else if (s[i] == 'e' || s[i] == 'E')
            {
                raw.push_back('e');
            }
            else if (s[i] == 'f' || s[i] == 'F')
            {
                raw.push_back('f');
            }
            else if (s[i] == 'g' || s[i] == 'G')
            {
                raw.push_back('g');
            }
            else if (s[i] == 'h' || s[i] == 'H')
            {
                raw.push_back('h');
            }
            else if (s[i] == 'i' || s[i] == 'I')
            {
                raw.push_back('i');
            }
            else if (s[i] == 'j' || s[i] == 'J')
            {
                raw.push_back('j');
            }
            else if (s[i] == 'k' || s[i] == 'K')
            {
                raw.push_back('k');
            }
            else if (s[i] == 'l' || s[i] == 'L')
            {
                raw.push_back('l');
            }
            else if (s[i] == 'm' || s[i] == 'M')
            {
                raw.push_back('m');
            }
            else if (s[i] == 'n' || s[i] == 'N')
            {
                raw.push_back('n');
            }
            else if (s[i] == 'o' || s[i] == 'O')
            {
                raw.push_back('o');
            }
            else if (s[i] == 'p' || s[i] == 'P')
            {
                raw.push_back('p');
            }
            else if (s[i] == 'q' || s[i] == 'Q')
            {
                raw.push_back('q');
            }
            else if (s[i] == 'r' || s[i] == 'R')
            {
                raw.push_back('r');
            }
            else if (s[i] == 's' || s[i] == 'S')
            {
                raw.push_back('s');
            }
            else if (s[i] == 't' || s[i] == 'T')
            {
                raw.push_back('t');
            }
            else if (s[i] == 'u' || s[i] == 'U')
            {
                raw.push_back('u');
            }
            else if (s[i] == 'v' || s[i] == 'V')
            {
                raw.push_back('v');
            }
            else if (s[i] == 'w' || s[i] == 'W')
            {
                raw.push_back('w');
            }
            else if (s[i] == 'x' || s[i] == 'X')
            {
                raw.push_back('x');
            }
            else if (s[i] == 'y' || s[i] == 'Y')
            {
                raw.push_back('y');
            }
            else if (s[i] == 'z' || s[i] == 'Z')
            {
                raw.push_back('z');
            }
            else if (s[i] == '0')
            {
                raw.push_back('0');
            }
            else if (s[i] == '1')
            {
                raw.push_back('1');
            }
            else if (s[i] == '2')
            {
                raw.push_back('2');
            }
            else if (s[i] == '3')
            {
                raw.push_back('3');
            }
            else if (s[i] == '4')
            {
                raw.push_back('4');
            }
            else if (s[i] == '5')
            {
                raw.push_back('5');
            }
            else if (s[i] == '6')
            {
                raw.push_back('6');
            }
            else if (s[i] == '7')
            {
                raw.push_back('7');
            }
            else if (s[i] == '8')
            {
                raw.push_back('8');
            }
            else if (s[i] == '9')
            {
                raw.push_back('9');
            }
        }
        if (raw == std::vector<char> (raw.rbegin(), raw.rend()))
        {
            return true;
        }
        return false;
    }
};