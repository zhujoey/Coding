#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

int n, strokes[100001], reverseStrokes[100001];
std::string colors;

void build (int *count)
{
    std::stack<char> active;
    
    for (int i = 0; i < n; ++i)
    {
        count[i + 1] = count[i]; 

        while (!active.empty() && active.top() > colors[i])
        {
            active.pop();
        }

        if (active.empty() || active.top() < colors[i])
        {
            active.push(colors[i]);
            ++count[i + 1];
        }
    }
}

int main ()
{
    int q, rangeStart, rangeEnd;
    std::cin >> n >> q >> colors;

    build(strokes);
    std::reverse(colors.begin(), colors.end());
    build(reverseStrokes);

    for (int i = 0; i < q; ++i)
    {
        std::cin >> rangeStart >> rangeEnd;
        std::cout << strokes[rangeStart - 1] + reverseStrokes[n - rangeEnd] << "\n";
    }

    return 0;
}