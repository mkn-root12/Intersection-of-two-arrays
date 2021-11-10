class Solution
{
public:
    bool isPalindrome(int x)
    {
        int thi = x;
        if (x < 0)
        {
            return false;
        }
        unsigned long long another = x % 10;
        x /= 10;
        int temp = 0;
        while (x != 0)
        {
            temp = x % 10;
            another = another * 10 + temp;
            x /= 10;
        }
        return thi == another;
    }
};
