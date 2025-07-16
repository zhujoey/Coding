class Solution
{
public:
    long long maximumBeauty(vector<int>& flower, long long newf, int target, int full, int part)
    {
        int n = flower.size(), comp = 0, low = 0, high = 0, mid = 0, loc = 0;
        long long maxb = 0, cost = 0, rem = 0, bestp = 0, req = 0, total = 0;
        vector<int> g = flower;
        vector<long long> prefix(n + 1, 0), suff(n + 1, 0);

        sort(g.begin(), g.end());

        for (int i = 0; i < n; ++i)
        {
            g[i] = min(g[i], target);
        }

        if (g[0] >= target)
        {
            return 1LL * n * full;
        }

        for (int i = 0; i < n; ++i)
        {
            prefix[i + 1] = prefix[i] + g[i];
        }

        for (int i = n - 1; i >= 0; --i)
        {
            suff[i] = suff[i + 1] + (target - g[i]);
        }

        for (comp = 0; comp <= n; ++comp)
        {
            cost = suff[n - comp];

            if (cost > newf)
            {
                continue;
            }

            rem = newf - cost;
            bestp = 0;

            if (comp < n)
            {
                low = 0;
                high = target - 1;

                while (low <= high)
                {
                    mid = (low + high) / 2;
                    loc = upper_bound(g.begin(), g.begin() + (n - comp), mid) - g.begin();
                    req = 1LL * mid * loc - prefix[loc];

                    if (req <= rem)
                    {
                        bestp = mid;
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
            }

            total = 1LL * comp * full + bestp * part;
            maxb = max(maxb, total);
        }

        return maxb;
    }
};