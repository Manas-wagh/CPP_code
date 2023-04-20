#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {

        int n;

        n = nums.size();
        if (n == 1)
        {
            return 1;
        }
        if (n == 2 && (nums[0] == nums[1]))
        {
            return 1;
        }
        int c = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                c++;
            }
        }
        if (c == n - 1)
        {
            return 1;
        }
        int ctr = 2;
        int prev = nums[1];
        int inc;
        if (nums[0] > nums[1])
        {
            inc = -1;
        }
        else if (nums[0] < nums[1])
        {
            inc = 1;
        }
        else
        {
            inc = 0;
            ctr = 1;
        }
        for (int i = 2; i < n; i++)
        {
            if ((nums[i] > prev) && (inc == 0 || inc == -1))
            {
                ctr++;
                inc = 1;
                prev = nums[i];
            }
            else if ((nums[i] < prev) && (inc == 0 || inc == 1))
            {
                ctr++;
                inc = -1;
                prev = nums[i];
            }
            else
            {
                prev = nums[i];
            }
        }
        return ctr;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}