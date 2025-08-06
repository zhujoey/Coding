#include <iostream>
#include <vector>

int main()
{
    long long n = 0;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    
    std::vector<long long> freq;
    long long count = 0;
    for (long long i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            count++;
        }
        else
        {
            if (count > 0)
            {
                freq.push_back(count);
            }
            count = 0;
        }
    }
    
    if (count > 0)
    {
        freq.push_back(count);
    }
    
    long long minBlock[2] = {9223372036854775807, 9223372036854775807};
    long long minEnd = 9223372036854775807;
    long long sind = 0;
    long long eind = freq.size() - 1;
    
    if (s[0] == '1')
    {
        minEnd = std::min(minEnd, freq[0]);
        sind++;
    }
    
    if (s[n - 1] == '1')
    {
        minEnd = std::min(minEnd, freq[eind]);
        eind--;
    }
    
    for (long long i = sind; i <= eind; i++)
    {
        minBlock[freq[i] % 2] = std::min(minBlock[freq[i] % 2], freq[i]);
    }
    
    long long spread = std::min(minEnd * 2 - 1, std::min(minBlock[0] - 1, minBlock[1]));
    long long infected = 0;
    
    for (long long block : freq)
    {
        infected += (block + spread - 1) / spread;
    }
    
    std::cout << infected << std::endl;
    return 0;
}
