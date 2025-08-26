#include <iostream>
#include <algorithm>

int main()
{
    long long n;
    std::cin >> n;
    long long funds[n], most = 0, ans = 0, numcows = n, cost;
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> funds[i];
    }
    std::sort(funds, funds + n);
    
    for (int i = 0; i < n; i++)
    {
        cost = funds[i]*numcows;
        if (cost > most)
        {
          most = cost;
          ans = funds[i];
    }
    
    numcows--;
  }
  
  std::cout << most << " " << ans << "\n";
  
  return 0;
}