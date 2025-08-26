#include <iostream>

int main()
{
	long long t, patchg, patchh, n, k, count;
	std::string type, ans;
	std::cin >> t;

	while (t--)
	{
		std::cin >> n >> k;
		std::cin >> type;

		patchg = -k - 1;
		patchh = -k - 1;
		count = 0;
		std::string ans(n, '.');

		for (int i = 0; i < n; i++)
		{
			if (type[i] == 'G' && i - patchg > k)
			{
				++count;
				if (i + k >= n)
				{
					patchg = i;
					if (ans[patchg] == 'H')
					{
					    patchg--;
					}
				}
				else
				{
					patchg = i + k;
				}
				ans[patchg] = 'G';
			}
			if (type[i] == 'H' && i - patchh > k)
			{
				++count;
				if (i + k >= n)
				{
					patchh = i;
					if (ans[patchh] == 'G')
					{
					    patchh--;
					}
				}
				else
				{
					patchh = i + k;
				}
				ans[patchh] = 'H';
			}
		}
		std::cout << count << "\n" << ans << "\n";
	}
}