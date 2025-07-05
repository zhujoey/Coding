#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::unordered_map<int, int> front;
    std::unordered_map<int, int> back;
    std::unordered_map<int, int> total;
    std::vector<std::pair<int, int>> cards(n);

    for (int i = 0; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        cards[i] = { a, b };
        ++front[a];
        if (a != b)
        {
            ++back[b];
        }
        ++total[a];
        ++total[b];
    }

    int req = (n + 1) / 2;
    int res = -1;

    for (std::unordered_map<int, int>::iterator entry = total.begin(); entry != total.end(); ++entry)
    {
        int color = entry->first;
        int f = front[color];
        int b = back[color];

        if (f + b >= req)
        {
            int moves = std::max(0, req - f);
            if (res == -1 || moves < res)
            {
                res = moves;
            }
        }
    }

    std::cout << res << std::endl;
    return 0;
}