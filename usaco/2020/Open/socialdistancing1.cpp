
#include <fstream>
#include <algorithm>

int main()
{
    std::ifstream input("socdist1.in");
    std::ofstream output("socdist1.out");

    int n = 0, first = 0, second = 0, current = 0, min = 0, lastonepos = -1, leading = 0, trailing = 0;
    char c;

    input >> n;
    min = n + 1;

    bool seenone = false;

    for (int i = 0; i < n; ++i)
    {
        input >> c;

        if (c == '0')
        {
            ++current;
        }
        else
        {
            if (current > first)
            {
                second = first;
                first = current;
            }
            else if (current > second)
            {
                second = current;
            }

            if (!seenone)
            {
                leading = current;
            }

            current = 0;

            if (lastonepos != -1)
            {
                int dist = i - lastonepos;
                if (dist < min)
                {
                    min = dist;
                }
            }
            lastonepos = i;
            seenone = true;
        }
    }

    trailing = current;

    if (current > first)
    {
        second = first;
        first = current;
    }
    else if (current > second)
    {
        second = current;
    }

    if (second == 0)
    {
        second = first;
    }

    if (min == n + 1)
    {
        min = 0;
    }

    int option1 = std::min((first + 1) / 2, (second + 1) / 2);
    int option2 = (first + 2) / 3;
    int option3 = std::min((first + 1) / 2, std::max(leading, trailing));
    int option4 = std::min(leading, trailing);

    int answer = std::max({option1, option2, option3, option4});
    if (answer > min)
    {
        answer = min;
    }

    output << answer << "\n";

    return 0;
}
