#include <vector>

class Solution
{
public:

    // Complexity: O(n^2)
    void rotate(std::vector<std::vector<int>>& matrix)
    {
        int rotatingValue = 0;

        if (matrix.size() <= 1)
        {
            return;
        }

        for (int y = 0; y <= (matrix.size() - 1) / 2; ++y)
        {
            for (int x = 0; x <= matrix.size() / 2 - 1; ++x)
            {
                rotatingValue = matrix[x][y];
                matrix[x][y] = matrix[matrix.size() - 1 - y][x];
                matrix[matrix.size() - 1 - y][x] = matrix[matrix.size() - 1 - x][matrix.size() - 1 - y];
                matrix[matrix.size() - 1 - x][matrix.size() - 1 - y] = matrix[y][matrix.size() - 1 - x];
                matrix[y][matrix.size() - 1 - x] = rotatingValue;                
            }
        }
    }
};