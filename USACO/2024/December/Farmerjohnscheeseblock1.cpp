#include <iostream>
#include <vector>

void check(const int &x, const int &y, const int &z, const int &size, std::vector<std::vector<std::vector<bool>>> &cube)
{
    int ans = 0;

    cube[x][y][z] = false;

    for (int a = 0; a < size; ++a)
    {
        for (int b = 0; b < size; ++b)
        {
            for (int c = 0; c < size; ++c)
            {
                if (cube[a][b][c] == true)
                {
                    break;
                }
                else if (c == size - 1)
                {
                    ++ans;
                }
            }
        }
    }
    for (int a = 0; a < size; ++a)
    {
        for (int c = 0; c < size; ++c)
        {
            for (int b = 0; b < size; ++b)
            {
                if (cube[a][b][c] == true)
                {
                    break;
                }
                else if (b == size - 1)
                {
                    ++ans;
                }
            }
        }
    }
    for (int c = 0; c < size; ++c)
    {
        for (int b = 0; b < size; ++b)
        {
            for (int a = 0; a < size; ++a)
            {
                if (cube[a][b][c] == true)
                {
                    break;
                }
                else if (a == size - 1)
                {
                    ++ans;
                }
            }
        }
    }

    std::cout << ans << std::endl;
}

int main()
{
    int x, y, z, inputcount, size = 0;
    std::cin >> size >> inputcount;
    std::vector<std::vector<std::vector<bool>>> cube(size, std::vector<std::vector<bool>>(size, std::vector<bool>(size, true)));

    for (int i = 0; i < inputcount; ++i)
    {
        std::cin >> x >> y >> z;
        check(x, y, z, size, cube);
    }
    
    return 0;
};