class Solution
{
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime)
    {
        int n = plantTime.size();
        vector<pair<int, int>> seeds;

        for (int i = 0; i < n; ++i)
        {
            seeds.push_back({growTime[i], plantTime[i]});
        }

        sort(seeds.rbegin(), seeds.rend());

        int current = 0;
        int maximum = 0;

        for (auto& seed : seeds)
        {
            current += seed.second;
            maximum = max(maximum, current + seed.first);
        }

        return maximum;
    }
};