#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int t, n, m;
    long long ans, sum, x;
    std::vector<long long> a;
    std::priority_queue<long long> maxheap;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minheap;

    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> m;
        a.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
        }

        ans = 0;

        sum = 0;
        while (!maxheap.empty())
        {
            maxheap.pop();
        }
        for (int i = m; i >= 2; i--)
        {
            sum += a[i];
            if (a[i] > 0)
            {
                maxheap.push(a[i]);
            }
            while (sum > 0 && !maxheap.empty())
            {
                x = maxheap.top();
                maxheap.pop();
                sum -= 2 * x;
                ans++;
            }
        }

        sum = 0;
        while (!minheap.empty())
        {
            minheap.pop();
        }
        for (int i = m + 1; i <= n; i++)
        {
            sum += a[i];
            if (a[i] < 0)
            {
                minheap.push(a[i]);
            }
            while (sum < 0 && !minheap.empty())
            {
                x = minheap.top();
                minheap.pop();
                sum -= 2 * x;
                ans++;
            }
        }

        std::cout << ans << "\n";
    }

    return 0;
}