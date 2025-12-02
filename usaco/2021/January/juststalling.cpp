#include <iostream>
#include <algorithm>

int n, a[20], b[20];
long long answer = 1;

int countbigger(int height)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] >= height)
        {
            total++;
        }
    }
    return total;
}

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }

    std::sort(a, a + n);

    for (int i = n - 1; i >= 0; i--)
    {
        answer *= countbigger(a[i]) - n + 1 + i;
    }

    std::cout << answer << std::endl;
    return 0;
}