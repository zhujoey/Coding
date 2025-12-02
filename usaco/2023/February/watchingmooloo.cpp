#include <iostream>
#include <algorithm>
 
int main(){
    long long n, k, ans = 0, day[100000], extendcost, newcost;
    std::cin >> n >> k;
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> day[i];
        if (i == 0)
        {
            ans += k + 1;
        }
        else
        {
            extendcost = day[i] - day[i-1];
            newcost = k + 1;
            ans += std::min(extendcost, newcost);
        }
    }
    std::cout << ans << "\n";
}