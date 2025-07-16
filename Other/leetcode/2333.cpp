class Solution
{
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2)
    {
        int n = nums1.size(), k = k1 + k2;
        long long ops, res = 0, dif, maxdif = 0;
        vector<long long> cnt(100001, 0);

        for (int i = 0; i < n; ++i)
        {
            dif = abs(nums1[i] - nums2[i]);
            ++cnt[dif];
            maxdif = max(maxdif, dif);
        }

        for (int i = (int)maxdif; i > 0 && k > 0; --i)
        {
            if (cnt[i] == 0)
            {
                continue;
            }

            ops = min((long long)k, cnt[i]);
            cnt[i] -= ops;
            cnt[i - 1] += ops;
            k -= (int)ops;
        }

        for (int i = 1; i <= (int)maxdif; ++i)
        {
            res += (long long)i * i * cnt[i];
        }

        return res;
    }
};