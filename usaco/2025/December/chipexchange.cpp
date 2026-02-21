#include <iostream>
#include <algorithm>

int main()
{
    long long t, a, b, ca, cb, fa, low, high, ans, x, lo, hi, worst, y, v, mstart, mend, left, right, m, m1, m2, c, mval, v1, v2;
    std::cin >> t;

    while (t--)
    {
        std::cin >> a >> b >> ca >> cb >> fa;

        low = 0;
        high = 1000000000000000000LL;
        ans = high;

        while (low <= high)
        {
            x = (low + high) / 2;

            lo = b;
            hi = b + x;
            c = a + b + x;

            worst = 4000000000000000000LL;

            y = lo;
            mval = y / cb;
            v = c - y + mval * ca;
            if (v < worst) worst = v;

            y = hi;
            mval = y / cb;
            v = c - y + mval * ca;
            if (v < worst) worst = v;

            mstart = (lo + cb - 1) / cb;
            mend = hi / cb;

            if (mstart <= mend)
            {
                left = mstart;
                right = mend;

                while (right - left > 5)
                {
                    m1 = left + (right - left) / 3;
                    m2 = right - (right - left) / 3;

                    y = m1 * cb - 1;
                    mval = y / cb;
                    v1 = c - y + mval * ca;

                    y = m2 * cb - 1;
                    mval = y / cb;
                    v2 = c - y + mval * ca;

                    if (v1 < v2)
                    {
                        right = m2 - 1;
                    }
                    else
                    {
                        left = m1 + 1;
                    }
                }

                for (m = left; m <= right; m++)
                {
                    y = m * cb - 1;
                    if (y >= lo && y <= hi)
                    {
                        mval = y / cb;
                        v = c - y + mval * ca;
                        if (v < worst) worst = v;
                    }
                }
            }

            if (worst >= fa)
            {
                ans = x;
                high = x - 1;
            }
            else
            {
                low = x + 1;
            }
        }

        std::cout << ans << "\n";
    }

    return 0;
}