#include <iostream>
#include <vector>

int main()
{
    long long n, c, tempnum, othertemp;
    std::vector<long long> f, p, temp;
    std::vector<std::vector<long long>> invite;
    for (int i = 0; i < c; ++i)
    {
        std::cin >> tempnum;
        f.push_back(tempnum);
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> tempnum;
        p.push_back(tempnum);
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> tempnum;
        temp.clear();
        for (int i = 0; i < tempnum; ++i)
        {
            std::cin >> othertemp;
            temp.push_back(othertemp);
        }
        invite.push_back(temp);
    }
    
}