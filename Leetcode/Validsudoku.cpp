#include <vector>
#include <algorithm>

class Solution
{
public:

    // Total Complexity(O(NlogN))
    bool isValidSudoku(const std::vector<std::vector<char>>& board)
    {
        for (int x = 0; x < 9; ++x)
        {
            if (!checkValidLine({board[x][0], board[x][1], board[x][2], board[x][3], board[x][4], board[x][5], board[x][6], board[x][7], board[x][8]}))
            {
                return false;
            }
            if (!checkValidLine({board[0][x], board[1][x], board[2][x], board[3][x], board[4][x], board[5][x], board[6][x], board[7][x], board[8][x]}))
            {
                return false;
            }
        }

        if (!checkValidLine({board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2], board[2][0], board[2][1], board[2][2]}))
        {
            return false;
        }
        else if (!checkValidLine({board[3][0], board[3][1], board[3][2], board[4][0], board[4][1], board[4][2], board[5][0], board[5][1], board[5][2]}))
        {
            return false;
        }
        else if (!checkValidLine({board[6][0], board[6][1], board[6][2], board[7][0], board[7][1], board[7][2], board[8][0], board[8][1], board[8][2]}))
        {
            return false;
        }
        else if (!checkValidLine({board[0][3], board[0][4], board[0][5], board[1][3], board[1][4], board[1][5], board[2][3], board[2][4], board[2][5]}))
        {
            return false;
        }
        else if (!checkValidLine({board[3][3], board[3][4], board[3][5], board[4][3], board[4][4], board[4][5], board[5][3], board[5][4], board[5][5]}))
        {
            return false;
        }
        else if (!checkValidLine({board[6][3], board[6][4], board[6][5], board[7][3], board[7][4], board[7][5], board[8][3], board[8][4], board[8][5]}))
        {
            return false;
        }
        else if (!checkValidLine({board[0][6], board[0][7], board[0][8], board[1][6], board[1][7], board[1][8], board[2][6], board[2][7], board[2][8]}))
        {
            return false;
        }
        else if (!checkValidLine({board[3][6], board[3][7], board[3][8], board[4][6], board[4][7], board[4][8], board[5][6], board[5][7], board[5][8]}))
        {
            return false;
        }
        else if (!checkValidLine({board[6][6], board[6][7], board[6][8], board[7][6], board[7][7], board[7][8], board[8][6], board[8][7], board[8][8]}))
        {
            return false;
        }

        return true;
    }
    
    // Complexity: O(NlogN)
    bool checkValidLine(std::vector<char> line)
    {
        std::sort(line.begin(), line.end());
        for (int i = 0; i < line.size() - 1; ++i)
        {
            if (line[i] == '.')
            {
                continue;
            }
            else
            {
                if (line[i] == line[i + 1])
                {
                    return false;
                }
            }
        }

        return true;
    }
};