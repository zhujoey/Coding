#include <fstream>
#include <queue>

int n, left = 0, right;
long long need, ans = 1e9 + 1, flavor = 0;
int f[100000], s[100000]; 
std::priority_queue<std::pair<int, int>> maxSpice;

int main() 
{
    std::ifstream inFile("hayfeast.in");
    std::ofstream outFile("hayfeast.out");

    inFile >> n >> need;

    for (right = 0; right < n; ++right) 
    {
        inFile >> f[right] >> s[right];
    }

    for (right = 0; right < n; ++right) 
    {
        flavor += f[right];
        maxSpice.push({s[right], right});

        while (flavor >= need) 
        {
            while (!maxSpice.empty() && maxSpice.top().second < left) 
            {
                maxSpice.pop();
            }

            ans = std::min(ans, (long long)maxSpice.top().first);
            flavor -= f[left];
            left++;
        }
    }

    outFile << ans << std::endl;
    inFile.close();
    outFile.close();

    return 0;
}