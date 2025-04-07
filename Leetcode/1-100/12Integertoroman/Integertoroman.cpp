class Solution
{
public:
    string intToRoman(int num)
    {
        int digit = 1;
        int value = 0;
        std::string ans = "";

        while (num > 0)
        {
            value = num % 10;
            num /= 10;

            if (digit == 1)
            {
                if (value <= 3)
                {
                    ans.append(value, 'I');
                }
                else if (value == 4)
                {
                    ans.append("VI");
                }
                else if (value >= 5 && value <= 8)
                {
                    ans.append(value - 5, 'I');
                    ans.append("V");
                }
                else
                {
                    ans.append("XI");
                }
            }
            else if (digit == 2)
            {
                if (value <= 3)
                {
                    ans.append(value, 'X');
                }
                else if (value == 4)
                {
                    ans.append("LX");
                }
                else if (value >= 5 && value <= 8)
                {
                    ans.append(value - 5, 'X');
                    ans.append("L");
                }
                else
                {
                    ans.append("CX");
                }
            }
            else if (digit == 3)
            {
                if (value <= 3)
                {
                    ans.append(value, 'C');
                }
                else if (value == 4)
                {
                    ans.append("DC");
                }
                else if (value >= 5 && value <= 8)
                {
                    ans.append(value - 5, 'C');
                    ans.append("D");
                }
                else
                {
                    ans.append("MC");
                }
            }
            else
            {
                ans.append(value, 'M');
            }

            ++digit;
        }

        return std::string(ans.rbegin(), ans.rend());
    }
};