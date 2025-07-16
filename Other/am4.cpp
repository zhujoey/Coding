#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

int main()
{
    double dist, a, b, c, x;
    // speed, pax, range, type, fuel
    const std::vector<std::tuple<int, int, int, std::string, int>> inf = {
        {877, 78, 2200, "arj21-700", 9},
        {926, 131, 3056, "727-100", 13},
        {903, 90, 2036, "dc-9-10", 14},
        {1096, 230, 5500, "mc-21-400", 19},
        {813, 250, 14500, "787-8", 16},
        {932, 300, 18000, "a350-900ulr", 14}
    };

    std::cin >> dist >> a >> b >> c;

    for (const auto& aircraft : inf)
    {
        int speed = std::get<0>(aircraft);
        int pax = std::get<1>(aircraft);
        int range = std::get<2>(aircraft);
        std::string type = std::get<3>(aircraft);
        int fuel = std::get<4>(aircraft);

        if (range < dist)
        {
            std::cout << type << " cannot complete the flight\n";
            continue;
        }

        x = pax / (1 + 2 * b / a + 3 * c / a);
        double total_econ = std::round(24 * speed * x / dist);
        if (total_econ > a - x)
        {
            std::cout << type << " will exceed passenger limits\n";
        }
        else
        {
            std::cout << type << " will fly ~" << total_econ
                      << " economy passengers and consume "
                      << 24 * fuel * speed << " lbs of fuel per day | economy: ~"
                      << std::round(x) << " business: ~"
                      << std::round(b * x / a) << " first: ~"
                      << std::round(c * x / a) << "\n";
        }
    }

    return 0;
}