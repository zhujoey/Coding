#include <iostream>
#include <fstream>

int minmoves(int cow1, int cow2, int cow3)
{
    if (cow2 - cow1 == 2 || cow3 - cow2 == 2)
    {
        return 1;
    }
    else if (cow2 - cow1 == 1 && cow3 - cow2 == 1)
    {
        return 0;
    }
    else
    {
        return 2;
    }
}

int maxmoves(int cow1, int cow2, int cow3)
{
    return std::max(cow2 - cow1, cow3 - cow2) - 1;
}

int main()
{
    int cow1, cow2, cow3;
    std::ifstream fin("herding.in");

    fin >> cow1 >> cow2 >> cow3;
    fin.close();

    if (cow1 > cow2)
    {
        std::swap(cow1, cow2);
    }
    if (cow2 > cow3)
    {
        std::swap(cow2, cow3);
    }
    if (cow1 > cow2)
    {
        std::swap(cow1, cow2);
    }
    
    std::ofstream fout("herding.out");
    fout << minmoves(cow1, cow2, cow3) << std::endl << maxmoves(cow1, cow2, cow3);
    fout.close();
};