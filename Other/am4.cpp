#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>

int main()
{
    std::string dest;
    double dist, a, b, c, t, x, y, z, daily;
    bool stop = false;
    //speed, pax, range, type
    const std::vector<std::tuple<int, int, int, std::string>> inf = {{930, 78, 2200, "arj"}, {894, 90, 2036, "dc-9-10"}, {1096, 230, 5500, "mc-21-400"}, {813, 250, 20000, "787-8"}};
    std::cout << "destination, distance, economy, business, first\n";
    std::cin >> t;
    while (t--)
    {
        std::cin >> dest >> dist >> a >> b >> c;
        stop = false;
        for (int i = 0; i < inf.size(); ++i)
        {
            if (std::get<2>(inf[i]) < dist)
            {
                std::cout << std::get<3>(inf[i]) << " cannot fly to " << dest << "\n";
                continue;
            }
            x = std::get<1>(inf[i]) / (1 + 2 * b / a + 3 * c / a);
            std::cout << std::get<3>(inf[i]) << " will fly ~" << std::round(24 * std::get<0>(inf[i]) * x / dist) << " econ to " << dest << " economy: ~" << std::round(x) << " business: ~" << std::round(b * x / a) << " first: ~" << std::round(c * x / a) << "\n";
        }
    }
    

    return 0;
}