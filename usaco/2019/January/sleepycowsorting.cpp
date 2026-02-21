#include <iostream>

int main()
{
    int n, a[100000];
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
	std::cin >> n;
	int ans = n - 1;
	for (int i = 0; i < n; ++i)
    {
		std::cin >> a[i];
    }
	for (int i = n - 2; i >= 0; --i)
	{
		if (a[i] < a[i+1])
		{
			ans = i;
		}
		else
		{
			break;
		}
	}
	std::cout << ans << '\n';
	return 0;
}