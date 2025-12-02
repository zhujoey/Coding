#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main()
{
    int a = 0, b = 0, k = 0, n = 0;
    std::unordered_map<std::string, int> members;
    std::vector<std::vector<char>> answer;
    std::vector<std::string> publication;

    std::cin >> k >> n;

    answer.assign(n, std::vector<char>(n, '?'));
    publication.assign(n, "");

    for (int i = 0; i < n; i++)
    {
        std::string name;
        std::cin >> name;
        members[name] = i;
        answer[i][i] = 'B';
    }

    for (int j = 0; j < k; j++)
    {
        for (int l = 0; l < n; l++)
        {
            std::cin >> publication[l];
        }

        for (int l = 0; l < n; l++)
        {
            bool alphabetical = true;
            for (int m = l + 1; m < n; m++)
            {
                if (publication[m - 1] > publication[m])
                {
                    alphabetical = false;
                }
                if (!alphabetical)
                {
                    a = members[publication[l]];
                    b = members[publication[m]];
                    answer[a][b] = '0';
                    answer[b][a] = '1';
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << answer[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}