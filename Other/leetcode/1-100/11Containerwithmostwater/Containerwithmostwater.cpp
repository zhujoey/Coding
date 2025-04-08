class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int front = 0;
        int end = height.size() - 1;
        int max = 0;

        while (front != end)
        {
            max = std::max((end - front) * std::min(height[front], height[end]), max);
            
            if (height[front] <= height[end])
            {
                ++front;
            }
            else
            {
                --end;
            }
        }

        return max;
    }
};