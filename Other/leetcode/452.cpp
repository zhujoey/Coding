class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        int current, ans = 1;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[1] < b[1];
        });
        current = points[0][1];
        for (int i = 1; i < points.size(); ++i)
        {
            if (points[i][0] > current)
            {
                ++ans;
                current = points[i][1];
            }
        }
        return ans;    
    }
};