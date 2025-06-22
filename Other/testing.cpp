#include <iostream>
#include <string>
#include <deque>
#include <unordered_set>
#include <algorithm>

int main()
{
    int n;
    std::string types = "";
    std::unordered_set<char> needs;
    std::deque<char> window;
    std::cin >> n >> types;
    for(int i = 0; i < n; ++i)
    {
        needs.insert(types[i]);
    }
    unsigned long long ans = n, i = 0;
    while (i <= n)
    {
        std::unordered_set<char> has(window.begin(), window.end());
        if (needs == has)
        {
            if (window.size() < ans)
            {
                ans = window.size();
            }
            window.pop_front();
        }
        else
        {
            window.push_back(types[i]);
            ++i;
        }
    }
    
    std::cout << ans;
    return 0;
}