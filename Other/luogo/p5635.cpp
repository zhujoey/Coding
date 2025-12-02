#include <iostream>
#include <set>
#include <utility>

int main()
{
    long long t, p, x, y;
    bool cbwwin, zhouwcwin, turn;
    std::cin >> t >> p;

    while (t--)
    {
        std::cin >> x >> y;
        std::set<std::pair<long long, long long>> seen;
        cbwwin = false, zhouwcwin = false, turn = true;

        while (true)
        {
            if (x == 0)
            {
                cbwwin = true;
                break;
            }
            if (y == 0)
            {
                zhouwcwin = true;
                break;
            }

            std::pair<long long, long long> current = {x, y};
            if (seen.count(current))
            {
                break;
            }
            seen.insert(current);

            if (turn)
            {
                x = (x + y) % p;
            }
            else
            {
                y = (x + y) % p;
            }

            turn = !turn;
        }

        if (cbwwin)
        {
            std::cout << "1\n";
        }
        else if (zhouwcwin)
        {
            std::cout << "2\n";
        }
        else
        {
            std::cout << "error\n";
        }
    }

    return 0;
}