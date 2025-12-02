#include <iostream>
#include <map>
#include <string>

int main(void)
{
    std::string animals[12] =
    {
        "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse",
        "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"
    };

    std::map<std::string, int> whenborn;
    int n = 0, diff = 0, a = 0, y = 0;
    std::string cowa = "", born = "", inword = "", relation = "", animal = "", yearword = "", fromword = "", cowb = "";

    whenborn["Bessie"] = 2021;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> cowa >> born >> inword >> relation >> animal >> yearword >> fromword >> cowb;
        whenborn[cowa] = whenborn[cowb];

        while (true)
        {
            if (relation == "previous")
            {
                --whenborn[cowa];
            }
            else
            {
                ++whenborn[cowa];
            }

            a = 0;
            y = 2021;
            while (y < whenborn[cowa])
            {
                ++y;
                ++a;
                if (a == 12)
                {
                    a = 0;
                }
            }
            while (y > whenborn[cowa])
            {
                --y;
                --a;
                if (a == -1)
                {
                    a = 11;
                }
            }

            if (animals[a] == animal)
            {
                break;
            }
        }
    }

    diff = whenborn["Bessie"] - whenborn["Elsie"];
    if (diff < 0)
    {
        diff = -diff;
    }
    std::cout << diff << "\n";
}