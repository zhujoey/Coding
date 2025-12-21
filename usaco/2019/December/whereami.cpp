
#include <fstream>
#include <string>

int main()
{
    std::ifstream fin("whereami.in");
    std::ofstream fout("whereami.out");

    int n;
    std::string s;
    fin >> n >> s;
    bool good = true;

    for (int guess = 1; guess <= n; guess++)
    {
        good = true;

        for (int i = 0; i + guess <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (s.substr(i, guess) == s.substr(j, guess))
                {
                    good = false;
                }
            }
        }

        if (good)
        {
            fout << guess << "\n";
            break;
        }
    }
}
