#include <iostream>
 
int main()
{
    long long z, n, h[200000], a[200000], t[200000], p[200000], days, smallidx, bigidx, adif, hdif, bigdays, smalldays;
    std::cin >> z;
    while (z--)
    {
        std::cin >> n;
        days = 0;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> h[i];
        }
        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            std::cin >> t[i];
        }
        for(int i = 0; i < n; i++)
        {
            p[t[i]] = i;
        }
        for(int i = n - 2; i >= 0; i--)
        {
            smallidx = p[i + 1];
            bigidx = p[i];
            hdif = (h[smallidx] + a[smallidx] * days) - (h[bigidx] + a[bigidx] * days);
            if (hdif >= 0)
            {
                adif = a[bigidx] - a[smallidx];
                if (adif <= 0)
                {
                    days = -1;
                    break;
                }
                days += hdif / adif + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            bigdays = h[p[i]] + a[p[i]] * days;
            smalldays = h[p[i+1]] + a[p[i+1]] * days;
            if (smalldays >= bigdays)
            {
                days = -1;
                break;
            }
        }
        std::cout << days << "\n";
    }
}