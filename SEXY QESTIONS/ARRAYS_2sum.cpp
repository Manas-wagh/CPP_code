#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int p, q, n;
        vector<int> ans;
        vector<int> temp;
        n = nums.size();
        for (int i = 0; i < n; i++)
        {
            temp.push_back(nums[i]);
        }
        sort(nums.begin(), nums.end());
        p = 0, q = n - 1;
        while (p < q)
        {
            if (nums[p] + nums[q] < target)
            {
                p++;
            }
            else if (nums[p] + nums[q] > target)
            {
                q--;
            }
            else
            {
                // ans.push_back(p);
                // ans.push_back(q);
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[p] == temp[i])
            {
                ans.push_back(i);
                break;
            }
        }
        for (int i = n - 1; i > -1; i--)
        {
            if (nums[q] == temp[i])
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};

///  for 3 SUM
// ie ek ele uthau and baki 2 ke liye 2sum

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {

                int low = i + 1, high = n - 1, sum = 0 - nums[i];

                while (low < high)
                {
                    if (nums[low] + nums[high] == sum)
                    {

                        vector<int> temp;
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        temp.push_back(nums[i]);

                        ans.push_back(temp);

                        while (low < high && nums[low] == nums[low + 1])
                        {
                            low++;
                        }
                        while (low < high && nums[high] == nums[high - 1])
                        {
                            high--;
                        }

                        low++;
                        high--;
                    }
                    else if (nums[low] + nums[high] < sum)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }
            }
        }
        return ans;
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