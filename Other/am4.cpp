#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

int main()
{
    double dist, a, b, c, x;
    // speed, pax, range, type, fuel
    const std::vector<std::tuple<int, int, int, std::string, int>> inf = {
        {1096, 230, 5500, "mc-21-400", 19},
        {813, 250, 14500, "787-8", 16},
        {980, 350, 10800, "747sp", 22},
        {876, 410, 12435, "md-11C", 24},
        {876, 410, 12655, "md-11", 24},
        {876, 410, 13408, "md-11ER", 24},
        {945, 600, 14500, "a380-800", 21},
        {871, 135, 5750, "a220-100", 10},
        {780, 117, 6020, "baby bus", 8},
        {871, 160, 6110, "a220-300", 12},
        {670, 124, 3600, "an12", 14},
        {680, 110, 4075, "an10a", 14},
        {780, 118, 3440, "737-100", 12},
        {780, 110, 4622, "737-200c", 14},
        {780, 123, 4449, "737-500", 13},
        {780, 102, 5473, "737-200adv", 13},
        {855, 130, 4170, "737-200", 12},
        {810, 134, 3815, "717-200", 9},
        {828, 110, 5648, "737-600", 12},
        {855, 128, 4707, "737-300", 12},
        {823, 120, 5940, "737-700c", 11},
        {780, 120, 4010, "737-400", 14},
        {828, 149, 6230, "737-700", 11},
        {977, 144, 9913, "707", 18},
        {780, 184, 7000, "737-800", 10},
        {953, 189, 4450, "727-200", 15},
        {828, 177, 3815, "737-900", 10},
        {828, 126, 10200, "737-700er", 11},
        {823, 215, 5925, "737-900er", 11},
        {839, 160, 6850, "737max7", 7},
        {839, 180, 6500, "737max8", 7},
        {839, 200, 7000, "737max9", 7},
        {839, 225, 7000, "737max10", 7},
        {926, 131, 3056, "727-100", 13}
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