#include <iostream>
#include <vector>

int check(const int &x, const int &y, const int &z, const int &size, std::vector<std::vector<std::vector<bool>>> &cube, const int &n, int &ans)
{
    cube[x][y][z] = false;

    bool axis1, axis2, axis3 = true;

    if (n < size)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    //can only be 0 when n < size

    for (int i = 0; i < size; ++i)
    {
        if (cube[x][y][i])
        {
            axis1 = false;
        }
        if (cube[x][i][z])
        {
            axis2 = false;
        }
        if (cube[i][y][z])
        {
            axis3 = false;
        }
        if (i == size)
        {
            if (axis1)
            {
                ++ans;
            }
            if (axis2)
            {
                ++ans;
            }
            if (axis3)
            {
                ++ans;
            }
        }
    }

    //combine all 3 axis checks into one loop
    //O(3 * size)

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

    //O(n)

    return 0;
};