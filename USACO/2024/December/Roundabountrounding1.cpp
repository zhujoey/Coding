#include <iostream>

int amount(int length)
{
    int lower = 0;
    int higher = 4;
    for (int i = 1; i < length - 1; ++i)
    {
        lower += 4;
        lower *= 10;
        higher *= 10;
        higher += 9;
    }

    lower += 5;

    return higher - lower + 1;
}

int count(const int &num)
{
    int temp = num;
    int answer = 0;
    int length = 1;
    while (temp > 10)
    {
        temp /= 10;
        ++length;
        answer += amount(length);
    }

    ++length;

    int lower = 0;
    int higher = 4;

    for (int i = 1; i < length - 1; ++i)
    {
        lower += 4;
        lower *= 10;
        higher *= 10;
        higher += 9;
    }

    lower += 5;

    if (num >= higher)
    {
        answer += higher - lower + 1;
    }
    else if (num < higher && num >= lower)
    {
        answer += num - lower + 1;
    }
    
    return answer;
}

int main()
{
    int inputcount = 0;
    int currentinput = 0;
    std::cin >> inputcount;

    for (int i = 0; i < inputcount; ++i)
    {
        std::cin >> currentinput;
        std::cout << count(currentinput) << std::endl;;
    }

    return 0;
};