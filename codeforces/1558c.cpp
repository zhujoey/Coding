#include <iostream>
#include <vector>
#include <algorithm>
 
void reverseprefix(std::vector<int>& a, int p, std::vector<int>& operations) 
{
    if (p <= 1) 
    {
        return;
    }
    operations.push_back(p);
    std::reverse(a.begin(), a.begin() + p);
}
 
int findindex(const std::vector<int>& a, int value) 
{
    for (int i = 0; i < a.size(); ++i) 
    {
        if (a[i] == value) 
        {
            return i + 1; 
        }
    }
    return -1;
}
 
void solve() 
{
    int n, pk, pkm1;
    bool possible;
    std::vector<int> a, operations;
 
    possible = true;
    std::cin >> n;
    a.resize(n);
    
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> a[i];
        if ((a[i] % 2) != ((i + 1) % 2)) 
        {
            possible = false;
        }
    }
    
    if (!possible) 
    {
        std::cout << -1 << "\n";
        return;
    }
    
    for (int k = n; k > 1; k -= 2) 
    {
        pk = findindex(a, k);
        reverseprefix(a, pk, operations);
        
        pkm1 = findindex(a, k - 1);
        reverseprefix(a, pkm1 - 1, operations);
        
        reverseprefix(a, pkm1 + 1, operations);
        
        reverseprefix(a, 3, operations);
        
        reverseprefix(a, k, operations);
    }
    
    std::cout << operations.size() << "\n";
    for (int i = 0; i < operations.size(); ++i) 
    {
        std::cout << operations[i] << (i == operations.size() - 1 ? "" : " ");
    }
    std::cout << "\n";
}
 
int main() 
{
    int t;
    std::cin >> t;
    while (t--) 
    {
        solve();
    }
    return 0;
}