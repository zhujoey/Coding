#include <iostream>
#include <algorithm>

int n, cows[150001], original[150001], q;
long long sum, tempSum;

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> cows[i];
        original[i] = cows[i];
    }
    
    std::sort(cows, cows + n);

    for (int i = 0; i < n; ++i)
    {
        sum += (i + 1) * cows[i];
    }

    std::cin >> q;

    for (int k = 0; k < q; ++k)
    {
        
    }

    return 0;
}