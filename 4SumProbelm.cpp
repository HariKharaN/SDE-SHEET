#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int left = j + 1;
                int right = n - 1;
                while (left < right)
                {
                    int s = a[i] + a[j] + a[left] + a[right];
                    if (s == k)
                    {
                        vector<int> v;
                        v.push_back(a[i]);
                        v.push_back(a[j]);
                        v.push_back(a[left]);
                        v.push_back(a[right]);
                        res.push_back(v);
                    }
                    if (s > k)
                    {
                        do
                        {
                            --right;
                        } while (a[right + 1] == a[right] && right > left);
                    }
                    else
                    {
                        do
                        {
                            ++left;
                        } while (a[left] == a[left - 1] && right > left);
                    }
                }
                while (j + 1 < n && a[j] == a[j + 1])
                    ++j;
            }
            while (i + 1 < n && a[i] == a[i + 1])
                ++i;
        }
        // sort(res.begin(), res.end());
        if (res.size() == 0)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < res.size(); i++)
            {
                for (int j = 0; j < res[i].size(); j++)
                {
                    cout << res[i][j] << " ";
                }
                cout << "$";
            }
            cout << endl;
        }
    }
}