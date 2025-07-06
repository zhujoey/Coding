#include <iostream>
#include <map>
#include <utility>
 
int main()
{
    long long n = 0, x[2000] = {}, y[2000] = {}, res = 0;
    std::map<std::pair<long long, long long>, long long> midpoints;
 
    std::cin >> n;
 
    for (long long i = 0; i < n; ++i)
    {
        std::cin >> x[i] >> y[i];
    }
 
    for (long long i = 0; i < n; ++i)
    {
        for (long long j = i + 1; j < n; ++j)
        {
            midpoints[std::make_pair(x[i] + x[j], y[i] + y[j])]++;
        }
    }
 
    for (std::map<std::pair<long long, long long>, long long>::iterator it = midpoints.begin(); it != midpoints.end(); ++it)
    {
        res += it->second * (it->second - 1) / 2;
    }
 
    std::cout << res << std::endl;
    return 0;
}