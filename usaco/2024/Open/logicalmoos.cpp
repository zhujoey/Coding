#include <iostream>
#include <string>
#include <vector>

int main()
{
	long long n, q, group[200000], groupcount = 0, g, l, r, leftgroup, rightgroup;
	std::cin >> n >> q;
	std::string s[200000];
	for (int i = 0; i < n; ++i)
	{
	    std::cin >> s[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == "or")
		{
			++groupcount;
		}
		else
		{
			if (i % 2 == 0)
			{
				group[i] = groupcount;
			}
		}
	}
	std::vector<long long> firstfalse(groupcount + 1, 1000000000), lastfalse(groupcount + 1, -1);
	for (int i = 0; i < n; i += 2)
	{
		g = group[i];
		if (s[i] == "false")
		{
			if(firstfalse[g] == 1000000000)
			{
				firstfalse[g] = i;
			}
			lastfalse[g] = i;
		}
	}
	long long totalfirsttrue = 1000000000, totallasttrue = -1;
	for (int i = 0; i <= groupcount; i++)
	{
		if(firstfalse[i] == 1000000000)
		{
			if(totalfirsttrue == 1000000000)
			{
				totalfirsttrue = i;
			}
			totallasttrue = i;
		}
	}
	while (q--)
	{
		std::cin >> l >> r;
		--l;
		--r;
		std::string t;
		std::cin >> t;
		leftgroup = group[l];
		rightgroup = group[r];
		if (totalfirsttrue < leftgroup || totallasttrue > rightgroup)
		{
			if (t == "true")
			{
			    std::cout << 'Y';
			}
			else
			{
			    std::cout << 'N';
			}
			continue;
		}
		if (t == "true")
	    {
			if (firstfalse[leftgroup] < l || lastfalse[rightgroup] > r)
			{
			    std::cout << 'N';
			}
			else
			{
			    std::cout << 'Y';
	        }
		}
		else
		{
			std::cout << 'Y';
		}
	}
	return 0;
}