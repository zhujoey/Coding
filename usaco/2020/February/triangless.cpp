#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

int main() 
{
    long long n, ans, cur, sz;
    std::ifstream infile("triangles.in");
    std::ofstream outfile("triangles.out");
    std::vector<std::pair<long long, long long>> v, todo[20001]; 
    std::vector<long long> sum0, sum1;

    infile >> n; 

    v.resize(n);
    for (long long i = 0; i < n; ++i) 
    {
        infile >> v[i].first >> v[i].second;
    }

    sum0.assign(n, 0);
    sum1.assign(n, 0);

    for (long long i = 0; i <= 20000; ++i) 
    {
        todo[i].clear();
    }
    for (long long i = 0; i < n; ++i) 
    {
        todo[v[i].first + 10000].push_back({v[i].second, i});
    }
    
    for (long long i = 0; i <= 20000; ++i) 
    {
        if (todo[i].size() > 0) 
        {
            sz = todo[i].size();
            std::sort(todo[i].begin(), todo[i].end());
            cur = 0; 
            for (long long j = 0; j < sz; ++j) 
            {
                cur = (cur + todo[i][j].first - todo[i][0].first) % 1000000007;
            }
            for (long long j = 0; j < sz; ++j) 
            {
                if (j) 
                {
                    cur = (cur + (2LL * j - sz) * (todo[i][j].first - todo[i][j - 1].first)) % 1000000007;
                    if (cur < 0) 
                    {
                        cur += 1000000007;
                    }
                }
                sum0[todo[i][j].second] = cur;
            }
        }
    }

    for (long long i = 0; i <= 20000; ++i) 
    {
        todo[i].clear();
    }
    for (long long i = 0; i < n; ++i) 
    {
        todo[v[i].second + 10000].push_back({v[i].first, i});
    }

    for (long long i = 0; i <= 20000; ++i) 
    {
        if (todo[i].size() > 0) 
        {
            sz = todo[i].size();
            std::sort(todo[i].begin(), todo[i].end());
            cur = 0; 
            for (long long j = 0; j < sz; ++j) 
            {
                cur = (cur + todo[i][j].first - todo[i][0].first) % 1000000007;
            }
            for (long long j = 0; j < sz; ++j) 
            {
                if (j) 
                {
                    cur = (cur + (2LL * j - sz) * (todo[i][j].first - todo[i][j - 1].first)) % 1000000007;
                    if (cur < 0) 
                    {
                        cur += 1000000007;
                    }
                }
                sum1[todo[i][j].second] = cur;
            }
        }
    }

    ans = 0; 
    for (long long i = 0; i < n; ++i) 
    {
        ans = (ans + (sum0[i] * sum1[i]) % 1000000007) % 1000000007;
    }
    
    outfile << ans << "\n";
    return 0;
}