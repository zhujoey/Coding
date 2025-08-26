#include <iostream>

int main() 
{
    int t = 0, n = 0, m = 0;
    char inputs[100][101] = {}, outputs[101] = {};
    bool tcpassed[100] = {}, allpassed = false, foundcondition = false, valid = false, affectsany = false;

    std::cin >> t;
    
    while (t--) 
    {
        std::cin >> n >> m;
        
        for (int i = 0; i < m; i++) 
        {
            std::cin >> inputs[i] >> outputs[i];
            tcpassed[i] = false;
        }

        allpassed = false;
        
        while (true) 
        {
            foundcondition = false;
            
            for (int bit = 0; bit < n; bit++) 
            {
                if (foundcondition) 
                {
                    break;
                }
                for (int val = 0; val <= 1; val++) 
                {
                    if (foundcondition) 
                    {
                        break;
                    }
                    for (int out = 0; out <= 1; out++) 
                    {
                        if (foundcondition) 
                        {
                            break;
                        }
                        
                        valid = true;
                        affectsany = false;
                        
                        for (int tc = 0; tc < m; tc++) 
                        {
                            if (!tcpassed[tc] && inputs[tc][bit] == '0' + val) 
                            {
                                affectsany = true;
                                if (outputs[tc] != '0' + out) 
                                {
                                    valid = false;
                                    break;
                                }
                            }
                        }
                        
                        if (valid && affectsany) 
                        {
                            foundcondition = true;
                            for (int tc = 0; tc < m; tc++) 
                            {
                                if (!tcpassed[tc] && inputs[tc][bit] == '0' + val) 
                                {
                                    tcpassed[tc] = true;
                                }
                            }
                        }
                    }
                }
            }
            
            if (!foundcondition) 
            {
                break;
            }
        }
        
        allpassed = true;
        for (int i = 0; i < m; i++) 
        {
            if (!tcpassed[i]) 
            {
                allpassed = false;
                break;
            }
        }
        
        if (allpassed) 
        {
            std::cout << "OK\n";
        } 
        else 
        {
            std::cout << "LIE\n";
        }
    }
    
    return 0;
}