#include <iostream>
#include <algorithm>

int sleeps[100001], sum, max, tempsum, ans, combines, cases, classes;

void count(int sleeps[100001], int n)
{
    sum = 0;
    max = 1;
    ans = 99999;
    for (int i = 0; i < n; ++i)
    {
        sum += sleeps[i];
        max = std::max(max, sleeps[i]);
    }
    
    if (sum == 0)
    {
        std::cout << 0 << "\n";
        return;
    }

    for (int i = max; i <= sum; ++i)
    {
        if (sum % i != 0)
        {
            continue;
        }

        tempsum = 0;
        combines = -1;

        for (int j = 0; j < n; ++j)
        {
            tempsum += sleeps[j];
            ++combines;

            if (tempsum == i)
            {
                tempsum = 0;
                --combines;
            }
            else if (tempsum > i)
            {
                break;
            }
        }

        if (tempsum == 0)
        {
            ++combines;
            ans = std::min(combines, ans);
        }
    }

    std::cout << ans << "\n";
}

int main()
{
    std::cin >> cases;
    for (int i = 0; i < cases; ++i)
    {
        std::cin >> classes;
        for (int j = 0; j < classes; ++j)
        {
            std::cin >> sleeps[j];
        }
        count(sleeps, classes);
    }
    return 0;
}