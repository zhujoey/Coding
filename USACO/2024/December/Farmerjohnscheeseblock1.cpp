#include <iostream>
#include <vector>

int check(const int &x, const int &y, const int &z, const int &size, std::vector<std::vector<std::vector<bool>>> &cube, const int &n, int &ans)
{
    cube[x][y][z] = false;

    if (n < size)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    for (int i = 0; i < size; ++i)
    {
        if (cube[x][y][i])
        {
            break;
        }
        if (i == size - 1)
        {
            ++ans;
        }
    }
    for (int i = 0; i < size; ++i)
    {
        if (cube[x][i][z])
        {
            break;
        }
        if (i == size - 1)
        {
            ++ans;
        }
    }
    for (int i = 0; i < size; ++i)
    {
        if (cube[i][y][z])
        {
            break;
        }
        if (i == size - 1)
        {
            ++ans;
        }
    }

    std::cout << ans << std::endl;
    return ans;
}

int main()
{
    int x, y, z, inputcount, size, count = 0;
    std::cin >> size >> inputcount;
    std::vector<std::vector<std::vector<bool>>> cube(size, std::vector<std::vector<bool>>(size, std::vector<bool>(size, true)));

    for (int i = 0; i < inputcount; ++i)
    {
        std::cin >> x >> y >> z;
        count = check(x, y, z, size, cube, i + 1, count);
    }
    
    return 0;
};