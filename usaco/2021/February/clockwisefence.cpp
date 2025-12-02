#include <iostream>
#include <string>

int main()
{
    int n, numdir = 0;
    char dir;
    std::string path;
    std::cin >> n;
    while (n--)
    {
        std::cin >> path;
        dir = path[0];
        numdir = 0;
        for (int i = 1; i < path.size(); ++i)
        {
            if (dir == 'N')
            {
                if (path[i] == 'W')
                {
                    --numdir;
                }
                else if (path[i] == 'E')
                {
                    ++numdir;
                }
            }
            else if (dir == 'E')
            {
                if (path[i] == 'N')
                {
                    --numdir;
                }
                else if (path[i] == 'S')
                {
                    ++numdir;
                }
            }
            else if (dir == 'S')
            {
                if (path[i] == 'E')
                {
                    --numdir;
                }
                else if (path[i] == 'W')
                {
                    ++numdir;
                }
            }
            else if (dir == 'W')
            {
                if (path[i] == 'S')
                {
                    --numdir;
                }
                else if (path[i] == 'N')
                {
                    ++numdir;
                }
            }
            dir = path[i];
        }
        if (numdir > 0)
        {
            std::cout << "CW\n";
        }
        else
        {
            std::cout << "CCW\n";
        }
    }
    return 0;
}