#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::string;

void addedge(vector<string> &grid, int u, int v)
{
    grid[u][v] = 'Y';
    grid[v][u] = 'Y';
}

int main()
{
    int k, n, nodea, nodeb, remainingdist, i, j;
    vector<string> grid;
    vector<int> line;
    int currentlevelnodes[32][2];

    if (!(cin >> k))
    {
        return 0;
    }

    n = 2;
    grid.assign(1001, string(1001, 'N'));
    line.assign(32, 0);

    currentlevelnodes[0][0] = 1;
    currentlevelnodes[0][1] = 1;

    for (i = 1; i <= 29; ++i)
    {
        n++;
        nodea = n;
        n++;
        nodeb = n;
        currentlevelnodes[i][0] = nodea;
        currentlevelnodes[i][1] = nodeb;
        
        if (i == 1)
        {
            addedge(grid, 1, nodea);
            addedge(grid, 1, nodeb);
        }
        else
        {
            addedge(grid, currentlevelnodes[i - 1][0], nodea);
            addedge(grid, currentlevelnodes[i - 1][1], nodea);
            addedge(grid, currentlevelnodes[i - 1][0], nodeb);
            addedge(grid, currentlevelnodes[i - 1][1], nodeb);
        }
    }

    line[0] = 2;
    for (i = 1; i <= 30; ++i)
    {
        n++;
        line[i] = n;
        addedge(grid, line[i], line[i - 1]);
    }

    for (i = 0; i <= 29; ++i)
    {
        if ((k >> i) & 1)
        {
            remainingdist = 31 - i - 1;
            if (i == 0)
            {
                addedge(grid, 1, line[remainingdist]);
            }
            else
            {
                addedge(grid, currentlevelnodes[i][0], line[remainingdist]);
                addedge(grid, currentlevelnodes[i][1], line[remainingdist]);
            }
        }
    }

    cout << n << "\n";
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}