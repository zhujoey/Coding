#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int n, q, startnum = 0, endnum = 0, strokes = 1, stop = 0, tempSize = 0;;
    std::string fence = "";
    std::cin >> n >> q >> fence;
    std::vector<int> starts = {}, ends = {}, sums = {}, reverseSums = {};
    std::vector<char> drawing = {fence[0]};

    for (int i = 0; i < q; ++i)
    {
        std::cin >> startnum >> endnum;
        starts.push_back(startnum - 1);
        ends.push_back(endnum - 1);
    }

    for (int i = 1; i < fence.size(); ++i)
    {
        sums.push_back(strokes);
        if (fence[i] > fence[i - 1])
        {
            ++strokes;
            drawing.push_back(fence[i]);
        }
        else if (fence[i] < fence[i - 1])
        {
            if (std::find(drawing.begin(), drawing.end(), fence[i]) == drawing.end())
            {
                for (int j = drawing.size() - 1; j >= 0; ++j)
                {
                    if (drawing[j] < fence[i])
                    {
                        stop = j;
                        break;
                    }
                    if (j == 0)
                    {
                        stop = -1;
                    }
                }

                tempSize = drawing.size() - 1 - stop;

                for (int j = 0; j < tempSize; ++j)
                {
                    drawing.pop_back();
                }

                drawing.push_back(fence[i]);
                ++strokes;
            }
        }
    }
    sums.push_back(strokes);

    std::reverse(fence.begin(), fence.end());
    strokes = 1;
    drawing = {fence[0]};

    for (int i = 1; i < fence.size(); ++i)
    {
        reverseSums.push_back(strokes);
        if (fence[i] > fence[i - 1])
        {
            ++strokes;
            drawing.push_back(fence[i]);
        }
        else if (fence[i] < fence[i - 1])
        {
            if (std::find(drawing.begin(), drawing.end(), fence[i]) == drawing.end())
            {
                for (int j = drawing.size() - 1; j >= 0; ++j)
                {
                    if (drawing[j] < fence[i])
                    {
                        stop = j;
                        break;
                    }
                    if (j == 0)
                    {
                        stop = -1;
                    }
                }

                tempSize = drawing.size() - 1 - stop;

                for (int j = 0; j < tempSize; ++j)
                {
                    drawing.pop_back();
                }

                drawing.push_back(fence[i]);
                ++strokes;
            }
        }
    }
    reverseSums.push_back(strokes);

    for (int i = 0; i < starts.size(); ++i)
    {
        if (starts[i] - 1 >= 0)
        {
            if (fence.size() - ends[i] - 1 >= 0)
            {
                std::cout << sums[starts[i] - 1] + reverseSums[fence.size() - ends[i] - 1] << std::endl;
            }
            else
            {
                std::cout << sums[starts[i] - 1] << std::endl;
            }
        }
        else if (fence.size() - ends[i] - 1 >= 0)
        {
            std::cout << reverseSums[fence.size() - ends[i] - 1] << std::endl;
        }
        else
        {
            std::cout << 0 << std::endl;
        }
    }

    return 0;
}