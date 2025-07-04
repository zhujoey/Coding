#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
 
int main()
{
    int n, type, j = 0, temp;
    bool adding = false;
    std::string flats;
    std::unordered_map<char, int> window;
    std::cin >> n >> flats;
    char current;
    
    for (int i = 0; i < n; ++i)
    {
        window[flats[i]] = 0;
    }
    
    type = window.size();
    window.clear();
 
    int ans = n, left = 0, unique_count = 0;
 
    for (int right = 0; right < n; ++right)
    {
        current = flats[right];
        if (window[current] == 0)
        {
            unique_count++;
        }
        window[current]++;

        while (unique_count == type)
        {
            ans = std::min(ans, right - left + 1);
            if (--window[flats[left]] == 0)
            {
                unique_count--;
            }
            left++;
        }
    }
 
    std::cout << ans;
    return 0;
}