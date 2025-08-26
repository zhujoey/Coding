#include <iostream>
#include <string>

int main()
{
    int q, ans, add, leastadd;
    bool possible;
    std::string mo;
    
    std::cin >> q;
    while (q--)
    {
        std::cin >> mo;
        ans = mo.size() - 3;
        possible = false;
        leastadd = 2;
        for (int i = 1; i < mo.size() - 1; ++i)
        {
            if (mo[i] == 'O')
            {
                add = 0;
                possible = true;
                if (mo[i - 1] != 'M')
                {
                    ++add;
                }
                if (mo[i + 1] != 'O')
                {
                    ++add;
                }
                if (add < leastadd)
                {
                    leastadd = add;
                }
            }
        }
        if (possible)
        {
            std::cout << leastadd + ans << "\n";
        }
        else
        {
            std::cout << "-1\n";
        }
    }

    return 0;
}