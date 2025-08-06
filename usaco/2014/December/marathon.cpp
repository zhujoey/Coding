#include <fstream>
#include <cmath>
#include <algorithm>

int main()
{
    std::ifstream infile("marathon.in");
    std::ofstream outfile("marathon.out");
    int n, x[100000], y[100000], saved = 0;
    infile >> n >> x[0] >> y[0] >> x[1] >> y[1];
    long long total = std::abs(x[1] - x[0]) + std::abs(y[1] - y[0]);
    for (int i = 2; i < n; ++i)
    {
        infile >> x[i] >> y[i];
        saved = std::max(saved, std::abs(x[i] - x[i - 1]) + std::abs(y[i] - y[i - 1]) + std::abs(x[i - 1] - x[i - 2]) + std::abs(y[i - 1] - y[i - 2]) - std::abs(x[i] - x[i - 2]) - std::abs(y[i] - y[i - 2]));
        total += std::abs(x[i] - x[i - 1]) + std::abs(y[i] - y[i - 1]);
    }
    outfile << total - saved << "\n";

    return 0;
}