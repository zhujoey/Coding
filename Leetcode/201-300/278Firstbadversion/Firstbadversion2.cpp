// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int front = 0;
        int back = n;

        while(back - front > 1)
        {
            if (isBadVersion(front / 2.0 + back / 2.0))
            {
                back = front / 2.0 + back / 2.0;
            }
            else
            {
                front = front / 2.0 + back / 2.0;
            }
        }

        return back;
    }
};