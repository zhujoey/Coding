#include <iostream>
#include <string>

int main()
{
    int n = 0, target = 0, count[3] = {0, 0, 0};
    std::string s = "";

    std::cin >> n >> s;
    target = n / 3;

    for (char c : s)
    {
        ++count[c - '0'];
    }

    for (int i = 0; i < n; ++i)
    {
        int digit = s[i] - '0';

        if (count[digit] > target)
        {
            for (int d = 0; d < digit; ++d)
            {
                if (count[d] < target)
                {
                    --count[digit];
                    ++count[d];
                    s[i] = static_cast<char>('0' + d);
                    break;
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; --i)
    {
        int digit = s[i] - '0';

        if (count[digit] > target)
        {
            for (int d = 2; d > digit; --d)
            {
                if (count[d] < target)
                {
                    --count[digit];
                    ++count[d];
                    s[i] = static_cast<char>('0' + d);
                    break;
                }
            }
        }
    }

    std::cout << s << std::endl;

    return 0;
}