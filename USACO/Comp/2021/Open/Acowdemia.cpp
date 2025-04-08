#include <iostream>
#include <algorithm>

int n;
long m;
int k;
int a[100001];

bool check(int x)
{
    long s = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] < x)
        {
            if(x - a[i] > m)
            {
                return false;
            }
            s += x - a[i];
        }

        if (s > m * k)
        {
            return false;
        }

        if (i == x)
        {
            return true;
        }
    }
}

int main()
{
    std::cin >> n >> m >> k;

    for(int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    std::sort(a+1, a+1+n, std::greater<int>());

    int l = 0, r = n, ans = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }

        else
        {
            r = mid - 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;

}