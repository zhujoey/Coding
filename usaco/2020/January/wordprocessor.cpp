
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::ifstream fin("word.in");
    std::ofstream fout("word.out");

    int n, k;
    fin >> n >> k;

    std::vector<std::string> words(n);
    for (int i = 0; i < n; i++)
    {
        fin >> words[i];
    }

    int w = 0;
    for (int i = 0; i < n; i++)
    {
        if (w + static_cast<int>(words[i].size()) > k)
        {
            fout << "\n" << words[i];
            w = words[i].size();
        }
        else
        {
            if (w > 0)
            {
                fout << " ";
            }
            fout << words[i];
            w += words[i].size();
        }
    }
    fout << "\n";

    return 0;
}
