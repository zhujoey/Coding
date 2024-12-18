#include <iostream>
#include <vector>

bool axis1, axis2, axis3 = true;
int ans = 0;

void check(const int &x, const int &y, const int &z, const int &size, std::vector<std::vector<std::vector<bool>>> &cube)
{
    ans = 0;

    cube[x][y][z] = false;

    for (int a = 0; a < size; ++a)
    {
        for (int b = 0; b < size; ++b)
        {
            axis1 = true;
            axis2 = true;
            axis3 = true;

            for (int c = 0; c < size; ++c)
            {
                if (cube[a][b][c] == true)
                {
                    axis1 = false;
                }
                else if (c == size - 1 && axis1)
                {
                    ++ans;
                }
                if (cube[a][c][b] == true)
                {
                    axis2 = false;
                }
                else if (c == size - 1 && axis2)
                {
                    ++ans;
                }
                if (cube[c][b][a] == true)
                {
                    axis3 = false;
                }
                else if (c == size - 1 && axis3)
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
}