#include <iostream>

int main()
{
    int t, n, a[1000], apos = -1, bpos = 0, acnt = 0, bcnt = 0, moves = 0, preacnt = 0, prevbcnt = 0, curracnt = 0, currbcnt = 0;

    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }

        apos = -1, bpos = n;
        acnt = bcnt = moves = preacnt = prevbcnt = curracnt = currbcnt = 0;

        while (apos < bpos - 1)
        {
            curracnt = 0;
            while (curracnt <= prevbcnt && apos < bpos - 1)
            {
                ++apos;
                curracnt += a[apos];
            }
            acnt += curracnt;
            preacnt = curracnt;
            ++moves;

            if (apos == bpos - 1)
            {
                break;
            }

            currbcnt = 0;
            while (currbcnt <= preacnt && apos < bpos - 1)
            {
                --bpos;
                currbcnt += a[bpos];
            }
            bcnt += currbcnt;
            prevbcnt = currbcnt;
            ++moves;
        }
        std::cout << moves << " " << acnt << " " << bcnt << "\n";
    }
}