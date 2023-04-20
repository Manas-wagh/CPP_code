#include <bits/stdc++.h>
using namespace std;

int ciel_index(vector<int> &tail, int len, int key)
{
    int low = 0;
    int high = len;
    while (high > low)
    {
        int mid = (high + low) / 2;
        if (tail[mid] >= key)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}

int Nested_rectangle(vector<pair<int, int>> &input)
{

    vector<int> tail(input.size());
    int len = 0;
    tail[0] = input[0].second;
    for (int i = 1; i < input.size(); i++)
    {
        if (input[i].second > tail[len]&&)
        {
            len++;
            tail[len] = input[i].second;
        }
        else
        {
            int c = ciel_index(tail, len, input[i].second);
            tail[c] = input[i].second;
        }
    }

    return len + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i].first >> input[i].second;
    }

    sort(input.begin(), input.end());
    cout<<Nested_rectangle(input);

    return 0;
}