#include <iostream>
#include <algorithm>

long long n, cows[150001], original[150001], q, change, target, targetIndex;
long long sum, tempSum;
long long prefix[151000];

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> cows[i];
        original[i] = cows[i];
    }

    std::sort(cows, cows + n);
    prefix[0]=cows[0];

    for (int i = 1; i < n; ++i)
    {
    	prefix[i] = prefix[i - 1] + cows[i];
	}

    for (int i = 0; i < n; ++i)
    {
        sum += (i + 1) * cows[i];
    }

    std::cin >> q;

    for (int i = 0; i < q; ++i)
    {
        std::cin >> change >> target;
        change = std::lower_bound(cows, cows + n, original[change - 1]) - cows;
        tempSum = sum;
        targetIndex = std::lower_bound(cows, cows + n, target) - cows;

        if (targetIndex > change)
        {
        	tempSum -= (prefix[targetIndex - 1] - prefix[change]);
        }
        else
        {
        	tempSum += (prefix[change - 1] - prefix[targetIndex - 1]);
            ++targetIndex;
        }

        std::cout << tempSum - (change + 1) * cows[change] + targetIndex * target << "\n";
    }

    return 0;
}