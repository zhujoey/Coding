#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

int main() 
{
    int n, h, k, q, i, idx;
    long long cyclecost, t, ans;
    std::vector<std::pair<int, int>> cards;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> hand;
    std::vector<long long> wintimes;

    std::cin >> n >> h;
    cards.resize(n);
    for (i = 0; i < n; ++i) 
    {
        std::cin >> cards[i].second;
        cards[i].first = 0;
    }

    std::cin >> k;
    for (i = 0; i < k; ++i) 
    {
        std::cin >> idx;
        cards[idx - 1].first = -1;
    }

    for (i = 0; i < h - 1; ++i) 
    {
        hand.push(cards[i]);
    }
    
    cyclecost = 0;
    for (i = 0; i <= n - h; ++i) 
    {
        hand.push(cards[i + h - 1]);
        cyclecost += hand.top().second;
        if (hand.top().first == -1) 
        {
            wintimes.push_back(cyclecost);
        }
        hand.pop();
    }

    std::cin >> q;
    for (i = 0; i < q; ++i) 
    {
        std::cin >> t;
        ans = t / cyclecost * wintimes.size();
        ans += std::upper_bound(wintimes.begin(), wintimes.end(), t % cyclecost) - wintimes.begin();
        std::cout << ans << "\n";
    }

    return 0;
}